//
//  RifleLog.h
//  Breakpad
//
//  Created by Dai Dongpeng on 2019/1/18.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RifleLogLevel) {
    RifleLogLevelDebug   = 1,
    RifleLogLevelInfo    = 2,
    RifleLogLevelWarn    = 3,
    RifleLogLevelError   = 4,
    RifleLogLevelSilent  = 5,
};

OBJC_EXTERN void RFLog(RifleLogLevel level, NSString * _Nonnull fmt, ...) NS_FORMAT_FUNCTION(2, 3);
OBJC_EXTERN void RFLogV(RifleLogLevel level, NSString * _Nonnull fmt, va_list args) NS_FORMAT_FUNCTION(2, 0);

#define RFLOG_DEFINE(lel,fmt,...) [RifleLog level:lel msg:fmt, ##__VA_ARGS__]

#define RFLogDebug(fmt, ...)  \
RFLOG_DEFINE(RifleLogLevelDebug, fmt, ##__VA_ARGS__)
#define RFLogInfo(fmt, ...)   \
RFLOG_DEFINE(RifleLogLevelInfo, fmt, ##__VA_ARGS__)
#define RFLogWarn(fmt, ...) \
RFLOG_DEFINE(RifleLogLevelWarn, fmt, ##__VA_ARGS__)
#define RFLogError(fmt, ...)  \
RFLOG_DEFINE(RifleLogLevelError, fmt, ##__VA_ARGS__)

NS_ASSUME_NONNULL_BEGIN

@interface RifleLog : NSObject

+ (void)level:(RifleLogLevel)level msg:(NSString *)fmt, ...;

@end

NS_ASSUME_NONNULL_END
