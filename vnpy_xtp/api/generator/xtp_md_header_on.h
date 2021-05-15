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

virtual void onSubscribeAllMarketData(int exchange_id, const dict &error) {};

virtual void onUnSubscribeAllMarketData(int exchange_id, const dict &error) {};

virtual void onSubscribeAllOrderBook(int exchange_id, const dict &error) {};

virtual void onUnSubscribeAllOrderBook(int exchange_id, const dict &error) {};

virtual void onSubscribeAllTickByTick(int exchange_id, const dict &error) {};

virtual void onUnSubscribeAllTickByTick(int exchange_id, const dict &error) {};

virtual void onQueryAllTickers(const dict &data, const dict &error, bool is_last) {};

virtual void onQueryTickersPriceInfo(const dict &data, const dict &error, bool is_last) {};

virtual void onSubscribeAllOptionMarketData(int exchange_id, const dict &error) {};

virtual void onUnSubscribeAllOptionMarketData(int exchange_id, const dict &error) {};

virtual void onSubscribeAllOptionOrderBook(int exchange_id, const dict &error) {};

virtual void onUnSubscribeAllOptionOrderBook(int exchange_id, const dict &error) {};

virtual void onSubscribeAllOptionTickByTick(int exchange_id, const dict &error) {};

virtual void onUnSubscribeAllOptionTickByTick(int exchange_id, const dict &error) {};

virtual void onQueryAllTickersFullInfo(const dict &data, const dict &error, bool is_last) {};

