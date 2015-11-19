#ifndef _DEVDEFINE_H
#define _DEVDEFINE_H

typedef struct{
   	unsigned char Command[4];
   	unsigned short Lc;
   	unsigned char  DataIn[512];
   	unsigned short Le;
}APDU_SEND;

typedef struct{
	unsigned short LenOut;
   	unsigned char  DataOut[512];
   	unsigned char  SWA;
   	unsigned char  SWB;
}APDU_RESP;

typedef struct
{
     unsigned int  modlen;          //PIN加密公钥模数长
     unsigned char mod[256];        //PIN加密公钥模数,不足位前补0x00
     unsigned char exp[4];          //PIN加密公钥指数,不足位前补0x00
     unsigned char iccrandomlen;    //从卡行取得的随机数长
     unsigned char iccrandom[8];    //从卡行取得的随机数
}RSA_PINKEY;

#define PED_RET_ERR_INPUT_CANCEL  -1
#define PED_RET_ERR_NO_ICC        -2
#define PED_RET_ERR_ICC_NO_INIT   -3
#define PED_RET_ERR_NO_PIN_INPUT  -4
#define PED_RET_ERR_INPUT_TIMEOUT -5

#endif
