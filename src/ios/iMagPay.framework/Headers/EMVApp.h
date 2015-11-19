//
//  EMVApp.h
//
//

typedef enum {
    PART_MATCH = 0x00,      //应用选择匹配标志(部分匹配)
    FULL_MATCH = 0x01       //应用选择匹配标志(完全匹配)
} SELECT_FLAG;

@interface EMVApp:NSObject {
}

// unsigned char AppName[33];       //本地应用名，以'\x00'结尾的字符串
// unsigned char AID[17];           //终端AID名称
// unsigned char AidLen;            //AID的长度
// unsigned char SelFlag;           //选择标志(PART_MATCH 部分匹配  FULL_MATCH 全匹配)
// unsigned char Priority;          //优先级标志
// unsigned char BlackFileCheck;    //黑名单检查标识：1-检查
// unsigned char TargetPer;         //目标百分比数
// unsigned char MaxTargetPer;      //最大目标百分比数
// unsigned char FloorLimitCheck;   //是否检查最低限额
// unsigned char RandTransSel;      //是否进行随机交易选择
// unsigned char VelocityCheck;     //是否进行频度检测
// unsigned long FloorLimit;        //最低限额
// unsigned long Threshold;         //阈值
// unsigned char TACDenial[6];      //终端行为代码(拒绝)
// unsigned char TACOnline[6];      //终端行为代码(联机)
// unsigned char TACDefault[6];     //终端行为代码(缺省)
// unsigned char AcquierId[6];      //收单行标志
// unsigned char dDOL[256];         //终端缺省DDOL
// unsigned char tDOL[256];         //终端缺省TDOL
// unsigned char Version[3];        //应用版本

-(void)setAppName:(NSString*)appName;
-(NSString*)getAppName;

-(void)setAID:(NSString*)aid;
-(NSString*)getAID;

//-(void)setAIDLen:(Byte)aidLen;
//-(Byte)getAIDLen;

-(void)setSelFlag:(SELECT_FLAG)selFlag;
-(SELECT_FLAG)getSelFlag;

-(void)setPriority:(Byte)priority;
-(Byte)getPriority;

//-(void)setBlackFileCheck:(Byte)blackFileCheck;
//-(Byte)getBlackFileCheck;

-(void)setTargetPer:(Byte)targetPer;
-(Byte)getTargetPer;

-(void)setMaxTargetPer:(Byte)maxTargetPer;
-(Byte)getMaxTargetPer;

-(void)setFloorLimitCheck:(Byte)floorLimitCheck;
-(Byte)getFloorLimitCheck;

//-(void)setRandTransSel:(Byte)randTransSel;
//-(Byte)getRandTransSel;

//-(void)setVelocityCheck:(Byte)velocityCheck;
//-(Byte)getVelocityCheck;

-(void)setFloorLimit:(long)floorLimit;
-(long)getFloorLimit;

-(void)setThreshold:(long)threshold;
-(long)getThreshold;

-(void)setTACDenial:(NSString*)tacDenial;
-(NSString*)getTACDenial;

-(void)setTACOnline:(NSString*)tacOnline;
-(NSString*)getTACOnline;

-(void)setTACDefault:(NSString*)tacDefault;
-(NSString*)getTACDefault;

-(void)setAcquierId:(NSString*)acquierId;
-(NSString*)getAcquierId;

-(void)setDDOL:(NSString*)dDOL;
-(NSString*)getDDOL;

-(void)setTDOL:(NSString*)tDOL;
-(NSString*)getTDOL;

-(void)setVersion:(NSString*)version;
-(NSString*)getVersion;

@end
