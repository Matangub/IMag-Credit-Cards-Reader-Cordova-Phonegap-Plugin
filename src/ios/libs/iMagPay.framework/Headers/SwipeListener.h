//
//  SwipeListener.h
//
//

#import "SwipeEvent.h"

/**
 * The listener interface for receiving "interesting" swipe events (connect,
 * disconnect, start, stop, read data, and parse data) on a reader.
 *
 * The class that is interested in processing a swipe event either implements
 * this interface (and all the methods it contains).
 *
 * The listener object created from that class is then registered with a
 * SwipeHandler using the SwipeHandler's addSwipeListener method. A swipe event
 * is generated when the reader is connected, disconnected, started work or
 * stopped work. A swipe event is also generated when read data from the reader
 * or parse the read data.
 */
@protocol SwipeListener <NSObject>

/**
 * fire after disconnected the reader
 */
-(void)onDisconnected:(SwipeEvent*)event;
    
/**
 * fire after connected the reader
 */
-(void)onConnected:(SwipeEvent*)event;
    
/**
 * fire after started the reader
 */
-(void)onStarted:(SwipeEvent*)event;
    
/**
 * fire after stopped the reader
 */
-(void)onStopped:(SwipeEvent*)event;
    
/**
 * fire after got the data from the reader.
 */
-(void)onReadData:(SwipeEvent*)event;

/**
 * fire after parsed the read data.
 */
-(void)onParseData:(SwipeEvent*)event;

@end