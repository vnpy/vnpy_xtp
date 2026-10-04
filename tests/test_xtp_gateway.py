from collections.abc import Callable, Iterator
from datetime import datetime
from typing import Any

import pytest

pytest.importorskip("vnpy_xtp.api", reason="缺少 XTP 原生扩展")

from vnpy.event import EventEngine  # noqa: E402
from vnpy.trader.constant import (  # noqa: E402
    Direction,
    Exchange,
    Offset,
    OrderType,
    Status,
)
from vnpy.trader.object import (  # noqa: E402
    OrderData,
    OrderRequest,
    PositionData,
    TickData,
)

from vnpy_xtp.api import (  # noqa: E402
    XTP_EXCHANGE_SH,
    XTP_MKT_INIT,
    XTP_MKT_SH_A,
    XTP_ORDER_STATUS_ALLTRADED,
    XTP_ORDER_STATUS_CANCELED,
    XTP_ORDER_STATUS_INIT,
    XTP_ORDER_STATUS_NOTRADEQUEUEING,
    XTP_ORDER_STATUS_PARTTRADEDNOTQUEUEING,
    XTP_ORDER_STATUS_PARTTRADEDQUEUEING,
    XTP_ORDER_STATUS_REJECTED,
    XTP_ORDER_STATUS_UNKNOWN,
    XTP_POSITION_DIRECTION_NET,
    XTP_PRICE_LIMIT,
    XTP_SIDE_BUY,
)
from vnpy_xtp.gateway import xtp_gateway  # noqa: E402
from vnpy_xtp.gateway.xtp_gateway import (  # noqa: E402
    CHINA_TZ,
    LOGLEVEL_VT2XTP,
    PROTOCOL_VT2XTP,
    XtpGateway,
    XtpMdApi,
    XtpTdApi,
)


class Sink:
    def __init__(self) -> None:
        self.logs: list[str] = []
        self.ticks: list[TickData] = []
        self.orders: list[OrderData] = []
        self.positions: list[PositionData] = []

    def attach(self, gateway: XtpGateway) -> None:
        gateway.write_log = self.logs.append
        gateway.on_tick = self.ticks.append
        gateway.on_order = self.orders.append
        gateway.on_position = self.positions.append


class CallRecorder:
    def __init__(self) -> None:
        self.calls: list[tuple[str, Any]] = []

    def patch(self, monkeypatch: pytest.MonkeyPatch, api: object, names: list[str]) -> None:
        for name in names:
            monkeypatch.setattr(api, name, self.make_stub(name))

    def make_stub(self, name: str) -> Callable[..., int]:
        def stub(*args: Any) -> int:
            self.calls.append((name, args[0] if args else None))
            return 0
        return stub

    def names(self) -> list[str]:
        return [name for name, _ in self.calls]


TD_METHODS: list[str] = [
    "createTraderApi",
    "setSoftwareKey",
    "subscribePublicTopic",
    "login",
    "init",
    "exit",
    "queryOptionAuctionInfo",
    "insertOrder",
    "cancelOrder",
    "queryAsset",
    "queryPosition",
    "queryCreditDebtInfo",
    "getApiLastError",
]

MD_METHODS: list[str] = [
    "createQuoteApi",
    "login",
    "init",
    "exit",
    "queryAllTickers",
    "subscribeMarketData",
    "getApiLastError",
]


@pytest.fixture(autouse=True)
def clear_contracts() -> Iterator[None]:
    xtp_gateway.symbol_contract_map.clear()
    yield
    xtp_gateway.symbol_contract_map.clear()


@pytest.fixture
def sink() -> Sink:
    return Sink()


@pytest.fixture
def recorder() -> CallRecorder:
    return CallRecorder()


@pytest.fixture
def gateway(sink: Sink, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> XtpGateway:
    engine: EventEngine = EventEngine()
    gateway: XtpGateway = XtpGateway(engine, "XTP")
    sink.attach(gateway)
    recorder.patch(monkeypatch, gateway.td_api, TD_METHODS)
    recorder.patch(monkeypatch, gateway.md_api, MD_METHODS)
    return gateway


@pytest.fixture
def td_api(gateway: XtpGateway) -> XtpTdApi:
    return gateway.td_api


@pytest.fixture
def md_api(gateway: XtpGateway) -> XtpMdApi:
    return gateway.md_api


def connect_setting() -> dict[str, Any]:
    return {
        "账号": "u1",
        "密码": "p1",
        "客户号": 1,
        "行情地址": "127.0.0.1",
        "行情端口": 6002,
        "交易地址": "10.0.0.2",
        "交易端口": 6001,
        "行情协议": "UDP",
        "日志级别": "INFO",
        "授权码": "key",
    }


def order_request(exchange: Exchange = Exchange.SSE) -> OrderRequest:
    return OrderRequest(
        symbol="600000",
        exchange=exchange,
        direction=Direction.LONG,
        type=OrderType.LIMIT,
        volume=100,
        price=10.5,
        offset=Offset.NONE,
    )


def order_event(status: int) -> dict[str, Any]:
    return {
        "ticker": "600000",
        "side": XTP_SIDE_BUY,
        "price_type": XTP_PRICE_LIMIT,
        "order_xtp_id": 15,
        "market": XTP_MKT_SH_A,
        "price": 10.5,
        "quantity": 100,
        "qty_traded": 0,
        "order_status": status,
        "insert_time": 20250926093000123,
    }


def test_connect_forwards_host_without_scheme(gateway: XtpGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    seen: dict[str, tuple] = {}
    monkeypatch.setattr(gateway.md_api, "connect", lambda *args: seen.__setitem__("md", args))
    monkeypatch.setattr(gateway.td_api, "connect", lambda *args: seen.__setitem__("td", args))

    gateway.connect(connect_setting())

    assert seen["md"][3] == "127.0.0.1"
    assert seen["md"][4] == 6002
    assert seen["md"][5] == "UDP"
    assert seen["md"][6] == LOGLEVEL_VT2XTP["INFO"]
    assert seen["td"][3] == "10.0.0.2"
    assert seen["td"][4] == 6001
    assert seen["td"][5] == "key"


def test_udp_quote_protocol_is_mapped(md_api: XtpMdApi, monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setattr(md_api, "login_server", lambda: None)
    md_api.connect("u1", "p1", 1, "127.0.0.1", 6002, "UDP", LOGLEVEL_VT2XTP["INFO"])

    assert md_api.server_ip == "127.0.0.1"
    assert md_api.server_port == 6002
    assert md_api.protocol == PROTOCOL_VT2XTP["UDP"]


def test_send_order_uses_insert_return(td_api: XtpTdApi, sink: Sink, monkeypatch: pytest.MonkeyPatch) -> None:
    td_api.session_id = 6

    def insert(req: dict[str, Any], session: int) -> int:
        assert session == 6
        assert req["ticker"] == "600000"
        assert req["quantity"] == 100
        assert req["price_type"] == XTP_PRICE_LIMIT
        return 88001

    monkeypatch.setattr(td_api, "insertOrder", insert)
    vt_orderid: str = td_api.send_order(order_request())

    assert vt_orderid == "XTP.88001"
    assert sink.orders[0].orderid == "88001"
    assert sink.orders[0].status == Status.SUBMITTING


def test_send_order_rejects_unknown_exchange(td_api: XtpTdApi, sink: Sink) -> None:
    assert td_api.send_order(order_request(exchange=Exchange.SHFE)) == ""
    assert sink.orders == []
    assert "不支持的交易所" in sink.logs[0]


@pytest.mark.parametrize(
    ("xtp_status", "status"),
    [
        (XTP_ORDER_STATUS_INIT, Status.SUBMITTING),
        (XTP_ORDER_STATUS_ALLTRADED, Status.ALLTRADED),
        (XTP_ORDER_STATUS_PARTTRADEDQUEUEING, Status.PARTTRADED),
        (XTP_ORDER_STATUS_PARTTRADEDNOTQUEUEING, Status.CANCELLED),
        (XTP_ORDER_STATUS_NOTRADEQUEUEING, Status.NOTTRADED),
        (XTP_ORDER_STATUS_CANCELED, Status.CANCELLED),
        (XTP_ORDER_STATUS_REJECTED, Status.REJECTED),
        (XTP_ORDER_STATUS_UNKNOWN, Status.SUBMITTING),
    ],
)
def test_order_status_mapping(td_api: XtpTdApi, sink: Sink, xtp_status: int, status: Status) -> None:
    td_api.onOrderEvent(order_event(xtp_status), {"error_id": 0, "error_msg": ""}, 1)

    order: OrderData = sink.orders[0]
    assert order.orderid == "15"
    assert order.status == status
    assert order.exchange == Exchange.SSE
    assert order.direction == Direction.LONG
    assert order.datetime == datetime(2025, 9, 26, 9, 30, 0, 123000, tzinfo=CHINA_TZ)


def test_position_volume_uses_total_qty(td_api: XtpTdApi, sink: Sink) -> None:
    td_api.onQueryPosition({
        "market": XTP_MKT_SH_A,
        "ticker": "600000",
        "position_direction": XTP_POSITION_DIRECTION_NET,
        "total_qty": 1000,
        "sellable_qty": 800,
        "avg_price": 10.5,
        "unrealized_pnl": 20,
        "yesterday_position": 600,
    }, {}, 1, False, 1)

    position: PositionData = sink.positions[0]
    assert position.symbol == "600000"
    assert position.exchange == Exchange.SSE
    assert position.direction == Direction.NET
    assert position.volume == 1000
    assert position.frozen == 200
    assert position.yd_volume == 600
    assert position.price == 10.5
    assert position.pnl == 20


def test_init_market_position_is_ignored(td_api: XtpTdApi, sink: Sink) -> None:
    td_api.onQueryPosition({"market": XTP_MKT_INIT}, {}, 1, True, 1)

    assert sink.positions == []


def test_credit_debt_tail_sums_short_volume(td_api: XtpTdApi, sink: Sink) -> None:
    td_api.onQueryCreditDebtInfo({
        "debt_type": 1,
        "ticker": "600000",
        "market": XTP_MKT_SH_A,
        "remain_qty": 300,
    }, {}, 1, False, 1)
    td_api.onQueryCreditDebtInfo({
        "debt_type": 1,
        "ticker": "600000",
        "market": XTP_MKT_SH_A,
        "remain_qty": 50,
    }, {}, 2, False, 1)
    assert sink.positions == []

    td_api.onQueryCreditDebtInfo({"debt_type": 0}, {}, 3, True, 1)

    position: PositionData = sink.positions[0]
    assert position.volume == 350
    assert position.direction == Direction.SHORT
    assert position.exchange == Exchange.SSE
    assert td_api.short_positions == {}


def test_depth_datetime_uses_data_time(md_api: XtpMdApi, sink: Sink) -> None:
    md_api.onDepthMarketData({
        "data_time": 20250926093000123,
        "ticker": "600000",
        "exchange_id": XTP_EXCHANGE_SH,
        "qty": 1000,
        "turnover": 10500,
        "last_price": 10.5,
        "upper_limit_price": 11.5,
        "lower_limit_price": 9.5,
        "open_price": 10.2,
        "high_price": 10.8,
        "low_price": 10.1,
        "pre_close_price": 10.4,
        "bid": [10.49, 10.48, 10.47, 10.46, 10.45],
        "ask": [10.51, 10.52, 10.53, 10.54, 10.55],
        "bid_qty": [1, 2, 3, 4, 5],
        "ask_qty": [6, 7, 8, 9, 10],
    })

    tick: TickData = sink.ticks[0]
    assert tick.symbol == "600000"
    assert tick.exchange == Exchange.SSE
    assert tick.datetime == datetime(2025, 9, 26, 9, 30, 0, 123000, tzinfo=CHINA_TZ)
    assert tick.bid_price_5 == 10.45
    assert tick.ask_volume_2 == 7


def test_close_without_connection_does_not_exit(
    td_api: XtpTdApi,
    md_api: XtpMdApi,
    recorder: CallRecorder,
) -> None:
    td_api.close()
    md_api.close()

    assert recorder.calls == []
