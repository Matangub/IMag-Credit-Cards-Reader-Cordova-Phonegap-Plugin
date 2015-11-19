//
//  DataParser.h
//
//

#import "SwipeDelegate.h"

@interface DataParser:NSThread {
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

//-(UInt32)getUnitNum:(UInt32)sampleRate;
//-(UInt32)getTotalNum:(UInt32)sampleRate;
//-(NSMutableString*)reverseString:(NSMutableString*)data;

-(void)destory;

@end
