void MdApi::OnDisconnected(int reason) 
{
	gil_scoped_acquire acquire;
	this->onDisconnected(reason);
};

void MdApi::OnError(XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onError(error);
};

void MdApi::OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker)
	{
		data["exchange_id"] = (int) ticker->exchange_id;
		data["ticker"] = ticker->ticker;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubMarketData(data, error, is_last);
};

void MdApi::OnUnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker)
	{
		data["exchange_id"] = (int) ticker->exchange_id;
		data["ticker"] = ticker->ticker;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubMarketData(data, error, is_last);
};

void MdApi::OnDepthMarketData(XTPMD *market_data, int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (market_data)
	{
		data["exchange_id"] = (int) market_data->exchange_id;
		data["ticker"] = market_data->ticker;
		data["last_price"] = market_data->last_price;
		data["pre_close_price"] = market_data->pre_close_price;
		data["open_price"] = market_data->open_price;
		data["high_price"] = market_data->high_price;
		data["low_price"] = market_data->low_price;
		data["close_price"] = market_data->close_price;
		data["pre_total_long_positon"] = market_data->pre_total_long_positon;
		data["total_long_positon"] = market_data->total_long_positon;
		data["pre_settl_price"] = market_data->pre_settl_price;
		data["settl_price"] = market_data->settl_price;
		data["upper_limit_price"] = market_data->upper_limit_price;
		data["lower_limit_price"] = market_data->lower_limit_price;
		data["pre_delta"] = market_data->pre_delta;
		data["curr_delta"] = market_data->curr_delta;
		data["data_time"] = market_data->data_time;
		data["qty"] = market_data->qty;
		data["turnover"] = market_data->turnover;
		data["avg_price"] = market_data->avg_price;
		data["bid"] = market_data->bid;
		data["ask"] = market_data->ask;
		data["bid_qty"] = market_data->bid_qty;
		data["ask_qty"] = market_data->ask_qty;
		data["trades_count"] = market_data->trades_count;
		data["ticker_status"] = market_data->ticker_status;
		data["stk"] = market_data->stk;
		data["opt"] = market_data->opt;
		data["data_type"] = market_data->data_type;
		data["r4"] = market_data->r4;
	}
	this->onDepthMarketData(data, bid1_qty, bid1_count, max_bid1_count, ask1_qty, ask1_count, max_ask1_count);
};

void MdApi::OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker)
	{
		data["exchange_id"] = (int) ticker->exchange_id;
		data["ticker"] = ticker->ticker;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubOrderBook(data, error, is_last);
};

void MdApi::OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker)
	{
		data["exchange_id"] = (int) ticker->exchange_id;
		data["ticker"] = ticker->ticker;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubOrderBook(data, error, is_last);
};

void MdApi::OnOrderBook(XTPOB *order_book) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (order_book)
	{
		data["exchange_id"] = (int) order_book->exchange_id;
		data["ticker"] = order_book->ticker;
		data["last_price"] = order_book->last_price;
		data["qty"] = order_book->qty;
		data["turnover"] = order_book->turnover;
		data["trades_count"] = order_book->trades_count;
		data["bid"] = order_book->bid;
		data["ask"] = order_book->ask;
		data["bid_qty"] = order_book->bid_qty;
		data["ask_qty"] = order_book->ask_qty;
		data["data_time"] = order_book->data_time;
	}
	this->onOrderBook(data);
};

void MdApi::OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker)
	{
		data["exchange_id"] = (int) ticker->exchange_id;
		data["ticker"] = ticker->ticker;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubTickByTick(data, error, is_last);
};

void MdApi::OnUnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker)
	{
		data["exchange_id"] = (int) ticker->exchange_id;
		data["ticker"] = ticker->ticker;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubTickByTick(data, error, is_last);
};

void MdApi::OnTickByTick(XTPTBT *tbt_data) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (tbt_data)
	{
		data["exchange_id"] = (int) tbt_data->exchange_id;
		data["ticker"] = tbt_data->ticker;
		data["seq"] = tbt_data->seq;
		data["data_time"] = tbt_data->data_time;
		data["type"] = (int) tbt_data->type;
		data["entrust"] = tbt_data->entrust;
		data["trade"] = tbt_data->trade;
	}
	this->onTickByTick(data);
};

void MdApi::OnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubscribeAllMarketData(exchange_id, error);
};

void MdApi::OnUnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubscribeAllMarketData(exchange_id, error);
};

void MdApi::OnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubscribeAllOrderBook(exchange_id, error);
};

void MdApi::OnUnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubscribeAllOrderBook(exchange_id, error);
};

void MdApi::OnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubscribeAllTickByTick(exchange_id, error);
};

void MdApi::OnUnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubscribeAllTickByTick(exchange_id, error);
};

void MdApi::OnQueryAllTickers(XTPQSI* ticker_info, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker_info)
	{
		data["exchange_id"] = (int) ticker_info->exchange_id;
		data["ticker"] = ticker_info->ticker;
		data["ticker_name"] = ticker_info->ticker_name;
		data["ticker_type"] = (int) ticker_info->ticker_type;
		data["pre_close_price"] = ticker_info->pre_close_price;
		data["upper_limit_price"] = ticker_info->upper_limit_price;
		data["lower_limit_price"] = ticker_info->lower_limit_price;
		data["price_tick"] = ticker_info->price_tick;
		data["buy_qty_unit"] = ticker_info->buy_qty_unit;
		data["sell_qty_unit"] = ticker_info->sell_qty_unit;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryAllTickers(data, error, is_last);
};

void MdApi::OnQueryTickersPriceInfo(XTPTPI* ticker_info, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker_info)
	{
		data["exchange_id"] = (int) ticker_info->exchange_id;
		data["ticker"] = ticker_info->ticker;
		data["last_price"] = ticker_info->last_price;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryTickersPriceInfo(data, error, is_last);
};

void MdApi::OnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubscribeAllOptionMarketData(exchange_id, error);
};

void MdApi::OnUnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubscribeAllOptionMarketData(exchange_id, error);
};

void MdApi::OnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubscribeAllOptionOrderBook(exchange_id, error);
};

void MdApi::OnUnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubscribeAllOptionOrderBook(exchange_id, error);
};

void MdApi::OnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onSubscribeAllOptionTickByTick(exchange_id, error);
};

void MdApi::OnUnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onUnSubscribeAllOptionTickByTick(exchange_id, error);
};

void MdApi::OnQueryAllTickersFullInfo(XTPQFI* ticker_info, XTPRI *error_info, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ticker_info)
	{
		data["exchange_id"] = (int) ticker_info->exchange_id;
		data["ticker"] = ticker_info->ticker;
		data["ticker_name"] = ticker_info->ticker_name;
		data["security_type"] = (int) ticker_info->security_type;
		data["ticker_qualification_class"] = (int) ticker_info->ticker_qualification_class;
		data["is_registration"] = ticker_info->is_registration;
		data["is_VIE"] = ticker_info->is_VIE;
		data["is_noprofit"] = ticker_info->is_noprofit;
		data["is_weighted_voting_rights"] = ticker_info->is_weighted_voting_rights;
		data["is_have_price_limit"] = ticker_info->is_have_price_limit;
		data["upper_limit_price"] = ticker_info->upper_limit_price;
		data["lower_limit_price"] = ticker_info->lower_limit_price;
		data["pre_close_price"] = ticker_info->pre_close_price;
		data["price_tick"] = ticker_info->price_tick;
		data["bid_qty_upper_limit"] = ticker_info->bid_qty_upper_limit;
		data["bid_qty_lower_limit"] = ticker_info->bid_qty_lower_limit;
		data["bid_qty_unit"] = ticker_info->bid_qty_unit;
		data["ask_qty_upper_limit"] = ticker_info->ask_qty_upper_limit;
		data["ask_qty_lower_limit"] = ticker_info->ask_qty_lower_limit;
		data["ask_qty_unit"] = ticker_info->ask_qty_unit;
		data["market_bid_qty_upper_limit"] = ticker_info->market_bid_qty_upper_limit;
		data["market_bid_qty_lower_limit"] = ticker_info->market_bid_qty_lower_limit;
		data["market_bid_qty_unit"] = ticker_info->market_bid_qty_unit;
		data["market_ask_qty_upper_limit"] = ticker_info->market_ask_qty_upper_limit;
		data["market_ask_qty_lower_limit"] = ticker_info->market_ask_qty_lower_limit;
		data["market_ask_qty_unit"] = ticker_info->market_ask_qty_unit;
		data["unknown"] = ticker_info->unknown;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryAllTickersFullInfo(data, error, is_last);
};

