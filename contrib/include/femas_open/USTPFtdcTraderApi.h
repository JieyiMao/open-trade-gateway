/////////////////////////////////////////////////////////////////////////
///@system ���ǰ��ϵͳ
///@company CFFEX
///@file USTPFtdcTraderApi.h
///@brief �����˿ͻ��˽ӿ�
///@history
///20130520	������	�������ļ�
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "USTPFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT 
#endif

class CUstpFtdcTraderSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	virtual void OnQryFrontConnected(){};	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ���������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
	virtual void OnQryFrontDisconnected(int nReason){};
	
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	
	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageStart(int nTopicID, int nSequenceNo){};
	
	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo){};


	///����Ӧ��
	virtual void OnRspError(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ǰ��ϵͳ�û���¼Ӧ��
	virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField *pRspUserLogout, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������˵�ȷ����Ӧ
	virtual void OnRspNotifyConfirm(CUstpFtdcInputNotifyConfirmField *pInputNotifyConfirm, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ���˵�ȷ����Ӧ
	virtual void OnRspQryNotifyConfirm(CUstpFtdcNotifyConfirmField *pNotifyConfirm, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��Ӧ��
	virtual void OnRspQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���۲���Ӧ��
	virtual void OnRspQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ѯ������Ӧ��
	virtual void OnRspForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ͻ��������Ӧ��
	virtual void OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����������֪ͨ
	virtual void OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField *pFlowMessageCancel) {};

	///�ɽ��ر�
	virtual void OnRtnTrade(CUstpFtdcTradeField *pTrade) {};

	///�����ر�
	virtual void OnRtnOrder(CUstpFtdcOrderField *pOrder) {};

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CUstpFtdcInputOrderField *pInputOrder, CUstpFtdcRspInfoField *pRspInfo) {};

	///������������ر�
	virtual void OnErrRtnOrderAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) {};

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField *pInstrumentStatus) {};

	///���ۻر�
	virtual void OnRtnQuote(CUstpFtdcRtnQuoteField *pRtnQuote) {};

	///����¼�����ر�
	virtual void OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, CUstpFtdcRspInfoField *pRspInfo) {};

	///���۳�������ر�
	virtual void OnErrRtnQuoteAction(CUstpFtdcOrderActionField *pOrderAction, CUstpFtdcRspInfoField *pRspInfo) {};

	///ѯ�ۻر�
	virtual void OnRtnForQuote(CUstpFtdcReqForQuoteField *pReqForQuote) {};

	///������Ϲ���֪ͨ
	virtual void OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField *pMarginCombinationLeg) {};

	///�ͻ��������ȷ��
	virtual void OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction) {};

	///��ѯǰ��ϵͳ�û���¼Ӧ��
	virtual void OnRspQueryUserLogin(CUstpFtdcRspUserLoginField *pRspUserLogin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������ѯӦ��
	virtual void OnRspQryOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ͷ�����˻���ѯӦ��
	virtual void OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField *pRspUserInvestor, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ױ����ѯӦ��
	virtual void OnRspQryTradingCode(CUstpFtdcRspTradingCodeField *pRspTradingCode, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����ʽ��˻���ѯӦ��
	virtual void OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField *pRspInvestorAccount, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CUstpFtdcRspInstrumentField *pRspInstrument, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������ѯӦ��
	virtual void OnRspQryExchange(CUstpFtdcRspExchangeField *pRspExchange, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���ֲֲ߳�ѯӦ��
	virtual void OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField *pRspInvestorPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�Ϲ������ѯӦ��
	virtual void OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField *pRspComplianceParam, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯӦ��
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField *pDissemination, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ�����������ʲ�ѯӦ��
	virtual void OnRspQryInvestorFee(CUstpFtdcInvestorFeeField *pInvestorFee, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Ͷ���߱�֤���ʲ�ѯӦ��
	virtual void OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField *pInvestorMargin, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ױ�����ϳֲֲ�ѯӦ��
	virtual void OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField *pRspInvestorCombPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���ױ��뵥�ȳֲֲ�ѯӦ��
	virtual void OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField *pRspInvestorLegPosition, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Լ����Ϣ��ѯӦ��
	virtual void OnRspQryInstrumentGroup(CUstpFtdcRspInstrumentGroupField *pRspInstrumentGroup, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ϱ�֤�����Ͳ�ѯӦ��
	virtual void OnRspQryClientMarginCombType(CUstpFtdcRspClientMarginCombTypeField *pRspClientMarginCombType, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ȩ¼��Ӧ��
	virtual void OnRspExecOrderInsert(CUstpFtdcInputExecOrderField *pInputExecOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ȩ����Ӧ��
	virtual void OnRspExecOrderAction(CUstpFtdcInputExecOrderActionField *pInputExecOrderAction, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ȩ֪ͨ
	virtual void OnRtnExecOrder(CUstpFtdcExecOrderField *pExecOrder) {};

	///��Ȩ¼�����ر�
	virtual void OnErrRtnExecOrderInsert(CUstpFtdcInputExecOrderField *pInputExecOrder, CUstpFtdcRspInfoField *pRspInfo) {};

	///��Ȩ��������ر�
	virtual void OnErrRtnExecOrderAction(CUstpFtdcInputExecOrderActionField *pInputExecOrderAction, CUstpFtdcRspInfoField *pRspInfo) {};

	///ϵͳʱ���ѯӦ��
	virtual void OnRspQrySystemTime(CUstpFtdcRspQrySystemTimeField *pRspQrySystemTime, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����֪ͨ
	virtual void OnRtnRiskNotify(CUstpFtdcRiskNotifyField *pRiskNotify) {};

	///�����ѯͶ���߽�������Ӧ
	virtual void OnRspQuerySettlementInfo(CUstpFtdcSettlementRspField *pSettlementRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ʽ��˻��������������Ӧ
	virtual void OnRspTradingAccountPasswordUpdate(CUstpFtdcTradingAccountPasswordUpdateRspField *pTradingAccountPasswordUpdateRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ֵ��۵���Ϣ��Ӧ
	virtual void OnRspQueryEWarrantOffset(CUstpFtdcEWarrantOffsetFieldRspField *pEWarrantOffsetFieldRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯת����ˮ��Ӧ
	virtual void OnRspQueryTransferSeriaOffset(CUstpFtdcTransferSerialFieldRspField *pTransferSerialFieldRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ����ǩԼ��ϵ��Ӧ
	virtual void OnRspQueryAccountregister(CUstpFtdcAccountregisterRspField *pAccountregisterRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڻ����������ʽ�ת�ڻ�Ӧ��
	virtual void OnRspFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڻ����������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq) {};

	///�ڻ������ڻ��ʽ�ת����Ӧ��
	virtual void OnRspFromFutureToBankByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڻ������ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq) {};

	///���з����ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByBank(CUstpFtdcTransferFieldReqField *pTransferFieldReq) {};

	///���з��������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByBank(CUstpFtdcTransferFieldReqField *pTransferFieldReq) {};

	///�ڻ������ѯ�������Ӧ��
	virtual void OnRspQueryBankAccountMoneyByFuture(CUstpFtdcAccountFieldRspField *pAccountFieldRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڻ������ѯ�������֪ͨ
	virtual void OnRtnQueryBankBalanceByFuture(CUstpFtdcAccountFieldRtnField *pAccountFieldRtn) {};

	///���з������ڿ���֪ͨ
	virtual void OnRtnOpenAccountByBank(CUstpFtdcSignUpOrCancleAccountRspFieldField *pSignUpOrCancleAccountRspField) {};

	///���з�����������֪ͨ
	virtual void OnRtnCancelAccountByBank(CUstpFtdcSignUpOrCancleAccountRspFieldField *pSignUpOrCancleAccountRspField) {};

	///���з��������ʽ�ת�ڻ�Ӧ��
	virtual void OnRspFromBankToFutureByBank(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���з����ڻ��ʽ�ת����Ӧ��
	virtual void OnRspFromFutureToBankByBank(CUstpFtdcTransferFieldReqField *pTransferFieldReq, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���˴﷢�������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByJSD(CUstpFtdcJSDMoneyField *pJSDMoney) {};

	///���˴﷢���ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByJSD(CUstpFtdcJSDMoneyField *pJSDMoney) {};

	///����ת��Ͷ�����ʽ��˻��䶯֪ͨ
	virtual void OnRtnTransferInvestorAccountChanged(CUstpFtdcTransferFieldReqField *pTransferFieldReq) {};

	///�ڻ����������˻�ǩԼӦ��
	virtual void OnRspSignUpAccountByFuture(CUstpFtdcSignUpOrCancleAccountRspFieldField *pSignUpOrCancleAccountRspField, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڻ����������˻���ԼӦ��
	virtual void OnRspCancleAccountByFuture(CUstpFtdcSignUpOrCancleAccountRspFieldField *pSignUpOrCancleAccountRspField, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ����ǩԼ״̬��Ӧ
	virtual void OnRspQuerySignUpOrCancleAccountStatus(CUstpFtdcQuerySignUpOrCancleAccountStatusRspFieldField *pQuerySignUpOrCancleAccountStatusRspField, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ڻ����������˻����Ӧ��
	virtual void OnRspChangeAccountByFuture(CUstpFtdcChangeAccountRspFieldField *pChangeAccountRspField, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���潻���ʻ�������Ӧ
	virtual void OnRspOpenSimTradeAccount(CUstpFtdcSimTradeAccountInfoField *pSimTradeAccountInfo, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///���潻���ʻ���ѯ��Ӧ
	virtual void OnRspCheckOpenSimTradeAccount(CUstpFtdcSimTradeAccountInfoField *pSimTradeAccountInfo, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
	virtual void OnRspCFMMCTradingAccountKey(CUstpFtdcCFMMCTradingAccountKeyRspField *pCFMMCTradingAccountKeyRsp, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��Ϣ֪ͨ
	virtual void OnRtnMsgNotify(CUstpFtdcMsgNotifyField *pMsgNotify) {};

	///�ֱֲ仯֪ͨ
	virtual void OnRtnClientPositionChange(CUstpFtdcClientPositionChangeField *pClientPositionChange) {};

	///�ʽ�仯֪ͨ
	virtual void OnRtnInvestorAccountChange(CUstpFtdcInvestorAccountChangeField *pInvestorAccountChange) {};

	///�����ֱֲ仯֪ͨӦ��
	virtual void OnRspQryEnableRtnMoneyPositoinChange(CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ʷ������ѯӦ��
	virtual void OnRspQueryHisOrder(CUstpFtdcOrderField *pOrder, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ʷ�ɽ�����ѯӦ��
	virtual void OnRspQueryHisTrade(CUstpFtdcTradeField *pTrade, CUstpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class TRADER_API_EXPORT CUstpFtdcTraderApi
{
public:
	///����TraderApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	static CUstpFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");
	
	///��ȡϵͳ�汾��
	///@param nMajorVersion ���汾��
	///@param nMinorVersion �Ӱ汾��
	///@return ϵͳ��ʶ�ַ���
	static const char *GetVersion(int &nMajorVersion, int &nMinorVersion);
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp����������Э�飬��127.0.0.1��������������ַ����17001�������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	virtual void RegisterQryFront(char *pszFrontAddress) = 0;
	
	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	///@remark ��tcp����������Э�飬��127.0.0.1��������������ַ����12001�������������˿ںš�
	///@remark RegisterFront������RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CUstpFtdcTraderSpi *pSpi) = 0;
	
	///����֤��
	///@param pszCertFileName �û�֤���ļ���
	///@param pszKeyFileName �û�˽Կ�ļ���
	///@param pszCaFileName ������CA֤���ļ���
	///@param pszKeyFilePassword �û�˽Կ�ļ�����
	///@return 0 �����ɹ�
	///@return -1 ������CA֤������ʧ��
	///@return -2 �û�֤������ʧ��
	///@return -3 �û�˽Կ����ʧ��	
	///@return -4 �û�֤��У��ʧ��
	virtual int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword) = 0;

	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        USTP_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        USTP_TERT_RESUME:���ϴ��յ�������
	///        USTP_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(USTP_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        USTP_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        USTP_TERT_RESUME:���ϴ��յ�������
	///        USTP_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(USTP_TE_RESUME_TYPE nResumeType) = 0;

	///���Ľ���Ա����
	///@param nResumeType ����Ա���ش���ʽ  
	///        USTP_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        USTP_TERT_RESUME:���ϴ��յ�������
	///        USTP_TERT_QUICK:ֻ���͵�¼����Ա��������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
	virtual void SubscribeUserTopic(USTP_TE_RESUME_TYPE nResumeType) = 0;
	///����ѯ������
	///@param nResumeType ����Ա���ش���ʽ  
	///        USTP_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        USTP_TERT_RESUME:���ϴ��յ�������
	///        USTP_TERT_QUICK:ֻ���͵�¼����Ա��������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
	virtual void SubscribeForQuote(USTP_TE_RESUME_TYPE nResumeType) = 0;
	
	///����������ʱʱ�䡣
	///@param timeout ������ʱʱ��(��)  
	virtual void SetHeartbeatTimeout(unsigned int timeout) = 0;
	
	///��������־�ļ�
	///@param pszReqLogFileName ������־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenRequestLog(const char *pszReqLogFileName) = 0;

	///��Ӧ����־�ļ�
	///@param pszRspLogFileName Ӧ����־�ļ���  
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	virtual int OpenResponseLog(const char *pszRspLogFileName) = 0;


	///���ǰ��ϵͳ�û���¼����
	virtual int ReqUserLogin(CUstpFtdcReqUserLoginField *pReqUserLogin, int nRequestID) = 0;

	///�û��˳�����
	virtual int ReqUserLogout(CUstpFtdcReqUserLogoutField *pReqUserLogout, int nRequestID) = 0;

	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///������˵�ȷ��
	virtual int ReqNotifyConfirm(CUstpFtdcInputNotifyConfirmField *pInputNotifyConfirm, int nRequestID) = 0;

	///�����ѯ���˵�ȷ��
	virtual int ReqQryNotifyConfirm(CUstpFtdcQryNotifyConfirmField *pQryNotifyConfirm, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CUstpFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CUstpFtdcOrderActionField *pOrderAction, int nRequestID) = 0;

	///���󱨼�¼��
	virtual int ReqQuoteInsert(CUstpFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

	///���۲�������
	virtual int ReqQuoteAction(CUstpFtdcQuoteActionField *pQuoteAction, int nRequestID) = 0;

	///�ͻ�ѯ������
	virtual int ReqForQuote(CUstpFtdcReqForQuoteField *pReqForQuote, int nRequestID) = 0;

	///�ͻ������������
	virtual int ReqMarginCombAction(CUstpFtdcInputMarginCombActionField *pInputMarginCombAction, int nRequestID) = 0;

	///������ѯ����
	virtual int ReqQryOrder(CUstpFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CUstpFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///����Ͷ�����˻���ѯ����
	virtual int ReqQryUserInvestor(CUstpFtdcQryUserInvestorField *pQryUserInvestor, int nRequestID) = 0;

	///���ױ����ѯ����
	virtual int ReqQryTradingCode(CUstpFtdcQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///Ͷ�����ʽ��˻���ѯ����
	virtual int ReqQryInvestorAccount(CUstpFtdcQryInvestorAccountField *pQryInvestorAccount, int nRequestID) = 0;

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CUstpFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///��������ѯ����
	virtual int ReqQryExchange(CUstpFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///Ͷ���ֲֲ߳�ѯ����
	virtual int ReqQryInvestorPosition(CUstpFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///������������
	virtual int ReqSubscribeTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///�Ϲ������ѯ����
	virtual int ReqQryComplianceParam(CUstpFtdcQryComplianceParamField *pQryComplianceParam, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryTopic(CUstpFtdcDisseminationField *pDissemination, int nRequestID) = 0;

	///Ͷ�����������ʲ�ѯ����
	virtual int ReqQryInvestorFee(CUstpFtdcQryInvestorFeeField *pQryInvestorFee, int nRequestID) = 0;

	///Ͷ���߱�֤���ʲ�ѯ����
	virtual int ReqQryInvestorMargin(CUstpFtdcQryInvestorMarginField *pQryInvestorMargin, int nRequestID) = 0;

	///���ױ�����ϳֲֲ�ѯ����
	virtual int ReqQryInvestorCombPosition(CUstpFtdcQryInvestorCombPositionField *pQryInvestorCombPosition, int nRequestID) = 0;

	///���ױ��뵥�ȳֲֲ�ѯ����
	virtual int ReqQryInvestorLegPosition(CUstpFtdcQryInvestorLegPositionField *pQryInvestorLegPosition, int nRequestID) = 0;

	///��ѯ��Լ����Ϣ
	virtual int ReqQryInstrumentGroup(CUstpFtdcQryUstpInstrumentGroupField *pQryUstpInstrumentGroup, int nRequestID) = 0;

	///��ѯ��ϱ�֤������
	virtual int ReqQryClientMarginCombType(CUstpFtdcQryClientMarginCombTypeField *pQryClientMarginCombType, int nRequestID) = 0;

	///��Ȩ¼������
	virtual int ReqExecOrderInsert(CUstpFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

	///��Ȩ��������
	virtual int ReqExecOrderAction(CUstpFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID) = 0;

	///��ѯϵͳʱ��
	virtual int ReqQrySystemTime(CUstpFtdcReqQrySystemTimeField *pReqQrySystemTime, int nRequestID) = 0;

	///�����ѯͶ���߽�����
	virtual int ReqQuerySettlementInfo(CUstpFtdcSettlementQryReqField *pSettlementQryReq, int nRequestID) = 0;

	///�ʽ��˻������������
	virtual int ReqTradingAccountPasswordUpdate(CUstpFtdcTradingAccountPasswordUpdateReqField *pTradingAccountPasswordUpdateReq, int nRequestID) = 0;

	///�����ѯ�ֵ��۵���Ϣ
	virtual int ReqQueryEWarrantOffset(CUstpFtdcEWarrantOffsetFieldReqField *pEWarrantOffsetFieldReq, int nRequestID) = 0;

	///�����ѯת����ˮ
	virtual int ReqQueryTransferSeria(CUstpFtdcTransferSerialFieldReqField *pTransferSerialFieldReq, int nRequestID) = 0;

	///�����ѯ����ǩԼ��ϵ
	virtual int ReqQueryAccountregister(CUstpFtdcAccountregisterReqField *pAccountregisterReq, int nRequestID) = 0;

	///�ڻ����������ʽ�ת�ڻ�����
	virtual int ReqFromBankToFutureByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, int nRequestID) = 0;

	///�ڻ������ڻ��ʽ�ת��������
	virtual int ReqFromFutureToBankByFuture(CUstpFtdcTransferFieldReqField *pTransferFieldReq, int nRequestID) = 0;

	///�ڻ������ѯ�����������
	virtual int ReqQueryBankAccountMoneyByFuture(CUstpFtdcAccountFieldReqField *pAccountFieldReq, int nRequestID) = 0;

	///�ڻ����������˻�ǩԼ����
	virtual int ReqSignUpAccountByFuture(CUstpFtdcSignUpOrCancleAccountReqFieldField *pSignUpOrCancleAccountReqField, int nRequestID) = 0;

	///�ڻ����������˻���Լ����
	virtual int ReqCancleAccountByFuture(CUstpFtdcSignUpOrCancleAccountReqFieldField *pSignUpOrCancleAccountReqField, int nRequestID) = 0;

	///�����ѯ����ǩԼ״̬
	virtual int ReqQuerySignUpOrCancleAccountStatus(CUstpFtdcQuerySignUpOrCancleAccountStatusReqFieldField *pQuerySignUpOrCancleAccountStatusReqField, int nRequestID) = 0;

	///�ڻ����������˻��������
	virtual int ReqChangeAccountByFuture(CUstpFtdcChangeAccountReqFieldField *pChangeAccountReqField, int nRequestID) = 0;

	///���潻���ʻ�����
	virtual int ReqOpenSimTradeAccount(CUstpFtdcSimTradeAccountInfoField *pSimTradeAccountInfo, int nRequestID) = 0;

	///���潻���ʻ���ѯ
	virtual int ReqCheckOpenSimTradeAccount(CUstpFtdcSimTradeAccountInfoField *pSimTradeAccountInfo, int nRequestID) = 0;

	///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
	virtual int ReqCFMMCTradingAccountKey(CUstpFtdcCFMMCTradingAccountKeyReqField *pCFMMCTradingAccountKeyReq, int nRequestID) = 0;

	///�����ֱֲ仯֪ͨ����
	virtual int ReqQryEnableRtnMoneyPositoinChange(CUstpFtdcEnableRtnMoneyPositoinChangeField *pEnableRtnMoneyPositoinChange, int nRequestID) = 0;

	///��ʷ������ѯ����
	virtual int ReqQueryHisOrder(CUstpFtdcQryHisOrderField *pQryHisOrder, int nRequestID) = 0;

	///��ʷ�ɽ�����ѯ����
	virtual int ReqQueryHisTrade(CUstpFtdcQryHisTradeField *pQryHisTrade, int nRequestID) = 0;
protected:
	~CUstpFtdcTraderApi(){};
};
