//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vnxtp.h"
#include "pybind11/pybind11.h"
#include "xtp/xtp_trader_api.h"


using namespace pybind11;
using namespace XTP::API;


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class TdApi : public TraderSpi
{
private:
	TraderApi* api;            //API����
	bool active = false;       //����״̬

public:
	TdApi()
	{
	};

	~TdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	///���ͻ��˵�ĳ�������뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á�
	///@param reason ����ԭ���������������Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark �û���������logout���µĶ��ߣ����ᴥ���˺�����api�����Զ������������߷���ʱ�����û�����ѡ����������������ڴ˺����е���Login���µ�¼��������session_id����ʱ�û��յ������ݸ�����֮ǰ��������
	virtual void OnDisconnected(uint64_t session_id, int reason);

	///����Ӧ��
	///@param error_info ����������Ӧ��������ʱ�ľ���Ĵ������ʹ�����Ϣ,��error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark �˺���ֻ���ڷ�������������ʱ�Ż���ã�һ�������û�����
	virtual void OnError(XTPRI *error_info);

	///����֪ͨ
	///@param order_info ������Ӧ������Ϣ���û�����ͨ��order_info.order_xtp_id������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����order_info.qty_left�ֶ��ڶ���Ϊδ�ɽ������ɡ�ȫ�ɡ��ϵ�״̬ʱ����ʾ�˶�����û�гɽ����������ڲ�����ȫ��״̬ʱ����ʾ�˶���������������order_info.order_cancel_xtp_idΪ������Ӧ�ĳ���ID����Ϊ0ʱ��ʾ�˵������ɹ�
	///@param error_info �������ܾ����߷�������ʱ�������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ÿ�ζ���״̬����ʱ�����ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߣ��ڶ���δ�ɽ���ȫ���ɽ���ȫ�����������ֳ������Ѿܾ���Щ״̬ʱ������Ӧ�����ڲ��ֳɽ�����������ɶ����ĳɽ��ر�������ȷ�ϡ����е�¼�˴��û��Ŀͻ��˶����յ����û��Ķ�����Ӧ
	virtual void OnOrderEvent(XTPOrderInfo *order_info, XTPRI *error_info, uint64_t session_id);

	///�ɽ�֪ͨ
	///@param trade_info �ɽ��ر��ľ�����Ϣ���û�����ͨ��trade_info.order_xtp_id������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ����������Ͻ�����exec_id����Ψһ��ʶһ�ʳɽ���������2�ʳɽ��ر�ӵ����ͬ��exec_id���������Ϊ�˱ʽ����Գɽ��ˡ����������exec_id��Ψһ�ģ���ʱ�޴��жϻ��ơ�report_index+market�ֶο������Ψһ��ʶ��ʾ�ɽ��ر���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark �����гɽ�������ʱ�򣬻ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ����е�¼�˴��û��Ŀͻ��˶����յ����û��ĳɽ��ر�����ض���Ϊ����״̬����Ҫ�û�ͨ���ɽ��ر��ĳɽ�������ȷ����OnOrderEvent()�������Ͳ���״̬��
	virtual void OnTradeEvent(XTPTradeReport *trade_info, uint64_t session_id);

	///����������Ӧ
	///@param cancel_info ����������Ϣ������������order_cancel_xtp_id�ʹ�������order_xtp_id
	///@param error_info �������ܾ����߷�������ʱ�������ʹ�����Ϣ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߣ���error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ����Ӧֻ���ڳ�����������ʱ���ص�
	virtual void OnCancelOrderError(XTPOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id);

	///�����ѯ������Ӧ
	///@param order_info ��ѯ����һ������
	///@param error_info ��ѯ����ʱ��������ʱ�����صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ����֧�ַ�ʱ�β�ѯ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryOrder(XTPQueryOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///��ҳ�����ѯ������Ӧ
	///@param order_info ��ѯ����һ������
	///@param req_count ��ҳ������������
	///@param order_sequence ��ҳ����ĵ�ǰ�ر�����
	///@param query_reference ��ǰ������Ϣ����Ӧ�Ĳ�ѯ��������Ҫ��¼�������ڽ�����һ�η�ҳ��ѯ��ʱ����Ҫ�õ�
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��order_sequenceΪ0���������β�ѯû�в鵽�κμ�¼����is_lastΪtrueʱ�����order_sequence����req_count����ô��ʾ���б��������Խ�����һ�η�ҳ��ѯ��������ȣ���ʾ���б����Ѿ���ѯ��ϡ�һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ�
	virtual void OnQueryOrderByPage(XTPQueryOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�ɽ���Ӧ
	///@param trade_info ��ѯ����һ���ɽ��ر�
	///@param error_info ��ѯ�ɽ��ر���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ����֧�ַ�ʱ�β�ѯ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryTrade(XTPQueryTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///��ҳ�����ѯ�ɽ���Ӧ
	///@param trade_info ��ѯ����һ���ɽ���Ϣ
	///@param req_count ��ҳ������������
	///@param trade_sequence ��ҳ����ĵ�ǰ�ر�����
	///@param query_reference ��ǰ������Ϣ����Ӧ�Ĳ�ѯ��������Ҫ��¼�������ڽ�����һ�η�ҳ��ѯ��ʱ����Ҫ�õ�
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��trade_sequenceΪ0���������β�ѯû�в鵽�κμ�¼����is_lastΪtrueʱ�����trade_sequence����req_count����ô��ʾ���лر������Խ�����һ�η�ҳ��ѯ��������ȣ���ʾ���лر��Ѿ���ѯ��ϡ�һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ�
	virtual void OnQueryTradeByPage(XTPQueryTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///�����ѯͶ���ֲ߳���Ӧ
	///@param position ��ѯ����һֻ��Ʊ�ĳֲ����
	///@param error_info ��ѯ�˻��ֲַ�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark �����û����ܳ��ж����Ʊ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryPosition(XTPQueryStkPositionRsp *position, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�ʽ��˻���Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param asset ��ѯ�����ʽ��˻����
	///@param error_info ��ѯ�ʽ��˻���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryAsset(XTPQueryAssetRsp *asset, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�ּ�������Ϣ��Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param fund_info ��ѯ���ķּ��������
	///@param error_info ��ѯ�ּ�����������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryStructuredFund(XTPStructuredFundInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�ʽ𻮲�������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param fund_transfer_info ��ѯ�����ʽ��˻����
	///@param error_info ��ѯ�ʽ��˻���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�ʽ𻮲�֪ͨ
	///@param fund_transfer_info �ʽ𻮲�֪ͨ�ľ�����Ϣ���û�����ͨ��fund_transfer_info.serial_id������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����
	///@param error_info �ʽ𻮲��������ܾ����߷�������ʱ�������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д��󡣵��ʽ𻮲�����Ϊһ�������Ľڵ�֮�仮������error_info.error_id=11000384ʱ��error_info.error_msgΪ����п����ڻ������ʽ�������Ϊ׼�����û������stringToInt��ת�����ɾݴ���д���ʵ��ʽ��ٴη��𻮲�����
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ���ʽ𻮲�������״̬�仯��ʱ�򣬻ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ����е�¼�˴��û��Ŀͻ��˶����յ����û����ʽ𻮲�֪ͨ��
	virtual void OnFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, uint64_t session_id);

	///�����ѯ�����ڵ�����ʽ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param fund_info ��ѯ���������ڵ�����ʽ����
	///@param error_info ��ѯ�����ڵ�����ʽ�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryOtherServerFund(XTPFundQueryRsp *fund_info, XTPRI *error_info, int request_id, uint64_t session_id);

	///�����ѯETF�嵥�ļ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param etf_info ��ѯ����ETF�嵥�ļ����
	///@param error_info ��ѯETF�嵥�ļ���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryETF(XTPQueryETFBaseRsp *etf_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯETF��Ʊ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param etf_component_info ��ѯ����ETF��Լ����سɷֹ���Ϣ
	///@param error_info ��ѯETF��Ʊ����������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryETFBasket(XTPQueryETFComponentRsp *etf_component_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�����¹��깺��Ϣ�б�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param ipo_info ��ѯ���Ľ����¹��깺��һֻ��Ʊ��Ϣ
	///@param error_info ��ѯ�����¹��깺��Ϣ�б���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryIPOInfoList(XTPQueryIPOTickerRsp *ipo_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�û��¹��깺�����Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param quota_info ��ѯ�����û�ĳ���г��Ľ����¹��깺�����Ϣ
	///@param error_info ���ѯ�û��¹��깺�����Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryIPOQuotaInfo(XTPQueryIPOQuotaRsp *quota_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ��Ȩ��Լ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param option_info ��ѯ������Ȩ��Լ���
	///@param error_info ��ѯ��Ȩ��Լ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryOptionAuctionInfo(XTPQueryOptionAuctionInfoRsp *option_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///������ȯҵ�����ֽ�ֱ�ӻ������Ӧ
	///@param cash_repay_info �ֽ�ֱ�ӻ���֪ͨ�ľ�����Ϣ���û�����ͨ��cash_repay_info.xtp_id������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����
	///@param error_info �ֽ𻹿������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnCreditCashRepay(XTPCrdCashRepayRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id);

	///������ȯҵ�����ֽ�Ϣ����Ӧ
	///@param cash_repay_info �ֽ�Ϣ֪ͨ�ľ�����Ϣ���û�����ͨ��cash_repay_info.xtp_id������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����
	///@param error_info �ֽ�Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnCreditCashRepayDebtInterestFee(XTPCrdCashRepayDebtInterestFeeRsp *cash_repay_info, XTPRI *error_info, uint64_t session_id);

	///�����ѯ������ȯҵ���е��ֽ�ֱ�ӻ��������Ӧ
	///@param cash_repay_info ��ѯ����ĳһ���ֽ�ֱ�ӻ���֪ͨ�ľ�����Ϣ
	///@param error_info ��ѯ�ֽ�ֱ�ӱ�����������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditCashRepayInfo(XTPCrdCashRepayInfo *cash_repay_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�����˻�������Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param fund_info ��ѯ���������˻�������Ϣ���
	///@param error_info ��ѯ�����˻�������Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditFundInfo(XTPCrdFundInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id);

	///�����ѯ�����˻���ծ��Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param debt_info ��ѯ���������˻���Լ��ծ���
	///@param error_info ��ѯ�����˻���ծ��Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditDebtInfo(XTPCrdDebtInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�����˻�ָ��֤ȯ��ծδ����Ϣ��Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param debt_info ��ѯ���������˻�ָ��֤ȯ��ծδ����Ϣ���
	///@param error_info ��ѯ�����˻�ָ��֤ȯ��ծδ����Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditTickerDebtInfo(XTPCrdDebtStockInfo *debt_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ�����˻������ʽ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param remain_amount ��ѯ���������˻������ʽ�
	///@param error_info ��ѯ�����˻������ʽ�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditAssetDebtInfo(double remain_amount, XTPRI *error_info, int request_id, uint64_t session_id);

	///�����ѯ�����˻�����ȯͷ����Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param assign_info ��ѯ���������˻�����ȯͷ����Ϣ
	///@param error_info ��ѯ�����˻�����ȯͷ����Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditTickerAssignInfo(XTPClientQueryCrdPositionStkInfo *assign_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///������ȯҵ���������ѯָ����ȯ��Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param stock_info ��ѯ������ȯ��Ϣ
	///@param error_info ��ѯ�����˻���ȯ��Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id);

	///������ȯҵ���������ѯ��ȯ��Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param stock_info ��ѯ������ȯ��Ϣ
	///@param error_info ��ѯ�����˻���ȯ��Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryMulCreditExcessStock(XTPClientQueryCrdSurplusStkRspInfo* stock_info, XTPRI *error_info, int request_id, uint64_t session_id, bool is_last);

	///������ȯҵ���и�ծ��Լչ�ڵ�֪ͨ
	///@param debt_extend_info ��ծ��Լչ��֪ͨ�ľ�����Ϣ���û�����ͨ��debt_extend_info.xtpid������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����
	///@param error_info ��ծ��Լչ�ڶ������ܾ����߷�������ʱ�������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ����ծ��Լչ�ڶ�����״̬�仯��ʱ�򣬻ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ����е�¼�˴��û��Ŀͻ��˶����յ����û��ĸ�ծ��Լչ��֪ͨ��
	virtual void OnCreditExtendDebtDate(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, uint64_t session_id);

	///��ѯ������ȯҵ���и�ծ��Լչ�ڶ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param debt_extend_info ��ѯ���ĸ�ծ��Լչ�����
	///@param error_info ��ѯ��ծ��Լչ�ڷ�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д��󡣵�error_info.error_id=11000350ʱ������û�м�¼����Ϊ������0ֵʱ��������Լ�����ܵ�ʱ�Ĵ���ԭ��
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditExtendDebtDateOrders(XTPCreditDebtExtendNotice *debt_extend_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///��ѯ������ȯҵ���������˻�������Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param fund_info �����˻�������Ϣ
	///@param error_info ��ѯ�����˻�������Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditFundExtraInfo(XTPCrdFundExtraInfo *fund_info, XTPRI *error_info, int request_id, uint64_t session_id);

	///��ѯ������ȯҵ���������˻�ָ��֤ȯ�ĸ�����Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	///@param fund_info �����˻�ָ��֤ȯ�ĸ�����Ϣ
	///@param error_info ��ѯ�����˻�������Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnQueryCreditPositionExtraInfo(XTPCrdPositionExtraInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///��Ȩ��ϲ��Ա���֪ͨ
	///@param order_info ������Ӧ������Ϣ���û�����ͨ��order_info.order_xtp_id������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����order_info.qty_left�ֶ��ڶ���Ϊδ�ɽ������ɡ�ȫ�ɡ��ϵ�״̬ʱ����ʾ�˶�����û�гɽ����������ڲ�����ȫ��״̬ʱ����ʾ�˶���������������order_info.order_cancel_xtp_idΪ������Ӧ�ĳ���ID����Ϊ0ʱ��ʾ�˵������ɹ�
	///@param error_info �������ܾ����߷�������ʱ�������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ÿ�ζ���״̬����ʱ�����ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߣ��ڶ���δ�ɽ���ȫ���ɽ���ȫ�����������ֳ������Ѿܾ���Щ״̬ʱ������Ӧ�����ڲ��ֳɽ�����������ɶ����ĳɽ��ر�������ȷ�ϡ����е�¼�˴��û��Ŀͻ��˶����յ����û��Ķ�����Ӧ
	virtual void OnOptionCombinedOrderEvent(XTPOptCombOrderInfo *order_info, XTPRI *error_info, uint64_t session_id);

	///��Ȩ��ϲ��Գɽ�֪ͨ
	///@param trade_info �ɽ��ر��ľ�����Ϣ���û�����ͨ��trade_info.order_xtp_id������������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ����������Ͻ�����exec_id����Ψһ��ʶһ�ʳɽ���������2�ʳɽ��ر�ӵ����ͬ��exec_id���������Ϊ�˱ʽ����Գɽ��ˡ����������exec_id��Ψһ�ģ���ʱ�޴��жϻ��ơ�report_index+market�ֶο������Ψһ��ʶ��ʾ�ɽ��ر���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark �����гɽ�������ʱ�򣬻ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ����е�¼�˴��û��Ŀͻ��˶����յ����û��ĳɽ��ر�����ض���Ϊ����״̬����Ҫ�û�ͨ���ɽ��ر��ĳɽ�������ȷ����OnOrderEvent()�������Ͳ���״̬��
	virtual void OnOptionCombinedTradeEvent(XTPOptCombTradeReport *trade_info, uint64_t session_id);

	///��Ȩ��ϲ��Գ���������Ӧ
	///@param cancel_info ����������Ϣ������������order_cancel_xtp_id�ʹ�������order_xtp_id
	///@param error_info �������ܾ����߷�������ʱ�������ʹ�����Ϣ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߣ���error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ����Ӧֻ���ڳ�����������ʱ���ص�
	virtual void OnCancelOptionCombinedOrderError(XTPOptCombOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id);

	///�����ѯ��Ȩ��ϲ��Ա�����Ӧ
	///@param order_info ��ѯ����һ������
	///@param error_info ��ѯ����ʱ��������ʱ�����صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ����֧�ַ�ʱ�β�ѯ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ��˶�Ӧ����������������ѯʹ�ã�������������ʱ����������û���·ӵ�£�����api����
	virtual void OnQueryOptionCombinedOrders(XTPQueryOptCombOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///��ҳ�����ѯ��Ȩ��ϲ��Ա�����Ӧ
	///@param order_info ��ѯ����һ������
	///@param req_count ��ҳ������������
	///@param order_sequence ��ҳ����ĵ�ǰ�ر�����
	///@param query_reference ��ǰ������Ϣ����Ӧ�Ĳ�ѯ��������Ҫ��¼�������ڽ�����һ�η�ҳ��ѯ��ʱ����Ҫ�õ�
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��order_sequenceΪ0���������β�ѯû�в鵽�κμ�¼����is_lastΪtrueʱ�����order_sequence����req_count����ô��ʾ���б��������Խ�����һ�η�ҳ��ѯ��������ȣ���ʾ���б����Ѿ���ѯ��ϡ�һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ�
	virtual void OnQueryOptionCombinedOrdersByPage(XTPQueryOptCombOrderRsp *order_info, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ��Ȩ��ϲ��Գɽ���Ӧ
	///@param trade_info ��ѯ����һ���ɽ��ر�
	///@param error_info ��ѯ�ɽ��ر���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ����֧�ַ�ʱ�β�ѯ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ��˶�Ӧ����������������ѯʹ�ã�������������ʱ����������û���·ӵ�£�����api����
	virtual void OnQueryOptionCombinedTrades(XTPQueryOptCombTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///��ҳ�����ѯ��Ȩ��ϲ��Գɽ���Ӧ
	///@param trade_info ��ѯ����һ���ɽ���Ϣ
	///@param req_count ��ҳ������������
	///@param trade_sequence ��ҳ����ĵ�ǰ�ر�����
	///@param query_reference ��ǰ������Ϣ����Ӧ�Ĳ�ѯ��������Ҫ��¼�������ڽ�����һ�η�ҳ��ѯ��ʱ����Ҫ�õ�
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark ��trade_sequenceΪ0���������β�ѯû�в鵽�κμ�¼����is_lastΪtrueʱ�����trade_sequence����req_count����ô��ʾ���лر������Խ�����һ�η�ҳ��ѯ��������ȣ���ʾ���лر��Ѿ���ѯ��ϡ�һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ�
	virtual void OnQueryOptionCombinedTradesByPage(XTPQueryOptCombTradeRsp *trade_info, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ��Ȩ��ϲ��Գֲ���Ӧ
	///@param position_info ��ѯ����һ���ֲ���Ϣ
	///@param error_info ��ѯ�ֲַ�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ�
	virtual void OnQueryOptionCombinedPosition(XTPQueryOptCombPositionRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///�����ѯ��Ȩ��ϲ�����Ϣ��Ӧ
	///@param strategy_info ��ѯ����һ����ϲ�����Ϣ
	///@param error_info ��ѯ�ɽ��ر���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ�
	virtual void OnQueryOptionCombinedStrategyInfo(XTPQueryCombineStrategyInfoRsp *strategy_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	///��ѯ��Ȩ��Ȩ�ϲ�ͷ�����Ӧ
	///@param position_info ��ѯ����һ����Ȩ�ϲ�ͷ����Ϣ
	///@param error_info ��ѯ�ֲַ�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param request_id ����Ϣ��Ӧ������Ӧ������ID
	///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
	///@remark һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ�
	virtual void OnQueryOptionCombinedExecPosition(XTPQueryOptCombExecPosRsp *position_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//-------------------------------------------------------------------------------------

	virtual void onDisconnected(uint64_t session_id, int reason) {};

	virtual void onError(const dict &error) {};

	virtual void onOrderEvent(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onTradeEvent(const dict &data, uint64_t session_id) {};

	virtual void onCancelOrderError(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onQueryOrder(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOrderByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryTrade(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryTradeByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryAsset(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryStructuredFund(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryFundTransfer(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onFundTransfer(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onQueryOtherServerFund(const dict &fund_info, const dict &error, int request_id, uint64_t session_id) {};

	virtual void onQueryETF(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryETFBasket(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryIPOInfoList(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryIPOQuotaInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionAuctionInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onCreditCashRepay(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onCreditCashRepayDebtInterestFee(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onQueryCreditCashRepayInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryCreditFundInfo(const dict &data, const dict &error, int request_id, uint64_t session_id) {};

	virtual void onQueryCreditDebtInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryCreditTickerDebtInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryCreditAssetDebtInfo(double remain_amount, const dict &error, int request_id, uint64_t session_id) {};

	virtual void onQueryCreditTickerAssignInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryCreditExcessStock(const dict &data, const dict &error, int request_id, uint64_t session_id) {};

	virtual void onQueryMulCreditExcessStock(const dict &data, const dict &error, int request_id, uint64_t session_id, bool is_last) {};

	virtual void onCreditExtendDebtDate(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onQueryCreditExtendDebtDateOrders(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryCreditFundExtraInfo(const dict &data, const dict &error, int request_id, uint64_t session_id) {};

	virtual void onQueryCreditPositionExtraInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onOptionCombinedOrderEvent(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onOptionCombinedTradeEvent(const dict &data, uint64_t session_id) {};

	virtual void onCancelOptionCombinedOrderError(const dict &data, const dict &error, uint64_t session_id) {};

	virtual void onQueryOptionCombinedOrders(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedOrdersByPage(const dict &data, int64_t req_count, int64_t order_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedTrades(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedTradesByPage(const dict &data, int64_t req_count, int64_t trade_sequence, int64_t query_reference, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedStrategyInfo(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	virtual void onQueryOptionCombinedExecPosition(const dict &data, const dict &error, int request_id, bool is_last, uint64_t session_id) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createTraderApi(int client_id, string save_file_path, int log_level);

	void release();

	void init();

	int exit();

	string getTradingDay();

	string getApiVersion();

	dict getApiLastError();

	int getClientIDByXTPID(uint64_t order_xtp_id);

	string getAccountByXTPID(uint64_t order_xtp_id);

	void subscribePublicTopic(int resume_type);

	void setSoftwareVersion(string version);

	void setSoftwareKey(string key);

	void setHeartBeatInterval(int interval);

	uint64_t login(string ip, int port, string user, string password, int sock_type);

	int logout(uint64_t session_id);

	bool isServerRestart(uint64_t session_id);

	int modifyUserTerminalInfo(const dict &req, uint64_t session_id);

	uint64_t insertOrder(const dict &req, uint64_t session_id);

	uint64_t cancelOrder(uint64_t order_xtp_id, uint64_t session_id);

	int queryOrderByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

	int queryOrders(const dict &req, uint64_t session_id, int request_id);

	int queryUnfinishedOrders(uint64_t session_id, int request_id);

	int queryOrdersByPage(const dict &req, uint64_t session_id, int request_id);

	int queryTradesByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

	int queryTrades(const dict &req, uint64_t session_id, int request_id);

	int queryTradesByPage(const dict &req, uint64_t session_id, int request_id);

	int queryPosition(string ticker, uint64_t session_id, int request_id);

	int queryAsset(uint64_t session_id, int request_id);

	int queryStructuredFund(const dict &req, uint64_t session_id, int request_id);

	int queryFundTransfer(const dict &req, uint64_t session_id, int request_id);

	int queryOtherServerFund(const dict &query_param, uint64_t session_id, int request_id);

	int queryETF(const dict &req, uint64_t session_id, int request_id);

	int queryETFTickerBasket(const dict &req, uint64_t session_id, int request_id);

	int queryIPOInfoList(uint64_t session_id, int request_id);

	int queryIPOQuotaInfo(uint64_t session_id, int request_id);

	int queryOptionAuctionInfo(const dict &req, uint64_t session_id, int request_id);

	int queryCreditCashRepayInfo(uint64_t session_id, int request_id);

	int queryCreditFundInfo(uint64_t session_id, int request_id);

	int queryCreditDebtInfo(uint64_t session_id, int request_id);

	int queryCreditTickerDebtInfo(const dict &req, uint64_t session_id, int request_id);

	int queryCreditAssetDebtInfo(uint64_t session_id, int request_id);

	int queryCreditTickerAssignInfo(const dict &req, uint64_t session_id, int request_id);

	int queryCreditExcessStock(const dict &req, uint64_t session_id, int request_id);

	int queryMulCreditExcessStock(const dict &req, uint64_t session_id, int request_id);

	int queryCreditExtendDebtDateOrders(uint64_t xtp_id, uint64_t session_id, int request_id);

	int queryCreditFundExtraInfo(uint64_t session_id, int request_id);

	int queryCreditPositionExtraInfo(const dict &req, uint64_t session_id, int request_id);

	int queryOptionCombinedUnfinishedOrders(uint64_t session_id, int request_id);

	int queryOptionCombinedOrderByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

	int queryOptionCombinedOrders(const dict &req, uint64_t session_id, int request_id);

	int queryOptionCombinedOrdersByPage(const dict &req, uint64_t session_id, int request_id);

	int queryOptionCombinedTradesByXTPID(uint64_t order_xtp_id, uint64_t session_id, int request_id);

	int queryOptionCombinedTrades(const dict &req, uint64_t session_id, int request_id);

	int queryOptionCombinedTradesByPage(const dict &req, uint64_t session_id, int request_id);

	int queryOptionCombinedPosition(const dict &req, uint64_t session_id, int request_id);

	int queryOptionCombinedStrategyInfo(uint64_t session_id, int request_id);

	int queryOptionCombinedExecPosition(const dict &req, uint64_t session_id, int request_id);
};
