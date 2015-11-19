//
//  M1Helper.h
//  iMagPay
//
//  Created by zheng wei on 15/1/25.
//  Copyright (c) 2015年 szzcs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Settings.h"
/*PassWord Type of M1 card*/
typedef  enum{
    PWD_TYPE_A = 0,
    PWD_TYPE_B = 1,
    PWD_TYPE_C = 2
} M1_PWD_TYPE;

@interface M1Helper : NSObject

/*Get the command of set auto read*/
-(NSString *)getSetAutoReadCommand;
/* Get the command of set manual read*/
-(NSString *)getSetManualReadCommand;
/**
 * Get the command of check password
 *
 * @param blockIdx
 *            the block index
 * @param pwdType
 *            the password type(PWD_TYPE_0A or PWD_TYPE_0B)
 * @param pwd
 *            the password on the block. 12 digits. M1 card default value is
 *            ff ff ff ff ff ff
 * @return String
 */
-(NSString *)getCheckPWDCommand:(int)blockIdx :(M1_PWD_TYPE)pwdType :(NSString *)pwd;

-(NSString *)getReadBlockCommand:(int)blockIdx;

-(NSString *)getWriteBlockCommand:(int)blockIdx :(NSString *)data;

-(NSString *)getReadAmountCommand:(int)blockIdx;

-(NSString *)getWriteAmountCommand:(int)blockIdx :(int)amount;

-(NSString *)getWriteAmountCommand:(int)blockIdx :(BOOL)addFlag :(int)amount;

-(NSString *)getReadSectorCommand:(int)sectorIdx;

-(NSString *)getReadSectorCommand:(int)blockIdx :(M1_PWD_TYPE)pwdType :(NSString *)pwd;

-(NSString *)getWriteSectorCommand:(int)sectorIdx :(NSString *)data;

-(NSString *)getWriteSectorCommand:(int)sectorIdx :(M1_PWD_TYPE)pwdType :(NSString *)pwd :(NSString *)data;

-(NSString *)getWritePWDCommand:(int)sectorIdx :(M1_PWD_TYPE)oldPwdType :(NSString *)oldPwd :(M1_PWD_TYPE)newPwdType :(NSString *)newPwd;

-(BOOL)checkResult:(NSString *)res;

-(NSString*)intToHexString:(int)value;

-(int)hexStringToInt:(NSString*)value;


@end
