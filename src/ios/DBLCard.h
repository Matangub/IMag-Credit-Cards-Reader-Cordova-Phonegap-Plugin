#import <UIKit/UIKit.h>
#import <Cordova/CDVPlugin.h>

#import "iMagPay/SwipeHandler.h"
#import "iMagPay/SwipeListener.h"
#import "iMagPay/Settings.h"

@interface DBLCard : CDVPlugin<SwipeListener>
{}

- (void)readCreditCard:(CDVInvokedUrlCommand*)command;

@end