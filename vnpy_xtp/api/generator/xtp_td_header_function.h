int queryOrderByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

int queryOrders(const dict &req, uint64_t session_id, int request_id);

int queryUnfinishedOrders(uint64_t session_id, int request_id);

int queryOrdersByPage(const dict &req, uint64_t session_id, int request_id);

int queryTradesByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

int queryTrades(const dict &req, uint64_t session_id, int request_id);

int queryTradesByPage(const dict &req, uint64_t session_id, int request_id);

int queryPosition(char ticker, uint64_t session_id, int request_id, = XTP_MKT_INIT);

int queryAsset(uint64_t session_id, int request_id);

int queryStructuredFund(const dict &req, uint64_t session_id, int request_id);

int queryFundTransfer(const dict &req, uint64_t session_id, int request_id);

int queryETF(const dict &req, uint64_t session_id, int request_id);

int queryETFTickerBasket(const dict &req, uint64_t session_id, int request_id);

int queryIPOInfoList(uint64_t session_id, int request_id);

int queryIPOQuotaInfo(uint64_t session_id, int request_id);

int queryOptionAuctionInfo(const dict &req, uint64_t session_id, int request_id);

int queryCreditCashRepayInfo(uint64_t session_id, int request_id);

int queryCreditFundInfo(uint64_t session_id, int request_id);

int queryCreditDebtInfo(uint64_t session_id, int request_id);

int queryCreditTickerDebtInfo(const dict &req, uint64_t session_id, int request_id);

int queryCreditAssetDebtInfo(uint64_t session_id, int request_id);

int queryCreditTickerAssignInfo(const dict &req, uint64_t session_id, int request_id);

int queryCreditExcessStock(const dict &req, uint64_t session_id, int request_id);

int queryMulCreditExcessStock(const dict &req, uint64_t session_id, int request_id);

int queryCreditExtendDebtDateOrders(uint64_t xtp_id, uint64_t session_id, int request_id);

int queryCreditFundExtraInfo(uint64_t session_id, int request_id);

int queryCreditPositionExtraInfo(const dict &req, uint64_t session_id, int request_id);

int queryOptionCombinedUnfinishedOrders(uint64_t session_id, int request_id);

int queryOptionCombinedOrderByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

int queryOptionCombinedOrders(const dict &req, uint64_t session_id, int request_id);

int queryOptionCombinedOrdersByPage(const dict &req, uint64_t session_id, int request_id);

int queryOptionCombinedTradesByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

int queryOptionCombinedTrades(const dict &req, uint64_t session_id, int request_id);

int queryOptionCombinedTradesByPage(const dict &req, uint64_t session_id, int request_id);

int queryOptionCombinedPosition(const dict &req, uint64_t session_id, int request_id);

int queryOptionCombinedStrategyInfo(uint64_t session_id, int request_id);

int queryOptionCombinedExecPosition(const dict &req, uint64_t session_id, int request_id);

