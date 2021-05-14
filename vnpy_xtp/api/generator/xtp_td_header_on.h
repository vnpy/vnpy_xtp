virtual void onDisconnected(uint64_t session_id, int reason) {};

virtual void onError(const dict &error) {};

virtual void onOrderEvent(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onTradeEvent(const dict &data, uint64_t session_id) {};

virtual void onCancelOrderError(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onQueryOrder(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOrderByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryTrade(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryTradeByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryAsset(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryStructuredFund(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryFundTransfer(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onFundTransfer(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onQueryETF(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryETFBasket(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryIPOInfoList(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryIPOQuotaInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOptionAuctionInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onCreditCashRepay(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onCreditCashRepayDebtInterestFee(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onQueryCreditCashRepayInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryCreditFundInfo(const dict &data, const dict &error, int request_id, uint64_t session_id) {};

virtual void onQueryCreditDebtInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryCreditTickerDebtInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryCreditAssetDebtInfo(double remain_amount, const dict &error, int request_id, uint64_t session_id) {};

virtual void onQueryCreditTickerAssignInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryCreditExcessStock(const dict &data, const dict &error, int request_id, uint64_t session_id) {};

virtual void onQueryMulCreditExcessStock(const dict &data, const dict &error, int request_id, uint64_t session_id, bool is_last) {};

virtual void onCreditExtendDebtDate(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onQueryCreditExtendDebtDateOrders(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryCreditFundExtraInfo(const dict &data, const dict &error, int request_id, uint64_t session_id) {};

virtual void onQueryCreditPositionExtraInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onOptionCombinedOrderEvent(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onOptionCombinedTradeEvent(const dict &data, uint64_t session_id) {};

virtual void onCancelOptionCombinedOrderError(const dict &data, const dict &error, uint64_t session_id) {};

virtual void onQueryOptionCombinedOrders(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOptionCombinedOrdersByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOptionCombinedTrades(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOptionCombinedTradesByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOptionCombinedPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOptionCombinedStrategyInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

virtual void onQueryOptionCombinedExecPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

