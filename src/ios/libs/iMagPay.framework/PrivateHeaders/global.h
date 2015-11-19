#ifndef _GLOBAL_H_
#define _GLOBAL_H_ 1

#ifndef PROTOTYPES
#define PROTOTYPES 1
#endif

typedef unsigned char *POINTER;
typedef unsigned short int UINT2;
//typedef unsigned long int UINT4;//2015.05.04修改,在64位环境下有问题
typedef unsigned int UINT4;

#ifndef NULL_PTR
#define NULL_PTR ((POINTER)0)
#endif

#ifndef UNUSED_ARG
#define UNUSED_ARG(x) x = *(&x);
#endif

#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) (void)
#endif

#endif 
