//
//  RifleConfig.h
//  RifleFramework
//
//  Created by Dai Dongpeng on 2019/1/22.
//

#import <Foundation/Foundation.h>
#import "RifleLog.h"

#define RIFLE_UNAVAILABLE(x) __attribute__((unavailable(x)))

#if __has_feature(nullability)
#define RIFLE_NONNULL __nonnull
#define RIFLE_NULLABLE __nullable
#define RIFLE_START_NONNULL _Pragma("clang assume_nonnull begin")
#define RIFLE_END_NONNULL _Pragma("clang assume_nonnull end")
#else
#define RIFLE_NONNULL
#define RIFLE_NULLABLE
#define RIFLE_START_NONNULL
#define RIFLE_END_NONNULL
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol RifleDelegate <NSObject>

@optional
/**
 *  发生异常时回调
 *
 *  @param exception 异常信息
 *
 *  @return 返回需上报记录，随异常上报一起上报
 */
- (NSString * RIFLE_NULLABLE)attachmentForException:(NSException * RIFLE_NULLABLE)exception;

@end

@interface RifleConfig : NSObject <NSCopying>

/**
 *  SDK Debug信息开关, 默认关闭
 */
@property (nonatomic, assign) BOOL debugMode;

/**
 *  设置自定义渠道标识
 */
@property (nonatomic, copy) NSString *channel;

/**
 *  设置自定义设备唯一标识
 */
@property (nonatomic, copy) NSString *deviceId;

/**
 *  设置自定义版本号,如果不设置则取 CFBundleVersion
 */
@property (nonatomic, copy) NSString *customAppVersion;

/**
 *  卡顿监控开关，默认关闭
 */
//@property (nonatomic) BOOL blockMonitorEnable;

/**
 *  卡顿监控判断间隔，单位为秒
 */
//@property (nonatomic) NSTimeInterval blockMonitorTimeout;

/**
 *  设置 App Groups Id (如有使用 Rifle iOS Extension SDK，请设置该值)
 */
//@property (nonatomic, copy) NSString *applicationGroupIdentifier;

/**
 *  进程内还原开关，默认开启
 */
//@property (nonatomic) BOOL symbolicateInProcessEnable;

/**
 *  非正常退出事件记录开关，默认关闭
 */
//@property (nonatomic) BOOL unexpectedTerminatingDetectionEnable;

/**
 *  页面信息记录开关，默认开启
 */
//@property (nonatomic) BOOL viewControllerTrackingEnable;

/**
 *  Rifle Delegate
 */
@property (nonatomic, assign) id<RifleDelegate> delegate;

/**
 * 控制自定义日志上报，默认值为RifleLogLevelSilent，即关闭日志记录功能。
 * 如果设置为RifleLogLevelWarn，则在崩溃时会上报Warn、Error接口打印的日志
 */
@property (nonatomic, assign) RifleLogLevel reportLogLevel;

/**
 * 控制台日志上报开关，默认开启
 */
@property (nonatomic, assign) BOOL consolelogEnable;

/**
 * 崩溃退出超时，如果监听到崩溃后，App一直没有退出，则到达超时时间后会自动abort进程退出
 * 默认值 5s， 单位 秒
 * 当赋值为0时，则不会自动abort进程退出
 */
@property (nonatomic, assign) NSUInteger crashAbortTimeout;

@end

NS_ASSUME_NONNULL_END
