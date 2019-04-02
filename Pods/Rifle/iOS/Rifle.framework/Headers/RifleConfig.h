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
 *  设置自定义渠道标识
 */
@property (nonatomic, copy) NSString *channel;

/**
 *  设置自定义设备唯一标识
 */
@property (nonatomic, copy) NSString *deviceId;

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
