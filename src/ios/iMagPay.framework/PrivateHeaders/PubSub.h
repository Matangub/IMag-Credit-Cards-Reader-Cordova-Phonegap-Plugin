#ifndef _PUBSUB_H
#define _PUBSUB_H

#include "Devdefine.h"

//#define DEBUG_PORT_NO			COM1	//串口调试信息输出使用的端口号

//unsigned char Dev_PortOpen(unsigned char channel, unsigned char *Attr);
//unsigned char Dev_PortClose(unsigned char channel);
//unsigned char Dev_PortSend(unsigned char channel, unsigned char ch);

void Dev_GetRand(unsigned char *buf, int len);
int Dev_GetPlainPin(unsigned char *pszPlainPin); // 20130710
int Dev_PedVerifyPlainPin (unsigned char IccSlot, unsigned char *ExpPinLenIn, unsigned char *IccRespOut, unsigned char Mode, unsigned long TimeoutMs);
int Dev_PedVerifyCipherPin (unsigned char IccSlot, unsigned char *ExpPinLenIn, RSA_PINKEY *RsaPinKeyIn, unsigned char *IccRespOut, unsigned char Mode, unsigned long TimeoutMs);
void Dev_Hash(unsigned char* DataIn, unsigned int DataInLen, unsigned char* DataOut);
int Dev_RSARecover(unsigned char *pbyModule, unsigned int dwModuleLen, unsigned char *pbyExp, unsigned int dwExpLen, unsigned char *pbyDataIn, unsigned char *pbyDataOut);
unsigned char Dev_IccIsoCommand(unsigned char slot, APDU_SEND *ApduSend, APDU_RESP *ApduRecv);

unsigned char IccIsoCommand(unsigned char slot, APDU_SEND *ApduSend, APDU_RESP *ApduRecv);
int GetPlainPin(unsigned char *pszPlainPin);

void vTwoOne(unsigned char *in, unsigned short in_len, unsigned char *out);
void vOneTwo(unsigned char *One, unsigned short len, unsigned char *Two);
void InitSeed(void);
int CheckTempValid(unsigned char *dat, unsigned char *datend);
unsigned char *SearchTLV(int DolList,unsigned short Tag, unsigned char *dat, unsigned char *enddat, int *TagLen);
void LongToStr(unsigned long ldat, unsigned char *str);
unsigned long StrToLong(unsigned char *str);
 
#endif
