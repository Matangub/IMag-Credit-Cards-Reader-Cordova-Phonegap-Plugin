//
//  SwipeHandler.h
//  Version 3.2
//

#import "SwipeDelegate.h"
#import "SwipeListener.h"

typedef enum {
    // Speed Mode: write 8X & read 1X
    SPEED_W8R1FSK = 1,
    // Speed Mode: write 8X & read 2X
    SPEED_W8R2FSK = 2
} SPEED_MODE;

@interface SwipeHandler:NSObject<SwipeDelegate> {
    id<SwipeListener> mSwipeListener;
}

@property(nonatomic, retain) id<SwipeListener> mSwipeListener;

// Detect if the data is ready for receiving. This method could be used to detect whether swipe operation is done or not. if returns YES, user can swipe card
-(BOOL)detect;
// Returns the reader connection status. if returns YES, the reader is connected
-(BOOL)isConnected;

// Returns auto start flag. if returns YES, SwipeHandler will call powerOn function when user insert the reader
-(BOOL)isAutoStart;
// Set auto start flag. if sets YES, SwipeHandler will call powerOn function when user insert the reader. Default is YES
-(void)setAutoStart:(BOOL)value;

// Returns the reader power on status. if returns YES, the reader is on
-(BOOL)isPowerOn;

// Power on the reader and the reader will work with default speed mode
-(void)powerOn;
// Power on the reader and the reader will work with speed mode. SPEED_MODE have two types: SPEED_W8R1FSK and SPEED_W8R2FSK. default is SPEED_W8R1FSK. SPEED_W8R2FSK is faster than SPEED_W8R1FSK about the data transmission(from reader to phone), but SPEED_W8R2FSK can not work on android and only work on iOS. if you want the reader to work with SPEED_W8R2FSK, you need to call [settings writeSpeedMode:SPEED_W8R2FSK] before you call [handler powerOn:SPEED_W8R2FSK]. you can call [handler powerOn:SPEED_W8R1FSK] and resume the reader，let it work on android and iOS. if not, you only can call [handler powerOn:SPEED_W8R2FSK] at next time.
-(void)powerOn:(SPEED_MODE)mode;
// Power off the reader and the reader will be stop work
-(void)powerOff;

//SPEED_MODE have two types: SPEED_W8R1FSK and SPEED_W8R2FSK. default is SPEED_W8R1FSK. SPEED_W8R2FSK is faster than SPEED_W8R1FSK about the data transmission(from reader to phone), but SPEED_W8R2FSK can not work on android and only work on iOS.  if you want the reader to work with SPEED_W8R2FSK, you need to call [settings writeSpeedMode:SPEED_W8R2FSK] before you call [handler changeSpeedMode:SPEED_W8R2FSK]. you can call [handler changeSpeedMode:SPEED_W8R1FSK] and resume the reader，let it work on android and iOS. if not, you only can call [handler powerOn:SPEED_W8R2FSK] at next time.
-(void)changeSpeedMode:(SPEED_MODE)mode;

// Write command to the reader(Non-blocking communication)
-(BOOL)writeCipherCode:(NSString*)cipherCode;

// Set the timeout value for the function of getDataWithCipherCode. default is 5s
-(void)setTimeout:(UInt32) timeout;
// Set the retry count for the function of getDataWithCipherCode. default is 0
-(void)setRetryCount:(UInt32) retryCount;
// Write command to the reader and wait the response from the reader. if the reader does not return any data over timeout value, it will return nil. if the retry count is greater than 0, it will try to rewrite.(Blocking communication)
-(NSString*)getDataWithCipherCode:(NSString*)cipherCode;

// Called before the app is destroyed. That is the final call and release
-(void)destroy;

@end