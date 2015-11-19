//
//  BluetoothHandler.h
//  Version 3.2
//  Created by zheng wei on 14/12/3.
//  Copyright (c) 2014年 szzcs. All rights reserved.
//
#import <CoreBluetooth/CoreBluetooth.h>
#import "EMVHandler.h"

@protocol BLEReaderDelegate <NSObject>
@optional
//可以通过以下代理方法知道设备连接情况
- (void)discoverPeripheralSuccess:(CBPeripheral *)peripheral RSSI:(NSNumber *)rssi;//找到了有serveUUID服务的设备,可以从这个设备中获取设备相应的信息NAME,RSSI.....
- (void)discoverPeripheralFail;//没有找到有serveUUID的设备
- (void)conectPeripheralSuccess;//连接设备成功
- (void)conectPeripheralFail;//连接设备失败
- (void)disconectPeripheral;//已经断开了连接
@end

@interface BluetoothHandler : EMVHandler
@property (nonatomic,assign)id<BLEReaderDelegate>myDelegate;
@property (nonatomic,readonly,assign)BOOL sendDataEnable;//是否可以发送数据，yes 可以， no 不可以,当设备连接好，并且找到发送特征值时，会自动设为YES,否则发送不了数据
@property (nonatomic,copy) NSString *serveUUID;//必须先设置
@property (nonatomic,copy) NSString *readUUID;//必须先设置
@property (nonatomic,copy) NSString *writeUUID;//必须先设置

- (void)autoToConect;//自动连接 ,当执行这个方法之后，就不需要再执行scanPeripheral和conectDiscoverPeripheral方法了，如果没有执行这个方法就需要结合BLEPrintDelegate里的方法分别执行扫描和连接方法才能成功连接设备
- (void)scanPeripheral;//扫描设备
- (void)conectDiscoverPeripheral;//连接设备
- (void)cancelConect;//取消连接

//覆盖掉SwipeHandler中下面的方法
-(BOOL)isConnected;
-(BOOL)isPowerOn;
// Set the timeout value for the function of getDataWithCipherCode. default is 5s
-(void)setTimeout:(UInt32) timeout;
// Set the retry count for the function of getDataWithCipherCode. default is 0
-(void)setRetryCount:(UInt32) retryCount;
-(NSString*)getDataWithCipherCode:(NSString*)cipherCode;

-(BOOL)writeCipherCode:(NSString*)cipherCode;
@end

