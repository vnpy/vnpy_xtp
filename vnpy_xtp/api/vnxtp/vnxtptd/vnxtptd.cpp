#include "vnxtptd.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void TdApi::OnDisconnected(uint64_t session_id, int reason)
{
	Task task = Task();
	task.task_name = ONDISCONNECTED;
	task.task_extra_long = session_id;
	task.task_extra_1 = reason;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
	this->task_queue.push(task);
};

void TdApi::OnQueryCreditAssetDebtInfo(double remain_amount, XTPRI *error_info, int request_id, uint64_t session_id)
{
	Task task = Task();
	task.task_name = ONQUERYCREDITASSETDEBTINFO;
	task.task_extra_double = remain_amount;

	if (error_info)
	{
		XTPRI *task_error = new XTPRI();
		*task_error = *error_info;
		task.task_error = task_error;
	}
	task.task_id = request_id;
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
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
	task.task_extra_long = session_id;
	this->task_queue.push(task);
};


///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void TdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case ONDISCONNECTED:
			{
				this->processDisconnected(&task);
				break;
			}

			case ONERROR:
			{
				this->processError(&task);
				break;
			}

			case ONORDEREVENT:
			{
				this->processOrderEvent(&task);
				break;
			}

			case ONTRADEEVENT:
			{
				this->processTradeEvent(&task);
				break;
			}

			case ONCANCELORDERERROR:
			{
				this->processCancelOrderError(&task);
				break;
			}

			case ONQUERYORDER:
			{
				this->processQueryOrder(&task);
				break;
			}

			case ONQUERYORDERBYPAGE:
			{
				this->processQueryOrderByPage(&task);
				break;
			}

			case ONQUERYTRADE:
			{
				this->processQueryTrade(&task);
				break;
			}

			case ONQUERYTRADEBYPAGE:
			{
				this->processQueryTradeByPage(&task);
				break;
			}

			case ONQUERYPOSITION:
			{
				this->processQueryPosition(&task);
				break;
			}

			case ONQUERYASSET:
			{
				this->processQueryAsset(&task);
				break;
			}

			case ONQUERYSTRUCTUREDFUND:
			{
				this->processQueryStructuredFund(&task);
				break;
			}

			case ONQUERYFUNDTRANSFER:
			{
				this->processQueryFundTransfer(&task);
				break;
			}

			case ONFUNDTRANSFER:
			{
				this->processFundTransfer(&task);
				break;
			}

			case ONQUERYETF:
			{
				this->processQueryETF(&task);
				break;
			}

			case ONQUERYETFBASKET:
			{
				this->processQueryETFBasket(&task);
				break;
			}

			case ONQUERYIPOINFOLIST:
			{
				this->processQueryIPOInfoList(&task);
				break;
			}

			case ONQUERYIPOQUOTAINFO:
			{
				this->processQueryIPOQuotaInfo(&task);
				break;
			}

			case ONQUERYOPTIONAUCTIONINFO:
			{
				this->processQueryOptionAuctionInfo(&task);
				break;
			}

			case ONCREDITCASHREPAY:
			{
				this->processCreditCashRepay(&task);
				break;
			}

			case ONCREDITCASHREPAYDEBTINTERESTFEE:
			{
				this->processCreditCashRepayDebtInterestFee(&task);
				break;
			}

			case ONQUERYCREDITCASHREPAYINFO:
			{
				this->processQueryCreditCashRepayInfo(&task);
				break;
			}

			case ONQUERYCREDITFUNDINFO:
			{
				this->processQueryCreditFundInfo(&task);
				break;
			}

			case ONQUERYCREDITDEBTINFO:
			{
				this->processQueryCreditDebtInfo(&task);
				break;
			}

			case ONQUERYCREDITTICKERDEBTINFO:
			{
				this->processQueryCreditTickerDebtInfo(&task);
				break;
			}

			case ONQUERYCREDITASSETDEBTINFO:
			{
				this->processQueryCreditAssetDebtInfo(&task);
				break;
			}

			case ONQUERYCREDITTICKERASSIGNINFO:
			{
				this->processQueryCreditTickerAssignInfo(&task);
				break;
			}

			case ONQUERYCREDITEXCESSSTOCK:
			{
				this->processQueryCreditExcessStock(&task);
				break;
			}

			case ONQUERYMULCREDITEXCESSSTOCK:
			{
				this->processQueryMulCreditExcessStock(&task);
				break;
			}

			case ONCREDITEXTENDDEBTDATE:
			{
				this->processCreditExtendDebtDate(&task);
				break;
			}

			case ONQUERYCREDITEXTENDDEBTDATEORDERS:
			{
				this->processQueryCreditExtendDebtDateOrders(&task);
				break;
			}

			case ONQUERYCREDITFUNDEXTRAINFO:
			{
				this->processQueryCreditFundExtraInfo(&task);
				break;
			}

			case ONQUERYCREDITPOSITIONEXTRAINFO:
			{
				this->processQueryCreditPositionExtraInfo(&task);
				break;
			}

			case ONOPTIONCOMBINEDORDEREVENT:
			{
				this->processOptionCombinedOrderEvent(&task);
				break;
			}

			case ONOPTIONCOMBINEDTRADEEVENT:
			{
				this->processOptionCombinedTradeEvent(&task);
				break;
			}

			case ONCANCELOPTIONCOMBINEDORDERERROR:
			{
				this->processCancelOptionCombinedOrderError(&task);
				break;
			}

			case ONQUERYOPTIONCOMBINEDORDERS:
			{
				this->processQueryOptionCombinedOrders(&task);
				break;
			}

			case ONQUERYOPTIONCOMBINEDORDERSBYPAGE:
			{
				this->processQueryOptionCombinedOrdersByPage(&task);
				break;
			}

			case ONQUERYOPTIONCOMBINEDTRADES:
			{
				this->processQueryOptionCombinedTrades(&task);
				break;
			}

			case ONQUERYOPTIONCOMBINEDTRADESBYPAGE:
			{
				this->processQueryOptionCombinedTradesByPage(&task);
				break;
			}

			case ONQUERYOPTIONCOMBINEDPOSITION:
			{
				this->processQueryOptionCombinedPosition(&task);
				break;
			}

			case ONQUERYOPTIONCOMBINEDSTRATEGYINFO:
			{
				this->processQueryOptionCombinedStrategyInfo(&task);
				break;
			}

			case ONQUERYOPTIONCOMBINEDEXECPOSITION:
			{
				this->processQueryOptionCombinedExecPosition(&task);
				break;
			}
			};

		}
	}
	catch (const TerminatedError&)
	{
	}
};

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
		data["market"] = (int)task_data->market;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["price_type"] = (int)task_data->price_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int)task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int)task_data->order_status;
		data["order_submit_status"] = (int)task_data->order_submit_status;
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
		data["market"] = (int)task_data->market;
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
		data["business_type"] = (int)task_data->business_type;
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
		data["market"] = (int)task_data->market;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["price_type"] = (int)task_data->price_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int)task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int)task_data->order_status;
		data["order_submit_status"] = (int)task_data->order_submit_status;
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
		data["market"] = (int)task_data->market;
		data["price"] = task_data->price;
		data["quantity"] = task_data->quantity;
		data["price_type"] = (int)task_data->price_type;
		data["side"] = task_data->side;
		data["position_effect"] = task_data->position_effect;
		data["business_type"] = (int)task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int)task_data->order_status;
		data["order_submit_status"] = (int)task_data->order_submit_status;
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
		data["market"] = (int)task_data->market;
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
		data["business_type"] = (int)task_data->business_type;
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
		data["market"] = (int)task_data->market;
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
		data["business_type"] = (int)task_data->business_type;
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
		data["market"] = (int)task_data->market;
		data["total_qty"] = task_data->total_qty;
		data["sellable_qty"] = task_data->sellable_qty;
		data["avg_price"] = task_data->avg_price;
		data["unrealized_pnl"] = task_data->unrealized_pnl;
		data["yesterday_position"] = task_data->yesterday_position;
		data["purchase_redeemable_qty"] = task_data->purchase_redeemable_qty;
		data["position_direction"] = (int)task_data->position_direction;
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
		data["account_type"] = (int)task_data->account_type;
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
		data["exchange_id"] = (int)task_data->exchange_id;
		data["sf_ticker"] = task_data->sf_ticker;
		data["sf_ticker_name"] = task_data->sf_ticker_name;
		data["ticker"] = task_data->ticker;
		data["ticker_name"] = task_data->ticker_name;
		data["split_merge_status"] = (int)task_data->split_merge_status;
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
		data["transfer_type"] = (int)task_data->transfer_type;
		data["amount"] = task_data->amount;
		data["oper_status"] = (int)task_data->oper_status;
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
		data["transfer_type"] = (int)task_data->transfer_type;
		data["amount"] = task_data->amount;
		data["oper_status"] = (int)task_data->oper_status;
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
		data["market"] = (int)task_data->market;
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
		data["market"] = (int)task_data->market;
		data["ticker"] = task_data->ticker;
		data["component_ticker"] = task_data->component_ticker;
		data["component_name"] = task_data->component_name;
		data["quantity"] = task_data->quantity;
		data["component_market"] = (int)task_data->component_market;
		data["replace_type"] = (int)task_data->replace_type;
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
		data["market"] = (int)task_data->market;
		data["ticker"] = task_data->ticker;
		data["ticker_name"] = task_data->ticker_name;
		data["ticker_type"] = (int)task_data->ticker_type;
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
		data["market"] = (int)task_data->market;
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
		data["security_id_source"] = (int)task_data->security_id_source;
		data["symbol"] = task_data->symbol;
		data["contract_id"] = task_data->contract_id;
		data["underlying_security_id"] = task_data->underlying_security_id;
		data["underlying_security_id_source"] = (int)task_data->underlying_security_id_source;
		data["list_date"] = task_data->list_date;
		data["last_trade_date"] = task_data->last_trade_date;
		data["ticker_type"] = (int)task_data->ticker_type;
		data["day_trading"] = task_data->day_trading;
		data["call_or_put"] = (int)task_data->call_or_put;
		data["delivery_day"] = task_data->delivery_day;
		data["delivery_month"] = task_data->delivery_month;
		data["exercise_type"] = (int)task_data->exercise_type;
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
		data["status"] = (int)task_data->status;
		data["request_amount"] = task_data->request_amount;
		data["cash_repay_amount"] = task_data->cash_repay_amount;
		data["position_effect"] = task_data->position_effect;

		dict info;
		info["error_info"] = task_data->error_info.error_id;
		info["error_msg"] = task_data->error_info.error_msg;
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
		data["market"] = (int)task_data->market;
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
		data["market"] = (int)task_data->market;
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
	this->onQueryCreditAssetDebtInfo(task->task_extra_double, error, task->task_id, task->task_extra);
};

void TdApi::processQueryCreditTickerAssignInfo(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		XTPClientQueryCrdPositionStkInfo *task_data = (XTPClientQueryCrdPositionStkInfo*)task->task_data;
		data["market"] = (int)task_data->market;
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
		data["market"] = (int)task_data->market;
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
		data["market"] = (int)task_data->market;
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
		data["oper_status"] = (int)task_data->oper_status;
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
		data["oper_status"] = (int)task_data->oper_status;
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
		data["market"] = (int)task_data->market;
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
		data["market"] = (int)task_data->market;
		data["quantity"] = task_data->quantity;
		data["side"] = task_data->side;
		data["business_type"] = (int)task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int)task_data->order_status;
		data["order_submit_status"] = (int)task_data->order_submit_status;
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
		data["market"] = (int)task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["business_type"] = (int)task_data->business_type;
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
		data["market"] = (int)task_data->market;
		data["quantity"] = task_data->quantity;
		data["side"] = task_data->side;
		data["business_type"] = (int)task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int)task_data->order_status;
		data["order_submit_status"] = (int)task_data->order_submit_status;
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
		data["market"] = (int)task_data->market;
		data["quantity"] = task_data->quantity;
		data["side"] = task_data->side;
		data["business_type"] = (int)task_data->business_type;
		data["qty_traded"] = task_data->qty_traded;
		data["qty_left"] = task_data->qty_left;
		data["insert_time"] = task_data->insert_time;
		data["update_time"] = task_data->update_time;
		data["cancel_time"] = task_data->cancel_time;
		data["trade_amount"] = task_data->trade_amount;
		data["order_local_id"] = task_data->order_local_id;
		data["order_status"] = (int)task_data->order_status;
		data["order_submit_status"] = (int)task_data->order_submit_status;
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
		data["market"] = (int)task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["business_type"] = (int)task_data->business_type;
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
		data["market"] = (int)task_data->market;
		data["local_order_id"] = task_data->local_order_id;
		data["exec_id"] = task_data->exec_id;
		data["quantity"] = task_data->quantity;
		data["trade_time"] = task_data->trade_time;
		data["trade_amount"] = task_data->trade_amount;
		data["report_index"] = task_data->report_index;
		data["order_exch_id"] = task_data->order_exch_id;
		data["trade_type"] = task_data->trade_type;
		data["side"] = task_data->side;
		data["business_type"] = (int)task_data->business_type;
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
		data["market"] = (int)task_data->market;
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
		data["market"] = (int)task_data->market;
		data["leg_num"] = task_data->leg_num;
		data["expire_date_type"] = (int)task_data->expire_date_type;
		data["underlying_type"] = (int)task_data->underlying_type;
		data["auto_sep_type"] = (int)task_data->auto_sep_type;
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
		data["market"] = (int)task_data->market;
		data["cntrt_code_1"] = task_data->cntrt_code_1;
		data["cntrt_name_1"] = task_data->cntrt_name_1;
		data["position_side_1"] = (int)task_data->position_side_1;
		data["call_or_put_1"] = (int)task_data->call_or_put_1;
		data["avl_qty_1"] = task_data->avl_qty_1;
		data["orig_own_qty_1"] = task_data->orig_own_qty_1;
		data["own_qty_1"] = task_data->own_qty_1;
		data["cntrt_code_2"] = task_data->cntrt_code_2;
		data["cntrt_name_2"] = task_data->cntrt_name_2;
		data["position_side_2"] = (int)task_data->position_side_2;
		data["call_or_put_2"] = (int)task_data->call_or_put_2;
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


///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void TdApi::createTraderApi(int client_id, string save_file_path, int log_level)
{
	if (!this->api)
	{
		this->api = TraderApi::CreateTraderApi(client_id, save_file_path.c_str(), XTP_LOG_LEVEL(log_level));
		this->api->RegisterSpi(this);
	}
};

void TdApi::init()
{
	if (!this->active)
	{
		this->active = true;
		this->task_thread = thread(&TdApi::processTask, this);
	}
};

void TdApi::release()
{
	this->api->Release();
};

int TdApi::exit()
{	
	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	return 1;
};

string TdApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
};

string TdApi::getApiVersion()
{
	string version = this->api->GetApiVersion();
	return version;
};

dict TdApi::getApiLastError()
{
	XTPRI*last_error = this->api->GetApiLastError();
	dict error;
	error["error_id"] = last_error->error_id;
	error["error_msg"] = last_error->error_msg;
	return error;
};

int TdApi::getClientIDByXTPID(long long order_xtp_id)
{
	int i = this->api->GetClientIDByXTPID(order_xtp_id);
	return i;
};

string TdApi::getAccountByXTPID(long long order_xtp_id)
{
	string account = this->api->GetAccountByXTPID(order_xtp_id);
	return account;
};

void TdApi::subscribePublicTopic(int resume_type)
{
	this->api->SubscribePublicTopic((XTP_TE_RESUME_TYPE)resume_type);
}


void TdApi::setSoftwareVersion(string version)
{
	this->api->SetSoftwareVersion(version.c_str());
}

void TdApi::setSoftwareKey(string key)
{
	this->api->SetSoftwareKey(key.c_str());
}

void TdApi::setHeartBeatInterval(int interval)
{
	this->api->SetHeartBeatInterval(interval);
}

long long TdApi::login(string ip, int port, string user, string password, int sock_type)
{
	long long i = this->api->Login(ip.c_str(), port, user.c_str(), password.c_str(), (XTP_PROTOCOL_TYPE)sock_type);
	return i;
};


int TdApi::logout(long long session_id)
{
	int i = this->api->Logout(session_id);
	return i;
};


long long TdApi::insertOrder(const dict &req, long long session_id)
{
	XTPOrderInsertInfo myreq = XTPOrderInsertInfo();
	memset(&myreq, 0, sizeof(myreq));
	myreq.order_xtp_id = getIntValue(req, "order_xtp_id");
	myreq.order_client_id = getIntValue(req, "order_client_id");
	getString(req, "ticker", myreq.ticker);
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getDouble(req, "price", &myreq.price);
	getDouble(req, "stop_price", &myreq.stop_price);
	myreq.quantity = getIntValue(req, "quantity");
	myreq.price_type = (XTP_PRICE_TYPE)getIntValue(req, "price_type");
	myreq.side = getIntValue(req, "side");
	myreq.position_effect = getIntValue(req, "position_effect");
	myreq.business_type = (XTP_BUSINESS_TYPE)getIntValue(req, "business_type");
	long long i = this->api->InsertOrder(&myreq, session_id);
	return i;
};

long long TdApi::cancelOrder(long long order_xtp_id, long long session_id)
{
	long long i = this->api->CancelOrder(order_xtp_id, session_id);
	return i;
}

int TdApi::queryOrderByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int i = this->api->QueryOrderByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryOrders(const dict &req, long long session_id, int request_id)
{
	XTPQueryOrderReq myreq = XTPQueryOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ticker", myreq.ticker);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryOrders(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryUnfinishedOrders(long long session_id, int request_id)
{
	int i = this->api->QueryUnfinishedOrders(session_id, request_id);
	return i;
};

int TdApi::queryOrdersByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryOrderByPageReq myreq = XTPQueryOrderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryOrdersByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryTradesByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int i = this->api->QueryTradesByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryTrades(const dict &req, long long session_id, int request_id)
{
	XTPQueryTraderReq myreq = XTPQueryTraderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ticker", myreq.ticker);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryTrades(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryTradesByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryTraderByPageReq myreq = XTPQueryTraderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryTradesByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryPosition(string ticker, long long session_id, int request_id)
{
	int i = this->api->QueryPosition(ticker.c_str(), session_id, request_id);
	return i;
};

int TdApi::queryAsset(long long session_id, int request_id)
{
	int i = this->api->QueryAsset(session_id, request_id);
	return i;
};

int TdApi::queryStructuredFund(const dict &req, long long session_id, int request_id)
{
	XTPQueryStructuredFundInfoReq myreq = XTPQueryStructuredFundInfoReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.exchange_id = (XTP_EXCHANGE_TYPE)getIntValue(req, "exchange_id");
	getString(req, "sf_ticker", myreq.sf_ticker);
	int i = this->api->QueryStructuredFund(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryFundTransfer(const dict &req, long long session_id, int request_id)
{
	XTPQueryFundTransferLogReq myreq = XTPQueryFundTransferLogReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.serial_id = getIntValue(req, "serial_id");
	int i = this->api->QueryFundTransfer(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryETF(const dict &req, long long session_id, int request_id)
{
	XTPQueryETFBaseReq myreq = XTPQueryETFBaseReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryETF(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryETFTickerBasket(const dict &req, long long session_id, int request_id)
{
	XTPQueryETFComponentReq myreq = XTPQueryETFComponentReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryETFTickerBasket(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryIPOInfoList(long long session_id, int request_id)
{
	int i = this->api->QueryIPOInfoList(session_id, request_id);
	return i;
};

int TdApi::queryIPOQuotaInfo(long long session_id, int request_id)
{
	int i = this->api->QueryIPOQuotaInfo(session_id, request_id);
	return i;
};

int TdApi::queryOptionAuctionInfo(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptionAuctionInfoReq myreq = XTPQueryOptionAuctionInfoReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryOptionAuctionInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditCashRepayInfo(long long session_id, int request_id)
{
	int i = this->api->QueryCreditCashRepayInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditFundInfo(long long session_id, int request_id)
{
	int i = this->api->QueryCreditFundInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditDebtInfo(long long session_id, int request_id)
{
	int i = this->api->QueryCreditDebtInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditTickerDebtInfo(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdDebtStockReq myreq = XTPClientQueryCrdDebtStockReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditTickerDebtInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditAssetDebtInfo(long long session_id, int request_id)
{
	int i = this->api->QueryCreditAssetDebtInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditTickerAssignInfo(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdPositionStockReq myreq = XTPClientQueryCrdPositionStockReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditTickerAssignInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditExcessStock(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdSurplusStkReqInfo myreq = XTPClientQueryCrdSurplusStkReqInfo();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditExcessStock(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryMulCreditExcessStock(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdSurplusStkReqInfo myreq = XTPClientQueryCrdSurplusStkReqInfo();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryMulCreditExcessStock(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryCreditExtendDebtDateOrders(int xtp_id, long long session_id, int request_id)
{
	int i = this->api->QueryCreditExtendDebtDateOrders(xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryCreditFundExtraInfo(long long session_id, int request_id)
{
	int i = this->api->QueryCreditFundExtraInfo(session_id, request_id);
	return i;
};

int TdApi::queryCreditPositionExtraInfo(const dict &req, long long session_id, int request_id)
{
	XTPClientQueryCrdPositionStockReq myreq = XTPClientQueryCrdPositionStockReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "ticker", myreq.ticker);
	int i = this->api->QueryCreditPositionExtraInfo(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedUnfinishedOrders(long long session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedUnfinishedOrders(session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrderByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedOrderByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrders(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombOrderReq myreq = XTPQueryOptCombOrderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryOptionCombinedOrders(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedOrdersByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombOrderByPageReq myreq = XTPQueryOptCombOrderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryOptionCombinedOrdersByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTradesByXTPID(long long order_xtp_id, long long session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedTradesByXTPID(order_xtp_id, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTrades(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombTraderReq myreq = XTPQueryOptCombTraderReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	myreq.begin_time = getIntValue(req, "begin_time");
	myreq.end_time = getIntValue(req, "end_time");
	int i = this->api->QueryOptionCombinedTrades(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedTradesByPage(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombTraderByPageReq myreq = XTPQueryOptCombTraderByPageReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.req_count = getIntValue(req, "req_count");
	myreq.reference = getIntValue(req, "reference");
	myreq.reserved = getIntValue(req, "reserved");
	int i = this->api->QueryOptionCombinedTradesByPage(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedPosition(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombPositionReq myreq = XTPQueryOptCombPositionReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "comb_num", myreq.comb_num);
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	int i = this->api->QueryOptionCombinedPosition(&myreq, session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedStrategyInfo(long long session_id, int request_id)
{
	int i = this->api->QueryOptionCombinedStrategyInfo(session_id, request_id);
	return i;
};

int TdApi::queryOptionCombinedExecPosition(const dict &req, long long session_id, int request_id)
{
	XTPQueryOptCombExecPosReq myreq = XTPQueryOptCombExecPosReq();
	memset(&myreq, 0, sizeof(myreq));
	myreq.market = (XTP_MARKET_TYPE)getIntValue(req, "market");
	getString(req, "cntrt_code_1", myreq.cntrt_code_1);
	getString(req, "cntrt_code_2", myreq.cntrt_code_2);
	int i = this->api->QueryOptionCombinedExecPosition(&myreq, session_id, request_id);
	return i;
};


///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyTdApi : public TdApi
{
public:
	using TdApi::TdApi;

	void onDisconnected(int extra, int extra_1) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onDisconnected, extra, extra_1);
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

	void onQueryOrderByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryOrderByPage, data, req_count, order_sequence, query_reference, request_id, is_last, session_id);
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

	void onQueryTradeByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryTradeByPage, data, req_count, trade_sequence, query_reference, request_id, is_last, session_id);
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

	void onQueryCreditAssetDebtInfo(double amount, const dict &error, int reqid, int extra) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryCreditAssetDebtInfo, amount, error, reqid, extra);
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

	void onQueryMulCreditExcessStock(const dict &data, const dict &error, int reqid, bool last, int extra) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryMulCreditExcessStock, data, error, reqid, last, extra);
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

	void onQueryOptionCombinedOrdersByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedOrdersByPage, data, req_count, order_sequence, query_reference, request_id, is_last, session_id);
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

	void onQueryOptionCombinedTradesByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onQueryOptionCombinedTradesByPage, data, req_count, trade_sequence, query_reference, request_id, is_last, session_id);
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
};


PYBIND11_MODULE(vnxtptd, m)
{
	class_<TdApi, PyTdApi> TdApi(m, "TdApi", module_local());
	TdApi
		.def(init<>())
		.def("createTraderApi", &TdApi::createTraderApi)
		.def("init", &TdApi::init)
		.def("release", &TdApi::release)
		.def("exit", &TdApi::exit)
		.def("getTradingDay", &TdApi::getTradingDay)
		.def("getApiVersion", &TdApi::getApiVersion)
		.def("getApiLastError", &TdApi::getApiLastError)
		.def("getClientIDByXTPID", &TdApi::getClientIDByXTPID)
		.def("getAccountByXTPID", &TdApi::getAccountByXTPID)
		.def("subscribePublicTopic", &TdApi::subscribePublicTopic)
		.def("setSoftwareVersion", &TdApi::setSoftwareVersion)
		.def("setSoftwareKey", &TdApi::setSoftwareKey)
		.def("setHeartBeatInterval", &TdApi::setHeartBeatInterval)
		.def("login", &TdApi::login)
		.def("logout", &TdApi::logout)
		.def("insertOrder", &TdApi::insertOrder)
		.def("cancelOrder", &TdApi::cancelOrder)

		.def("queryOrderByXTPID", &TdApi::queryOrderByXTPID)
		.def("queryOrders", &TdApi::queryOrders)
		.def("queryUnfinishedOrders", &TdApi::queryUnfinishedOrders)
		.def("queryOrdersByPage", &TdApi::queryOrdersByPage)
		.def("queryTradesByXTPID", &TdApi::queryTradesByXTPID)
		.def("queryTrades", &TdApi::queryTrades)
		.def("queryTradesByPage", &TdApi::queryTradesByPage)
		.def("queryPosition", &TdApi::queryPosition)
		.def("queryAsset", &TdApi::queryAsset)
		.def("queryStructuredFund", &TdApi::queryStructuredFund)
		.def("queryFundTransfer", &TdApi::queryFundTransfer)
		.def("queryETF", &TdApi::queryETF)
		.def("queryETFTickerBasket", &TdApi::queryETFTickerBasket)
		.def("queryIPOInfoList", &TdApi::queryIPOInfoList)
		.def("queryIPOQuotaInfo", &TdApi::queryIPOQuotaInfo)
		.def("queryOptionAuctionInfo", &TdApi::queryOptionAuctionInfo)
		.def("queryCreditCashRepayInfo", &TdApi::queryCreditCashRepayInfo)
		.def("queryCreditFundInfo", &TdApi::queryCreditFundInfo)
		.def("queryCreditDebtInfo", &TdApi::queryCreditDebtInfo)
		.def("queryCreditTickerDebtInfo", &TdApi::queryCreditTickerDebtInfo)
		.def("queryCreditAssetDebtInfo", &TdApi::queryCreditAssetDebtInfo)
		.def("queryCreditTickerAssignInfo", &TdApi::queryCreditTickerAssignInfo)
		.def("queryCreditExcessStock", &TdApi::queryCreditExcessStock)
		.def("queryMulCreditExcessStock", &TdApi::queryMulCreditExcessStock)
		.def("queryCreditExtendDebtDateOrders", &TdApi::queryCreditExtendDebtDateOrders)
		.def("queryCreditFundExtraInfo", &TdApi::queryCreditFundExtraInfo)
		.def("queryCreditPositionExtraInfo", &TdApi::queryCreditPositionExtraInfo)
		.def("queryOptionCombinedUnfinishedOrders", &TdApi::queryOptionCombinedUnfinishedOrders)
		.def("queryOptionCombinedOrderByXTPID", &TdApi::queryOptionCombinedOrderByXTPID)
		.def("queryOptionCombinedOrders", &TdApi::queryOptionCombinedOrders)
		.def("queryOptionCombinedOrdersByPage", &TdApi::queryOptionCombinedOrdersByPage)
		.def("queryOptionCombinedTradesByXTPID", &TdApi::queryOptionCombinedTradesByXTPID)
		.def("queryOptionCombinedTrades", &TdApi::queryOptionCombinedTrades)
		.def("queryOptionCombinedTradesByPage", &TdApi::queryOptionCombinedTradesByPage)
		.def("queryOptionCombinedPosition", &TdApi::queryOptionCombinedPosition)
		.def("queryOptionCombinedStrategyInfo", &TdApi::queryOptionCombinedStrategyInfo)
		.def("queryOptionCombinedExecPosition", &TdApi::queryOptionCombinedExecPosition)

		.def("onDisconnected", &TdApi::onDisconnected)
		.def("onError", &TdApi::onError)
		.def("onOrderEvent", &TdApi::onOrderEvent)
		.def("onTradeEvent", &TdApi::onTradeEvent)
		.def("onCancelOrderError", &TdApi::onCancelOrderError)
		.def("onQueryOrder", &TdApi::onQueryOrder)
		.def("onQueryOrderByPage", &TdApi::onQueryOrderByPage)
		.def("onQueryTrade", &TdApi::onQueryTrade)
		.def("onQueryTradeByPage", &TdApi::onQueryTradeByPage)
		.def("onQueryPosition", &TdApi::onQueryPosition)
		.def("onQueryAsset", &TdApi::onQueryAsset)
		.def("onQueryStructuredFund", &TdApi::onQueryStructuredFund)
		.def("onQueryFundTransfer", &TdApi::onQueryFundTransfer)
		.def("onFundTransfer", &TdApi::onFundTransfer)
		.def("onQueryETF", &TdApi::onQueryETF)
		.def("onQueryETFBasket", &TdApi::onQueryETFBasket)
		.def("onQueryIPOInfoList", &TdApi::onQueryIPOInfoList)
		.def("onQueryIPOQuotaInfo", &TdApi::onQueryIPOQuotaInfo)
		.def("onQueryOptionAuctionInfo", &TdApi::onQueryOptionAuctionInfo)
		.def("onCreditCashRepay", &TdApi::onCreditCashRepay)
		.def("onCreditCashRepayDebtInterestFee", &TdApi::onCreditCashRepayDebtInterestFee)
		.def("onQueryCreditCashRepayInfo", &TdApi::onQueryCreditCashRepayInfo)
		.def("onQueryCreditFundInfo", &TdApi::onQueryCreditFundInfo)
		.def("onQueryCreditDebtInfo", &TdApi::onQueryCreditDebtInfo)
		.def("onQueryCreditTickerDebtInfo", &TdApi::onQueryCreditTickerDebtInfo)
		.def("onQueryCreditAssetDebtInfo", &TdApi::onQueryCreditAssetDebtInfo)
		.def("onQueryCreditTickerAssignInfo", &TdApi::onQueryCreditTickerAssignInfo)
		.def("onQueryCreditExcessStock", &TdApi::onQueryCreditExcessStock)
		.def("onQueryMulCreditExcessStock", &TdApi::onQueryMulCreditExcessStock)
		.def("onCreditExtendDebtDate", &TdApi::onCreditExtendDebtDate)
		.def("onQueryCreditExtendDebtDateOrders", &TdApi::onQueryCreditExtendDebtDateOrders)
		.def("onQueryCreditFundExtraInfo", &TdApi::onQueryCreditFundExtraInfo)
		.def("onQueryCreditPositionExtraInfo", &TdApi::onQueryCreditPositionExtraInfo)
		.def("onOptionCombinedOrderEvent", &TdApi::onOptionCombinedOrderEvent)
		.def("onOptionCombinedTradeEvent", &TdApi::onOptionCombinedTradeEvent)
		.def("onCancelOptionCombinedOrderError", &TdApi::onCancelOptionCombinedOrderError)
		.def("onQueryOptionCombinedOrders", &TdApi::onQueryOptionCombinedOrders)
		.def("onQueryOptionCombinedOrdersByPage", &TdApi::onQueryOptionCombinedOrdersByPage)
		.def("onQueryOptionCombinedTrades", &TdApi::onQueryOptionCombinedTrades)
		.def("onQueryOptionCombinedTradesByPage", &TdApi::onQueryOptionCombinedTradesByPage)
		.def("onQueryOptionCombinedPosition", &TdApi::onQueryOptionCombinedPosition)
		.def("onQueryOptionCombinedStrategyInfo", &TdApi::onQueryOptionCombinedStrategyInfo)
		.def("onQueryOptionCombinedExecPosition", &TdApi::onQueryOptionCombinedExecPosition)
		;
}


