void TdApi::OnDisconnected(uint64_t session_id, int reason) 
{
	Task task = Task();
	task.task_name = ONDISCONNECTED;
	task.task_extra = session_id;
	task.task_extra = reason;
	this->task_queue.push(task);
};

void TdApi::OnError(XTPRI *error_info) 
{
	Task task = Task();
	task.task_name = ONERROR;
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	this->task_queue.push(task);
};

void TdApi::OnOrderEvent(XTPOrderInfo *order_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONORDEREVENT;
	if (order_info)
	{
		XTPOrderInfo *task_data = new XTPOrderInfo();
		*task_data = *order_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnTradeEvent(XTPTradeReport *trade_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONTRADEEVENT;
	if (trade_info)
	{
		XTPTradeReport *task_data = new XTPTradeReport();
		*task_data = *trade_info;
		task.task_data = task_data;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnCancelOrderError(XTPOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONCANCELORDERERROR;
	if (cancel_info)
	{
		XTPOrderCancelInfo *task_data = new XTPOrderCancelInfo();
		*task_data = *cancel_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOrder(XTPQueryOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYORDER;
	if (order_info)
	{
		XTPQueryOrderRsp *task_data = new XTPQueryOrderRsp();
		*task_data = *order_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOrderByPage(XTPQueryOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYORDERBYPAGE;
	if (order_info)
	{
		XTPQueryOrderRsp *task_data = new XTPQueryOrderRsp();
		*task_data = *order_info;
		task.task_data = task_data;
	}
	task.task_extra = req_count;
	task.task_extra = order_sequence;
	task.task_extra = query_reference;
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryTrade(XTPQueryTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYTRADE;
	if (trade_info)
	{
		XTPQueryTradeRsp *task_data = new XTPQueryTradeRsp();
		*task_data = *trade_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryTradeByPage(XTPQueryTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYTRADEBYPAGE;
	if (trade_info)
	{
		XTPQueryTradeRsp *task_data = new XTPQueryTradeRsp();
		*task_data = *trade_info;
		task.task_data = task_data;
	}
	task.task_extra = req_count;
	task.task_extra = trade_sequence;
	task.task_extra = query_reference;
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryPosition(XTPQueryStkPositionRsp *position, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYPOSITION;
	if (position)
	{
		XTPQueryStkPositionRsp *task_data = new XTPQueryStkPositionRsp();
		*task_data = *position;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryAsset(XTPQueryAssetRsp *asset, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYASSET;
	if (asset)
	{
		XTPQueryAssetRsp *task_data = new XTPQueryAssetRsp();
		*task_data = *asset;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryStructuredFund(XTPStructuredFundInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYSTRUCTUREDFUND;
	if (fund_info)
	{
		XTPStructuredFundInfo *task_data = new XTPStructuredFundInfo();
		*task_data = *fund_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYFUNDTRANSFER;
	if (fund_transfer_info)
	{
		XTPFundTransferNotice *task_data = new XTPFundTransferNotice();
		*task_data = *fund_transfer_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONFUNDTRANSFER;
	if (fund_transfer_info)
	{
		XTPFundTransferNotice *task_data = new XTPFundTransferNotice();
		*task_data = *fund_transfer_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryETF(XTPQueryETFBaseRsp *etf_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYETF;
	if (etf_info)
	{
		XTPQueryETFBaseRsp *task_data = new XTPQueryETFBaseRsp();
		*task_data = *etf_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryETFBasket(XTPQueryETFComponentRsp *etf_component_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYETFBASKET;
	if (etf_component_info)
	{
		XTPQueryETFComponentRsp *task_data = new XTPQueryETFComponentRsp();
		*task_data = *etf_component_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryIPOInfoList(XTPQueryIPOTickerRsp *ipo_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYIPOINFOLIST;
	if (ipo_info)
	{
		XTPQueryIPOTickerRsp *task_data = new XTPQueryIPOTickerRsp();
		*task_data = *ipo_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryIPOQuotaInfo(XTPQueryIPOQuotaRsp *quota_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYIPOQUOTAINFO;
	if (quota_info)
	{
		XTPQueryIPOQuotaRsp *task_data = new XTPQueryIPOQuotaRsp();
		*task_data = *quota_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp *option_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONAUCTIONINFO;
	if (option_info)
	{
		XTPQueryOptionAuctionInfoRsp *task_data = new XTPQueryOptionAuctionInfoRsp();
		*task_data = *option_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnCreditCashRepay(XTPCrdCashRepayRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONCREDITCASHREPAY;
	if (cash_repay_info)
	{
		XTPCrdCashRepayRsp *task_data = new XTPCrdCashRepayRsp();
		*task_data = *cash_repay_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnCreditCashRepayDebtInterestFee(XTPCrdCashRepayDebtInterestFeeRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONCREDITCASHREPAYDEBTINTERESTFEE;
	if (cash_repay_info)
	{
		XTPCrdCashRepayDebtInterestFeeRsp *task_data = new XTPCrdCashRepayDebtInterestFeeRsp();
		*task_data = *cash_repay_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditCashRepayInfo(XTPCrdCashRepayInfo *cash_repay_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITCASHREPAYINFO;
	if (cash_repay_info)
	{
		XTPCrdCashRepayInfo *task_data = new XTPCrdCashRepayInfo();
		*task_data = *cash_repay_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditFundInfo(XTPCrdFundInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITFUNDINFO;
	if (fund_info)
	{
		XTPCrdFundInfo *task_data = new XTPCrdFundInfo();
		*task_data = *fund_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditDebtInfo(XTPCrdDebtInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITDEBTINFO;
	if (debt_info)
	{
		XTPCrdDebtInfo *task_data = new XTPCrdDebtInfo();
		*task_data = *debt_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditTickerDebtInfo(XTPCrdDebtStockInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITTICKERDEBTINFO;
	if (debt_info)
	{
		XTPCrdDebtStockInfo *task_data = new XTPCrdDebtStockInfo();
		*task_data = *debt_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditAssetDebtInfo(double remain_amount, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITASSETDEBTINFO;
	if (remain_amount)
	{
		float *task_data = new float();
		*task_data = *remain_amount;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditTickerAssignInfo(XTPClientQueryCrdPositionStkInfo *assign_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITTICKERASSIGNINFO;
	if (assign_info)
	{
		XTPClientQueryCrdPositionStkInfo *task_data = new XTPClientQueryCrdPositionStkInfo();
		*task_data = *assign_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITEXCESSSTOCK;
	if (stock_info)
	{
		XTPClientQueryCrdSurplusStkRspInfo *task_data = new XTPClientQueryCrdSurplusStkRspInfo();
		*task_data = *stock_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryMulCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id, bool is_last) 
{
	Task task = Task();
	task.task_name = ONQUERYMULCREDITEXCESSSTOCK;
	if (stock_info)
	{
		XTPClientQueryCrdSurplusStkRspInfo *task_data = new XTPClientQueryCrdSurplusStkRspInfo();
		*task_data = *stock_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_extra = session_id;
	task.task_last = is_last;
	this->task_queue.push(task);
};

void TdApi::OnCreditExtendDebtDate(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONCREDITEXTENDDEBTDATE;
	if (debt_extend_info)
	{
		XTPCreditDebtExtendNotice *task_data = new XTPCreditDebtExtendNotice();
		*task_data = *debt_extend_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditExtendDebtDateOrders(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITEXTENDDEBTDATEORDERS;
	if (debt_extend_info)
	{
		XTPCreditDebtExtendNotice *task_data = new XTPCreditDebtExtendNotice();
		*task_data = *debt_extend_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditFundExtraInfo(XTPCrdFundExtraInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITFUNDEXTRAINFO;
	if (fund_info)
	{
		XTPCrdFundExtraInfo *task_data = new XTPCrdFundExtraInfo();
		*task_data = *fund_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditPositionExtraInfo(XTPCrdPositionExtraInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYCREDITPOSITIONEXTRAINFO;
	if (fund_info)
	{
		XTPCrdPositionExtraInfo *task_data = new XTPCrdPositionExtraInfo();
		*task_data = *fund_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnOptionCombinedOrderEvent(XTPOptCombOrderInfo *order_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONOPTIONCOMBINEDORDEREVENT;
	if (order_info)
	{
		XTPOptCombOrderInfo *task_data = new XTPOptCombOrderInfo();
		*task_data = *order_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnOptionCombinedTradeEvent(XTPOptCombTradeReport *trade_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONOPTIONCOMBINEDTRADEEVENT;
	if (trade_info)
	{
		XTPOptCombTradeReport *task_data = new XTPOptCombTradeReport();
		*task_data = *trade_info;
		task.task_data = task_data;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnCancelOptionCombinedOrderError(XTPOptCombOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONCANCELOPTIONCOMBINEDORDERERROR;
	if (cancel_info)
	{
		XTPOptCombOrderCancelInfo *task_data = new XTPOptCombOrderCancelInfo();
		*task_data = *cancel_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionCombinedOrders(XTPQueryOptCombOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONCOMBINEDORDERS;
	if (order_info)
	{
		XTPQueryOptCombOrderRsp *task_data = new XTPQueryOptCombOrderRsp();
		*task_data = *order_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionCombinedOrdersByPage(XTPQueryOptCombOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONCOMBINEDORDERSBYPAGE;
	if (order_info)
	{
		XTPQueryOptCombOrderRsp *task_data = new XTPQueryOptCombOrderRsp();
		*task_data = *order_info;
		task.task_data = task_data;
	}
	task.task_extra = req_count;
	task.task_extra = order_sequence;
	task.task_extra = query_reference;
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionCombinedTrades(XTPQueryOptCombTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONCOMBINEDTRADES;
	if (trade_info)
	{
		XTPQueryOptCombTradeRsp *task_data = new XTPQueryOptCombTradeRsp();
		*task_data = *trade_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionCombinedTradesByPage(XTPQueryOptCombTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONCOMBINEDTRADESBYPAGE;
	if (trade_info)
	{
		XTPQueryOptCombTradeRsp *task_data = new XTPQueryOptCombTradeRsp();
		*task_data = *trade_info;
		task.task_data = task_data;
	}
	task.task_extra = req_count;
	task.task_extra = trade_sequence;
	task.task_extra = query_reference;
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionCombinedPosition(XTPQueryOptCombPositionRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONCOMBINEDPOSITION;
	if (position_info)
	{
		XTPQueryOptCombPositionRsp *task_data = new XTPQueryOptCombPositionRsp();
		*task_data = *position_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionCombinedStrategyInfo(XTPQueryCombineStrategyInfoRsp *strategy_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONCOMBINEDSTRATEGYINFO;
	if (strategy_info)
	{
		XTPQueryCombineStrategyInfoRsp *task_data = new XTPQueryCombineStrategyInfoRsp();
		*task_data = *strategy_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryOptionCombinedExecPosition(XTPQueryOptCombExecPosRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) 
{
	Task task = Task();
	task.task_name = ONQUERYOPTIONCOMBINEDEXECPOSITION;
	if (position_info)
	{
		XTPQueryOptCombExecPosRsp *task_data = new XTPQueryOptCombExecPosRsp();
		*task_data = *position_info;
		task.task_data = task_data;
	}
	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_last = is_last;
	task.task_extra = session_id;
	this->task_queue.push(task);
};

