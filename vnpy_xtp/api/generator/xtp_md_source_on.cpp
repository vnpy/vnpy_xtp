void onDisconnected(int reason) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onDisconnected, reason);
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
		PYBIND11_OVERLOAD(void, MdApi, onError, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubMarketData(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubMarketData, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubMarketData(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubMarketData, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onDepthMarketData(const dict &data, int64_t bid1_qty, int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty, int32_t ask1_count, int32_t max_ask1_count) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onDepthMarketData, data, bid1_qty, bid1_count, max_bid1_count, ask1_qty, ask1_count, max_ask1_count);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubOrderBook(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubOrderBook, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubOrderBook(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubOrderBook, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onOrderBook(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onOrderBook, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubTickByTick(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubTickByTick, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubTickByTick(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubTickByTick, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onTickByTick(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onTickByTick, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubscribeAllMarketData(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubscribeAllMarketData, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubscribeAllMarketData(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubscribeAllMarketData, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubscribeAllOrderBook(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubscribeAllOrderBook, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubscribeAllOrderBook(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubscribeAllOrderBook, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubscribeAllTickByTick(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubscribeAllTickByTick, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubscribeAllTickByTick(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubscribeAllTickByTick, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryAllTickers(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onQueryAllTickers, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryTickersPriceInfo(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onQueryTickersPriceInfo, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubscribeAllOptionMarketData(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubscribeAllOptionMarketData, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubscribeAllOptionMarketData(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubscribeAllOptionMarketData, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubscribeAllOptionOrderBook(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubscribeAllOptionOrderBook, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubscribeAllOptionOrderBook(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubscribeAllOptionOrderBook, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onSubscribeAllOptionTickByTick(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onSubscribeAllOptionTickByTick, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onUnSubscribeAllOptionTickByTick(int exchange_id, const dict &error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onUnSubscribeAllOptionTickByTick, exchange_id, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onQueryAllTickersFullInfo(const dict &data, const dict &error, bool is_last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onQueryAllTickersFullInfo, data, error, is_last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

