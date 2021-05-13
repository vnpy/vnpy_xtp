int TdApi::queryOrderByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryOrderByXTPID(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOrders(const dict &req, long long session_id, int request_id)
{
	XTPQueryOrderReq myreq = XTPQueryOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ticker", myreq.ticker);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryOrders(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryUnfinishedOrders(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryUnfinishedOrders(&myreq, request_id);
	return i;
};

int TdApi::queryOrdersByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryOrderByPageReq myreq = XTPQueryOrderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryOrdersByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryTradesByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryTradesByXTPID(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryTrades(const dict &req, long long session_id, int request_id)
{
	XTPQueryTraderReq myreq = XTPQueryTraderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ticker", myreq.ticker);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryTrades(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryTradesByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryTraderByPageReq myreq = XTPQueryTraderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryTradesByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryPosition()
{
	char myreq = char();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryPosition(&myreq, );
	return i;
};

int TdApi::queryAsset(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryAsset(&myreq, request_id);
	return i;
};

int TdApi::queryStructuredFund(const dict &req, long long session_id, int request_id)
{
	XTPQueryStructuredFundInfoReq myreq = XTPQueryStructuredFundInfoReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.exchange_id = (XTP_EXCHANGE_TYPE) getIntValue(req, "exchange_id");
	getString(req, "sf_ticker", myreq.sf_ticker);
	int i = this->api->QueryStructuredFund(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryFundTransfer(const dict &req, long long session_id, int request_id)
{
	XTPQueryFundTransferLogReq myreq = XTPQueryFundTransferLogReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.serial_id = getIntValue(req, "serial_id");
	int i = this->api->QueryFundTransfer(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryETF(const dict &req, long long session_id, int request_id)
{
	XTPQueryETFBaseReq myreq = XTPQueryETFBaseReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryETF(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryETFTickerBasket(const dict &req, long long session_id, int request_id)
{
	XTPQueryETFComponentReq myreq = XTPQueryETFComponentReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryETFTickerBasket(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryIPOInfoList(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryIPOInfoList(&myreq, request_id);
	return i;
};

int TdApi::queryIPOQuotaInfo(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryIPOQuotaInfo(&myreq, request_id);
	return i;
};

int TdApi::queryOptionAuctionInfo(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptionAuctionInfoReq myreq = XTPQueryOptionAuctionInfoReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryOptionAuctionInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditCashRepayInfo(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryCreditCashRepayInfo(&myreq, request_id);
	return i;
};

int TdApi::queryCreditFundInfo(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryCreditFundInfo(&myreq, request_id);
	return i;
};

int TdApi::queryCreditDebtInfo(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryCreditDebtInfo(&myreq, request_id);
	return i;
};

int TdApi::queryCreditTickerDebtInfo(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdDebtStockReq myreq = XTPClientQueryCrdDebtStockReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditTickerDebtInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditAssetDebtInfo(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryCreditAssetDebtInfo(&myreq, request_id);
	return i;
};

int TdApi::queryCreditTickerAssignInfo(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdPositionStockReq myreq = XTPClientQueryCrdPositionStockReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditTickerAssignInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditExcessStock(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdSurplusStkReqInfo myreq = XTPClientQueryCrdSurplusStkReqInfo();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditExcessStock(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryMulCreditExcessStock(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdSurplusStkReqInfo myreq = XTPClientQueryCrdSurplusStkReqInfo();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryMulCreditExcessStock(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditExtendDebtDateOrders(int xtp_id, long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryCreditExtendDebtDateOrders(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditFundExtraInfo(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryCreditFundExtraInfo(&myreq, request_id);
	return i;
};

int TdApi::queryCreditPositionExtraInfo(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdPositionStockReq myreq = XTPClientQueryCrdPositionStockReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditPositionExtraInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedUnfinishedOrders(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryOptionCombinedUnfinishedOrders(&myreq, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrderByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryOptionCombinedOrderByXTPID(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrders(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombOrderReq myreq = XTPQueryOptCombOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryOptionCombinedOrders(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrdersByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombOrderByPageReq myreq = XTPQueryOptCombOrderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryOptionCombinedOrdersByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTradesByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryOptionCombinedTradesByXTPID(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTrades(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombTraderReq myreq = XTPQueryOptCombTraderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryOptionCombinedTrades(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTradesByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombTraderByPageReq myreq = XTPQueryOptCombTraderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryOptionCombinedTradesByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedPosition(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombPositionReq myreq = XTPQueryOptCombPositionReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	int i = this->api->QueryOptionCombinedPosition(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedStrategyInfo(long long session_id, int request_id)
{
	int myreq = int();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QueryOptionCombinedStrategyInfo(&myreq, request_id);
	return i;
};

int TdApi::queryOptionCombinedExecPosition(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombExecPosReq myreq = XTPQueryOptCombExecPosReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE) getIntValue(req, "market");
	getString(req, "cntrt_code_1", myreq.cntrt_code_1);
	getString(req, "cntrt_code_2", myreq.cntrt_code_2);
	int i = this->api->QueryOptionCombinedExecPosition(&myreq, session_id, request_id);
	return i;
};

