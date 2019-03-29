//
//  Rifle.h
//  RifleFramework
//
//  Created by Dai Dongpeng on 2019/1/22.
//

#import <Foundation/Foundation.h>
#import "RifleConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface Rifle : NSObject

/**
 *  初始化Rifle,使用默认RifleConfig
 *
 *  @param appId 注册Rifle分配的应用唯一标识
 */
//+ (void)startWithAppId:(NSString * RIFLE_NULLABLE)appId;

/**
 *  使用指定配置初始化Rifle
 *
 *  @param appId 注册Rifle分配的应用唯一标识
 *  @param config 传入配置的 RifleConfig
 */
+ (void)startWithAppId:(NSString *)appId
                config:(RifleConfig * RIFLE_NULLABLE)config;

/**
 *  使用指定配置初始化Rifle
 *
 *  @param appId 注册Rifle分配的应用唯一标识
 *  @param development 是否开发设备
 *  @param config 传入配置的 RifleConfig
 */
//+ (void)startWithAppId:(NSString * RIFLE_NULLABLE)appId
//     developmentDevice:(BOOL)development
//                config:(RifleConfig * RIFLE_NULLABLE)config;

/**
 *  设置用户标识
 *
 *  @param userId 用户标识
 */
+ (void)setUserIdentifier:(NSString *)userId;

/**
 *  设置关键数据，随崩溃信息上报
 *
 *  @param value KEY
 *  @param key VALUE
 */
+ (void)setUserValue:(NSString *)value
              forKey:(NSString *)key;

/**
 *  获取关键数据
 *
 *  @return 关键数据
 */
+ (NSDictionary * RIFLE_NULLABLE)allUserValues;

/**
 *  获取设备ID
 *
 *  @return 设备ID
 */
+ (NSString *)RifleDeviceId;

/**
 *  上报自定义Objective-C异常
 *
 *  @param exception 异常信息
 */
//+ (void)reportException:(NSException *)exception;

/**
 *  上报错误
 *
 *  @param error 错误信息
 */
+ (void)reportError:(NSError *)error;

/**
 *    @brief 上报自定义错误
 *
 *    @param category    类型(Cocoa=3,CSharp=4,JS=5,Lua=6)
 *    @param aName       名称
 *    @param aReason     错误原因
 *    @param aStackArray 堆栈
 *    @param info        附加数据
 *    @param terminate   上报后是否退出应用进程
 */
+ (void)reportExceptionWithCategory:(NSUInteger)category
                               name:(NSString *)aName
                             reason:(NSString *)aReason
                          callStack:(NSArray *)aStackArray
                          extraInfo:(NSDictionary *)info
                       terminateApp:(BOOL)terminate;

/**
 *  SDK 版本信息
 *
 *  @return SDK版本号
 */
+ (NSString *)sdkVersion;

+ (NSUInteger)sdkVersionNumber;

//+ (BOOL)isAppCrashedOnStartUpExceedTheLimit;

+ (void)setUploadBlock:(void(^)(NSString *path, NSDictionary *para, BOOL first, void(^succBlock)(NSURLResponse *res), void(^failedBlock)(NSError *error)))uploadBlock;

@end

NS_ASSUME_NONNULL_END
