//
//  DLMyCentral.h
//
//  Created by zheng wei on 14/12/3.
//  Copyright (c) 2014年 szzcs. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import<UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "DLUUID.h"
@class DLMyPeripheral;
@protocol DLmyCentralDelegate <NSObject>
- (void)scanPeripheral:(DLMyPeripheral *)peripherals RSSI:(NSNumber *)rssi;
- (void)didConectPeripheral;
- (void)failConectPeripheral;
- (void)didDisconectPeripheral;
- (void)peripheralsCanWriteData;
@end
@interface DLMyCentral : NSObject<CBCentralManagerDelegate>

@property (nonatomic,readonly)BOOL canSentData;
@property (nonatomic ,strong)DLMyPeripheral *myPeripheral;
@property (nonatomic,assign)id<DLmyCentralDelegate>myDelegate;
@property (nonatomic,assign)BOOL isautoConect;
@property (nonatomic,copy) NSString *serveUUID;
@property (nonatomic,copy) NSString *readUUID;
@property (nonatomic,copy) NSString *writeUUID;


- (id)initWithServeUUID:(NSString *)UUIDstr;
- (void)scanWithServeUUID:(NSString *)UUIDstr;
- (void)conectPeripheral;
- (void)cancelMyConect;
@end
