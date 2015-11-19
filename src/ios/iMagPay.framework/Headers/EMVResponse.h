//
//  EMVResponse.h
//
//

#define ONLINE_APPROVE          0x00// 联机返回码(联机批准)
#define ONLINE_DENIAL           0x01// 联机返回码(联机拒绝)
#define ONLINE_FAILED           0x02// 联机返回码(联机失败)

@interface EMVResponse:NSObject {
}

-(void)setARC:(NSString*)arc;
-(NSString*)getARC;

-(void)setIAD:(NSString*)iad;
-(NSString*)getIAD;

-(void)setScript:(NSString*)script;
-(NSString*)getScript;

-(void)setStatus:(int)status;
-(int)getStatus;

@end
