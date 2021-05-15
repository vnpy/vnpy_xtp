XTPOrderInsertInfo = {
	"order_xtp_id": "uint64_t",
	"order_client_id": "uint32_t",
	"ticker": "char",
	"market": "enum",
	"price": "double",
	"stop_price": "double",
	"quantity": "int64_t",
	"price_type": "enum",
	"u32": "uint32_t",
	"side": "uint8_t",
	"position_effect": "uint8_t",
	"reserved1": "uint8_t",
	"reserved2": "uint8_t",
	"business_type": "enum",
}

XTPOrderCancelInfo = {
	"order_cancel_xtp_id": "uint64_t",
	"order_xtp_id": "uint64_t",
}

XTPOrderInfo = {
	"order_xtp_id": "uint64_t",
	"order_client_id": "uint32_t",
	"order_cancel_client_id": "uint32_t",
	"order_cancel_xtp_id": "uint64_t",
	"ticker": "char",
	"market": "enum",
	"price": "double",
	"quantity": "int64_t",
	"price_type": "enum",
	"u32": "uint32_t",
	"side": "uint8_t",
	"position_effect": "uint8_t",
	"reserved1": "uint8_t",
	"reserved2": "uint8_t",
	"business_type": "enum",
	"qty_traded": "int64_t",
	"qty_left": "int64_t",
	"insert_time": "int64_t",
	"update_time": "int64_t",
	"cancel_time": "int64_t",
	"trade_amount": "double",
	"order_local_id": "char",
	"order_status": "enum",
	"order_submit_status": "enum",
	"order_type": "char",
}

XTPTradeReport = {
	"order_xtp_id": "uint64_t",
	"order_client_id": "uint32_t",
	"ticker": "char",
	"market": "enum",
	"local_order_id": "uint64_t",
	"exec_id": "char",
	"price": "double",
	"quantity": "int64_t",
	"trade_time": "int64_t",
	"trade_amount": "double",
	"report_index": "uint64_t",
	"order_exch_id": "char",
	"trade_type": "char",
	"u32": "uint32_t",
	"side": "uint8_t",
	"position_effect": "uint8_t",
	"reserved1": "uint8_t",
	"reserved2": "uint8_t",
	"business_type": "enum",
	"branch_pbu": "char",
}

XTPQueryOrderReq = {
	"ticker": "char",
	"begin_time": "int64_t",
	"end_time": "int64_t",
}

XTPQueryOrderRsp = XTPOrderInfo

XTPQueryOrderByPageReq = {
	"req_count": "int64_t",
	"reference": "int64_t",
	"reserved": "int64_t",
}

XTPQueryReportByExecIdReq = {
	"order_xtp_id": "uint64_t",
	"exec_id": "char",
}

XTPQueryTraderReq = {
	"ticker": "char",
	"begin_time": "int64_t",
	"end_time": "int64_t",
}

XTPQueryTradeRsp = XTPTradeReport

XTPQueryTraderByPageReq = {
	"req_count": "int64_t",
	"reference": "int64_t",
	"reserved": "int64_t",
}

XTPQueryAssetRsp = {
	"total_asset": "double",
	"buying_power": "double",
	"security_asset": "double",
	"fund_buy_amount": "double",
	"fund_buy_fee": "double",
	"fund_sell_amount": "double",
	"fund_sell_fee": "double",
	"withholding_amount": "double",
	"account_type": "enum",
	"frozen_margin": "double",
	"frozen_exec_cash": "double",
	"frozen_exec_fee": "double",
	"pay_later": "double",
	"preadva_pay": "double",
	"orig_banlance": "double",
	"banlance": "double",
	"deposit_withdraw": "double",
	"trade_netting": "double",
	"captial_asset": "double",
	"force_freeze_amount": "double",
	"preferred_amount": "double",
	"repay_stock_aval_banlance": "double",
	"fund_order_data_charges": "double",
	"fund_cancel_data_charges": "double",
	"unknown": "uint64_t",
}

XTPQueryStkPositionReq = {
	"ticker": "char",
	"market": "enum",
}

XTPQueryStkPositionRsp = {
	"ticker": "char",
	"ticker_name": "char",
	"market": "enum",
	"total_qty": "int64_t",
	"sellable_qty": "int64_t",
	"avg_price": "double",
	"unrealized_pnl": "double",
	"yesterday_position": "int64_t",
	"purchase_redeemable_qty": "int64_t",
	"position_direction": "enum",
	"reserved1": "uint32_t",
	"executable_option": "int64_t",
	"lockable_position": "int64_t",
	"executable_underlying": "int64_t",
	"locked_position": "int64_t",
	"usable_locked_position": "int64_t",
	"profit_price": "double",
	"buy_cost": "double",
	"profit_cost": "double",
	"unknown": "uint64_t",
}

XTPCreditDebtExtendNotice = {
	"xtpid": "uint64_t",
	"debt_id": "char",
	"oper_status": "enum",
	"oper_time": "uint64_t",
}

XTPFundTransferNotice = {
	"serial_id": "uint64_t",
	"transfer_type": "enum",
	"amount": "double",
	"oper_status": "enum",
	"transfer_time": "uint64_t",
}

XTPQueryFundTransferLogReq = {
	"serial_id": "uint64_t",
}

XTPFundTransferLog = XTPFundTransferNotice

XTPQueryStructuredFundInfoReq = {
	"exchange_id": "enum",
	"sf_ticker": "char",
}

XTPStructuredFundInfo = {
	"exchange_id": "enum",
	"sf_ticker": "char",
	"sf_ticker_name": "char",
	"ticker": "char",
	"ticker_name": "char",
	"split_merge_status": "enum",
	"ratio": "uint32_t",
	"min_split_qty": "uint32_t",
	"min_merge_qty": "uint32_t",
	"net_price": "double",
}

XTPQueryETFBaseReq = {
	"market": "enum",
	"ticker": "char",
}

XTPQueryETFBaseRsp = {
	"market": "enum",
	"etf": "char",
	"subscribe_redemption_ticker": "char",
	"unit": "int32_t",
	"subscribe_status": "int32_t",
	"redemption_status": "int32_t",
	"max_cash_ratio": "double",
	"estimate_amount": "double",
	"cash_component": "double",
	"net_value": "double",
	"total_amount": "double",
}

XTPQueryETFComponentReq = {
	"market": "enum",
	"ticker": "char",
}

XTPQueryETFComponentRspV1 = {
	"market": "enum",
	"ticker": "char",
	"component_ticker": "char",
	"component_name": "char",
	"quantity": "int64_t",
	"component_market": "enum",
	"replace_type": "enum",
	"premium_ratio": "double",
	"amount": "double",
}

XTPQueryETFComponentRsp = {
	"market": "enum",
	"ticker": "char",
	"component_ticker": "char",
	"component_name": "char",
	"quantity": "int64_t",
	"component_market": "enum",
	"replace_type": "enum",
	"premium_ratio": "double",
	"amount": "double",
	"creation_premium_ratio": "double",
	"redemption_discount_ratio": "double",
	"creation_amount": "double",
	"redemption_amount": "double",
}

XTPQueryIPOTickerRsp = {
	"market": "enum",
	"ticker": "char",
	"ticker_name": "char",
	"ticker_type": "enum",
	"price": "double",
	"unit": "int32_t",
	"qty_upper_limit": "int32_t",
}

XTPQueryIPOQuotaRspV1 = {
	"market": "enum",
	"quantity": "int32_t",
}

XTPQueryIPOQuotaRsp = {
	"market": "enum",
	"quantity": "int32_t",
	"tech_quantity": "int32_t",
	"unused": "int32_t",
}

XTPUserTerminalInfoReq = {
	"local_ip": "char",
	"mac_addr": "char",
	"hd": "char",
	"term_type": "enum",
	"internet_ip": "char",
	"internet_port": "int32_t",
	"client_version": "char",
	"macos_sno": "char",
	"unused": "char",
}

XTPQueryOptionAuctionInfoReq = {
	"market": "enum",
	"ticker": "char",
}

XTPQueryOptionAuctionInfoRsp = {
	"ticker": "char",
	"security_id_source": "enum",
	"symbol": "char",
	"contract_id": "char",
	"underlying_security_id": "char",
	"underlying_security_id_source": "enum",
	"list_date": "uint32_t",
	"last_trade_date": "uint32_t",
	"ticker_type": "enum",
	"day_trading": "int32_t",
	"call_or_put": "enum",
	"delivery_day": "uint32_t",
	"delivery_month": "uint32_t",
	"exercise_type": "enum",
	"exercise_begin_date": "uint32_t",
	"exercise_end_date": "uint32_t",
	"exercise_price": "double",
	"qty_unit": "int64_t",
	"contract_unit": "int64_t",
	"contract_position": "int64_t",
	"prev_close_price": "double",
	"prev_clearing_price": "double",
	"lmt_buy_max_qty": "int64_t",
	"lmt_buy_min_qty": "int64_t",
	"lmt_sell_max_qty": "int64_t",
	"lmt_sell_min_qty": "int64_t",
	"mkt_buy_max_qty": "int64_t",
	"mkt_buy_min_qty": "int64_t",
	"mkt_sell_max_qty": "int64_t",
	"mkt_sell_min_qty": "int64_t",
	"price_tick": "double",
	"upper_limit_price": "double",
	"lower_limit_price": "double",
	"sell_margin": "double",
	"margin_ratio_param1": "double",
	"margin_ratio_param2": "double",
	"unknown": "uint64_t",
}

XTPOptCombOrderCancelInfo = XTPOrderCancelInfo

XTPCombLegStrategy = {
	"call_or_put": "enum",
	"position_side": "enum",
	"exercise_price_seq": "char",
	"expire_date_seq": "int32_t",
	"leg_qty": "int64_t",
}

XTPQueryOptCombineReq = {
	"strategy_id": "char",
	"market": "enum",
}

XTPQueryCombineStrategyInfoRsp = {
	"strategy_id": "char",
	"strategy_name": "char",
	"market": "enum",
	"leg_num": "int32_t",
	"leg_strategy": "XTPCombLegStrategy",
	"expire_date_type": "enum",
	"underlying_type": "enum",
	"auto_sep_type": "enum",
	"reserved": "uint64_t",
}

XTPOptCombLegInfo = {
	"leg_security_id": "char",
	"leg_cntr_type": "enum",
	"leg_side": "enum",
	"leg_covered": "enum",
	"leg_qty": "int32_t",
}

XTPOptCombPlugin = {
	"strategy_id": "char",
	"comb_num": "char",
	"num_legs": "int32_t",
	"leg_detail": "XTPOptCombLegInfo",
}

XTPQueryOptCombPositionReq = {
	"comb_num": "char",
	"market": "enum",
}

XTPQueryOptCombPositionRsp = {
	"strategy_id": "char",
	"strategy_name": "char",
	"market": "enum",
	"total_qty": "int64_t",
	"available_qty": "int64_t",
	"yesterday_position": "int64_t",
	"opt_comb_info": "XTPOptCombPlugin",
	"reserved": "uint64_t",
}

XTPQueryOptExecInfoRsp = {
	"market": "enum",
	"cntrt_code": "char",
	"own_qty_long": "int64_t",
	"own_qty_short": "int64_t",
	"own_qty_short_cover": "int64_t",
	"net_qty": "int64_t",
	"combed_qty_long": "int64_t",
	"combed_qty_short": "int64_t",
	"combed_qty_short_cover": "int64_t",
	"total_execute_gene_order_qty": "int64_t",
	"total_execute_gene_confirm_qty": "int64_t",
	"total_execute_comb_order_qty": "int64_t",
	"total_execute_comb_confirm_qty": "int64_t",
	"reserved": "uint64_t",
}

XTPQueryOptCombExecPosReq = {
	"market": "enum",
	"cntrt_code_1": "char",
	"cntrt_code_2": "char",
}

XTPQueryOptCombExecPosRsp = {
	"market": "enum",
	"cntrt_code_1": "char",
	"cntrt_name_1": "char",
	"position_side_1": "enum",
	"call_or_put_1": "enum",
	"avl_qty_1": "int64_t",
	"orig_own_qty_1": "int64_t",
	"own_qty_1": "int64_t",
	"cntrt_code_2": "char",
	"cntrt_name_2": "char",
	"position_side_2": "enum",
	"call_or_put_2": "enum",
	"avl_qty_2": "int64_t",
	"orig_own_qty_2": "int64_t",
	"own_qty_2": "int64_t",
	"net_qty": "int64_t",
	"order_qty": "int64_t",
	"confirm_qty": "int64_t",
	"avl_qty": "int64_t",
	"reserved": "uint64_t",
}

XTPCrdCashRepayRsp = {
	"xtp_id": "int64_t",
	"request_amount": "double",
	"cash_repay_amount": "double",
}

XTPCrdCashRepayDebtInterestFeeRsp = {
	"xtp_id": "int64_t",
	"request_amount": "double",
	"cash_repay_amount": "double",
	"debt_compact_id": "char",
	"unknow": "char",
}

XTPCrdCashRepayInfo = {
	"xtp_id": "int64_t",
	"status": "enum",
	"request_amount": "double",
	"cash_repay_amount": "double",
	"position_effect": "uint8_t",
	"error_info": "XTPRI",
}

XTPCrdDebtInfo = {
	"debt_type": "int32_t",
	"debt_id": "char",
	"position_id": "int64_t",
	"order_xtp_id": "uint64_t",
	"debt_status": "int32_t",
	"market": "enum",
	"ticker": "char",
	"order_date": "uint64_t",
	"end_date": "uint64_t",
	"orig_end_date": "uint64_t",
	"is_extended": "bool",
	"remain_amt": "double",
	"remain_qty": "int64_t",
	"remain_principal": "double",
	"due_right_qty": "int64_t",
	"unknown": "int64_t",
}

XTPCrdFundInfo = {
	"maintenance_ratio": "double",
	"all_asset": "double",
	"all_debt": "double",
	"line_of_credit": "double",
	"guaranty": "double",
	"reserved": "double",
}

XTPClientQueryCrdDebtStockReq = {
	"market": "enum",
	"ticker": "char",
}

XTPCrdDebtStockInfo = {
	"market": "enum",
	"ticker": "char",
	"stock_repay_quantity": "int64_t",
	"stock_total_quantity": "int64_t",
}

XTPClientQueryCrdPositionStockReq = {
	"market": "enum",
	"ticker": "char",
}

XTPClientQueryCrdPositionStkInfo = {
	"market": "enum",
	"ticker": "char",
	"limit_qty": "int64_t",
	"yesterday_qty": "int64_t",
	"left_qty": "int64_t",
	"frozen_qty": "int64_t",
}

XTPClientQueryCrdSurplusStkReqInfo = {
	"market": "enum",
	"ticker": "char",
}

XTPClientQueryCrdSurplusStkRspInfo = {
	"market": "enum",
	"ticker": "char",
	"transferable_quantity": "int64_t",
	"transferred_quantity": "int64_t",
}

XTPCreditDebtExtendReq = {
	"xtpid": "uint64_t",
	"debt_id": "char",
	"defer_days": "uint32_t",
	"fund_account": "char",
	"password": "char",
}

XTPCreditDebtExtendAck = XTPCreditDebtExtendNotice

XTPCrdFundExtraInfo = {
	"mf_rs_avl_used": "double",
	"reserve": "char",
}

XTPCrdPositionExtraInfo = {
	"market": "enum",
	"ticker": "char",
	"mf_rs_avl_used": "double",
	"reserve": "char",
}

XTPOptCombOrderInsertInfo = {
	"order_xtp_id": "uint64_t",
	"order_client_id": "uint32_t",
	"market": "enum",
	"quantity": "int64_t",
	"side": "uint8_t",
	"business_type": "enum",
	"opt_comb_info": "XTPOptCombPlugin",
}

XTPOptCombOrderInfo = {
	"order_xtp_id": "uint64_t",
	"order_client_id": "uint32_t",
	"order_cancel_client_id": "uint32_t",
	"order_cancel_xtp_id": "uint64_t",
	"market": "enum",
	"quantity": "int64_t",
	"side": "uint8_t",
	"business_type": "enum",
	"qty_traded": "int64_t",
	"qty_left": "int64_t",
	"insert_time": "int64_t",
	"update_time": "int64_t",
	"cancel_time": "int64_t",
	"trade_amount": "double",
	"order_local_id": "char",
	"order_status": "enum",
	"order_submit_status": "enum",
	"order_type": "char",
	"opt_comb_info": "XTPOptCombPlugin",
}

XTPOptCombTradeReport = {
	"order_xtp_id": "uint64_t",
	"order_client_id": "uint32_t",
	"market": "enum",
	"local_order_id": "uint64_t",
	"exec_id": "char",
	"quantity": "int64_t",
	"trade_time": "int64_t",
	"trade_amount": "double",
	"report_index": "uint64_t",
	"order_exch_id": "char",
	"trade_type": "char",
	"side": "uint8_t",
	"business_type": "enum",
	"branch_pbu": "char",
	"opt_comb_info": "XTPOptCombPlugin",
}

XTPQueryOptCombOrderReq = {
	"comb_num": "char",
	"begin_time": "int64_t",
	"end_time": "int64_t",
}

XTPQueryOptCombOrderRsp = XTPOptCombOrderInfo

XTPQueryOptCombOrderByPageReq = {
	"req_count": "int64_t",
	"reference": "int64_t",
	"reserved": "int64_t",
}

XTPQueryOptCombReportByExecIdReq = {
	"order_xtp_id": "uint64_t",
	"exec_id": "char",
}

XTPQueryOptCombTraderReq = {
	"comb_num": "char",
	"begin_time": "int64_t",
	"end_time": "int64_t",
}

XTPQueryOptCombTradeRsp = XTPOptCombTradeReport

XTPQueryOptCombTraderByPageReq = {
	"req_count": "int64_t",
	"reference": "int64_t",
	"reserved": "int64_t",
}

