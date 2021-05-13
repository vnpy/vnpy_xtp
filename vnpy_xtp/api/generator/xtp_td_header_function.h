int queryOrderByXTPID(int order_xtp_id, int session_id, int request_id);

int queryOrders(const dict &req, int session_id, int request_id);

int queryUnfinishedOrders(int session_id, int request_id);

int queryOrdersByPage(const dict &req, int session_id, int request_id);

int queryTradesByXTPID(int order_xtp_id, int session_id, int request_id);

int queryTrades(const dict &req, int session_id, int request_id);

int queryTradesByPage(const dict &req, int session_id, int request_id);

int queryPosition();

int queryAsset(int session_id, int request_id);

int queryStructuredFund(const dict &req, int session_id, int request_id);

int queryFundTransfer(const dict &req, int session_id, int request_id);

int queryETF(const dict &req, int session_id, int request_id);

int queryETFTickerBasket(const dict &req, int session_id, int request_id);

int queryIPOInfoList(int session_id, int request_id);

int queryIPOQuotaInfo(int session_id, int request_id);

int queryOptionAuctionInfo(const dict &req, int session_id, int request_id);

int queryCreditCashRepayInfo(int session_id, int request_id);

int queryCreditFundInfo(int session_id, int request_id);

int queryCreditDebtInfo(int session_id, int request_id);

int queryCreditTickerDebtInfo(const dict &req, int session_id, int request_id);

int queryCreditAssetDebtInfo(int session_id, int request_id);

int queryCreditTickerAssignInfo(const dict &req, int session_id, int request_id);

int queryCreditExcessStock(const dict &req, int session_id, int request_id);

int queryMulCreditExcessStock(const dict &req, int session_id, int request_id);

int queryCreditExtendDebtDateOrders(int xtp_id, int session_id, int request_id);

int queryCreditFundExtraInfo(int session_id, int request_id);

int queryCreditPositionExtraInfo(const dict &req, int session_id, int request_id);

int queryOptionCombinedUnfinishedOrders(int session_id, int request_id);

int queryOptionCombinedOrderByXTPID(int order_xtp_id, int session_id, int request_id);

int queryOptionCombinedOrders(const dict &req, int session_id, int request_id);

int queryOptionCombinedOrdersByPage(const dict &req, int session_id, int request_id);

int queryOptionCombinedTradesByXTPID(int order_xtp_id, int session_id, int request_id);

int queryOptionCombinedTrades(const dict &req, int session_id, int request_id);

int queryOptionCombinedTradesByPage(const dict &req, int session_id, int request_id);

int queryOptionCombinedPosition(const dict &req, int session_id, int request_id);

int queryOptionCombinedStrategyInfo(int session_id, int request_id);

int queryOptionCombinedExecPosition(const dict &req, int session_id, int request_id);

