#ifndef _DES_H_
#define _DES_H_
void s_DesInit(void);
extern void des(unsigned char *input,unsigned char *output,unsigned char *key,int mode);

static void scrunch(unsigned char *, unsigned long *);
static void unscrun(unsigned long *, unsigned char *);
static void desfunc(unsigned long *, unsigned long *);
static void cookey(unsigned long *);
static void deskey(unsigned char *, int);
//static void s_des(unsigned char *, unsigned char *);
static void usekey(register unsigned long *from);

unsigned char  Tdes(unsigned char* inputData,unsigned char* outputData,unsigned char* keyData,long mode,long counter);
#endif