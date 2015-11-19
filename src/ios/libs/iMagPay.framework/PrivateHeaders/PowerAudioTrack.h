//
//  PowerAudioTrack.h
//
//

#import <AudioToolbox/AudioToolbox.h>
#import "AudioUtils.h"

@interface PowerAudioTrack:NSObject {
    AudioComponentInstance toneUnit;
}

/** 获取输出声道 */
-(AUDIO_CHANNEL)getOutputChannel;
/** 设置输出声道 */
-(void)setOutputChannel:(AUDIO_CHANNEL)channel;

-(void)play;
-(void)replay;

-(void)stop;

-(BOOL)isPlaying;

@end
