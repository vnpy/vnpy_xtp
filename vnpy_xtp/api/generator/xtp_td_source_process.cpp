void TdApi::processDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onDisconnected(task->task_extra, task->task_extra);
};

void TdApi::processError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onError(error);
};

void TdApi::processOrderEvent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPOrderInfo *task_data = (XTPOrderInfo*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["order_cancel_client_id"] = task_data->order_cancel_client_id;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["ticker"] = task_data->ticker;
		data["market"] = (int) task_data->market;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["price_type"] = (int) task_data->price_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int) task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int) task_data->order_status;
		data["order_submit_status"] = (int) task_data->order_submit_status;
		data["order_type"] = task_data->order_type;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onOrderEvent(data, error, task->task_extra);
};

void TdApi::processTradeEvent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPTradeReport *task_data = (XTPTradeReport*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["ticker"] = task_data->ticker;
		data["market"] = (int) task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int) task_data->business_type;
		data["branch_pbu"] = task_data->branch_pbu;
		delete task_data;
	}
	this->onTradeEvent(data, task->task_extra);
};

void TdApi::processCancelOrderError(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPOrderCancelInfo *task_data = (XTPOrderCancelInfo*)task->task_data;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["order_xtp_id"] = task_data->order_xtp_id;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onCancelOrderError(data, error, task->task_extra);
};

void TdApi::processQueryOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOrderRsp *task_data = (XTPQueryOrderRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["order_cancel_client_id"] = task_data->order_cancel_client_id;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["ticker"] = task_data->ticker;
		data["market"] = (int) task_data->market;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["price_type"] = (int) task_data->price_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int) task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int) task_data->order_status;
		data["order_submit_status"] = (int) task_data->order_submit_status;
		data["order_type"] = task_data->order_type;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryOrder(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOrderByPage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOrderRsp *task_data = (XTPQueryOrderRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["order_cancel_client_id"] = task_data->order_cancel_client_id;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["ticker"] = task_data->ticker;
		data["market"] = (int) task_data->market;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["price_type"] = (int) task_data->price_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int) task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int) task_data->order_status;
		data["order_submit_status"] = (int) task_data->order_submit_status;
		data["order_type"] = task_data->order_type;
		delete task_data;
	}
	this->onQueryOrderByPage(data, task->task_extra, task->task_extra, task->task_extra, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryTradeRsp *task_data = (XTPQueryTradeRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["ticker"] = task_data->ticker;
		data["market"] = (int) task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int) task_data->business_type;
		data["branch_pbu"] = task_data->branch_pbu;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryTrade(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryTradeByPage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryTradeRsp *task_data = (XTPQueryTradeRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["ticker"] = task_data->ticker;
		data["market"] = (int) task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int) task_data->business_type;
		data["branch_pbu"] = task_data->branch_pbu;
		delete task_data;
	}
	this->onQueryTradeByPage(data, task->task_extra, task->task_extra, task->task_extra, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryStkPositionRsp *task_data = (XTPQueryStkPositionRsp*)task->task_data;
		data["ticker"] = task_data->ticker;
		data["ticker_name"] = task_data->ticker_name;
		data["market"] = (int) task_data->market;
		data["total_qty"] = task_data->total_qty;
		data["sellable_qty"] = task_data->sellable_qty;
		data["avg_price"] = task_data->avg_price;
		data["unrealized_pnl"] = task_data->unrealized_pnl;
		data["yesterday_position"] = task_data->yesterday_position;
		data["purchase_redeemable_qty"] = task_data->purchase_redeemable_qty;
		data["position_direction"] = (int) task_data->position_direction;
		data["reserved1"] = task_data->reserved1;
		data["executable_option"] = task_data->executable_option;
		data["lockable_position"] = task_data->lockable_position;
		data["executable_underlying"] = task_data->executable_underlying;
		data["locked_position"] = task_data->locked_position;
		data["usable_locked_position"] = task_data->usable_locked_position;
		data["profit_price"] = task_data->profit_price;
		data["buy_cost"] = task_data->buy_cost;
		data["profit_cost"] = task_data->profit_cost;
		data["unknown"] = task_data->unknown;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryPosition(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryAsset(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryAssetRsp *task_data = (XTPQueryAssetRsp*)task->task_data;
		data["total_asset"] = task_data->total_asset;
		data["buying_power"] = task_data->buying_power;
		data["security_asset"] = task_data->security_asset;
		data["fund_buy_amount"] = task_data->fund_buy_amount;
		data["fund_buy_fee"] = task_data->fund_buy_fee;
		data["fund_sell_amount"] = task_data->fund_sell_amount;
		data["fund_sell_fee"] = task_data->fund_sell_fee;
		data["withholding_amount"] = task_data->withholding_amount;
		data["account_type"] = (int) task_data->account_type;
		data["frozen_margin"] = task_data->frozen_margin;
		data["frozen_exec_cash"] = task_data->frozen_exec_cash;
		data["frozen_exec_fee"] = task_data->frozen_exec_fee;
		data["pay_later"] = task_data->pay_later;
		data["preadva_pay"] = task_data->preadva_pay;
		data["orig_banlance"] = task_data->orig_banlance;
		data["banlance"] = task_data->banlance;
		data["deposit_withdraw"] = task_data->deposit_withdraw;
		data["trade_netting"] = task_data->trade_netting;
		data["captial_asset"] = task_data->captial_asset;
		data["force_freeze_amount"] = task_data->force_freeze_amount;
		data["preferred_amount"] = task_data->preferred_amount;
		data["repay_stock_aval_banlance"] = task_data->repay_stock_aval_banlance;
		data["fund_order_data_charges"] = task_data->fund_order_data_charges;
		data["fund_cancel_data_charges"] = task_data->fund_cancel_data_charges;
		data["unknown"] = task_data->unknown;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryAsset(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryStructuredFund(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPStructuredFundInfo *task_data = (XTPStructuredFundInfo*)task->task_data;
		data["exchange_id"] = (int) task_data->exchange_id;
		data["sf_ticker"] = task_data->sf_ticker;
		data["sf_ticker_name"] = task_data->sf_ticker_name;
		data["ticker"] = task_data->ticker;
		data["ticker_name"] = task_data->ticker_name;
		data["split_merge_status"] = (int) task_data->split_merge_status;
		data["ratio"] = task_data->ratio;
		data["min_split_qty"] = task_data->min_split_qty;
		data["min_merge_qty"] = task_data->min_merge_qty;
		data["net_price"] = task_data->net_price;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryStructuredFund(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryFundTransfer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPFundTransferNotice *task_data = (XTPFundTransferNotice*)task->task_data;
		data["serial_id"] = task_data->serial_id;
		data["transfer_type"] = (int) task_data->transfer_type;
		data["amount"] = task_data->amount;
		data["oper_status"] = (int) task_data->oper_status;
		data["transfer_time"] = task_data->transfer_time;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryFundTransfer(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processFundTransfer(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPFundTransferNotice *task_data = (XTPFundTransferNotice*)task->task_data;
		data["serial_id"] = task_data->serial_id;
		data["transfer_type"] = (int) task_data->transfer_type;
		data["amount"] = task_data->amount;
		data["oper_status"] = (int) task_data->oper_status;
		data["transfer_time"] = task_data->transfer_time;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onFundTransfer(data, error, task->task_extra);
};

void TdApi::processQueryETF(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryETFBaseRsp *task_data = (XTPQueryETFBaseRsp*)task->task_data;
		data["market"] = (int) task_data->market;
		data["etf"] = task_data->etf;
		data["subscribe_redemption_ticker"] = task_data->subscribe_redemption_ticker;
		data["unit"] = task_data->unit;
		data["subscribe_status"] = task_data->subscribe_status;
		data["redemption_status"] = task_data->redemption_status;
		data["max_cash_ratio"] = task_data->max_cash_ratio;
		data["estimate_amount"] = task_data->estimate_amount;
		data["cash_component"] = task_data->cash_component;
		data["net_value"] = task_data->net_value;
		data["total_amount"] = task_data->total_amount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryETF(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryETFBasket(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryETFComponentRsp *task_data = (XTPQueryETFComponentRsp*)task->task_data;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["component_ticker"] = task_data->component_ticker;
		data["component_name"] = task_data->component_name;
		data["quantity"] = task_data->quantity;
		data["component_market"] = (int) task_data->component_market;
		data["replace_type"] = (int) task_data->replace_type;
		data["premium_ratio"] = task_data->premium_ratio;
		data["amount"] = task_data->amount;
		data["creation_premium_ratio"] = task_data->creation_premium_ratio;
		data["redemption_discount_ratio"] = task_data->redemption_discount_ratio;
		data["creation_amount"] = task_data->creation_amount;
		data["redemption_amount"] = task_data->redemption_amount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryETFBasket(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryIPOInfoList(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryIPOTickerRsp *task_data = (XTPQueryIPOTickerRsp*)task->task_data;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["ticker_name"] = task_data->ticker_name;
		data["ticker_type"] = (int) task_data->ticker_type;
		data["price"] = task_data->price;
		data["unit"] = task_data->unit;
		data["qty_upper_limit"] = task_data->qty_upper_limit;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryIPOInfoList(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryIPOQuotaInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryIPOQuotaRsp *task_data = (XTPQueryIPOQuotaRsp*)task->task_data;
		data["market"] = (int) task_data->market;
		data["quantity"] = task_data->quantity;
		data["tech_quantity"] = task_data->tech_quantity;
		data["unused"] = task_data->unused;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryIPOQuotaInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOptionAuctionInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOptionAuctionInfoRsp *task_data = (XTPQueryOptionAuctionInfoRsp*)task->task_data;
		data["ticker"] = task_data->ticker;
		data["security_id_source"] = (int) task_data->security_id_source;
		data["symbol"] = task_data->symbol;
		data["contract_id"] = task_data->contract_id;
		data["underlying_security_id"] = task_data->underlying_security_id;
		data["underlying_security_id_source"] = (int) task_data->underlying_security_id_source;
		data["list_date"] = task_data->list_date;
		data["last_trade_date"] = task_data->last_trade_date;
		data["ticker_type"] = (int) task_data->ticker_type;
		data["day_trading"] = task_data->day_trading;
		data["call_or_put"] = (int) task_data->call_or_put;
		data["delivery_day"] = task_data->delivery_day;
		data["delivery_month"] = task_data->delivery_month;
		data["exercise_type"] = (int) task_data->exercise_type;
		data["exercise_begin_date"] = task_data->exercise_begin_date;
		data["exercise_end_date"] = task_data->exercise_end_date;
		data["exercise_price"] = task_data->exercise_price;
		data["qty_unit"] = task_data->qty_unit;
		data["contract_unit"] = task_data->contract_unit;
		data["contract_position"] = task_data->contract_position;
		data["prev_close_price"] = task_data->prev_close_price;
		data["prev_clearing_price"] = task_data->prev_clearing_price;
		data["lmt_buy_max_qty"] = task_data->lmt_buy_max_qty;
		data["lmt_buy_min_qty"] = task_data->lmt_buy_min_qty;
		data["lmt_sell_max_qty"] = task_data->lmt_sell_max_qty;
		data["lmt_sell_min_qty"] = task_data->lmt_sell_min_qty;
		data["mkt_buy_max_qty"] = task_data->mkt_buy_max_qty;
		data["mkt_buy_min_qty"] = task_data->mkt_buy_min_qty;
		data["mkt_sell_max_qty"] = task_data->mkt_sell_max_qty;
		data["mkt_sell_min_qty"] = task_data->mkt_sell_min_qty;
		data["price_tick"] = task_data->price_tick;
		data["upper_limit_price"] = task_data->upper_limit_price;
		data["lower_limit_price"] = task_data->lower_limit_price;
		data["sell_margin"] = task_data->sell_margin;
		data["margin_ratio_param1"] = task_data->margin_ratio_param1;
		data["margin_ratio_param2"] = task_data->margin_ratio_param2;
		data["unknown"] = task_data->unknown;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryOptionAuctionInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processCreditCashRepay(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdCashRepayRsp *task_data = (XTPCrdCashRepayRsp*)task->task_data;
		data["xtp_id"] = task_data->xtp_id;
		data["request_amount"] = task_data->request_amount;
		data["cash_repay_amount"] = task_data->cash_repay_amount;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onCreditCashRepay(data, error, task->task_extra);
};

void TdApi::processCreditCashRepayDebtInterestFee(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdCashRepayDebtInterestFeeRsp *task_data = (XTPCrdCashRepayDebtInterestFeeRsp*)task->task_data;
		data["xtp_id"] = task_data->xtp_id;
		data["request_amount"] = task_data->request_amount;
		data["cash_repay_amount"] = task_data->cash_repay_amount;
		data["debt_compact_id"] = task_data->debt_compact_id;
		data["unknow"] = task_data->unknow;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onCreditCashRepayDebtInterestFee(data, error, task->task_extra);
};

void TdApi::processQueryCreditCashRepayInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdCashRepayInfo *task_data = (XTPCrdCashRepayInfo*)task->task_data;
		data["xtp_id"] = task_data->xtp_id;
		data["status"] = (int) task_data->status;
		data["request_amount"] = task_data->request_amount;
		data["cash_repay_amount"] = task_data->cash_repay_amount;
		data["position_effect"] = task_data->position_effect;
		data["error_info"] = (int) task_data->error_info;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditCashRepayInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryCreditFundInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdFundInfo *task_data = (XTPCrdFundInfo*)task->task_data;
		data["maintenance_ratio"] = task_data->maintenance_ratio;
		data["all_asset"] = task_data->all_asset;
		data["all_debt"] = task_data->all_debt;
		data["line_of_credit"] = task_data->line_of_credit;
		data["guaranty"] = task_data->guaranty;
		data["reserved"] = task_data->reserved;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditFundInfo(data, error, task->task_id, task->task_extra);
};

void TdApi::processQueryCreditDebtInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdDebtInfo *task_data = (XTPCrdDebtInfo*)task->task_data;
		data["debt_type"] = task_data->debt_type;
		data["debt_id"] = task_data->debt_id;
		data["position_id"] = task_data->position_id;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["debt_status"] = task_data->debt_status;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["order_date"] = task_data->order_date;
		data["end_date"] = task_data->end_date;
		data["orig_end_date"] = task_data->orig_end_date;
		data["is_extended"] = task_data->is_extended;
		data["remain_amt"] = task_data->remain_amt;
		data["remain_qty"] = task_data->remain_qty;
		data["remain_principal"] = task_data->remain_principal;
		data["due_right_qty"] = task_data->due_right_qty;
		data["unknown"] = task_data->unknown;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditDebtInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryCreditTickerDebtInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdDebtStockInfo *task_data = (XTPCrdDebtStockInfo*)task->task_data;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["stock_repay_quantity"] = task_data->stock_repay_quantity;
		data["stock_total_quantity"] = task_data->stock_total_quantity;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditTickerDebtInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryCreditAssetDebtInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditAssetDebtInfo(task->task_extra, error, task->task_id, task->task_extra);
};

void TdApi::processQueryCreditTickerAssignInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPClientQueryCrdPositionStkInfo *task_data = (XTPClientQueryCrdPositionStkInfo*)task->task_data;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["limit_qty"] = task_data->limit_qty;
		data["yesterday_qty"] = task_data->yesterday_qty;
		data["left_qty"] = task_data->left_qty;
		data["frozen_qty"] = task_data->frozen_qty;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditTickerAssignInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryCreditExcessStock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPClientQueryCrdSurplusStkRspInfo *task_data = (XTPClientQueryCrdSurplusStkRspInfo*)task->task_data;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["transferable_quantity"] = task_data->transferable_quantity;
		data["transferred_quantity"] = task_data->transferred_quantity;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditExcessStock(data, error, task->task_id, task->task_extra);
};

void TdApi::processQueryMulCreditExcessStock(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPClientQueryCrdSurplusStkRspInfo *task_data = (XTPClientQueryCrdSurplusStkRspInfo*)task->task_data;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["transferable_quantity"] = task_data->transferable_quantity;
		data["transferred_quantity"] = task_data->transferred_quantity;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryMulCreditExcessStock(data, error, task->task_id, task->task_extra, task->task_last);
};

void TdApi::processCreditExtendDebtDate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCreditDebtExtendNotice *task_data = (XTPCreditDebtExtendNotice*)task->task_data;
		data["xtpid"] = task_data->xtpid;
		data["debt_id"] = task_data->debt_id;
		data["oper_status"] = (int) task_data->oper_status;
		data["oper_time"] = task_data->oper_time;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onCreditExtendDebtDate(data, error, task->task_extra);
};

void TdApi::processQueryCreditExtendDebtDateOrders(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCreditDebtExtendNotice *task_data = (XTPCreditDebtExtendNotice*)task->task_data;
		data["xtpid"] = task_data->xtpid;
		data["debt_id"] = task_data->debt_id;
		data["oper_status"] = (int) task_data->oper_status;
		data["oper_time"] = task_data->oper_time;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditExtendDebtDateOrders(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryCreditFundExtraInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdFundExtraInfo *task_data = (XTPCrdFundExtraInfo*)task->task_data;
		data["mf_rs_avl_used"] = task_data->mf_rs_avl_used;
		data["reserve"] = task_data->reserve;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditFundExtraInfo(data, error, task->task_id, task->task_extra);
};

void TdApi::processQueryCreditPositionExtraInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPCrdPositionExtraInfo *task_data = (XTPCrdPositionExtraInfo*)task->task_data;
		data["market"] = (int) task_data->market;
		data["ticker"] = task_data->ticker;
		data["mf_rs_avl_used"] = task_data->mf_rs_avl_used;
		data["reserve"] = task_data->reserve;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryCreditPositionExtraInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processOptionCombinedOrderEvent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPOptCombOrderInfo *task_data = (XTPOptCombOrderInfo*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["order_cancel_client_id"] = task_data->order_cancel_client_id;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["market"] = (int) task_data->market;
		data["quantity"] = task_data->quantity;
		data["side"] = task_data->side;
		data["business_type"] = (int) task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int) task_data->order_status;
		data["order_submit_status"] = (int) task_data->order_submit_status;
		data["order_type"] = task_data->order_type;
		data["opt_comb_info"] = task_data->opt_comb_info;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onOptionCombinedOrderEvent(data, error, task->task_extra);
};

void TdApi::processOptionCombinedTradeEvent(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPOptCombTradeReport *task_data = (XTPOptCombTradeReport*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["market"] = (int) task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["business_type"] = (int) task_data->business_type;
		data["branch_pbu"] = task_data->branch_pbu;
		data["opt_comb_info"] = task_data->opt_comb_info;
		delete task_data;
	}
	this->onOptionCombinedTradeEvent(data, task->task_extra);
};

void TdApi::processCancelOptionCombinedOrderError(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPOptCombOrderCancelInfo *task_data = (XTPOptCombOrderCancelInfo*)task->task_data;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["order_xtp_id"] = task_data->order_xtp_id;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onCancelOptionCombinedOrderError(data, error, task->task_extra);
};

void TdApi::processQueryOptionCombinedOrders(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOptCombOrderRsp *task_data = (XTPQueryOptCombOrderRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["order_cancel_client_id"] = task_data->order_cancel_client_id;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["market"] = (int) task_data->market;
		data["quantity"] = task_data->quantity;
		data["side"] = task_data->side;
		data["business_type"] = (int) task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int) task_data->order_status;
		data["order_submit_status"] = (int) task_data->order_submit_status;
		data["order_type"] = task_data->order_type;
		data["opt_comb_info"] = task_data->opt_comb_info;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryOptionCombinedOrders(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOptionCombinedOrdersByPage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOptCombOrderRsp *task_data = (XTPQueryOptCombOrderRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["order_cancel_client_id"] = task_data->order_cancel_client_id;
		data["order_cancel_xtp_id"] = task_data->order_cancel_xtp_id;
		data["market"] = (int) task_data->market;
		data["quantity"] = task_data->quantity;
		data["side"] = task_data->side;
		data["business_type"] = (int) task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int) task_data->order_status;
		data["order_submit_status"] = (int) task_data->order_submit_status;
		data["order_type"] = task_data->order_type;
		data["opt_comb_info"] = task_data->opt_comb_info;
		delete task_data;
	}
	this->onQueryOptionCombinedOrdersByPage(data, task->task_extra, task->task_extra, task->task_extra, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOptionCombinedTrades(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOptCombTradeRsp *task_data = (XTPQueryOptCombTradeRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["market"] = (int) task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["business_type"] = (int) task_data->business_type;
		data["branch_pbu"] = task_data->branch_pbu;
		data["opt_comb_info"] = task_data->opt_comb_info;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryOptionCombinedTrades(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOptionCombinedTradesByPage(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOptCombTradeRsp *task_data = (XTPQueryOptCombTradeRsp*)task->task_data;
		data["order_xtp_id"] = task_data->order_xtp_id;
		data["order_client_id"] = task_data->order_client_id;
		data["market"] = (int) task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["business_type"] = (int) task_data->business_type;
		data["branch_pbu"] = task_data->branch_pbu;
		data["opt_comb_info"] = task_data->opt_comb_info;
		delete task_data;
	}
	this->onQueryOptionCombinedTradesByPage(data, task->task_extra, task->task_extra, task->task_extra, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOptionCombinedPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOptCombPositionRsp *task_data = (XTPQueryOptCombPositionRsp*)task->task_data;
		data["strategy_id"] = task_data->strategy_id;
		data["strategy_name"] = task_data->strategy_name;
		data["market"] = (int) task_data->market;
		data["total_qty"] = task_data->total_qty;
		data["available_qty"] = task_data->available_qty;
		data["yesterday_position"] = task_data->yesterday_position;
		data["reserved"] = task_data->reserved;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryOptionCombinedPosition(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOptionCombinedStrategyInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryCombineStrategyInfoRsp *task_data = (XTPQueryCombineStrategyInfoRsp*)task->task_data;
		data["strategy_id"] = task_data->strategy_id;
		data["strategy_name"] = task_data->strategy_name;
		data["market"] = (int) task_data->market;
		data["leg_num"] = task_data->leg_num;
		data["expire_date_type"] = (int) task_data->expire_date_type;
		data["underlying_type"] = (int) task_data->underlying_type;
		data["auto_sep_type"] = (int) task_data->auto_sep_type;
		data["reserved"] = task_data->reserved;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryOptionCombinedStrategyInfo(data, error, task->task_id, task->task_last, task->task_extra);
};

void TdApi::processQueryOptionCombinedExecPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPQueryOptCombExecPosRsp *task_data = (XTPQueryOptCombExecPosRsp*)task->task_data;
		data["market"] = (int) task_data->market;
		data["cntrt_code_1"] = task_data->cntrt_code_1;
		data["cntrt_name_1"] = task_data->cntrt_name_1;
		data["position_side_1"] = (int) task_data->position_side_1;
		data["call_or_put_1"] = (int) task_data->call_or_put_1;
		data["avl_qty_1"] = task_data->avl_qty_1;
		data["orig_own_qty_1"] = task_data->orig_own_qty_1;
		data["own_qty_1"] = task_data->own_qty_1;
		data["cntrt_code_2"] = task_data->cntrt_code_2;
		data["cntrt_name_2"] = task_data->cntrt_name_2;
		data["position_side_2"] = (int) task_data->position_side_2;
		data["call_or_put_2"] = (int) task_data->call_or_put_2;
		data["avl_qty_2"] = task_data->avl_qty_2;
		data["orig_own_qty_2"] = task_data->orig_own_qty_2;
		data["own_qty_2"] = task_data->own_qty_2;
		data["net_qty"] = task_data->net_qty;
		data["order_qty"] = task_data->order_qty;
		data["confirm_qty"] = task_data->confirm_qty;
		data["avl_qty"] = task_data->avl_qty;
		data["reserved"] = task_data->reserved;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		XTPRI *task_error = (XTPRI*)task->task_error;
		error["error_id"] = task_error->error_id;
		error["error_msg"] = task_error->error_msg;
		delete task_error;
	}
	this->onQueryOptionCombinedExecPosition(data, error, task->task_id, task->task_last, task->task_extra);
};

