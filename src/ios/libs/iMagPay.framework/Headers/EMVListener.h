//
//  EMVListener.h
//
//

#import "EMVResponse.h"

typedef enum {
    OFFLINE_PLAIN_PIN = 0x01,
    OFFLINE_ENCRYPT_PIN = 0x02,
    ONLINE_PIN = 0x03
} PIN_TYPE;

@protocol EMVListener <NSObject>

-(int)onSelectApp:(NSMutableArray*)apps;

-(BOOL)onReadData;

-(NSString*)onReadPin:(PIN_TYPE)type :(int)ucPinTryCnt;

-(EMVResponse*)onSubmitData;

-(void)onConfirmData;

-(void)onReversalData;

@end