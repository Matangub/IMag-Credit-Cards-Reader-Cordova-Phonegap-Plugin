//
//  DLMyPeripheral.h
//
//  Created by zheng wei on 14/12/3.
//  Copyright (c) 2014年 szzcs. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BluetoothHandler.h"
//修改名称用到的接口
#import "DLUUID.h"
#define AIR_PATCH_COMMAND_XMEMOTY_WRITE         0x09
#define AIR_PATCH_COMMAND_E2PROM_WRITE          0x0b
typedef struct _AIR_PATCH_COMMAND_FORMAT
{
    unsigned char commandID;
    char parameters[19];
}__attribute__((packed)) AIR_PATCH_COMMAND_FORMAT;

typedef struct _WRITE_EEPROM_COMMAND_FORMAT
{
    unsigned char addr[2];
    unsigned char length;
    char    data[16];
}__attribute__((packed)) WRITE_EEPROM_COMMAND_FORMAT;
@protocol DLmyPeripheralDelegate <NSObject>
- (void)findCharacteristicForWrite;
@end
@interface DLMyPeripheral : NSObject<CBPeripheralDelegate>
{
    id<SwipeDelegate>  __unsafe_unretained mDelegate;//********
}
@property (nonatomic,assign)id<SwipeDelegate>mDelegate;//********
@property (nonatomic,strong) CBPeripheral *peripheral;
@property (nonatomic,copy) NSString *deviceName;
@property (nonatomic,assign) BOOL conectedStae;
@property (nonatomic,assign)id<DLmyPeripheralDelegate>myDelegate;

//DIS
@property(retain) CBCharacteristic *manufactureNameChar;
@property(retain) CBCharacteristic *modelNumberChar;
@property(retain) CBCharacteristic *serialNumberChar;
@property(retain) CBCharacteristic *hardwareRevisionChar;
@property(retain) CBCharacteristic *firmwareRevisionChar;
@property(retain) CBCharacteristic *softwareRevisionChar;
@property(retain) CBCharacteristic *systemIDChar;
@property(retain) CBCharacteristic *certDataListChar;
@property(retain) CBCharacteristic *specificChar1;
@property(retain) CBCharacteristic *specificChar2;

//Proprietary
@property(retain) CBCharacteristic *airPatchChar;
@property(retain) CBCharacteristic *transparentDataWriteChar;
@property(retain) CBCharacteristic *transparentDataReadChar;
@property(retain) CBCharacteristic *connectionParameterChar;
@property (nonatomic,copy) NSString *serveUUID;
@property (nonatomic,copy) NSString *readUUID;
@property (nonatomic,copy) NSString *writeUUID;

//- (void)printerReset;//初始化
//- (void)printLineFeed;//换行
//- (void)printFontWith:(FontEnum)font;//设置字体大小
//- (void)printAliginWith:(AlignEnum)algin;//设置打印位置
//- (void)printTheContent:(NSString *)content;//打印文字
//- (void)printTheDocumentWithPath:(NSString *)path ;//打印文档
//- (void)printTheBarCodeWithBarcodeContent:(NSString *)content withCodeType:(CodeTypeEnum)codetype ;//打印条形码
//- (void)printTheQrCodeWithQrcodeCotent:(NSString *)content size:(CGSize)size;//打印二维码
//- (void)printTheImageWithImage:(UIImage *)myImage ;//打印图片
//- (void)getVersion:(NSString *)str;
//- (void)changeName:(NSString *)name;//修改名称
- (void)sendCommand:(NSString *)str;
@end
