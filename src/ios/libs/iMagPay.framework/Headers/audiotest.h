//
//  audiotest.h
//  Version 3.2
//

#import <UIKit/UIKit.h>
#import "SwipeDelegate.h"

@interface audiotest:UIViewController<SwipeDelegate> {
}

-(void)Swipeinitialization;

-(NSString *)Swipedetect;
-(BOOL)Swipereaddata:(uint8_t*)data connector:(uint8_t*)ctype;

-(int)Parsedata:(NSString*)inputdata;
-(void)Writeciphercode;

-(int)Checkheadphonestatus;

-(void)Poweron;
-(void)PowerOff;
-(BOOL)Powerstatus;

-(BOOL)Clearbuffer;

-(void)dealloc;

@end