void onDisconnected(int extra, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onDisconnected, extra, extra);
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

void onOrderEvent(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOrderEvent, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTradeEvent(const dict &data, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onTradeEvent, data, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCancelOrderError(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCancelOrderError, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOrder(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOrder, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOrderByPage(const dict &data, int extra, int extra, int extra, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOrderByPage, data, extra, extra, extra, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTrade(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTrade, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTradeByPage(const dict &data, int extra, int extra, int extra, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryTradeByPage, data, extra, extra, extra, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryPosition(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryPosition, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryAsset(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryAsset, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryStructuredFund(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryStructuredFund, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryFundTransfer(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryFundTransfer, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onFundTransfer(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onFundTransfer, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryETF(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryETF, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryETFBasket(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryETFBasket, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryIPOInfoList(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryIPOInfoList, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryIPOQuotaInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryIPOQuotaInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionAuctionInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionAuctionInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditCashRepay(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditCashRepay, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditCashRepayDebtInterestFee(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditCashRepayDebtInterestFee, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditCashRepayInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditCashRepayInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditFundInfo(const dict &data, const dict &error, int reqid, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditFundInfo, data, error, reqid, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditDebtInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditDebtInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditTickerDebtInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditTickerDebtInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditAssetDebtInfo(const dict &data, const dict &error, int reqid, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditAssetDebtInfo, data, error, reqid, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditTickerAssignInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditTickerAssignInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditExcessStock(const dict &data, const dict &error, int reqid, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditExcessStock, data, error, reqid, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryMulCreditExcessStock(const dict &data, const dict &error, int reqid, int extra, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryMulCreditExcessStock, data, error, reqid, extra, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCreditExtendDebtDate(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCreditExtendDebtDate, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditExtendDebtDateOrders(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditExtendDebtDateOrders, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditFundExtraInfo(const dict &data, const dict &error, int reqid, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditFundExtraInfo, data, error, reqid, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryCreditPositionExtraInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryCreditPositionExtraInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOptionCombinedOrderEvent(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOptionCombinedOrderEvent, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOptionCombinedTradeEvent(const dict &data, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onOptionCombinedTradeEvent, data, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onCancelOptionCombinedOrderError(const dict &data, const dict &error, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onCancelOptionCombinedOrderError, data, error, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedOrders(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedOrders, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedOrdersByPage(const dict &data, int extra, int extra, int extra, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedOrdersByPage, data, extra, extra, extra, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedTrades(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedTrades, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedTradesByPage(const dict &data, int extra, int extra, int extra, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedTradesByPage, data, extra, extra, extra, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedPosition(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedPosition, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedStrategyInfo(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedStrategyInfo, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryOptionCombinedExecPosition(const dict &data, const dict &error, int reqid, bool last, int extra) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedExecPosition, data, error, reqid, last, extra);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

