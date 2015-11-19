//
//  AudioUtils.h
//
//

#import <MediaPlayer/MPMusicPlayerController.h>

typedef enum {
    LEFT_CHANNEL    = 0,
    RIGHT_CHANNEL   = 1,
    DOUBLE_CHANNEL  = 2
} AUDIO_CHANNEL;

@interface AudioUtils:NSObject {
}

+(void)maxVolume;
+(float)backupVolume;
+(float)restoreVolume;
+(void)disableVolumeSlider;

@end
