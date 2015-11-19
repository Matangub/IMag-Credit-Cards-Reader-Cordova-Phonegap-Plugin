//
//  EMVCapk.h
//
//

@interface EMVCapk:NSObject {
}

//unsigned char RID[5];            //应用注册服务商ID
//unsigned char KeyID;             //密钥索引
//unsigned char HashInd;           //HASH算法标志
//unsigned char ArithInd;          //RSA算法标志
//unsigned char ModulLen;          //模长度
//unsigned char Modul[248];        //模
//unsigned char ExponentLen;       //指数长度
//unsigned char Exponent[3];       //指数
//unsigned char ExpDate[3];        //有效期(YYMMDD)
//unsigned char CheckSum[20];      //密钥校验和

-(void)setRID:(NSString*)rid;
-(NSString*)getRID;

-(void)setKeyId:(Byte)keyId;
-(Byte)getKeyId;

//-(void)setHashInd:(Byte)hashInd;
//-(Byte)getHashInd;

//-(void)setArithInd:(Byte)arithInd;
//-(Byte)getArithInd;

//-(void)setModulLen:(Byte)modulLen;
//-(Byte)getModulLen;

-(void)setModul:(NSString*)modul;
-(NSString*)getModul;

//-(void)setExponentLen:(Byte)exponentLen;
//-(Byte)getExponentLen;

-(void)setExponent:(NSString*)exponent;
-(NSString*)getExponent;

-(void)setExpDate:(NSString*)expDate;
-(NSString*)getExpDate;

-(void)setCheckSum:(NSString*)checkSum;
-(NSString*)getCheckSum;

@end
