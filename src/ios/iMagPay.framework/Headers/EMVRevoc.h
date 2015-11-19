//
//  EMVRevoc.h
//
//

@interface EMVRevoc:NSObject {
}

//unsigned char   ucRid[5];  		        // RID
//unsigned char   ucIndex;   		        // CA公钥索引
//unsigned char   ucCertSn[3];              // 发卡行证书序列号

-(void)setUCRID:(NSString*)ucRID;
-(NSString*)getUCRID;

-(void)setUCIndex:(Byte)ucIndex;
-(Byte)getUCIndex;

-(void)setUCCertSn:(NSString*)ucCertSn;
-(NSString*)getUCCertSn;

@end
