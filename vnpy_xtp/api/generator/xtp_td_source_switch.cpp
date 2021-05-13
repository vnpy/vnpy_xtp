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

