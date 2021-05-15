void TdApi::OnDisconnected(uint64_t session_id, int reason) 
{
	gil_scoped_acquire acquire;
	this->onDisconnected(session_id, reason);
};

void TdApi::OnError(XTPRI *error_info) 
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

void TdApi::OnOrderEvent(XTPOrderInfo *order_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (order_info)
	{
		data["order_xtp_id"] = order_info->order_xtp_id;
		data["order_client_id"] = order_info->order_client_id;
		data["order_cancel_client_id"] = order_info->order_cancel_client_id;
		data["order_cancel_xtp_id"] = order_info->order_cancel_xtp_id;
		data["ticker"] = order_info->ticker;
		data["market"] = (int) order_info->market;
		data["price"] = order_info->price;
		data["quantity"] = order_info->quantity;
		data["price_type"] = (int) order_info->price_type;
		data["u32"] = order_info->u32;
		data["side"] = order_info->side;
		data["position_effect"] = order_info->position_effect;
		data["reserved1"] = order_info->reserved1;
		data["reserved2"] = order_info->reserved2;
		data["business_type"] = (int) order_info->business_type;
		data["qty_traded"] = order_info->qty_traded;
		data["qty_left"] = order_info->qty_left;
		data["insert_time"] = order_info->insert_time;
		data["update_time"] = order_info->update_time;
		data["cancel_time"] = order_info->cancel_time;
		data["trade_amount"] = order_info->trade_amount;
		data["order_local_id"] = order_info->order_local_id;
		data["order_status"] = (int) order_info->order_status;
		data["order_submit_status"] = (int) order_info->order_submit_status;
		data["order_type"] = order_info->order_type;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onOrderEvent(data, error, session_id);
};

void TdApi::OnTradeEvent(XTPTradeReport *trade_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (trade_info)
	{
		data["order_xtp_id"] = trade_info->order_xtp_id;
		data["order_client_id"] = trade_info->order_client_id;
		data["ticker"] = trade_info->ticker;
		data["market"] = (int) trade_info->market;
		data["local_order_id"] = trade_info->local_order_id;
		data["exec_id"] = trade_info->exec_id;
		data["price"] = trade_info->price;
		data["quantity"] = trade_info->quantity;
		data["trade_time"] = trade_info->trade_time;
		data["trade_amount"] = trade_info->trade_amount;
		data["report_index"] = trade_info->report_index;
		data["order_exch_id"] = trade_info->order_exch_id;
		data["trade_type"] = trade_info->trade_type;
		data["u32"] = trade_info->u32;
		data["side"] = trade_info->side;
		data["position_effect"] = trade_info->position_effect;
		data["reserved1"] = trade_info->reserved1;
		data["reserved2"] = trade_info->reserved2;
		data["business_type"] = (int) trade_info->business_type;
		data["branch_pbu"] = trade_info->branch_pbu;
	}
	this->onTradeEvent(data, session_id);
};

void TdApi::OnCancelOrderError(XTPOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (cancel_info)
	{
		data["order_cancel_xtp_id"] = cancel_info->order_cancel_xtp_id;
		data["order_xtp_id"] = cancel_info->order_xtp_id;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onCancelOrderError(data, error, session_id);
};

void TdApi::OnQueryOrder(XTPQueryOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (order_info)
	{
		data["order_xtp_id"] = order_info->order_xtp_id;
		data["order_client_id"] = order_info->order_client_id;
		data["order_cancel_client_id"] = order_info->order_cancel_client_id;
		data["order_cancel_xtp_id"] = order_info->order_cancel_xtp_id;
		data["ticker"] = order_info->ticker;
		data["market"] = (int) order_info->market;
		data["price"] = order_info->price;
		data["quantity"] = order_info->quantity;
		data["price_type"] = (int) order_info->price_type;
		data["u32"] = order_info->u32;
		data["side"] = order_info->side;
		data["position_effect"] = order_info->position_effect;
		data["reserved1"] = order_info->reserved1;
		data["reserved2"] = order_info->reserved2;
		data["business_type"] = (int) order_info->business_type;
		data["qty_traded"] = order_info->qty_traded;
		data["qty_left"] = order_info->qty_left;
		data["insert_time"] = order_info->insert_time;
		data["update_time"] = order_info->update_time;
		data["cancel_time"] = order_info->cancel_time;
		data["trade_amount"] = order_info->trade_amount;
		data["order_local_id"] = order_info->order_local_id;
		data["order_status"] = (int) order_info->order_status;
		data["order_submit_status"] = (int) order_info->order_submit_status;
		data["order_type"] = order_info->order_type;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryOrder(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryOrderByPage(XTPQueryOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (order_info)
	{
		data["order_xtp_id"] = order_info->order_xtp_id;
		data["order_client_id"] = order_info->order_client_id;
		data["order_cancel_client_id"] = order_info->order_cancel_client_id;
		data["order_cancel_xtp_id"] = order_info->order_cancel_xtp_id;
		data["ticker"] = order_info->ticker;
		data["market"] = (int) order_info->market;
		data["price"] = order_info->price;
		data["quantity"] = order_info->quantity;
		data["price_type"] = (int) order_info->price_type;
		data["u32"] = order_info->u32;
		data["side"] = order_info->side;
		data["position_effect"] = order_info->position_effect;
		data["reserved1"] = order_info->reserved1;
		data["reserved2"] = order_info->reserved2;
		data["business_type"] = (int) order_info->business_type;
		data["qty_traded"] = order_info->qty_traded;
		data["qty_left"] = order_info->qty_left;
		data["insert_time"] = order_info->insert_time;
		data["update_time"] = order_info->update_time;
		data["cancel_time"] = order_info->cancel_time;
		data["trade_amount"] = order_info->trade_amount;
		data["order_local_id"] = order_info->order_local_id;
		data["order_status"] = (int) order_info->order_status;
		data["order_submit_status"] = (int) order_info->order_submit_status;
		data["order_type"] = order_info->order_type;
	}
	this->onQueryOrderByPage(data, req_count, order_sequence, query_reference, request_id, is_last, session_id);
};

void TdApi::OnQueryTrade(XTPQueryTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (trade_info)
	{
		data["order_xtp_id"] = trade_info->order_xtp_id;
		data["order_client_id"] = trade_info->order_client_id;
		data["ticker"] = trade_info->ticker;
		data["market"] = (int) trade_info->market;
		data["local_order_id"] = trade_info->local_order_id;
		data["exec_id"] = trade_info->exec_id;
		data["price"] = trade_info->price;
		data["quantity"] = trade_info->quantity;
		data["trade_time"] = trade_info->trade_time;
		data["trade_amount"] = trade_info->trade_amount;
		data["report_index"] = trade_info->report_index;
		data["order_exch_id"] = trade_info->order_exch_id;
		data["trade_type"] = trade_info->trade_type;
		data["u32"] = trade_info->u32;
		data["side"] = trade_info->side;
		data["position_effect"] = trade_info->position_effect;
		data["reserved1"] = trade_info->reserved1;
		data["reserved2"] = trade_info->reserved2;
		data["business_type"] = (int) trade_info->business_type;
		data["branch_pbu"] = trade_info->branch_pbu;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryTrade(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryTradeByPage(XTPQueryTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (trade_info)
	{
		data["order_xtp_id"] = trade_info->order_xtp_id;
		data["order_client_id"] = trade_info->order_client_id;
		data["ticker"] = trade_info->ticker;
		data["market"] = (int) trade_info->market;
		data["local_order_id"] = trade_info->local_order_id;
		data["exec_id"] = trade_info->exec_id;
		data["price"] = trade_info->price;
		data["quantity"] = trade_info->quantity;
		data["trade_time"] = trade_info->trade_time;
		data["trade_amount"] = trade_info->trade_amount;
		data["report_index"] = trade_info->report_index;
		data["order_exch_id"] = trade_info->order_exch_id;
		data["trade_type"] = trade_info->trade_type;
		data["u32"] = trade_info->u32;
		data["side"] = trade_info->side;
		data["position_effect"] = trade_info->position_effect;
		data["reserved1"] = trade_info->reserved1;
		data["reserved2"] = trade_info->reserved2;
		data["business_type"] = (int) trade_info->business_type;
		data["branch_pbu"] = trade_info->branch_pbu;
	}
	this->onQueryTradeByPage(data, req_count, trade_sequence, query_reference, request_id, is_last, session_id);
};

void TdApi::OnQueryPosition(XTPQueryStkPositionRsp *position, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (position)
	{
		data["ticker"] = position->ticker;
		data["ticker_name"] = position->ticker_name;
		data["market"] = (int) position->market;
		data["total_qty"] = position->total_qty;
		data["sellable_qty"] = position->sellable_qty;
		data["avg_price"] = position->avg_price;
		data["unrealized_pnl"] = position->unrealized_pnl;
		data["yesterday_position"] = position->yesterday_position;
		data["purchase_redeemable_qty"] = position->purchase_redeemable_qty;
		data["position_direction"] = (int) position->position_direction;
		data["reserved1"] = position->reserved1;
		data["executable_option"] = position->executable_option;
		data["lockable_position"] = position->lockable_position;
		data["executable_underlying"] = position->executable_underlying;
		data["locked_position"] = position->locked_position;
		data["usable_locked_position"] = position->usable_locked_position;
		data["profit_price"] = position->profit_price;
		data["buy_cost"] = position->buy_cost;
		data["profit_cost"] = position->profit_cost;
		data["unknown"] = position->unknown;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryPosition(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryAsset(XTPQueryAssetRsp *asset, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (asset)
	{
		data["total_asset"] = asset->total_asset;
		data["buying_power"] = asset->buying_power;
		data["security_asset"] = asset->security_asset;
		data["fund_buy_amount"] = asset->fund_buy_amount;
		data["fund_buy_fee"] = asset->fund_buy_fee;
		data["fund_sell_amount"] = asset->fund_sell_amount;
		data["fund_sell_fee"] = asset->fund_sell_fee;
		data["withholding_amount"] = asset->withholding_amount;
		data["account_type"] = (int) asset->account_type;
		data["frozen_margin"] = asset->frozen_margin;
		data["frozen_exec_cash"] = asset->frozen_exec_cash;
		data["frozen_exec_fee"] = asset->frozen_exec_fee;
		data["pay_later"] = asset->pay_later;
		data["preadva_pay"] = asset->preadva_pay;
		data["orig_banlance"] = asset->orig_banlance;
		data["banlance"] = asset->banlance;
		data["deposit_withdraw"] = asset->deposit_withdraw;
		data["trade_netting"] = asset->trade_netting;
		data["captial_asset"] = asset->captial_asset;
		data["force_freeze_amount"] = asset->force_freeze_amount;
		data["preferred_amount"] = asset->preferred_amount;
		data["repay_stock_aval_banlance"] = asset->repay_stock_aval_banlance;
		data["fund_order_data_charges"] = asset->fund_order_data_charges;
		data["fund_cancel_data_charges"] = asset->fund_cancel_data_charges;
		data["unknown"] = asset->unknown;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryAsset(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryStructuredFund(XTPStructuredFundInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (fund_info)
	{
		data["exchange_id"] = (int) fund_info->exchange_id;
		data["sf_ticker"] = fund_info->sf_ticker;
		data["sf_ticker_name"] = fund_info->sf_ticker_name;
		data["ticker"] = fund_info->ticker;
		data["ticker_name"] = fund_info->ticker_name;
		data["split_merge_status"] = (int) fund_info->split_merge_status;
		data["ratio"] = fund_info->ratio;
		data["min_split_qty"] = fund_info->min_split_qty;
		data["min_merge_qty"] = fund_info->min_merge_qty;
		data["net_price"] = fund_info->net_price;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryStructuredFund(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (fund_transfer_info)
	{
		data["serial_id"] = fund_transfer_info->serial_id;
		data["transfer_type"] = (int) fund_transfer_info->transfer_type;
		data["amount"] = fund_transfer_info->amount;
		data["oper_status"] = (int) fund_transfer_info->oper_status;
		data["transfer_time"] = fund_transfer_info->transfer_time;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryFundTransfer(data, error, request_id, is_last, session_id);
};

void TdApi::OnFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (fund_transfer_info)
	{
		data["serial_id"] = fund_transfer_info->serial_id;
		data["transfer_type"] = (int) fund_transfer_info->transfer_type;
		data["amount"] = fund_transfer_info->amount;
		data["oper_status"] = (int) fund_transfer_info->oper_status;
		data["transfer_time"] = fund_transfer_info->transfer_time;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onFundTransfer(data, error, session_id);
};

void TdApi::OnQueryETF(XTPQueryETFBaseRsp *etf_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (etf_info)
	{
		data["market"] = (int) etf_info->market;
		data["etf"] = etf_info->etf;
		data["subscribe_redemption_ticker"] = etf_info->subscribe_redemption_ticker;
		data["unit"] = etf_info->unit;
		data["subscribe_status"] = etf_info->subscribe_status;
		data["redemption_status"] = etf_info->redemption_status;
		data["max_cash_ratio"] = etf_info->max_cash_ratio;
		data["estimate_amount"] = etf_info->estimate_amount;
		data["cash_component"] = etf_info->cash_component;
		data["net_value"] = etf_info->net_value;
		data["total_amount"] = etf_info->total_amount;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryETF(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryETFBasket(XTPQueryETFComponentRsp *etf_component_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (etf_component_info)
	{
		data["market"] = (int) etf_component_info->market;
		data["ticker"] = etf_component_info->ticker;
		data["component_ticker"] = etf_component_info->component_ticker;
		data["component_name"] = etf_component_info->component_name;
		data["quantity"] = etf_component_info->quantity;
		data["component_market"] = (int) etf_component_info->component_market;
		data["replace_type"] = (int) etf_component_info->replace_type;
		data["premium_ratio"] = etf_component_info->premium_ratio;
		data["amount"] = etf_component_info->amount;
		data["creation_premium_ratio"] = etf_component_info->creation_premium_ratio;
		data["redemption_discount_ratio"] = etf_component_info->redemption_discount_ratio;
		data["creation_amount"] = etf_component_info->creation_amount;
		data["redemption_amount"] = etf_component_info->redemption_amount;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryETFBasket(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryIPOInfoList(XTPQueryIPOTickerRsp *ipo_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (ipo_info)
	{
		data["market"] = (int) ipo_info->market;
		data["ticker"] = ipo_info->ticker;
		data["ticker_name"] = ipo_info->ticker_name;
		data["ticker_type"] = (int) ipo_info->ticker_type;
		data["price"] = ipo_info->price;
		data["unit"] = ipo_info->unit;
		data["qty_upper_limit"] = ipo_info->qty_upper_limit;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryIPOInfoList(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryIPOQuotaInfo(XTPQueryIPOQuotaRsp *quota_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (quota_info)
	{
		data["market"] = (int) quota_info->market;
		data["quantity"] = quota_info->quantity;
		data["tech_quantity"] = quota_info->tech_quantity;
		data["unused"] = quota_info->unused;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryIPOQuotaInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp *option_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (option_info)
	{
		data["ticker"] = option_info->ticker;
		data["security_id_source"] = (int) option_info->security_id_source;
		data["symbol"] = option_info->symbol;
		data["contract_id"] = option_info->contract_id;
		data["underlying_security_id"] = option_info->underlying_security_id;
		data["underlying_security_id_source"] = (int) option_info->underlying_security_id_source;
		data["list_date"] = option_info->list_date;
		data["last_trade_date"] = option_info->last_trade_date;
		data["ticker_type"] = (int) option_info->ticker_type;
		data["day_trading"] = option_info->day_trading;
		data["call_or_put"] = (int) option_info->call_or_put;
		data["delivery_day"] = option_info->delivery_day;
		data["delivery_month"] = option_info->delivery_month;
		data["exercise_type"] = (int) option_info->exercise_type;
		data["exercise_begin_date"] = option_info->exercise_begin_date;
		data["exercise_end_date"] = option_info->exercise_end_date;
		data["exercise_price"] = option_info->exercise_price;
		data["qty_unit"] = option_info->qty_unit;
		data["contract_unit"] = option_info->contract_unit;
		data["contract_position"] = option_info->contract_position;
		data["prev_close_price"] = option_info->prev_close_price;
		data["prev_clearing_price"] = option_info->prev_clearing_price;
		data["lmt_buy_max_qty"] = option_info->lmt_buy_max_qty;
		data["lmt_buy_min_qty"] = option_info->lmt_buy_min_qty;
		data["lmt_sell_max_qty"] = option_info->lmt_sell_max_qty;
		data["lmt_sell_min_qty"] = option_info->lmt_sell_min_qty;
		data["mkt_buy_max_qty"] = option_info->mkt_buy_max_qty;
		data["mkt_buy_min_qty"] = option_info->mkt_buy_min_qty;
		data["mkt_sell_max_qty"] = option_info->mkt_sell_max_qty;
		data["mkt_sell_min_qty"] = option_info->mkt_sell_min_qty;
		data["price_tick"] = option_info->price_tick;
		data["upper_limit_price"] = option_info->upper_limit_price;
		data["lower_limit_price"] = option_info->lower_limit_price;
		data["sell_margin"] = option_info->sell_margin;
		data["margin_ratio_param1"] = option_info->margin_ratio_param1;
		data["margin_ratio_param2"] = option_info->margin_ratio_param2;
		data["unknown"] = option_info->unknown;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryOptionAuctionInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnCreditCashRepay(XTPCrdCashRepayRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (cash_repay_info)
	{
		data["xtp_id"] = cash_repay_info->xtp_id;
		data["request_amount"] = cash_repay_info->request_amount;
		data["cash_repay_amount"] = cash_repay_info->cash_repay_amount;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onCreditCashRepay(data, error, session_id);
};

void TdApi::OnCreditCashRepayDebtInterestFee(XTPCrdCashRepayDebtInterestFeeRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (cash_repay_info)
	{
		data["xtp_id"] = cash_repay_info->xtp_id;
		data["request_amount"] = cash_repay_info->request_amount;
		data["cash_repay_amount"] = cash_repay_info->cash_repay_amount;
		data["debt_compact_id"] = cash_repay_info->debt_compact_id;
		data["unknow"] = cash_repay_info->unknow;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onCreditCashRepayDebtInterestFee(data, error, session_id);
};

void TdApi::OnQueryCreditCashRepayInfo(XTPCrdCashRepayInfo *cash_repay_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (cash_repay_info)
	{
		data["xtp_id"] = cash_repay_info->xtp_id;
		data["status"] = (int) cash_repay_info->status;
		data["request_amount"] = cash_repay_info->request_amount;
		data["cash_repay_amount"] = cash_repay_info->cash_repay_amount;
		data["position_effect"] = cash_repay_info->position_effect;
		data["error_info"] = cash_repay_info->error_info;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditCashRepayInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryCreditFundInfo(XTPCrdFundInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (fund_info)
	{
		data["maintenance_ratio"] = fund_info->maintenance_ratio;
		data["all_asset"] = fund_info->all_asset;
		data["all_debt"] = fund_info->all_debt;
		data["line_of_credit"] = fund_info->line_of_credit;
		data["guaranty"] = fund_info->guaranty;
		data["reserved"] = fund_info->reserved;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditFundInfo(data, error, request_id, session_id);
};

void TdApi::OnQueryCreditDebtInfo(XTPCrdDebtInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (debt_info)
	{
		data["debt_type"] = debt_info->debt_type;
		data["debt_id"] = debt_info->debt_id;
		data["position_id"] = debt_info->position_id;
		data["order_xtp_id"] = debt_info->order_xtp_id;
		data["debt_status"] = debt_info->debt_status;
		data["market"] = (int) debt_info->market;
		data["ticker"] = debt_info->ticker;
		data["order_date"] = debt_info->order_date;
		data["end_date"] = debt_info->end_date;
		data["orig_end_date"] = debt_info->orig_end_date;
		data["is_extended"] = debt_info->is_extended;
		data["remain_amt"] = debt_info->remain_amt;
		data["remain_qty"] = debt_info->remain_qty;
		data["remain_principal"] = debt_info->remain_principal;
		data["due_right_qty"] = debt_info->due_right_qty;
		data["unknown"] = debt_info->unknown;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditDebtInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryCreditTickerDebtInfo(XTPCrdDebtStockInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (debt_info)
	{
		data["market"] = (int) debt_info->market;
		data["ticker"] = debt_info->ticker;
		data["stock_repay_quantity"] = debt_info->stock_repay_quantity;
		data["stock_total_quantity"] = debt_info->stock_total_quantity;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditTickerDebtInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryCreditAssetDebtInfo(double remain_amount, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditAssetDebtInfo(remain_amount, error, request_id, session_id);
};

void TdApi::OnQueryCreditTickerAssignInfo(XTPClientQueryCrdPositionStkInfo *assign_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (assign_info)
	{
		data["market"] = (int) assign_info->market;
		data["ticker"] = assign_info->ticker;
		data["limit_qty"] = assign_info->limit_qty;
		data["yesterday_qty"] = assign_info->yesterday_qty;
		data["left_qty"] = assign_info->left_qty;
		data["frozen_qty"] = assign_info->frozen_qty;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditTickerAssignInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (stock_info)
	{
		data["market"] = (int) stock_info->market;
		data["ticker"] = stock_info->ticker;
		data["transferable_quantity"] = stock_info->transferable_quantity;
		data["transferred_quantity"] = stock_info->transferred_quantity;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditExcessStock(data, error, request_id, session_id);
};

void TdApi::OnQueryMulCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id, bool is_last) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (stock_info)
	{
		data["market"] = (int) stock_info->market;
		data["ticker"] = stock_info->ticker;
		data["transferable_quantity"] = stock_info->transferable_quantity;
		data["transferred_quantity"] = stock_info->transferred_quantity;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryMulCreditExcessStock(data, error, request_id, session_id, is_last);
};

void TdApi::OnCreditExtendDebtDate(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (debt_extend_info)
	{
		data["xtpid"] = debt_extend_info->xtpid;
		data["debt_id"] = debt_extend_info->debt_id;
		data["oper_status"] = (int) debt_extend_info->oper_status;
		data["oper_time"] = debt_extend_info->oper_time;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onCreditExtendDebtDate(data, error, session_id);
};

void TdApi::OnQueryCreditExtendDebtDateOrders(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (debt_extend_info)
	{
		data["xtpid"] = debt_extend_info->xtpid;
		data["debt_id"] = debt_extend_info->debt_id;
		data["oper_status"] = (int) debt_extend_info->oper_status;
		data["oper_time"] = debt_extend_info->oper_time;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditExtendDebtDateOrders(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryCreditFundExtraInfo(XTPCrdFundExtraInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (fund_info)
	{
		data["mf_rs_avl_used"] = fund_info->mf_rs_avl_used;
		data["reserve"] = fund_info->reserve;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditFundExtraInfo(data, error, request_id, session_id);
};

void TdApi::OnQueryCreditPositionExtraInfo(XTPCrdPositionExtraInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (fund_info)
	{
		data["market"] = (int) fund_info->market;
		data["ticker"] = fund_info->ticker;
		data["mf_rs_avl_used"] = fund_info->mf_rs_avl_used;
		data["reserve"] = fund_info->reserve;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryCreditPositionExtraInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnOptionCombinedOrderEvent(XTPOptCombOrderInfo *order_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (order_info)
	{
		data["order_xtp_id"] = order_info->order_xtp_id;
		data["order_client_id"] = order_info->order_client_id;
		data["order_cancel_client_id"] = order_info->order_cancel_client_id;
		data["order_cancel_xtp_id"] = order_info->order_cancel_xtp_id;
		data["market"] = (int) order_info->market;
		data["quantity"] = order_info->quantity;
		data["side"] = order_info->side;
		data["business_type"] = (int) order_info->business_type;
		data["qty_traded"] = order_info->qty_traded;
		data["qty_left"] = order_info->qty_left;
		data["insert_time"] = order_info->insert_time;
		data["update_time"] = order_info->update_time;
		data["cancel_time"] = order_info->cancel_time;
		data["trade_amount"] = order_info->trade_amount;
		data["order_local_id"] = order_info->order_local_id;
		data["order_status"] = (int) order_info->order_status;
		data["order_submit_status"] = (int) order_info->order_submit_status;
		data["order_type"] = order_info->order_type;
		data["opt_comb_info"] = order_info->opt_comb_info;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onOptionCombinedOrderEvent(data, error, session_id);
};

void TdApi::OnOptionCombinedTradeEvent(XTPOptCombTradeReport *trade_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (trade_info)
	{
		data["order_xtp_id"] = trade_info->order_xtp_id;
		data["order_client_id"] = trade_info->order_client_id;
		data["market"] = (int) trade_info->market;
		data["local_order_id"] = trade_info->local_order_id;
		data["exec_id"] = trade_info->exec_id;
		data["quantity"] = trade_info->quantity;
		data["trade_time"] = trade_info->trade_time;
		data["trade_amount"] = trade_info->trade_amount;
		data["report_index"] = trade_info->report_index;
		data["order_exch_id"] = trade_info->order_exch_id;
		data["trade_type"] = trade_info->trade_type;
		data["side"] = trade_info->side;
		data["business_type"] = (int) trade_info->business_type;
		data["branch_pbu"] = trade_info->branch_pbu;
		data["opt_comb_info"] = trade_info->opt_comb_info;
	}
	this->onOptionCombinedTradeEvent(data, session_id);
};

void TdApi::OnCancelOptionCombinedOrderError(XTPOptCombOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (cancel_info)
	{
		data["order_cancel_xtp_id"] = cancel_info->order_cancel_xtp_id;
		data["order_xtp_id"] = cancel_info->order_xtp_id;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onCancelOptionCombinedOrderError(data, error, session_id);
};

void TdApi::OnQueryOptionCombinedOrders(XTPQueryOptCombOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (order_info)
	{
		data["order_xtp_id"] = order_info->order_xtp_id;
		data["order_client_id"] = order_info->order_client_id;
		data["order_cancel_client_id"] = order_info->order_cancel_client_id;
		data["order_cancel_xtp_id"] = order_info->order_cancel_xtp_id;
		data["market"] = (int) order_info->market;
		data["quantity"] = order_info->quantity;
		data["side"] = order_info->side;
		data["business_type"] = (int) order_info->business_type;
		data["qty_traded"] = order_info->qty_traded;
		data["qty_left"] = order_info->qty_left;
		data["insert_time"] = order_info->insert_time;
		data["update_time"] = order_info->update_time;
		data["cancel_time"] = order_info->cancel_time;
		data["trade_amount"] = order_info->trade_amount;
		data["order_local_id"] = order_info->order_local_id;
		data["order_status"] = (int) order_info->order_status;
		data["order_submit_status"] = (int) order_info->order_submit_status;
		data["order_type"] = order_info->order_type;
		data["opt_comb_info"] = order_info->opt_comb_info;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryOptionCombinedOrders(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryOptionCombinedOrdersByPage(XTPQueryOptCombOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (order_info)
	{
		data["order_xtp_id"] = order_info->order_xtp_id;
		data["order_client_id"] = order_info->order_client_id;
		data["order_cancel_client_id"] = order_info->order_cancel_client_id;
		data["order_cancel_xtp_id"] = order_info->order_cancel_xtp_id;
		data["market"] = (int) order_info->market;
		data["quantity"] = order_info->quantity;
		data["side"] = order_info->side;
		data["business_type"] = (int) order_info->business_type;
		data["qty_traded"] = order_info->qty_traded;
		data["qty_left"] = order_info->qty_left;
		data["insert_time"] = order_info->insert_time;
		data["update_time"] = order_info->update_time;
		data["cancel_time"] = order_info->cancel_time;
		data["trade_amount"] = order_info->trade_amount;
		data["order_local_id"] = order_info->order_local_id;
		data["order_status"] = (int) order_info->order_status;
		data["order_submit_status"] = (int) order_info->order_submit_status;
		data["order_type"] = order_info->order_type;
		data["opt_comb_info"] = order_info->opt_comb_info;
	}
	this->onQueryOptionCombinedOrdersByPage(data, req_count, order_sequence, query_reference, request_id, is_last, session_id);
};

void TdApi::OnQueryOptionCombinedTrades(XTPQueryOptCombTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (trade_info)
	{
		data["order_xtp_id"] = trade_info->order_xtp_id;
		data["order_client_id"] = trade_info->order_client_id;
		data["market"] = (int) trade_info->market;
		data["local_order_id"] = trade_info->local_order_id;
		data["exec_id"] = trade_info->exec_id;
		data["quantity"] = trade_info->quantity;
		data["trade_time"] = trade_info->trade_time;
		data["trade_amount"] = trade_info->trade_amount;
		data["report_index"] = trade_info->report_index;
		data["order_exch_id"] = trade_info->order_exch_id;
		data["trade_type"] = trade_info->trade_type;
		data["side"] = trade_info->side;
		data["business_type"] = (int) trade_info->business_type;
		data["branch_pbu"] = trade_info->branch_pbu;
		data["opt_comb_info"] = trade_info->opt_comb_info;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryOptionCombinedTrades(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryOptionCombinedTradesByPage(XTPQueryOptCombTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (trade_info)
	{
		data["order_xtp_id"] = trade_info->order_xtp_id;
		data["order_client_id"] = trade_info->order_client_id;
		data["market"] = (int) trade_info->market;
		data["local_order_id"] = trade_info->local_order_id;
		data["exec_id"] = trade_info->exec_id;
		data["quantity"] = trade_info->quantity;
		data["trade_time"] = trade_info->trade_time;
		data["trade_amount"] = trade_info->trade_amount;
		data["report_index"] = trade_info->report_index;
		data["order_exch_id"] = trade_info->order_exch_id;
		data["trade_type"] = trade_info->trade_type;
		data["side"] = trade_info->side;
		data["business_type"] = (int) trade_info->business_type;
		data["branch_pbu"] = trade_info->branch_pbu;
		data["opt_comb_info"] = trade_info->opt_comb_info;
	}
	this->onQueryOptionCombinedTradesByPage(data, req_count, trade_sequence, query_reference, request_id, is_last, session_id);
};

void TdApi::OnQueryOptionCombinedPosition(XTPQueryOptCombPositionRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (position_info)
	{
		data["strategy_id"] = position_info->strategy_id;
		data["strategy_name"] = position_info->strategy_name;
		data["market"] = (int) position_info->market;
		data["total_qty"] = position_info->total_qty;
		data["available_qty"] = position_info->available_qty;
		data["yesterday_position"] = position_info->yesterday_position;
		data["opt_comb_info"] = position_info->opt_comb_info;
		data["reserved"] = position_info->reserved;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryOptionCombinedPosition(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryOptionCombinedStrategyInfo(XTPQueryCombineStrategyInfoRsp *strategy_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (strategy_info)
	{
		data["strategy_id"] = strategy_info->strategy_id;
		data["strategy_name"] = strategy_info->strategy_name;
		data["market"] = (int) strategy_info->market;
		data["leg_num"] = strategy_info->leg_num;
		data["leg_strategy"] = strategy_info->leg_strategy;
		data["expire_date_type"] = (int) strategy_info->expire_date_type;
		data["underlying_type"] = (int) strategy_info->underlying_type;
		data["auto_sep_type"] = (int) strategy_info->auto_sep_type;
		data["reserved"] = strategy_info->reserved;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryOptionCombinedStrategyInfo(data, error, request_id, is_last, session_id);
};

void TdApi::OnQueryOptionCombinedExecPosition(XTPQueryOptCombExecPosRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	gil_scoped_acquire acquire;
	dict data;
	if (position_info)
	{
		data["market"] = (int) position_info->market;
		data["cntrt_code_1"] = position_info->cntrt_code_1;
		data["cntrt_name_1"] = position_info->cntrt_name_1;
		data["position_side_1"] = (int) position_info->position_side_1;
		data["call_or_put_1"] = (int) position_info->call_or_put_1;
		data["avl_qty_1"] = position_info->avl_qty_1;
		data["orig_own_qty_1"] = position_info->orig_own_qty_1;
		data["own_qty_1"] = position_info->own_qty_1;
		data["cntrt_code_2"] = position_info->cntrt_code_2;
		data["cntrt_name_2"] = position_info->cntrt_name_2;
		data["position_side_2"] = (int) position_info->position_side_2;
		data["call_or_put_2"] = (int) position_info->call_or_put_2;
		data["avl_qty_2"] = position_info->avl_qty_2;
		data["orig_own_qty_2"] = position_info->orig_own_qty_2;
		data["own_qty_2"] = position_info->own_qty_2;
		data["net_qty"] = position_info->net_qty;
		data["order_qty"] = position_info->order_qty;
		data["confirm_qty"] = position_info->confirm_qty;
		data["avl_qty"] = position_info->avl_qty;
		data["reserved"] = position_info->reserved;
	}
	dict error;
	if (error_info)
	{
		error["error_id"] = error_info->error_id;
		error["error_msg"] = error_info->error_msg;
	}
	this->onQueryOptionCombinedExecPosition(data, error, request_id, is_last, session_id);
};

