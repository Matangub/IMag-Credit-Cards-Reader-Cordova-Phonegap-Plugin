//
//  EMVParam.h
//
//

#import "EMVApp.h"
#import "EMVCapk.h"
#import "EMVRevoc.h"

//#define PART_MATCH			0x00	//应用选择匹配标志(部分匹配)
//#define FULL_MATCH			0x01	//应用选择匹配标志(完全匹配)
//typedef enum {
//    PART_MATCH = 0x00,      //应用选择匹配标志(部分匹配)
//    FULL_MATCH = 0x01       //应用选择匹配标志(完全匹配)
//} SELECT_FLAG;

// 标准交易类型码值
//#define EMV_TRANS_TYPE_CASH          0x01       //CASH
//#define EMV_TRANS_TYPE_GOODS	       0x00       //GOODS AND SERVICE
//#define EMV_TRANS_TYPE_CASHBACK      0x09       //CASHBACK
typedef enum {
    TRANS_TYPE_CASH = 0x01,
    TRANS_TYPE_GOODS = 0x00,
    TRANS_TYPE_CASHBACK = 0x09
} TRANS_TYPE;

#define APP_ONLINE_REFER        0x04        //联机返回码(联机参考)
#define APP_ONLINE_ABORT        4

#define APP_TRANS_DECLINE       1
#define APP_TRANS_APPROVE       2
#define APP_TRANS_TERMINATE     3

//交易处理函数返回码定义
#define STATUS_OK               0           //成功
//#define STATUS_RESELECT_APP     -1          //重新选择应用
#define STATUS_ICC_CMD_ERR      -2          //IC命令失败
#define STATUS_ICC_BLOCK        -3          //IC卡锁卡

#define STATUS_RSP_ERR          -4          //IC返回码错误
#define STATUS_APP_BLOCK        -5          //应用已锁
#define STATUS_NO_APP           -6          //卡片里没有EMV应用
#define STATUS_CANCEL           -7          //用户取消当前操作或交易

#define STATUS_TIME_OUT         -8          //用户操作超时
#define STATUS_DATA_ERR         -9          //卡片数据错误
#define STATUS_NOT_ACCEPT       -10         //交易不接受
#define STATUS_DENIAL           -11         //交易被拒绝
#define STATUS_KEY_EXP          -12         //密钥过期

//函数返回码定义
#define STATUS_NO_PINPAD        -13         //没有密码键盘或键盘不可用
#define STATUS_NO_PASSWORD      -14         //没有密码或用户忽略了密码输入
#define STATUS_SUM_ERR          -15         //认证中心密钥校验和错误
#define STATUS_NOT_FOUND        -16         //没有找到指定的数据或元素
#define STATUS_NO_DATA          -17         //指定的数据元素没有数据
#define STATUS_OVERFLOW         -18         //内存溢出

#define STATUS_DATA_EXIST       -20
#define STATUS_FILE_ERR         -21
#define STATUS_PIN_BLOCK        -22

#define STATUS_ICC_RSP_6985     -23         // GAC中卡片回送6985, 由应用决定是否fallback
#define STATUS_PARAM_ERR        -24         // EMV参数错误
#define STATUS_CID_ERR          -25         // CDA认证时,恢复的CID与卡片回送的CID信息不一致

@interface EMVParam:NSObject {
}

//unsigned char MerchName[256];    //商户名
//unsigned char MerchCateCode[2];  //商户类别码(没要求可不设置)
//unsigned char MerchId[15];       //商户标志(商户号)
//unsigned char TermId[8];         //终端标志(POS号)
//unsigned char TerminalType;      //终端类型
//unsigned char Capability[3];     //终端性能
//unsigned char ExCapability[5];   //终端扩展性能
//unsigned char TransCurrExp;      //交易货币代码指数
//unsigned char CountryCode[2];    //终端国家代码
//unsigned char TransCurrCode[2];  //交易货币代码
//unsigned char TransType;         //当前交易类型(EMV_CASH EMV_GOODS EMV_SERVICE EMV_GOODS&EMV_CASHBACK EMV_SERVICE&EMV_CASHBACK)
//unsigned char GetDataPIN;        //密码检测前是否读重试次数
//unsigned char SurportPSESel;     //是否支持PSE选择方式
//unsigned char TermIFDSn [8];     // IFD序列号

//unsigned char ucBypassAllFlg;    //whether bypass all other pin when one pin has been bypassed 1-Yes, 0-No
//unsigned char ucBypassPin;       //0-不支持，1－支持，默认支持
//unsigned char ucBatchCapture;    //0-online data capture, 1-batch capture

//unsigned long lAmntAuth;         // 授权金额
//unsigned long lAmntOther;        // 其他金额
//unsigned char tDate[3];          // 交易日期指针(3 BYTE)
//unsigned char tTime[3];          // 交易时间指针(3 BYTE)
//unsigned char tTrace[4];         // 交易序列计数器(4 BYTE)
//unsigned char tTermUN[4];        // 终端随机数（9F37，4BYTE)

-(void)setMerchName:(NSString*)merchName;
-(NSString*)getMerchName;

-(void)setMerchCateCode:(NSString*)merchCateCode;
-(NSString*)getMerchCateCode;

-(void)setMerchId:(NSString*)merchId;
-(NSString*)getMerchId;

-(void)setTermId:(NSString*)termId;
-(NSString*)getTermId;

-(void)setTerminalType:(Byte)terminalType;
-(Byte)getTerminalType;

-(void)setCapability:(NSString*)capability;
-(NSString*)getCapability;

-(void)setExCapability:(NSString*)exCapability;
-(NSString*)getExCapability;

-(void)setTransCurrExp:(Byte)transCurrExp;
-(Byte)getTransCurrExp;

-(void)setCountryCode:(NSString*)countryCode;
-(NSString*)getCountryCode;

-(void)setTransCurrCode:(NSString*)transCurrCode;
-(NSString*)getTransCurrCode;

-(void)setTransType:(TRANS_TYPE)transType;
-(TRANS_TYPE)getTransType;

//-(void)setGetDataPINCount:(Byte)getDataPinCount;
//-(Byte)getGetDataPINCount;

//-(void)setSupportPSESel:(Byte)supportPSESel;
//-(Byte)getSupportPSESel;

-(void)setTermIFDSn:(NSString*)termIFDSn;
-(NSString*)getTermIFDSn;

// whether bypass all other pin when one pin has been bypassed 1-Yes, 0-No
//-(void)setUCBypassAllFlg:(Byte)ucBypassAllFlg;
//-(Byte)getUCBypassAllFlg;

//-(void)setUCBypassPin:(Byte)ucBypassPin;
//-(Byte)getUCBypassPin;

// 0-online data capture, 1-batch capture
//-(void)setUCBatchCapture:(Byte)ucBatchCapture;
//-(Byte)getUCBatchCapture;

//-(void)setUCSupportAccountType:(Byte)ucSupportAccountType;
//-(Byte)getUCSupportAccountType;

-(void)setAuthAmnt:(long)authAmnt;
-(long)getAuthAmnt;

-(void)setOtherAmnt:(long)otherAmnt;
-(long)getOtherAmnt;

-(void)setTransDate:(NSString*)transDate;
-(NSString*)getTransDate;

-(void)setTransTime:(NSString*)transTime;
-(NSString*)getTransTime;

//-(void)setTransTrace:(NSString*)transTrace;
//-(NSString*)getTransTrace;

//-(void)setTransTermUN:(NSString*)transTermUN;
//-(NSString*)getTransTermUN;

-(void)setSlot:(Byte)slot;
-(Byte)getSlot;

-(void)setReadOnly:(Boolean)readOnly;
-(Boolean)isReadOnly;

-(void)addApp:(EMVApp*)app;
-(void)delApp:(EMVApp*)app;
-(NSMutableArray*)getApps;

-(void)addCapk:(EMVCapk*)capk;
-(void)delCapk:(EMVCapk*)capk;
-(NSMutableArray*)getCapks;

-(void)addRecov:(EMVRevoc*)revoc;
-(void)delRecov:(EMVRevoc*)revoc;
-(NSMutableArray*)getRevocs;

@end
