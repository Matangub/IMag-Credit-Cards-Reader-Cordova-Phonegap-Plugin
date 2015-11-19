#ifndef _EMVLIB_API_H
#define _EMVLIB_API_H

#define MAX_REVOCLIST_NUM	30		// �����б�
#define MAX_APP_NUM			30		//EMV��Ӧ���б����ɴ洢��Ӧ����
#define MAX_CANDLIST_NUM	30		//
#define PART_MATCH			0x00	//Ӧ��ѡ��ƥ���־(����ƥ��)
#define FULL_MATCH			0x01	//Ӧ��ѡ��ƥ���־(��ȫƥ��)

// ��׼����������ֵ
#define EMV_TRANS_TYPE_CASH          0x01       //CASH
#define EMV_TRANS_TYPE_GOODS	     0x00       //GOODS AND SERVICE
#define EMV_TRANS_TYPE_CASHBACK      0x09       //CASHBACK

//���״��?����붨��
#define EMV_OK             0         //�ɹ�
#define EMV_RESELECT_APP  -1         //����ѡ��Ӧ��
#define ICC_CMD_ERR       -2         //IC����ʧ��
#define ICC_BLOCK         -3         //IC����    
   
#define EMV_RSP_ERR       -4         //IC���������
#define EMV_APP_BLOCK     -5         //Ӧ������
#define EMV_NO_APP        -6         //��Ƭ��û��EMVӦ��
#define EMV_USER_CANCEL   -7         //�û�ȡ��ǰ��������
#define EMV_TIME_OUT      -8         //�û�������ʱ
#define EMV_DATA_ERR      -9         //��Ƭ��ݴ���
#define EMV_NOT_ACCEPT    -10        //���ײ�����
#define EMV_DENIAL        -11        //���ױ��ܾ�
#define EMV_KEY_EXP       -12        //��Կ����

//������붨��
#define EMV_NO_PINPAD     -13        //û��������̻���̲�����
#define EMV_NO_PASSWORD   -14        //û��������û���������������
#define EMV_SUM_ERR       -15        //��֤������ԿУ��ʹ���
#define EMV_NOT_FOUND     -16        //û���ҵ�ָ������ݻ�Ԫ��
#define EMV_NO_DATA       -17        //ָ�������Ԫ��û�����
#define EMV_OVERFLOW      -18        //�ڴ����
 
#define EMV_DATA_EXIST    -20
#define EMV_FILE_ERR      -21
#define EMV_PIN_BLOCK     -22

#define ICC_RSP_6985      -23        // GAC�п�Ƭ����6985, ��Ӧ�þ����Ƿ�fallback
#define EMV_PARAM_ERR     -24        // EMV�������
#define EMV_CID_ERR       -25        // CDA��֤ʱ,�ָ���CID�뿨Ƭ���͵�CID��Ϣ��һ��
 
#define EMV_PED_TIMEOUT   0x01		// PED�ӿڷ��� PED_RET_ERR_INPUT_TIMEOUT
#define EMV_PED_WAIT      0x02		// PED�ӿڷ��� PED_RET_ERR_WAIT_INTERVAL
#define EMV_PED_FAIL      0x03		// PED�ӿڷ����������
 

#define ONLINE_APPROVE    0x00       //�������(������׼)	
#define ONLINE_DENIAL     0x01       //�������(����ܾ�)	
#define ONLINE_FAILED     0x02       //�������(����ʧ��)	
  
#define EMV_AC_AAC        0x00
#define EMV_AC_TC         0x01
#define EMV_AC_ARQC       0x02

#define EMV_CVM_OFF_PLAIN_PIN   0x01
#define EMV_CVM_OFF_ENCRYPT_PIN 0x02 
#define EMV_CVM_ONLINE_PIN    0x03

 
#define EMV_CVM_CMD_CANCEL   1
#define EMV_CVM_CMD_FINISHED 2
#define EMV_CVM_CMD_FAILED   3

typedef struct{
	unsigned char AppName[33];       //����Ӧ������'\x00'��β���ַ�
	unsigned char AID[17];           //�ն�AID���
	unsigned char AidLen;            //AID�ĳ���
    unsigned char SelFlag;           //ѡ���־(PART_MATCH ����ƥ��  FULL_MATCH ȫƥ��)      
	unsigned char Priority;          //���ȼ���־
	unsigned char BlackFileCheck;    // �������ʶ��1-���
	unsigned char TargetPer;         //Ŀ��ٷֱ���
	unsigned char MaxTargetPer;      //���Ŀ��ٷֱ���
 	unsigned char FloorLimitCheck;   //�Ƿ�������޶�
	unsigned char RandTransSel;      //�Ƿ���������ѡ��
	unsigned char VelocityCheck;     //�Ƿ����Ƶ�ȼ�� 
    unsigned long FloorLimit;        //����޶�
	unsigned long Threshold;         //��ֵ
 	unsigned char TACDenial[6];      //�ն���Ϊ����(�ܾ�)
	unsigned char TACOnline[6];      //�ն���Ϊ����(����)
	unsigned char TACDefault[6];     //�ն���Ϊ����(ȱʡ)
    unsigned char AcquierId[6];      //�յ��б�־
	unsigned char dDOL[256];         //�ն�ȱʡDDOL
	unsigned char tDOL[256];         //�ն�ȱʡTDOL
	unsigned char Version[3];        //Ӧ�ð汾 
}EMV_APPLIST;

typedef struct{
	unsigned char aucAppPreName[17];  //Ӧ������ѡ����ƣ���'\0'��β 
	unsigned char aucAppLabel[17];    //Ӧ�ñ�ǩ����'\0'��β 
	unsigned char aucAID[17]; 		  //��ƬAID����'\0'��β
	unsigned char ucAidLen; 		  //��ƬAID����
	unsigned char ucPriority;         //���ȼ���־
	unsigned char ucPriorityExistFlg;
}EMV_APPLABEL_LIST;

typedef struct {
	unsigned char RID[5];            //Ӧ��ע�������ID
	unsigned char KeyID;             //��Կ����
	unsigned char HashInd;           //HASH�㷨��־
	unsigned char ArithInd;          //RSA�㷨��־
	unsigned char ModulLen;          //ģ����
	unsigned char Modul[248];        //ģ
	unsigned char ExponentLen;       //ָ���
	unsigned char Exponent[3];       //ָ��
	unsigned char ExpDate[3];        //��Ч��(YYMMDD)
	unsigned char CheckSum[20];      //��ԿУ���
}EMV_CAPK;

typedef struct{
	unsigned char MerchName[256];    //�̻���
	unsigned char MerchCateCode[2];  //�̻������(ûҪ��ɲ�����)
	unsigned char MerchId[15];       //�̻���־(�̻���)
	unsigned char TermId[8];         //�ն˱�־(POS��)
	unsigned char TerminalType;      //�ն�����
	unsigned char Capability[3];     //�ն�����
	unsigned char ExCapability[5];   //�ն���չ����
	unsigned char TransCurrExp;      //���׻��Ҵ���ָ��
	unsigned char CountryCode[2];    //�ն˹�Ҵ���
	unsigned char TransCurrCode[2];  //���׻��Ҵ���
	unsigned char TransType;         //��ǰ��������(EMV_CASH EMV_GOODS EMV_SERVICE EMV_GOODS&EMV_CASHBACK EMV_SERVICE&EMV_CASHBACK)
	unsigned char GetDataPIN;        //������ǰ�Ƿ�����Դ���
	unsigned char SurportPSESel;     //�Ƿ�֧��PSEѡ��ʽ
	unsigned char TermIFDSn [8];     // IFD���к�
	
	unsigned char ucBypassAllFlg;   //whether bypass all other pin when one pin has been bypassed 1-Yes, 0-No
	unsigned char  ucBypassPin; 	//0-��֧�֣�1��֧�֣�Ĭ��֧��
	unsigned char  ucBatchCapture;  // 0-online data capture, 1-batch capture
}EMV_PARAM;

typedef  struct 
{
	unsigned char   ucRid[5];  		        // RID
	unsigned char   ucIndex;   		        // CA��Կ����
	unsigned char   ucCertSn[3];            // ������֤�����к�
}EMV_REVOCLIST;

typedef struct  EMV_GPO_DATA_STRUCT
{
    unsigned long  lAmntAuth;      // ��Ȩ���
    unsigned long  lAmntOther;     // ������
    unsigned char  tDate[3];      // ��������ָ��(3 BYTE)
    unsigned char  tTime[3];      // ����ʱ��ָ��(3 BYTE)
    unsigned char  tTrace[4];     // �������м�����(4 BYTE)    
	unsigned char  tTermUN[4];    // �ն������9F37��4BYTE)
}EMV_TRANSDATA;

//��Կ��Ӧ�ù��?����
int	EMVLIB_KernelInit(void); 
int EMVLIB_GetTLVData(unsigned short ucTag, unsigned char *ucDataOut, int *iOutLen);
int EMVLIB_SetTLVData(unsigned short ucTag, unsigned char *ucDataIn, int iDataLen);
int EMVLIB_GetScriptResult(unsigned char *ucResult, int *iRetLen);
void EMVLIB_GetParameter(EMV_PARAM *stParam);
void EMVLIB_SetParameter(EMV_PARAM *stParam);

//��Կ��Ӧ�ù��?����
int EMVLIB_AddApp(const EMV_APPLIST *App);
int EMVLIB_GetFinalApp(EMV_APPLIST *App);
int EMVLIB_DelApp(unsigned char *AID, int AidLen);
int EMVLIB_DelAllApp(void);

int EMVLIB_AddCAPK(const EMV_CAPK  *capk ); 
int EMVLIB_DelCAPK(void);

int EMVLIB_AddRevocList(EMV_REVOCLIST *pRevocList);
void EMVLIB_DelAllRevocList(void);

//���״��?����
int EMVLIB_AppSelect(int Slot, EMV_APPLABEL_LIST *pstCandList, int *pnNum);
int EMVLIB_FinalSelect(unsigned char ucAidNo, unsigned char ucReadLogFlag, EMV_APPLABEL_LIST *pstCandList, int *pnNum);
int EMVLIB_GetProcessOption(EMV_TRANSDATA  *pDtIn, EMV_APPLABEL_LIST *pstCandList, int *pnNum);
int EMVLIB_ReadAppData(void);
int EMVLIB_CardAuth(void);
int EMVLIB_TransProcess(unsigned char ucBlackFileFlag, unsigned long ulLastAmt, unsigned char *pPinTryCntOut); 
int EMVLIB_PINVerification(unsigned char ucPinEntryResult, unsigned char *pPinTryCntOut, unsigned int bypassFlag);
int EMVLIB_ActionAnalyse(unsigned char ucForceOnline, unsigned char *pACTypeOut);
int EMVLIB_OnlineDataProcess(int nCommuStatus, unsigned char *paucScriptIn, int nScriptLen, unsigned char *pACTypeOut);

//��������־
int EMVLIB_CardLogAppSlt(int Slot, unsigned char ucFlg, EMV_APPLABEL_LIST *pstCandList, int *pnNum);
int EMVLIB_ReadLogRecord(int RecordNo);
int EMVLIB_GetLogItem(unsigned short Tag, unsigned char *TagData, int *TagLen);

//���Կ��ؽӿ�
void EMVLIB_SetDebug(int EnableFlag);
 
#endif
