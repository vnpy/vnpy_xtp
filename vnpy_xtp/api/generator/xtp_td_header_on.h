virtual void onDisconnected(int extra, int extra) {};

virtual void onError(const dict &error) {};

virtual void onOrderEvent(const dict &data, const dict &error, int extra) {};

virtual void onTradeEvent(int extra) {};

virtual void onCancelOrderError(const dict &data, const dict &error, int extra) {};

virtual void onQueryOrder(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryOrderByPage(const dict &data) {};

virtual void onQueryTrade(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryTradeByPage(const dict &data) {};

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

virtual void onQueryCreditAssetDebtInfo(const dict &data, const dict &error, int reqid, int extra) {};

virtual void onQueryCreditTickerAssignInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryCreditExcessStock(const dict &data, const dict &error, int reqid, int extra) {};

virtual void onQueryMulCreditExcessStock(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onCreditExtendDebtDate(const dict &data, const dict &error, int extra) {};

virtual void onQueryCreditExtendDebtDateOrders(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryCreditFundExtraInfo(const dict &data, const dict &error, int reqid, int extra) {};

virtual void onQueryCreditPositionExtraInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onOptionCombinedOrderEvent(const dict &data, const dict &error, int extra) {};

virtual void onOptionCombinedTradeEvent(int extra) {};

virtual void onCancelOptionCombinedOrderError(const dict &data, const dict &error, int extra) {};

virtual void onQueryOptionCombinedOrders(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryOptionCombinedOrdersByPage(const dict &data) {};

virtual void onQueryOptionCombinedTrades(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryOptionCombinedTradesByPage(const dict &data) {};

virtual void onQueryOptionCombinedPosition(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryOptionCombinedStrategyInfo(const dict &data, const dict &error, int reqid, bool last, int extra) {};

virtual void onQueryOptionCombinedExecPosition(const dict &data, const dict &error, int reqid, bool last, int extra) {};

