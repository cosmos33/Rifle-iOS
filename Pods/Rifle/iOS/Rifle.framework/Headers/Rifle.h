//
//  Rifle.h
//  RifleFramework
//
//  Created by Dai Dongpeng on 2019/1/22.
//

#import <Foundation/Foundation.h>
#import "RifleConfig.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, RifleExceptionType) {
    RifleExceptionType_Cocoa = 1,
    RifleExceptionType_CSharp = 2,
    RifleExceptionType_JS = 3,
    RifleExceptionType_Lua = 4,
    RifleExceptionType_Custom = 5
};

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
//+ (void)reportError:(NSError *)error;

/**
 *    @brief 上报自定义异常，如果 setEnableRecordCustomException 设置为 NO，则无任何操作；默认是YES
 *
 *    @param category    RifleExceptionType类型，支持Cocoa/CSharp/JS/Lua/Custom
 *    @param aName       名称
 *    @param aReason     错误原因
 *    @param aStackArray 堆栈
 *    @param info        附加数据
 */
+ (void)reportExceptionWithCategory:(RifleExceptionType)category
                               name:(NSString *)aName
                             reason:(NSString *)aReason
                          callStack:(NSArray * RIFLE_NULLABLE)aStackArray
                          extraInfo:(NSDictionary * RIFLE_NULLABLE)info;
/**
 *  SDK 版本信息
 *
 *  @return SDK版本号
 */
+ (NSString *)sdkVersion;

/**
 *  SDK 版本信息
 *
 *  @return SDK版本号
 */
+ (NSUInteger)sdkVersionNumber;

//+ (BOOL)isAppCrashedOnStartUpExceedTheLimit;

/**
 *  设置Log的等级，是否在控制台打印日志
 *
 *  @param level              log等级，默认为RifleLogLevelSilent
 *  @param consolePrint       是否在控制台打印日志，默认为 NO
 */
+ (void)setLogLevel:(RifleLogLevel)level consolePrint:(BOOL)consolePrint;

/**
 *  是否记录自定义异常，默认是YES
 *
 *  @param en              是否记录
 */
+ (void)setEnableRecordCustomException:(BOOL)en;

/**
 *  进入新页面调用,统计当前crash/异常发生所在页面.
 *
 *  @param pageName  当前页面名字
 */
+ (void)updateCurrentPage:(NSString *)pageName;

@end

NS_ASSUME_NONNULL_END
