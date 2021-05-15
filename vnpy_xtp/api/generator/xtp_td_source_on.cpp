void onDisconnected(uint64_t session_id, int reason) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onDisconnected, session_id, reason);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onError(const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onError, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOrderEvent(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOrderEvent, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTradeEvent(const dict &data, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onTradeEvent, data, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCancelOrderError(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCancelOrderError, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOrder(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOrder, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOrderByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOrderByPage, data, req_count, order_sequence, query_reference, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTrade(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTrade, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTradeByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTradeByPage, data, req_count, trade_sequence, query_reference, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPosition, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryAsset(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryAsset, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryStructuredFund(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryStructuredFund, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryFundTransfer(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryFundTransfer, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onFundTransfer(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onFundTransfer, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryETF(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryETF, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryETFBasket(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryETFBasket, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryIPOInfoList(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryIPOInfoList, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryIPOQuotaInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryIPOQuotaInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionAuctionInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionAuctionInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditCashRepay(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditCashRepay, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditCashRepayDebtInterestFee(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditCashRepayDebtInterestFee, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditCashRepayInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditCashRepayInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditFundInfo(const dict &data, const dict &error, int request_id, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditFundInfo, data, error, request_id, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditDebtInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditTickerDebtInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditTickerDebtInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditAssetDebtInfo(double remain_amount, const dict &error, int request_id, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditAssetDebtInfo, remain_amount, error, request_id, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditTickerAssignInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditTickerAssignInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditExcessStock(const dict &data, const dict &error, int request_id, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditExcessStock, data, error, request_id, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryMulCreditExcessStock(const dict &data, const dict &error, int request_id, uint64_t session_id, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryMulCreditExcessStock, data, error, request_id, session_id, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditExtendDebtDate(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditExtendDebtDate, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditExtendDebtDateOrders(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditExtendDebtDateOrders, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditFundExtraInfo(const dict &data, const dict &error, int request_id, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditFundExtraInfo, data, error, request_id, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditPositionExtraInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditPositionExtraInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOptionCombinedOrderEvent(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOptionCombinedOrderEvent, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOptionCombinedTradeEvent(const dict &data, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOptionCombinedTradeEvent, data, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCancelOptionCombinedOrderError(const dict &data, const dict &error, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCancelOptionCombinedOrderError, data, error, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedOrders(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedOrders, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedOrdersByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedOrdersByPage, data, req_count, order_sequence, query_reference, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedTrades(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedTrades, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedTradesByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedTradesByPage, data, req_count, trade_sequence, query_reference, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedPosition, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedStrategyInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedStrategyInfo, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedExecPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedExecPosition, data, error, request_id, is_last, session_id);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

