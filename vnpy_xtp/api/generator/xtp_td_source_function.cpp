int TdApi::queryOrderByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id)
{
	int i = this->api->QueryOrderByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryOrders(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOrderReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ticker", myreq.ticker);
	getInt64_t(req, "begin_time", &myreq.begin_time);
	getInt64_t(req, "end_time", &myreq.end_time);
	int i = this->api->QueryOrders(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryUnfinishedOrders(uint64_t session_id, int request_id)
{
	int i = this->api->QueryUnfinishedOrders(session_id, request_id);
	return i;
};

int TdApi::queryOrdersByPage(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOrderByPageReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getInt64_t(req, "req_count", &myreq.req_count);
	getInt64_t(req, "reference", &myreq.reference);
	getInt64_t(req, "reserved", &myreq.reserved);
	int i = this->api->QueryOrdersByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryTradesByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id)
{
	int i = this->api->QueryTradesByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryTrades(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryTraderReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ticker", myreq.ticker);
	getInt64_t(req, "begin_time", &myreq.begin_time);
	getInt64_t(req, "end_time", &myreq.end_time);
	int i = this->api->QueryTrades(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryTradesByPage(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryTraderByPageReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getInt64_t(req, "req_count", &myreq.req_count);
	getInt64_t(req, "reference", &myreq.reference);
	getInt64_t(req, "reserved", &myreq.reserved);
	int i = this->api->QueryTradesByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryPosition(char ticker, uint64_t session_id, int request_id, = XTP_MKT_INIT)
{
	int i = this->api->QueryPosition(ticker, session_id, request_id, XTP_MKT_INIT);
	return i;
};

int TdApi::queryAsset(uint64_t session_id, int request_id)
{
	int i = this->api->QueryAsset(session_id, request_id);
	return i;
};

int TdApi::queryStructuredFund(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryStructuredFundInfoReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "exchange_id", &myreq.exchange_id);
	getString(req, "sf_ticker", myreq.sf_ticker);
	int i = this->api->QueryStructuredFund(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryFundTransfer(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryFundTransferLogReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getUint64_t(req, "serial_id", &myreq.serial_id);
	int i = this->api->QueryFundTransfer(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryETF(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryETFBaseReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryETF(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryETFTickerBasket(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryETFComponentReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryETFTickerBasket(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryIPOInfoList(uint64_t session_id, int request_id)
{
	int i = this->api->QueryIPOInfoList(session_id, request_id);
	return i;
};

int TdApi::queryIPOQuotaInfo(uint64_t session_id, int request_id)
{
	int i = this->api->QueryIPOQuotaInfo(session_id, request_id);
	return i;
};

int TdApi::queryOptionAuctionInfo(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOptionAuctionInfoReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryOptionAuctionInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditCashRepayInfo(uint64_t session_id, int request_id)
{
	int i = this->api->QueryCreditCashRepayInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditFundInfo(uint64_t session_id, int request_id)
{
	int i = this->api->QueryCreditFundInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditDebtInfo(uint64_t session_id, int request_id)
{
	int i = this->api->QueryCreditDebtInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditTickerDebtInfo(const dict &req, uint64_t session_id, int request_id)
{
	XTPClientQueryCrdDebtStockReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditTickerDebtInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditAssetDebtInfo(uint64_t session_id, int request_id)
{
	int i = this->api->QueryCreditAssetDebtInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditTickerAssignInfo(const dict &req, uint64_t session_id, int request_id)
{
	XTPClientQueryCrdPositionStockReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditTickerAssignInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditExcessStock(const dict &req, uint64_t session_id, int request_id)
{
	XTPClientQueryCrdSurplusStkReqInfo myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditExcessStock(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryMulCreditExcessStock(const dict &req, uint64_t session_id, int request_id)
{
	XTPClientQueryCrdSurplusStkReqInfo myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryMulCreditExcessStock(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditExtendDebtDateOrders(uint64_t xtp_id, uint64_t session_id, int request_id)
{
	int i = this->api->QueryCreditExtendDebtDateOrders(xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryCreditFundExtraInfo(uint64_t session_id, int request_id)
{
	int i = this->api->QueryCreditFundExtraInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditPositionExtraInfo(const dict &req, uint64_t session_id, int request_id)
{
	XTPClientQueryCrdPositionStockReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditPositionExtraInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedUnfinishedOrders(uint64_t session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedUnfinishedOrders(session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrderByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedOrderByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrders(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOptCombOrderReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	getInt64_t(req, "begin_time", &myreq.begin_time);
	getInt64_t(req, "end_time", &myreq.end_time);
	int i = this->api->QueryOptionCombinedOrders(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrdersByPage(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOptCombOrderByPageReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getInt64_t(req, "req_count", &myreq.req_count);
	getInt64_t(req, "reference", &myreq.reference);
	getInt64_t(req, "reserved", &myreq.reserved);
	int i = this->api->QueryOptionCombinedOrdersByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTradesByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedTradesByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTrades(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOptCombTraderReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	getInt64_t(req, "begin_time", &myreq.begin_time);
	getInt64_t(req, "end_time", &myreq.end_time);
	int i = this->api->QueryOptionCombinedTrades(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTradesByPage(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOptCombTraderByPageReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getInt64_t(req, "req_count", &myreq.req_count);
	getInt64_t(req, "reference", &myreq.reference);
	getInt64_t(req, "reserved", &myreq.reserved);
	int i = this->api->QueryOptionCombinedTradesByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedPosition(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOptCombPositionReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	getEnum(req, "market", &myreq.market);
	int i = this->api->QueryOptionCombinedPosition(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedStrategyInfo(uint64_t session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedStrategyInfo(session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedExecPosition(const dict &req, uint64_t session_id, int request_id)
{
	XTPQueryOptCombExecPosReq myreq;
	memset(&myreq, 0, sizeof(myreq));
	getEnum(req, "market", &myreq.market);
	getString(req, "cntrt_code_1", myreq.cntrt_code_1);
	getString(req, "cntrt_code_2", myreq.cntrt_code_2);
	int i = this->api->QueryOptionCombinedExecPosition(&myreq, session_id, request_id);
	return i;
};

