virtual void onDisconnected(int reason) {};

virtual void onError(const dict &error) {};

virtual void onSubMarketData(const dict &data, const dict &error, bool is_last) {};

virtual void onUnSubMarketData(const dict &data, const dict &error, bool is_last) {};

virtual void onDepthMarketData(const dict &data, int64_t bid1_qty, int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty, int32_t ask1_count, int32_t max_ask1_count) {};

virtual void onSubOrderBook(const dict &data, const dict &error, bool is_last) {};

virtual void onUnSubOrderBook(const dict &data, const dict &error, bool is_last) {};

virtual void onOrderBook(const dict &data) {};

virtual void onSubTickByTick(const dict &data, const dict &error, bool is_last) {};

virtual void onUnSubTickByTick(const dict &data, const dict &error, bool is_last) {};

virtual void onTickByTick(const dict &data) {};

virtual void onSubscribeAllMarketData(const dict &error) {};

virtual void onUnSubscribeAllMarketData(const dict &error) {};

virtual void onSubscribeAllOrderBook(const dict &error) {};

virtual void onUnSubscribeAllOrderBook(const dict &error) {};

virtual void onSubscribeAllTickByTick(const dict &error) {};

virtual void onUnSubscribeAllTickByTick(const dict &error) {};

virtual void onQueryAllTickers(const dict &data, const dict &error, bool is_last) {};

virtual void onQueryTickersPriceInfo(const dict &data, const dict &error, bool is_last) {};

virtual void onSubscribeAllOptionMarketData(const dict &error) {};

virtual void onUnSubscribeAllOptionMarketData(const dict &error) {};

virtual void onSubscribeAllOptionOrderBook(const dict &error) {};

virtual void onUnSubscribeAllOptionOrderBook(const dict &error) {};

virtual void onSubscribeAllOptionTickByTick(const dict &error) {};

virtual void onUnSubscribeAllOptionTickByTick(const dict &error) {};

virtual void onQueryAllTickersFullInfo(const dict &data, const dict &error, bool is_last) {};

