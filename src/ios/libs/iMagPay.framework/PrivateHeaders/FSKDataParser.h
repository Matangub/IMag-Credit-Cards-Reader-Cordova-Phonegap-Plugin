//
//  FSKDataParser.h
//
//

#import "SwipeDelegate.h"

@interface FSKDataParser:NSThread {
    id<SwipeDelegate> mSwipeDelegate;
}

@property(nonatomic, retain) id<SwipeDelegate> mSwipeDelegate;

//-(void)reset;
-(void)addData:(NSData*)data;

-(void)startParsing;

-(BOOL)isParsing;
-(BOOL)isReady;

//-(void)parse:(NSData*)nsdata;
//-(void)parseData:(UInt32)length;
//-(void)decode:(NSString*)data;

//-(NSMutableString*)reverseString:(NSMutableString*)data;

-(void)destory;

@end
