#ifndef _RSACALC_H_
#define _RSACALC_H_

unsigned char RsaSetPublicKey(unsigned char  cLenMod, unsigned char *pMod, unsigned char cLenExp, unsigned char *pExp);

unsigned char RsaPKeyDecrypt(unsigned char *pIn, unsigned char cLenIn, unsigned char *pOut, unsigned char *pLenOut);

int RSARecover(unsigned char *pbyModule, unsigned int dwModuleLen, unsigned char *pbyExp, unsigned int dwExpLen, unsigned char *pbyDataIn, unsigned char *pbyDataOut);
		
#endif

