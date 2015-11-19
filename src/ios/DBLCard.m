#import <Cordova/CDV.h>
#import "DBLCard.h"

@interface DBLCard () {
    NSString* callbackId;
}
@end

@implementation DBLCard

- (void)readCreditCard:(CDVInvokedUrlCommand *)command {
    self->callbackId = command.callbackId;
    
    SwipeHandler *handler = [[SwipeHandler alloc] init];
    handler.mSwipeListener = self;
    
    Settings *settings = [[Settings alloc] init];
    [settings setSwipeHandler:handler];
    
    if ([handler isConnected] == YES) {
        [handler powerOn];
    }
    
    NSLog(@"readCreditCard");
}

- (void)onConnected:(SwipeEvent*)event {
    NSLog(@"Connected.");
}

- (void)onStarted:(SwipeEvent*)event {
    NSLog(@"Started.");
}

- (void)onStopped:(SwipeEvent*)event {
    NSLog(@"Stopped.");
}

- (void)onDisconnected:(SwipeEvent*)event {
    NSLog(@"Disconnected.");
}

- (void)onReadData:(SwipeEvent*)event
{}

- (void)onParseData:(SwipeEvent*)event {
    NSMutableArray *data = [NSMutableArray arrayWithArray:
                            [[event getValue] componentsSeparatedByString:@" "]];
    
    NSLog(@"hex data: %@", [event getValue]);
    
    NSUInteger i = 0;
    for (id stringHex in [data copy]) {
        unsigned asciiCode = 0;
        
        NSScanner *scanner = [NSScanner scannerWithString:stringHex];
        [scanner scanHexInt:&asciiCode];
        
        [data replaceObjectAtIndex:i withObject:[NSString stringWithFormat:@"%c", asciiCode]];
        
        i++;
    }
    
    NSString *deviceResult = [data componentsJoinedByString:@""];
    if (![deviceResult hasPrefix:@";"]) {
        return;
    }
    NSLog(@"deviceResult: %@", deviceResult);
    
    NSString *creditCardNumber = [deviceResult substringWithRange:NSMakeRange(1, [deviceResult rangeOfString:@"="].location - 1)];
    NSString *expDate = [deviceResult substringWithRange:NSMakeRange([deviceResult rangeOfString:@"="].location+1,4)];
    NSString *cardHolder = [deviceResult substringFromIndex: [deviceResult rangeOfString:@"="].location+5];
    
    NSLog(@"creditCardNumber: %@", creditCardNumber);
    NSLog(@"expDate: %@", expDate);
    NSLog(@"cardHolder: %@", cardHolder);
    
    NSString *fullData = [NSString stringWithFormat:@"%@/%@/%@", creditCardNumber, cardHolder, expDate];
    NSLog(@"fullData: %@", fullData);
    
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:fullData];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self->callbackId];
}

@end
