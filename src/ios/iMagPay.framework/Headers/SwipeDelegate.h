//
//  SwipeDelegate.h
//
//

@protocol SwipeDelegate <NSObject>

-(void)onReadData:(NSString*)value;
-(void)onParseData:(NSString*)value;

@end
