//
//  DataAudioRecord.h
//
//

#import "AQRecorder.h"
#import "DataParser.h"
#import "FSKDataParser.h"

@interface DataAudioRecord:NSObject {
    AQRecorder *recorder;

    DataParser *dataParser;
    FSKDataParser *fskDataParser;
//    FSKDataParser *fsk1DataParser;
//    FSKDataParser *fsk2DataParser;
}

-(void)startParsing:(UInt32)sampleRate;

-(void)stop;

-(BOOL)isParsing;

-(DataParser*)getDataParser;
-(FSKDataParser*)getFSKDataParser;
//-(FSKDataParser*)getFSK1DataParser;
//-(FSKDataParser*)getFSK2DataParser;

-(void)destory;

@end