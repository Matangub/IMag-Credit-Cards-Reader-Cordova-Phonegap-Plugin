#ifndef _EMV_COMMONVAR_H
#define _EMV_COMMONVAR_H

#include <stdio.h>
#include <string.h>
 
//#include <posapi.h>
#include "emvlib_api.h"
#include "elements.h"
#include "PubSub.h"
#include "IcCard.h"
 
#define PINKEY       0x01
#define ICPKEY       0x02

extern int k_AppNum;
extern int k_SelAppNo;
extern EMV_APPLIST k_TermAppList[MAX_APP_NUM];
extern EMV_APPLIST k_AppList[MAX_CANDLIST_NUM];
extern EMV_PARAM k_TermParam;
extern ELEMENT_DATA k_EmvData[ELEMENTS_NUM];
extern const ELEMENT_ATTR k_ElementAttr[ELEMENTS_NUM];
extern EMV_APPLABEL_LIST k_AppLabelList[MAX_CANDLIST_NUM];

extern void vInitRevocList(void);
extern int  emvCheckIssRevocList(unsigned char *pRid, unsigned char ucIndex, unsigned char *pCertSn);

extern void InitAppList(void);
extern void InitPKStatus(void);
extern void InitTLVData(void);
extern void InitElements(void);

extern int  InitCAPKList(void);

extern int  SDAAuth(void);
extern int  DDAAuth(void);
extern int  GetICPK(int flag);
extern int  EncryptPin(unsigned char *pin, int *len);
extern int  CDAAuth(unsigned char *pCDAData, int nCDADataLen);
extern int  emvSaveTLVData(unsigned short Tag, unsigned char *Data, int len, int UniqueFlag);
extern int  ProcDOL(unsigned char *DOL, unsigned char *DOLEnd,unsigned char *OutDat, int *OutLen);
extern int  AnalyseTLV(unsigned char *dat, unsigned char *endptr, int UniqueFlag);
extern int CheckTLV(unsigned char *dat, int len); 
extern int CheckTagTempValid(unsigned char *ucData, unsigned char *ucDataEnd, unsigned short *TagList, int TagListLen);
 
extern int nGetPinKey(RSA_PINKEY *RsaPinKey);

unsigned char emvSetNoBlockAppFlg(unsigned char ucFlg);
unsigned char emvGetNoBlockAppFlg(void);

extern unsigned char IccGetSlot(void);

#endif

