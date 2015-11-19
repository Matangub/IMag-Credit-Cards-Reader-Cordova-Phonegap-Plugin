//
//  SwipeEvent.h
//
//

typedef enum {
    /** Event type: reader disconnected */
	EVENT_TYPE_DISCONNECTED = 1,
	/** Event type: reader connected */
	EVENT_TYPE_CONNECTED = 2,
	/** Event type: reader started */
	EVENT_TYPE_STARTED = 3,
	/** Event type: reader stopped */
	EVENT_TYPE_STOPPED = 4,
	/** Event type: read data from reader */
	EVENT_TYPE_READDATA = 5,
	/** Event type: parse data */
	EVENT_TYPE_PARSEDATA = 6
} EVENT_TYPE;

/**
 * This class represents a swipe event and holds informations such as the event
 * type, the source, and the data.
 */
@interface SwipeEvent:NSObject {
}

-(void)setType:(int)type;
/**
 * Returns the event type
 */
-(int)getType;

-(void)setValue:(NSString*)value;
/**
 * Returns the event data
 */
-(NSString*)getValue;

@end