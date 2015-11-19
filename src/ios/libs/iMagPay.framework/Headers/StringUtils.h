//
//  StringUtils.h
//  iMagPay
//
//  Created by zheng wei on 15/4/14.
//  Copyright (c) 2015年 szzcs.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StringUtils : NSObject

//format hex str with @" ",like:aabbccdd to aa bb cc dd .
+(NSString *)formatCommand:(NSString *)str;
//format uchar buffer to hex str with @" "
+(NSString *)ucharToStr:(unsigned char*)buffer :(int)len;
//int to hex str,like: 1 to @"01"
+(NSString*)intToHexString:(int)value ;
//hex str to int,like @"0a" to 10
+(int)hexStringToint:(NSString *)str;
//format hex str(with @" ") to uchar
+(void)strTouchar:(NSString *)str :(unsigned char*)buffer;
//format str to uchar,like :1 to 31
+(void)digitsTouchar:(NSString *)str :(unsigned char*)buffer;
@end
