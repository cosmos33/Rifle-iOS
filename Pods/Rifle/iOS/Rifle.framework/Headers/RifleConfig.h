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

@interface RifleReport : NSObject
/**
 *  自定义渠道标识,同RifleConfig ：channel
 */
@property (nonatomic, copy) NSString *channel;

/**
 *  版本号,同RifleConfig ：customAppVersion
 */
@property (nonatomic, copy) NSString *appVersion;

/**
 *  app的启动时间，Unix 时间戳，单位是毫秒
 */
@property (nonatomic, assign) NSUInteger startTime;

/**
 *  app的crash时间，Unix 时间戳，单位是毫秒
 */
@property (nonatomic, assign) NSUInteger crashTime;

@end

@protocol RifleDelegate <NSObject>

@optional

/**
 *  当Rifle对象监测到程序在上次运行过程中出现crash，在下次启动Rifle的时候会同步调用这个方法。
 *
 *  @param report app发生crash时的一些信息
 */
- (void)rifleDidDetectCrashForLastExecutionWithReport:(RifleReport *)report;

@end

@interface RifleConfig : NSObject <NSCopying>

/**
 *  设置自定义渠道标识
 */
@property (nonatomic, copy) NSString *channel;

/**
 *  设置自定义版本号,如果不设置则按下面规则来取："CFBundleShortVersionString (CFBundleVersion)"
 */
@property (nonatomic, copy) NSString *customAppVersion;

/**
 *  Rifle Delegate
 */
@property (nonatomic, assign) id<RifleDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
