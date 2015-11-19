//
//  Settings.h
//
//

#import "SwipeHandler.h"
#import "audiotest.h"
#import "des.h"
#import "StringUtils.h"

typedef enum {
    /** Data Mode: Plain text output */
    TYPE_PLAINTEX   = 1,
    /** Data Mode: 3DES encryption */
    TYPE_3DES       = 2,
    /** Data Mode: DUKPT encryption */
    TYPE_DUKPT      = 3,
    /** Data Mode: DUKPT_HSM encryption */
    TYPE_DUKPT_HSM  = 4
} DATA_MODE;

typedef enum {
    /** Track Mode: Only read track 1 data */
    TRACK_1         = 1,
    /** Track Mode: Only read track 2 data */
    TRACK_2         = 2,
    /** Track Mode: Read track 1 and track 2 data */
    TRACK_BOTH      = 3
} TRACK_MODE;

typedef enum {
    /** Slot of Contactless IC Card */
    SLOT_IC = 0,
    /** Slot of Non-contact IC Card */
    SLOT_RF = 5,
    /** Slot of Mifare1 Card  */
    SLOT_M1 = 6
} SLOT_TYPE;

typedef enum {
    PIN_TYPE_PLAIN_TEXT = 2,
    PIN_TYPE_3DES = 1,
    PIN_TYPE_DUKPT = 0
} PIN_DATA_TYPE;

typedef enum {
    /** Write plain text APDU and Get plain text response */
	APDU_WP_RP = 1,
	/** Write plain text APDU and Get 3DES encryption response */
	APDU_WP_R3DES = 2,
	/** Write plain text APDU and Get DUKPT encryption response */
	APDU_WP_RDUKPT = 3,
	/** Write 3DES encryption APDU and Get 3DES encryption response */
	APDU_W3DES_R3DES = 4,
	/** Write DUKPT encryption APDU and Get DUKPT encryption response */
	APDU_WDUKPT_RDUKPT = 5
} APDU_DATA_MODE;

typedef enum{
    EMV_DATA_ENCRYPT =1,
    EMV_DATA_DECRYPT =2
}EMV_DATA_TYPE;

@interface Settings:NSObject {
}

//  if use SwipeHander.h of new api, call the function, not call setAudioTest function
-(void)setSwipeHandler:(SwipeHandler*)swipeHandler;
//  if use audiotest.h of old api, call the function, not call setSwipeHandler function
-(void)setAudioTest:(audiotest*)audioTest;

// Write command to the reader(Non-blocking communication)
-(BOOL)writeCipherCode:(NSString*)cipherCode;

// Write command to the reader and wait the response from the reader. if the reader does not return any data over timeout value, it will return nil. if the retry count is greater than 0, it will try to rewrite.(Blocking communication)
-(NSString*)getDataWithCipherCode:(NSString*)cipherCode;

//  Write get version command
-(BOOL)writeVersion;

//  Write get sn command
-(BOOL)writeGetSN;

//  Write data mode
-(BOOL)writeMode:(DATA_MODE)mode;

//  Write read mode. Reader can be set for only read track 1 or only read track 2 or read both
-(BOOL)writeReadMode:(TRACK_MODE)mode;

//  Write speed mode
//  Write speed mode: W8R1FSK or W8R2FSK. W8R2FSK is faster than W8R1FSK. W8R2FSK will work well on iOS, but it is not good on Android.
//  So if the reader need to work on Android, do not use W8R2FSK. the default of reader is W8R1FSK)
-(BOOL)writeSpeedMode:(SPEED_MODE)mode;

//  Write 3DES key
//  key is 32 digits of hex string, like "aa aa aa aa bb bb bb bb cc cc cc cc dd dd dd dd"
-(BOOL)writeDESKey:(NSString*)key;

//  Write DUKPT BDK and KSN
//  bdk is 32 digits of hex string. it can be a random hex string. like "aa aa aa aa bb bb bb bb cc cc cc cc dd dd dd dd"
//  ksn is 20 digits of hex string. the first 6 digits can be a random hex string, then 8 digits can be a sequence hex string,
//     then the last 6 digits is "000000". like "11 22 33 00 00 00 01 00 00 00"
-(BOOL)writeDUKPTKey:(NSString*)bdk :(NSString*)ksn;

//  Write lock command. Be careful： after successfully written, the reader can not be changed
-(BOOL)writeLock;

//  Write unlock command. if the reader is locked, administrator need to call the function and unlock the reader,
//      then can write command to reader. The unlocked is temporary. after off and on, administrator can not write key.
//  key is the frist 20 digits of bdk. if bdk is "aa aa aa aa bb bb bb bb cc cc cc cc dd dd dd dd",
//      key is "aa aa aa aa bb bb bb bb cc cc"
-(BOOL)writeUnlock:(NSString*)key;

//  Write unlock command. if the reader is locked, administrator need to call the function and unlock the reader,
//      then can write command to reader. The unlocked is forever. after off and on, administrator can write key too.
//  key is the frist 20 digits of bdk. if bdk is "aa aa aa aa bb bb bb bb cc cc cc cc dd dd dd dd",
//      key is "aa aa aa aa bb bb bb bb cc cc"
-(BOOL)writeForeverUnlock:(NSString*)key;

//  Write SN to reader. SN is 26 digits hex string, like XX XX XX XX XX XX XX XX XX XX XX XX XX {LRC} 00 00
//  LRC is 0xXX^0xXX^0xXX^0xXX^0xXX^0xXX^0xXX^0xXX^0xXX^0xXX^0xXX^0xXX^0xXX
//  eg. 20 12 10 10 00 10 00 00 00 00 00 00 00 22 00 00
-(BOOL)writeSN:(NSString*)sn;

//  Format SN. SN max length is 26. if SN is 20121010001, call formatSN,
//  it will return "20 12 10 10 00 1f ff ff ff ff ff ff ff 22 00 00"
-(NSString*)formatSN:(NSString*)sn;

//  Write get data command. so reader will re－send data
-(BOOL)writeGetData;

//  Write get battery command. so EMV reader will response the battery value
//  max battery:0c
//  min battery:01
-(BOOL)writeGetBattery;

//  Write get ksn command. app should use the ksn and finish a full emv process.
//  the funcion is for writeAPDU or getDataWithAPDU
-(BOOL)writeGetKSN;

//  Write reset
-(BOOL)writeReset:(SLOT_TYPE)slot;

//  Write off
-(BOOL)writeOff:(SLOT_TYPE)slot;

//  Write IC reset
-(BOOL)writeICReset;

//  Write IC random
-(BOOL)writeICRandom;

//  Write IC EMV
-(BOOL)writeICEMV;

//  Write IC off
-(BOOL)writeICOff;

//  Write APDU(Non-blocking communication)
//  apdu like 00 b2 01 0c 00
-(BOOL)writeAPDU:(NSString*)apdu;

//  Write APDU(Non-blocking communication)
//  slot is the specified slot of reader. 0~FF
//  apdu like 00 b2 01 0c 00
-(BOOL)writeAPDU:(int)slot :(NSString*)apdu;

//  Write APDU(Non-blocking communication)
//  type is the specified type of data trans. See APDU_WP_RP/APDU_WP_R3DES/APDU_WP_RDUKPT/APDU_W3DES_R3DES/APDU_WDUKPT_RDUKPT
//  slot is the specified slot of reader. 0~FF
//  apdu like 00 b2 01 0c 00
-(BOOL)writeAPDU:(APDU_DATA_MODE)type :(int)slot :(NSString*)apdu;

//  Write get sn command and wait the response. so EMV reader will return the sn
-(NSString*)getSN;

//  Write get battery command and wait the response. so EMV reader will return the battery value
//  max battery:0c
//  min battery:01
-(NSString*)getBattery;

//  Write get ksn command and wait the response. so EMV reader will return
//  current ksn. app should use the ksn and finish a full emv process. the
//  funcion is for writeAPDU or getDataWithAPDU
-(NSString*)getKSN;

//  Write reset and wait the response
-(NSString*)reset:(SLOT_TYPE)slot;

//  Write off and wait the response
-(NSString*)off:(SLOT_TYPE)slot;

//  Write IC reset and wait the response
-(NSString*)icReset;

//  Write IC random and wait the response
-(NSString*)icRandom;

//  Write IC EMV and wait the response
-(NSString*)icEMV;

//  Write IC off and wait the response
-(NSString*)icOff;

//  Write APDU and Wait the response, see the getDataWithCipherCode of SwipeHandler(Blocking communication)
//  apdu like 00 b2 01 0c 00
-(NSString*)getDataWithAPDU:(NSString*)apdu;

//  Write APDU and Wait the response, see the getDataWithCipherCode of SwipeHandler(Blocking communication)
//  slot is the specified slot of reader. 0~FF
//  apdu like 00 b2 01 0c 00
-(NSString*)getDataWithAPDU:(int)slot :(NSString*)apdu;

//  Write APDU and Wait the response, see the getDataWithCipherCode of SwipeHandler(Blocking communication)
//  type is the specified type of data trans. See APDU_WP_RP/APDU_WP_R3DES/APDU_WP_RDUKPT/APDU_W3DES_R3DES/APDU_WDUKPT_RDUKPT
//  slot is the specified slot of reader. 0~FF
//  apdu like 00 b2 01 0c 00
-(NSString*)getDataWithAPDU:(APDU_DATA_MODE)type :(int)slot :(NSString*)apdu;

-(NSString*)pinOpen:(PIN_DATA_TYPE)type;

-(NSString*)pinClose;

-(NSString*)clearPinData;

-(NSString*)getPinData;

-(NSString*)getEncryptKSN;

-(int)getPinCount;

-(NSString*)intToHexString:(int)value;
-(int)hexStringToInt:(NSString*)value;

//For弘达上业
-(BOOL)writeTMK:(NSString*)auKey :(NSString*)data;

-(NSString*)getEncryptedPIN:(NSString*)pan :(NSString*)pin;

-(NSString*)getMACBlock:(NSString*)data;

-(BOOL)writeSignIn:(NSString*)data;
//For弘达上业
@end
