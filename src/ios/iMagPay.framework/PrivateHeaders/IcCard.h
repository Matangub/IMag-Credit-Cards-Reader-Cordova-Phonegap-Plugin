#ifndef _ICCARD_H
#define _ICCARD_H
 
#define ICC_NO_RECORD     -30

#define GAC_AAC           0x00
#define GAC_TC            0x40
#define GAC_ARQC          0x80
#define GAC_CDA           0x10

#define GDATA_ATC         0x36
#define GDATA_LATC        0x13
#define GDATA_PTC         0x17
#define GDATA_LOG         0x4F

#define PLAIN_PIN         0x80
#define ENCRYPT_PIN       0x88
 
void IccSetSlot(int Slot);
int  IccExternalAuth(unsigned char *dat, int len);
int  IccGenerateAC(unsigned char p1, unsigned char *DatIn, int InLen, unsigned char *DataOut, int *OutLen);
int  IccGetChallenge(unsigned char *Challenge);
int  IccGetData(unsigned char p2, unsigned char *DataOut, int *OutLen);
int  IccGetProcOptions(unsigned char *Pdol, int DolLen, unsigned char *OutData, int *OutLen);
int  IccInteralAuth(unsigned char *AuthData, int DatLen, unsigned char *OutData, int *OutLen);
int  IccReadRecord(int Num, unsigned char SFI, unsigned char *OutData, int *OutLen);
int  IccVerify(int PinType, unsigned char *Pin, int PinLen, unsigned char *pSWOut);
int  IccSelect(int FirstSel,unsigned char *fname, int fLen, unsigned char *OutData, int *OutLen);
int  IccProcScript(unsigned char *cmd, int len);

#endif
