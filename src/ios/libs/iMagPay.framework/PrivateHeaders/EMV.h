#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CommonUtils.h"
#include "EMVHandler.h"
#include "EMVParam.h"
#include "EMVResponse.h"
#include "EmvLib_Api.h"
#include "PubSub.h"

int appCMP(const void* a, const void* b);

class EMV {
public:
    EMV();
    ~EMV();

    /********** EMV init ***************/
    void kernelInit(EMVHandler* handler, EMVParam* param);

    /******** EMV process **************/
    int process(void);
    void cancel(void);

    void setTLVData(unsigned short tag, NSString* data);
    NSString* getTLVData(unsigned short tag);
    NSString* getScriptResult(void);
    
    void setCount(long count);

    /******** Exchange APDU ************/
    NSString* getSend(void);
    int setRecv(NSString* recv);

private:
    EMVHandler* mHandler;
    EMVParam* mParam;
    NSMutableString* apdu;
    BOOL verfityFlag;
    BOOL cancelFlag;
    long count;
    
    void initTermParam(void);
    void loadAllAIDs(void);

    int addCapk(unsigned char ucIndex, unsigned char *pRid);
    int addRevoc(unsigned char ucIndex, unsigned char *pRid);

    int pinEntryProcess(int nPINEntryPath, unsigned char ucPinTryCnt);
    int readPin(PIN_TYPE type, unsigned char ucPinTryCnt);

    void bcd_to_asc(unsigned char* ascii_buf, unsigned char* bcd_buf, int conv_len, unsigned char type);
    unsigned long str_to_ulong(unsigned char* str);

    int str_to_char(NSString* data, int len, unsigned char* out);
    NSString* char_to_str(unsigned char* in, int len);
};