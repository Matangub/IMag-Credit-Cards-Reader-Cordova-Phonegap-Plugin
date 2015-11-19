//
//  EMVHandler.h
//  Version 3.2
//

#import <string.h>
#import "SwipeHandler.h"
#import "Settings.h"
#import "EMVListener.h"
#import "EMVParam.h"

@interface EMVHandler:SwipeHandler {
    id<EMVListener> mEMVDelegete;
}

@property(nonatomic, retain) id<EMVListener> mEMVListener;

-(void)setShowAPDU:(BOOL)showAPDU;

-(BOOL)isShowAPDU;

-(BOOL)isRunning;

-(void)setEncrypt:(BOOL)encryptFlag;

-(BOOL)isEncrypt;

-(int)getEmvType;

-(void)setEmvType:(int)emvType;

-(void)cancel;

-(int)getStatus;

-(NSString*)getKSN;

-(void)setMessage:(NSString*)msg;
-(NSString*)getMessage;

-(void)kernelInit:(EMVParam*)param;

-(NSString*)icReset;

-(int)process;

-(void)icOff;

-(void)setTLVData:(unsigned short)tag :(NSString*)data;

-(NSString*)getTLVData:(unsigned short)tag;

-(NSString*)getScriptResult;

-(int)onSelectApp:(NSMutableArray*)apps;

-(BOOL)onReadData;

-(NSString*)onReadPin:(PIN_TYPE)type :(int)ucPinTryCnt;

-(EMVResponse*)onSubmitData;

-(void)onConfirmData;

-(void)onReversalData;

@end