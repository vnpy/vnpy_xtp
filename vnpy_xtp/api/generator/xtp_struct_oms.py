XTPOrderInsertInfo = {
    "order_xtp_id": "int",
    "order_client_id": "int",
    "ticker": "string",
    "market": "enum",
    "price": "float",
    "stop_price": "float",
    "quantity": "int",
    "price_type": "enum",
    "side": "int",
    "position_effect": "int",
    "business_type": "enum",
}

XTPOrderCancelInfo = {
    "order_cancel_xtp_id": "int",
    "order_xtp_id": "int",
}

XTPOrderInfo = {
    "order_xtp_id": "int",
    "order_client_id": "int",
    "order_cancel_client_id": "int",
    "order_cancel_xtp_id": "int",
    "ticker": "string",
    "market": "enum",
    "price": "float",
    "quantity": "int",
    "price_type": "enum",
    "side": "int",
    "position_effect": "int",
    "business_type": "enum",
    "qty_traded": "int",
    "qty_left": "int",
    "insert_time": "int",
    "update_time": "int",
    "cancel_time": "int",
    "trade_amount": "float",
    "order_local_id": "string",
    "order_status": "enum",
    "order_submit_status": "enum",
    "order_type": "string",
}

XTPTradeReport = {
    "order_xtp_id": "int",
    "order_client_id": "int",
    "ticker": "string",
    "market": "enum",
    "local_order_id": "int",
    "exec_id": "string",
    "price": "float",
    "quantity": "int",
    "trade_time": "int",
    "trade_amount": "float",
    "report_index": "int",
    "order_exch_id": "string",
    "trade_type": "string",
    "side": "int",
    "position_effect": "int",
    "business_type": "enum",
    "branch_pbu": "string",
}

XTPQueryOrderReq = {
    "ticker": "string",
    "begin_time": "int",
    "end_time": "int",
}

XTPQueryOrderByPageReq = {
    "req_count": "int",
    "reference": "int",
    "reserved": "int",
}

XTPQueryReportByExecIdReq = {
    "order_xtp_id": "int",
    "exec_id": "string",
}

XTPQueryTraderReq = {
    "ticker": "string",
    "begin_time": "int",
    "end_time": "int",
}

XTPQueryTraderByPageReq = {
    "req_count": "int",
    "reference": "int",
    "reserved": "int",
}

XTPQueryAssetRsp = {
    "total_asset": "float",
    "buying_power": "float",
    "security_asset": "float",
    "fund_buy_amount": "float",
    "fund_buy_fee": "float",
    "fund_sell_amount": "float",
    "fund_sell_fee": "float",
    "withholding_amount": "float",
    "account_type": "enum",
    "frozen_margin": "float",
    "frozen_exec_cash": "float",
    "frozen_exec_fee": "float",
    "pay_later": "float",
    "preadva_pay": "float",
    "orig_banlance": "float",
    "banlance": "float",
    "deposit_withdraw": "float",
    "trade_netting": "float",
    "captial_asset": "float",
    "force_freeze_amount": "float",
    "preferred_amount": "float",
    "repay_stock_aval_banlance": "float",
    "fund_order_data_charges": "float",
    "fund_cancel_data_charges": "float",
    "unknown": "int",
}

XTPQueryStkPositionReq = {
    "ticker": "string",
    "market": "enum",
}

XTPQueryStkPositionRsp = {
    "ticker": "string",
    "ticker_name": "string",
    "market": "enum",
    "total_qty": "int",
    "sellable_qty": "int",
    "avg_price": "float",
    "unrealized_pnl": "float",
    "yesterday_position": "int",
    "purchase_redeemable_qty": "int",
    "position_direction": "enum",
    "reserved1": "int",
    "executable_option": "int",
    "lockable_position": "int",
    "executable_underlying": "int",
    "locked_position": "int",
    "usable_locked_position": "int",
    "profit_price": "float",
    "buy_cost": "float",
    "profit_cost": "float",
    "unknown": "int",
}

XTPCreditDebtExtendNotice = {
    "xtpid": "int",
    "debt_id": "string",
    "oper_status": "enum",
    "oper_time": "int",
}

XTPFundTransferNotice = {
    "serial_id": "int",
    "transfer_type": "enum",
    "amount": "float",
    "oper_status": "enum",
    "transfer_time": "int",
}

XTPQueryFundTransferLogReq = {
    "serial_id": "int",
}

XTPQueryStructuredFundInfoReq = {
    "exchange_id": "enum",
    "sf_ticker": "string",
}

XTPStructuredFundInfo = {
    "exchange_id": "enum",
    "sf_ticker": "string",
    "sf_ticker_name": "string",
    "ticker": "string",
    "ticker_name": "string",
    "split_merge_status": "enum",
    "ratio": "int",
    "min_split_qty": "int",
    "min_merge_qty": "int",
    "net_price": "float",
}

XTPQueryETFBaseReq = {
    "market": "enum",
    "ticker": "string",
}

XTPQueryETFBaseRsp = {
    "market": "enum",
    "etf": "string",
    "subscribe_redemption_ticker": "string",
    "unit": "int",
    "subscribe_status": "int",
    "redemption_status": "int",
    "max_cash_ratio": "float",
    "estimate_amount": "float",
    "cash_component": "float",
    "net_value": "float",
    "total_amount": "float",
}

XTPQueryETFComponentReq = {
    "market": "enum",
    "ticker": "string",
}

XTPQueryETFComponentRspV1 = {
    "market": "enum",
    "ticker": "string",
    "component_ticker": "string",
    "component_name": "string",
    "quantity": "int",
    "component_market": "enum",
    "replace_type": "enum",
    "premium_ratio": "float",
    "amount": "float",
}

XTPQueryETFComponentRsp = {
    "market": "enum",
    "ticker": "string",
    "component_ticker": "string",
    "component_name": "string",
    "quantity": "int",
    "component_market": "enum",
    "replace_type": "enum",
    "premium_ratio": "float",
    "amount": "float",
    "creation_premium_ratio": "float",
    "redemption_discount_ratio": "float",
    "creation_amount": "float",
    "redemption_amount": "float",
}

XTPQueryIPOTickerRsp = {
    "market": "enum",
    "ticker": "string",
    "ticker_name": "string",
    "ticker_type": "enum",
    "price": "float",
    "unit": "int",
    "qty_upper_limit": "int",
}

XTPQueryIPOQuotaRspV1 = {
    "market": "enum",
    "quantity": "int",
}

XTPQueryIPOQuotaRsp = {
    "market": "enum",
    "quantity": "int",
    "tech_quantity": "int",
    "unused": "int",
}

XTPUserTerminalInfoReq = {
    "local_ip": "string",
    "mac_addr": "string",
    "hd": "string",
    "term_type": "enum",
    "internet_ip": "string",
    "internet_port": "int",
    "client_version": "string",
    "macos_sno": "string",
    "unused": "string",
}

XTPQueryOptionAuctionInfoReq = {
    "market": "enum",
    "ticker": "string",
}

XTPQueryOptionAuctionInfoRsp = {
    "ticker": "string",
    "security_id_source": "enum",
    "symbol": "string",
    "contract_id": "string",
    "underlying_security_id": "string",
    "underlying_security_id_source": "enum",
    "list_date": "int",
    "last_trade_date": "int",
    "ticker_type": "enum",
    "day_trading": "int",
    "call_or_put": "enum",
    "delivery_day": "int",
    "delivery_month": "int",
    "exercise_type": "enum",
    "exercise_begin_date": "int",
    "exercise_end_date": "int",
    "exercise_price": "float",
    "qty_unit": "int",
    "contract_unit": "int",
    "contract_position": "int",
    "prev_close_price": "float",
    "prev_clearing_price": "float",
    "lmt_buy_max_qty": "int",
    "lmt_buy_min_qty": "int",
    "lmt_sell_max_qty": "int",
    "lmt_sell_min_qty": "int",
    "mkt_buy_max_qty": "int",
    "mkt_buy_min_qty": "int",
    "mkt_sell_max_qty": "int",
    "mkt_sell_min_qty": "int",
    "price_tick": "float",
    "upper_limit_price": "float",
    "lower_limit_price": "float",
    "sell_margin": "float",
    "margin_ratio_param1": "float",
    "margin_ratio_param2": "float",
    "unknown": "int",
}

XTPCombLegStrategy = {
    "call_or_put": "enum",
    "position_side": "enum",
    "exercise_price_seq": "string",
    "expire_date_seq": "int",
    "leg_qty": "int",
}

XTPQueryOptCombineReq = {
    "strategy_id": "string",
    "market": "enum",
}

XTPQueryCombineStrategyInfoRsp = {
    "strategy_id": "string",
    "strategy_name": "string",
    "market": "enum",
    "leg_num": "int",
    "expire_date_type": "enum",
    "underlying_type": "enum",
    "auto_sep_type": "enum",
    "reserved": "int",
}

XTPOptCombLegInfo = {
    "leg_security_id": "string",
    "leg_cntr_type": "enum",
    "leg_side": "enum",
    "leg_covered": "enum",
    "leg_qty": "int",
}

XTPOptCombPlugin = {
    "strategy_id": "string",
    "comb_num": "string",
    "num_legs": "int",
}

XTPQueryOptCombPositionReq = {
    "comb_num": "string",
    "market": "enum",
}

XTPQueryOptCombPositionRsp = {
    "strategy_id": "string",
    "strategy_name": "string",
    "market": "enum",
    "total_qty": "int",
    "available_qty": "int",
    "yesterday_position": "int",
    "reserved": "int",
}

XTPQueryOptExecInfoRsp = {
    "market": "enum",
    "cntrt_code": "string",
    "own_qty_long": "int",
    "own_qty_short": "int",
    "own_qty_short_cover": "int",
    "net_qty": "int",
    "combed_qty_long": "int",
    "combed_qty_short": "int",
    "combed_qty_short_cover": "int",
    "total_execute_gene_order_qty": "int",
    "total_execute_gene_confirm_qty": "int",
    "total_execute_comb_order_qty": "int",
    "total_execute_comb_confirm_qty": "int",
    "reserved": "int",
}

XTPQueryOptCombExecPosReq = {
    "market": "enum",
    "cntrt_code_1": "string",
    "cntrt_code_2": "string",
}

XTPQueryOptCombExecPosRsp = {
    "market": "enum",
    "cntrt_code_1": "string",
    "cntrt_name_1": "string",
    "position_side_1": "enum",
    "call_or_put_1": "enum",
    "avl_qty_1": "int",
    "orig_own_qty_1": "int",
    "own_qty_1": "int",
    "cntrt_code_2": "string",
    "cntrt_name_2": "string",
    "position_side_2": "enum",
    "call_or_put_2": "enum",
    "avl_qty_2": "int",
    "orig_own_qty_2": "int",
    "own_qty_2": "int",
    "net_qty": "int",
    "order_qty": "int",
    "confirm_qty": "int",
    "avl_qty": "int",
    "reserved": "int",
}

XTPCrdCashRepayRsp = {
    "xtp_id": "int",
    "request_amount": "float",
    "cash_repay_amount": "float",
}

XTPCrdCashRepayDebtInterestFeeRsp = {
    "xtp_id": "int",
    "request_amount": "float",
    "cash_repay_amount": "float",
    "debt_compact_id": "string",
    "unknow": "string",
}

XTPCrdCashRepayInfo = {
    "xtp_id": "int",
    "status": "enum",
    "request_amount": "float",
    "cash_repay_amount": "float",
    "position_effect": "int",
    "error_info": "enum",
}

XTPCrdDebtInfo = {
    "debt_type": "int",
    "debt_id": "string",
    "position_id": "int",
    "order_xtp_id": "int",
    "debt_status": "int",
    "market": "enum",
    "ticker": "string",
    "order_date": "int",
    "end_date": "int",
    "orig_end_date": "int",
    "is_extended": "bool",
    "remain_amt": "float",
    "remain_qty": "int",
    "remain_principal": "float",
    "due_right_qty": "int",
    "unknown": "int",
}

XTPCrdFundInfo = {
    "maintenance_ratio": "float",
    "all_asset": "float",
    "all_debt": "float",
    "line_of_credit": "float",
    "guaranty": "float",
    "reserved": "float",
}

XTPClientQueryCrdDebtStockReq = {
    "market": "enum",
    "ticker": "string",
}

XTPCrdDebtStockInfo = {
    "market": "enum",
    "ticker": "string",
    "stock_repay_quantity": "int",
    "stock_total_quantity": "int",
}

XTPClientQueryCrdPositionStockReq = {
    "market": "enum",
    "ticker": "string",
}

XTPClientQueryCrdPositionStkInfo = {
    "market": "enum",
    "ticker": "string",
    "limit_qty": "int",
    "yesterday_qty": "int",
    "left_qty": "int",
    "frozen_qty": "int",
}

XTPClientQueryCrdSurplusStkReqInfo = {
    "market": "enum",
    "ticker": "string",
}

XTPClientQueryCrdSurplusStkRspInfo = {
    "market": "enum",
    "ticker": "string",
    "transferable_quantity": "int",
    "transferred_quantity": "int",
}

XTPCreditDebtExtendReq = {
    "xtpid": "int",
    "debt_id": "string",
    "defer_days": "int",
    "fund_account": "string",
    "password": "string",
}

XTPCrdFundExtraInfo = {
    "mf_rs_avl_used": "float",
    "reserve": "string",
}

XTPCrdPositionExtraInfo = {
    "market": "enum",
    "ticker": "string",
    "mf_rs_avl_used": "float",
    "reserve": "string",
}

XTPOptCombOrderInsertInfo = {
    "order_xtp_id": "int",
    "order_client_id": "int",
    "market": "enum",
    "quantity": "int",
    "side": "int",
    "business_type": "enum",
    "opt_comb_info": "XTPOptCombPlugin",
}

XTPOptCombOrderInfo = {
    "order_xtp_id": "int",
    "order_client_id": "int",
    "order_cancel_client_id": "int",
    "order_cancel_xtp_id": "int",
    "market": "enum",
    "quantity": "int",
    "side": "int",
    "business_type": "enum",
    "qty_traded": "int",
    "qty_left": "int",
    "insert_time": "int",
    "update_time": "int",
    "cancel_time": "int",
    "trade_amount": "float",
    "order_local_id": "string",
    "order_status": "enum",
    "order_submit_status": "enum",
    "order_type": "string",
    "opt_comb_info": "XTPOptCombPlugin",
}

XTPOptCombTradeReport = {
    "order_xtp_id": "int",
    "order_client_id": "int",
    "market": "enum",
    "local_order_id": "int",
    "exec_id": "string",
    "quantity": "int",
    "trade_time": "int",
    "trade_amount": "float",
    "report_index": "int",
    "order_exch_id": "string",
    "trade_type": "string",
    "side": "int",
    "business_type": "enum",
    "branch_pbu": "string",
    "opt_comb_info": "XTPOptCombPlugin",
}

XTPQueryOptCombOrderReq = {
    "comb_num": "string",
    "begin_time": "int",
    "end_time": "int",
}

XTPQueryOptCombOrderByPageReq = {
    "req_count": "int",
    "reference": "int",
    "reserved": "int",
}

XTPQueryOptCombReportByExecIdReq = {
    "order_xtp_id": "int",
    "exec_id": "string",
}

XTPQueryOptCombTraderReq = {
    "comb_num": "string",
    "begin_time": "int",
    "end_time": "int",
}

XTPQueryOptCombTraderByPageReq = {
    "req_count": "int",
    "reference": "int",
    "reserved": "int",
}

XTPQueryOrderRsp = XTPOrderInfo
XTPQueryTradeRsp = XTPTradeReport
XTPFundTransferLog = XTPFundTransferNotice
XTPOptCombOrderCancelInfo = XTPOrderCancelInfo
XTPQueryOptCombOrderRsp = XTPOptCombOrderInfo
XTPQueryOptCombTradeRsp = XTPOptCombTradeReport