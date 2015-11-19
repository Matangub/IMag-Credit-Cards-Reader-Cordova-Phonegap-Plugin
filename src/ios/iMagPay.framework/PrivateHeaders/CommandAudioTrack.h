//
//  CommandAudioTrack.h
//
//

#import <AudioToolbox/AudioToolbox.h>
#import <math.h>
#import "AudioUtils.h"

#ifndef ONE_COMMAND_LENGTH
    #define ONE_COMMAND_LENGTH (12)
#endif

@interface CommandAudioTrack:NSObject {
    NSMutableArray *commandQueue;
    AudioComponentInstance toneUnit;
}

@property (strong, nonatomic) NSMutableArray *commandQueue;

/** 获取输出声道 */
-(AUDIO_CHANNEL)getOutputChannel;
/** 设置输出声道 */
-(void)setOutputChannel:(AUDIO_CHANNEL)channel;

-(void)play;

-(void)stop;

-(BOOL)isPlaying;
-(void)setHighSpeed:(BOOL)value;
-(BOOL)isHighSpeed;

-(void)send:(NSString*)hexString;

@end