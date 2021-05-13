//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnxtp.h"
#include "pybind11/pybind11.h"
#include "xtp/xtp_trader_api.h"


using namespace pybind11;
using namespace XTP::API;


//常量
#define ONDISCONNECTED 0
#define ONERROR 1
#define ONORDEREVENT 2
#define ONTRADEEVENT 3
#define ONCANCELORDERERROR 4
#define ONQUERYORDER 5
#define ONQUERYORDERBYPAGE 6
#define ONQUERYTRADE 7
#define ONQUERYTRADEBYPAGE 8
#define ONQUERYPOSITION 9
#define ONQUERYASSET 10
#define ONQUERYSTRUCTUREDFUND 11
#define ONQUERYFUNDTRANSFER 12
#define ONFUNDTRANSFER 13
#define ONQUERYETF 14
#define ONQUERYETFBASKET 15
#define ONQUERYIPOINFOLIST 16
#define ONQUERYIPOQUOTAINFO 17
#define ONQUERYOPTIONAUCTIONINFO 18
#define ONCREDITCASHREPAY 19
#define ONCREDITCASHREPAYDEBTINTERESTFEE 20
#define ONQUERYCREDITCASHREPAYINFO 21
#define ONQUERYCREDITFUNDINFO 22
#define ONQUERYCREDITDEBTINFO 23
#define ONQUERYCREDITTICKERDEBTINFO 24
#define ONQUERYCREDITASSETDEBTINFO 25
#define ONQUERYCREDITTICKERASSIGNINFO 26
#define ONQUERYCREDITEXCESSSTOCK 27
#define ONQUERYMULCREDITEXCESSSTOCK 28
#define ONCREDITEXTENDDEBTDATE 29
#define ONQUERYCREDITEXTENDDEBTDATEORDERS 30
#define ONQUERYCREDITFUNDEXTRAINFO 31
#define ONQUERYCREDITPOSITIONEXTRAINFO 32
#define ONOPTIONCOMBINEDORDEREVENT 33
#define ONOPTIONCOMBINEDTRADEEVENT 34
#define ONCANCELOPTIONCOMBINEDORDERERROR 35
#define ONQUERYOPTIONCOMBINEDORDERS 36
#define ONQUERYOPTIONCOMBINEDORDERSBYPAGE 37
#define ONQUERYOPTIONCOMBINEDTRADES 38
#define ONQUERYOPTIONCOMBINEDTRADESBYPAGE 39
#define ONQUERYOPTIONCOMBINEDPOSITION 40
#define ONQUERYOPTIONCOMBINEDSTRATEGYINFO 41
#define ONQUERYOPTIONCOMBINEDEXECPOSITION 42


///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class TdApi : public TraderSpi
{
private:
	TraderApi* api;            //API对象
	thread task_thread;                    //工作线程指针（向python中推送数据）
	TaskQueue task_queue;                //任务队列
	bool active = false;                //工作状态

public:
	TdApi()
	{
	};

	~TdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API回调函数
	//-------------------------------------------------------------------------------------

	///当客户端的某个连接与交易后台通信连接断开时，该方法被调用。
	///@param reason 错误原因，请与错误代码表对应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 用户主动调用logout导致的断线，不会触发此函数。api不会自动重连，当断线发生时，请用户自行选择后续操作，可以在此函数中调用Login重新登录，并更新session_id，此时用户收到的数据跟断线之前是连续的
	virtual void OnDisconnected(uint64_t session_id, int reason);

	///错误应答
	///@param error_info 当服务器响应发生错误时的具体的错误代码和错误信息,当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@remark 此函数只有在服务器发生错误时才会调用，一般无需用户处理
	virtual void OnError(XTPRI *error_info);

	///报单通知
	///@param order_info 订单响应具体信息，用户可以通过order_info.order_xtp_id来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单，order_info.qty_left字段在订单为未成交、部成、全成、废单状态时，表示此订单还没有成交的数量，在部撤、全撤状态时，表示此订单被撤的数量。order_info.order_cancel_xtp_id为其所对应的撤单ID，不为0时表示此单被撤成功
	///@param error_info 订单被拒绝或者发生错误时错误代码和错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 每次订单状态更新时，都会被调用，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线，在订单未成交、全部成交、全部撤单、部分撤单、已拒绝这些状态时会有响应，对于部分成交的情况，请由订单的成交回报来自行确认。所有登录了此用户的客户端都将收到此用户的订单响应
	virtual void OnOrderEvent(XTPOrderInfo *order_info, XTPRI *error_info, uint64_t session_id);

	///成交通知
	///@param trade_info 成交回报的具体信息，用户可以通过trade_info.order_xtp_id来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单。对于上交所，exec_id可以唯一标识一笔成交。当发现2笔成交回报拥有相同的exec_id，则可以认为此笔交易自成交了。对于深交所，exec_id是唯一的，暂时无此判断机制。report_index+market字段可以组成唯一标识表示成交回报。
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 订单有成交发生的时候，会被调用，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。所有登录了此用户的客户端都将收到此用户的成交回报。相关订单为部成状态，需要用户通过成交回报的成交数量来确定，OnOrderEvent()不会推送部成状态。
	virtual void OnTradeEvent(XTPTradeReport *trade_info, uint64_t session_id);

	///撤单出错响应
	///@param cancel_info 撤单具体信息，包括撤单的order_cancel_xtp_id和待撤单的order_xtp_id
	///@param error_info 撤单被拒绝或者发生错误时错误代码和错误信息，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 此响应只会在撤单发生错误时被回调
	virtual void OnCancelOrderError(XTPOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id);

	///请求查询报单响应
	///@param order_info 查询到的一个报单
	///@param error_info 查询报单时发生错误时，返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 由于支持分时段查询，一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryOrder(XTPQueryOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///分页请求查询报单响应
	///@param order_info 查询到的一个报单
	///@param req_count 分页请求的最大数量
	///@param order_sequence 分页请求的当前回报数量
	///@param query_reference 当前报单信息所对应的查询索引，需要记录下来，在进行下一次分页查询的时候需要用到
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 当order_sequence为0，表明当次查询没有查到任何记录，当is_last为true时，如果order_sequence等于req_count，那么表示还有报单，可以进行下一次分页查询，如果不等，表示所有报单已经查询完毕。一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。
	virtual void OnQueryOrderByPage(XTPQueryOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///请求查询成交响应
	///@param trade_info 查询到的一个成交回报
	///@param error_info 查询成交回报发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 由于支持分时段查询，一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryTrade(XTPQueryTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///分页请求查询成交响应
	///@param trade_info 查询到的一个成交信息
	///@param req_count 分页请求的最大数量
	///@param trade_sequence 分页请求的当前回报数量
	///@param query_reference 当前报单信息所对应的查询索引，需要记录下来，在进行下一次分页查询的时候需要用到
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 当trade_sequence为0，表明当次查询没有查到任何记录，当is_last为true时，如果trade_sequence等于req_count，那么表示还有回报，可以进行下一次分页查询，如果不等，表示所有回报已经查询完毕。一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。
	virtual void OnQueryTradeByPage(XTPQueryTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///请求查询投资者持仓响应
	///@param position 查询到的一只股票的持仓情况
	///@param error_info 查询账户持仓发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 由于用户可能持有多个股票，一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryPosition(XTPQueryStkPositionRsp *position, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询资金账户响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param asset 查询到的资金账户情况
	///@param error_info 查询资金账户发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryAsset(XTPQueryAssetRsp *asset, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询分级基金信息响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param fund_info 查询到的分级基金情况
	///@param error_info 查询分级基金发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryStructuredFund(XTPStructuredFundInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询资金划拨订单响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param fund_transfer_info 查询到的资金账户情况
	///@param error_info 查询资金账户发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///资金划拨通知
	///@param fund_transfer_info 资金划拨通知的具体信息，用户可以通过fund_transfer_info.serial_id来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单。
	///@param error_info 资金划拨订单被拒绝或者发生错误时错误代码和错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误。当资金划拨方向为一号两中心节点之间划拨，且error_info.error_id=11000384时，error_info.error_msg为结点中可用于划拨的资金（以整数为准），用户需进行stringToInt的转化，可据此填写合适的资金，再次发起划拨请求
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 当资金划拨订单有状态变化的时候，会被调用，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。所有登录了此用户的客户端都将收到此用户的资金划拨通知。
	virtual void OnFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, uint64_t session_id);

	///请求查询ETF清单文件的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param etf_info 查询到的ETF清单文件情况
	///@param error_info 查询ETF清单文件发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryETF(XTPQueryETFBaseRsp *etf_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询ETF股票篮的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param etf_component_info 查询到的ETF合约的相关成分股信息
	///@param error_info 查询ETF股票篮发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryETFBasket(XTPQueryETFComponentRsp *etf_component_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询今日新股申购信息列表的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param ipo_info 查询到的今日新股申购的一只股票信息
	///@param error_info 查询今日新股申购信息列表发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryIPOInfoList(XTPQueryIPOTickerRsp *ipo_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询用户新股申购额度信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param quota_info 查询到的用户某个市场的今日新股申购额度信息
	///@param error_info 查查询用户新股申购额度信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryIPOQuotaInfo(XTPQueryIPOQuotaRsp *quota_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询期权合约的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param option_info 查询到的期权合约情况
	///@param error_info 查询期权合约发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp *option_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///融资融券业务中现金直接还款的响应
	///@param cash_repay_info 现金直接还款通知的具体信息，用户可以通过cash_repay_info.xtp_id来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单。
	///@param error_info 现金还款发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnCreditCashRepay(XTPCrdCashRepayRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id);

	///融资融券业务中现金还息的响应
	///@param cash_repay_info 现金还息通知的具体信息，用户可以通过cash_repay_info.xtp_id来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单。
	///@param error_info 现金还息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnCreditCashRepayDebtInterestFee(XTPCrdCashRepayDebtInterestFeeRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id);

	///请求查询融资融券业务中的现金直接还款报单的响应
	///@param cash_repay_info 查询到的某一笔现金直接还款通知的具体信息
	///@param error_info 查询现金直接报单发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditCashRepayInfo(XTPCrdCashRepayInfo *cash_repay_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询信用账户额外信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param fund_info 查询到的信用账户额外信息情况
	///@param error_info 查询信用账户额外信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditFundInfo(XTPCrdFundInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id);

	///请求查询信用账户负债信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param debt_info 查询到的信用账户合约负债情况
	///@param error_info 查询信用账户负债信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditDebtInfo(XTPCrdDebtInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询信用账户指定证券负债未还信息响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param debt_info 查询到的信用账户指定证券负债未还信息情况
	///@param error_info 查询信用账户指定证券负债未还信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditTickerDebtInfo(XTPCrdDebtStockInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询信用账户待还资金的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param remain_amount 查询到的信用账户待还资金
	///@param error_info 查询信用账户待还资金发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditAssetDebtInfo(double remain_amount, XTPRI *error_info, int request_id, uint64_t session_id);

	///请求查询信用账户可融券头寸信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param assign_info 查询到的信用账户可融券头寸信息
	///@param error_info 查询信用账户可融券头寸信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditTickerAssignInfo(XTPClientQueryCrdPositionStkInfo *assign_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///融资融券业务中请求查询指定余券信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param stock_info 查询到的余券信息
	///@param error_info 查询信用账户余券信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id);

	///融资融券业务中请求查询余券信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param stock_info 查询到的余券信息
	///@param error_info 查询信用账户余券信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param session_id 资金账户对应的session_id，登录时得到
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryMulCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id, bool is_last);

	///融资融券业务中负债合约展期的通知
	///@param debt_extend_info 负债合约展期通知的具体信息，用户可以通过debt_extend_info.xtpid来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单。
	///@param error_info 负债合约展期订单被拒绝或者发生错误时错误代码和错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误。
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 当负债合约展期订单有状态变化的时候，会被调用，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。所有登录了此用户的客户端都将收到此用户的负债合约展期通知。
	virtual void OnCreditExtendDebtDate(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, uint64_t session_id);

	///查询融资融券业务中负债合约展期订单响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param debt_extend_info 查询到的负债合约展期情况
	///@param error_info 查询负债合约展期发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误。当error_info.error_id=11000350时，表明没有记录，当为其他非0值时，表明合约发生拒单时的错误原因
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditExtendDebtDateOrders(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///查询融资融券业务中信用账户附加信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param fund_info 信用账户附加信息
	///@param error_info 查询信用账户附加信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditFundExtraInfo(XTPCrdFundExtraInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id);

	///查询融资融券业务中信用账户指定证券的附加信息的响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	///@param fund_info 信用账户指定证券的附加信息
	///@param error_info 查询信用账户附加信息发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线
	virtual void OnQueryCreditPositionExtraInfo(XTPCrdPositionExtraInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///期权组合策略报单通知
	///@param order_info 订单响应具体信息，用户可以通过order_info.order_xtp_id来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单，order_info.qty_left字段在订单为未成交、部成、全成、废单状态时，表示此订单还没有成交的数量，在部撤、全撤状态时，表示此订单被撤的数量。order_info.order_cancel_xtp_id为其所对应的撤单ID，不为0时表示此单被撤成功
	///@param error_info 订单被拒绝或者发生错误时错误代码和错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 每次订单状态更新时，都会被调用，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线，在订单未成交、全部成交、全部撤单、部分撤单、已拒绝这些状态时会有响应，对于部分成交的情况，请由订单的成交回报来自行确认。所有登录了此用户的客户端都将收到此用户的订单响应
	virtual void OnOptionCombinedOrderEvent(XTPOptCombOrderInfo *order_info, XTPRI *error_info, uint64_t session_id);

	///期权组合策略成交通知
	///@param trade_info 成交回报的具体信息，用户可以通过trade_info.order_xtp_id来管理订单，通过GetClientIDByXTPID() == client_id来过滤自己的订单。对于上交所，exec_id可以唯一标识一笔成交。当发现2笔成交回报拥有相同的exec_id，则可以认为此笔交易自成交了。对于深交所，exec_id是唯一的，暂时无此判断机制。report_index+market字段可以组成唯一标识表示成交回报。
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 订单有成交发生的时候，会被调用，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。所有登录了此用户的客户端都将收到此用户的成交回报。相关订单为部成状态，需要用户通过成交回报的成交数量来确定，OnOrderEvent()不会推送部成状态。
	virtual void OnOptionCombinedTradeEvent(XTPOptCombTradeReport *trade_info, uint64_t session_id);

	///期权组合策略撤单出错响应
	///@param cancel_info 撤单具体信息，包括撤单的order_cancel_xtp_id和待撤单的order_xtp_id
	///@param error_info 撤单被拒绝或者发生错误时错误代码和错误信息，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 此响应只会在撤单发生错误时被回调
	virtual void OnCancelOptionCombinedOrderError(XTPOptCombOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id);

	///请求查询期权组合策略报单响应
	///@param order_info 查询到的一个报单
	///@param error_info 查询报单时发生错误时，返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 由于支持分时段查询，一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。此对应的请求函数不建议轮询使用，当报单量过多时，容易造成用户线路拥堵，导致api断线
	virtual void OnQueryOptionCombinedOrders(XTPQueryOptCombOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///分页请求查询期权组合策略报单响应
	///@param order_info 查询到的一个报单
	///@param req_count 分页请求的最大数量
	///@param order_sequence 分页请求的当前回报数量
	///@param query_reference 当前报单信息所对应的查询索引，需要记录下来，在进行下一次分页查询的时候需要用到
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 当order_sequence为0，表明当次查询没有查到任何记录，当is_last为true时，如果order_sequence等于req_count，那么表示还有报单，可以进行下一次分页查询，如果不等，表示所有报单已经查询完毕。一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。
	virtual void OnQueryOptionCombinedOrdersByPage(XTPQueryOptCombOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///请求查询期权组合策略成交响应
	///@param trade_info 查询到的一个成交回报
	///@param error_info 查询成交回报发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 由于支持分时段查询，一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。此对应的请求函数不建议轮询使用，当报单量过多时，容易造成用户线路拥堵，导致api断线
	virtual void OnQueryOptionCombinedTrades(XTPQueryOptCombTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///分页请求查询期权组合策略成交响应
	///@param trade_info 查询到的一个成交信息
	///@param req_count 分页请求的最大数量
	///@param trade_sequence 分页请求的当前回报数量
	///@param query_reference 当前报单信息所对应的查询索引，需要记录下来，在进行下一次分页查询的时候需要用到
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 当trade_sequence为0，表明当次查询没有查到任何记录，当is_last为true时，如果trade_sequence等于req_count，那么表示还有回报，可以进行下一次分页查询，如果不等，表示所有回报已经查询完毕。一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。
	virtual void OnQueryOptionCombinedTradesByPage(XTPQueryOptCombTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///请求查询期权组合策略持仓响应
	///@param position_info 查询到的一个持仓信息
	///@param error_info 查询持仓发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。
	virtual void OnQueryOptionCombinedPosition(XTPQueryOptCombPositionRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///请求查询期权组合策略信息响应
	///@param strategy_info 查询到的一个组合策略信息
	///@param error_info 查询成交回报发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。
	virtual void OnQueryOptionCombinedStrategyInfo(XTPQueryCombineStrategyInfoRsp *strategy_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///查询期权行权合并头寸的响应
	///@param position_info 查询到的一个行权合并头寸信息
	///@param error_info 查询持仓发生错误时返回的错误信息，当error_info为空，或者error_info.error_id为0时，表明没有错误
	///@param request_id 此消息响应函数对应的请求ID
	///@param is_last 此消息响应函数是否为request_id这条请求所对应的最后一个响应，当为最后一个的时候为true，如果为false，表示还有其他后续消息响应
	///@param session_id 资金账户对应的session_id，登录时得到
	///@remark 一个查询请求可能对应多个响应，需要快速返回，否则会堵塞后续消息，当堵塞严重时，会触发断线。
	virtual void OnQueryOptionCombinedExecPosition(XTPQueryOptCombExecPosRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------
	void processTask();

	void processDisconnected(Task *task);

	void processError(Task *task);

	void processOrderEvent(Task *task);

	void processTradeEvent(Task *task);

	void processCancelOrderError(Task *task);

	void processQueryOrder(Task *task);

	void processQueryOrderByPage(Task *task);

	void processQueryTrade(Task *task);

	void processQueryTradeByPage(Task *task);

	void processQueryPosition(Task *task);

	void processQueryAsset(Task *task);

	void processQueryStructuredFund(Task *task);

	void processQueryFundTransfer(Task *task);

	void processFundTransfer(Task *task);

	void processQueryETF(Task *task);

	void processQueryETFBasket(Task *task);

	void processQueryIPOInfoList(Task *task);

	void processQueryIPOQuotaInfo(Task *task);

	void processQueryOptionAuctionInfo(Task *task);

	void processCreditCashRepay(Task *task);

	void processCreditCashRepayDebtInterestFee(Task *task);

	void processQueryCreditCashRepayInfo(Task *task);

	void processQueryCreditFundInfo(Task *task);

	void processQueryCreditDebtInfo(Task *task);

	void processQueryCreditTickerDebtInfo(Task *task);

	void processQueryCreditAssetDebtInfo(Task *task);

	void processQueryCreditTickerAssignInfo(Task *task);

	void processQueryCreditExcessStock(Task *task);

	void processQueryMulCreditExcessStock(Task *task);

	void processCreditExtendDebtDate(Task *task);

	void processQueryCreditExtendDebtDateOrders(Task *task);

	void processQueryCreditFundExtraInfo(Task *task);

	void processQueryCreditPositionExtraInfo(Task *task);

	void processOptionCombinedOrderEvent(Task *task);

	void processOptionCombinedTradeEvent(Task *task);

	void processCancelOptionCombinedOrderError(Task *task);

	void processQueryOptionCombinedOrders(Task *task);

	void processQueryOptionCombinedOrdersByPage(Task *task);

	void processQueryOptionCombinedTrades(Task *task);

	void processQueryOptionCombinedTradesByPage(Task *task);

	void processQueryOptionCombinedPosition(Task *task);

	void processQueryOptionCombinedStrategyInfo(Task *task);

	void processQueryOptionCombinedExecPosition(Task *task);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
	//-------------------------------------------------------------------------------------

	virtual void onDisconnected(int extra, int extra_1) {};

	virtual void onError(const dict &error) {};

	virtual void onOrderEvent(const dict &data, const dict &error, int extra) {};

	virtual void onTradeEvent(const dict &data, int extra) {};

	virtual void onCancelOrderError(const dict &data, const dict &error, int extra) {};

	virtual void onQueryOrder(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryOrderByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryTrade(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryTradeByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryPosition(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryAsset(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryStructuredFund(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryFundTransfer(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onFundTransfer(const dict &data, const dict &error, int extra) {};

	virtual void onQueryETF(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryETFBasket(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryIPOInfoList(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryIPOQuotaInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryOptionAuctionInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onCreditCashRepay(const dict &data, const dict &error, int extra) {};

	virtual void onCreditCashRepayDebtInterestFee(const dict &data, const dict &error, int extra) {};

	virtual void onQueryCreditCashRepayInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryCreditFundInfo(const dict &data, const dict &error, int reqid, int extra) {};

	virtual void onQueryCreditDebtInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryCreditTickerDebtInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryCreditAssetDebtInfo(double amount, const dict &error, int reqid, int extra) {};

	virtual void onQueryCreditTickerAssignInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryCreditExcessStock(const dict &data, const dict &error, int reqid, int extra) {};

	virtual void onQueryMulCreditExcessStock(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onCreditExtendDebtDate(const dict &data, const dict &error, int extra) {};

	virtual void onQueryCreditExtendDebtDateOrders(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryCreditFundExtraInfo(const dict &data, const dict &error, int reqid, int extra) {};

	virtual void onQueryCreditPositionExtraInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onOptionCombinedOrderEvent(const dict &data, const dict &error, int extra) {};

	virtual void onOptionCombinedTradeEvent(const dict &data, int extra) {};

	virtual void onCancelOptionCombinedOrderError(const dict &data, const dict &error, int extra) {};

	virtual void onQueryOptionCombinedOrders(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryOptionCombinedOrdersByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedTrades(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryOptionCombinedTradesByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedPosition(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryOptionCombinedStrategyInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	virtual void onQueryOptionCombinedExecPosition(const dict &data, const dict &error, int reqid, bool last, int extra) {};

	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void createTraderApi(int client_id, string save_file_path, int log_level);

	void release();

	void init();

	int exit();

	string getTradingDay();

	string getApiVersion();

	dict getApiLastError();

	int getClientIDByXTPID(long long order_xtp_id);

	string getAccountByXTPID(long long order_xtp_id);

	void subscribePublicTopic(int resume_type);

	void setSoftwareVersion(string version);

	void setSoftwareKey(string key);

	void setHeartBeatInterval(int interval);

	long long login(string ip, int port, string user, string password, int sock_type);

	int logout(long long session_id);

	long long insertOrder(const dict &req, long long session_id);

	long long cancelOrder(long long order_xtp_id, long long session_id);

	int queryOrderByXTPID(long long order_xtp_id, long long session_id, int request_id);

	int queryOrders(const dict &req, long long session_id, int request_id);

	int queryUnfinishedOrders(long long session_id, int request_id);

	int queryOrdersByPage(const dict &req, long long session_id, int request_id);

	int queryTradesByXTPID(long long order_xtp_id, long long session_id, int request_id);

	int queryTrades(const dict &req, long long session_id, int request_id);

	int queryTradesByPage(const dict &req, long long session_id, int request_id);

	int queryPosition(string ticker, long long session_id, int request_id);

	int queryAsset(long long session_id, int request_id);

	int queryStructuredFund(const dict &req, long long session_id, int request_id);

	int queryFundTransfer(const dict &req, long long session_id, int request_id);

	int queryETF(const dict &req, long long session_id, int request_id);

	int queryETFTickerBasket(const dict &req, long long session_id, int request_id);

	int queryIPOInfoList(long long session_id, int request_id);

	int queryIPOQuotaInfo(long long session_id, int request_id);

	int queryOptionAuctionInfo(const dict &req, long long session_id, int request_id);

	int queryCreditCashRepayInfo(long long session_id, int request_id);

	int queryCreditFundInfo(long long session_id, int request_id);

	int queryCreditDebtInfo(long long session_id, int request_id);

	int queryCreditTickerDebtInfo(const dict &req, long long session_id, int request_id);

	int queryCreditAssetDebtInfo(long long session_id, int request_id);

	int queryCreditTickerAssignInfo(const dict &req, long long session_id, int request_id);

	int queryCreditExcessStock(const dict &req, long long session_id, int request_id);

	int queryMulCreditExcessStock(const dict &req, long long session_id, int request_id);

	int queryCreditExtendDebtDateOrders(int xtp_id, long long session_id, int request_id);

	int queryCreditFundExtraInfo(long long session_id, int request_id);

	int queryCreditPositionExtraInfo(const dict &req, long long session_id, int request_id);

	int queryOptionCombinedUnfinishedOrders(long long session_id, int request_id);

	int queryOptionCombinedOrderByXTPID(long long order_xtp_id, long long session_id, int request_id);

	int queryOptionCombinedOrders(const dict &req, long long session_id, int request_id);

	int queryOptionCombinedOrdersByPage(const dict &req, long long session_id, int request_id);

	int queryOptionCombinedTradesByXTPID(long long order_xtp_id, long long session_id, int request_id);

	int queryOptionCombinedTrades(const dict &req, long long session_id, int request_id);

	int queryOptionCombinedTradesByPage(const dict &req, long long session_id, int request_id);

	int queryOptionCombinedPosition(const dict &req, long long session_id, int request_id);

	int queryOptionCombinedStrategyInfo(long long session_id, int request_id);

	int queryOptionCombinedExecPosition(const dict &req, long long session_id, int request_id);
};
