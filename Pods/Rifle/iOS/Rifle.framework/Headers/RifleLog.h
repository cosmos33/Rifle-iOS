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

//#define RFLogDebug(...)  \
//[self level:RifleLogLevelDebug func:__func__ msg:__VA_ARGS__]
//#define RFLogInfo(...)   \
//[self level:RifleLogLevelInfo func:__func__ msg:__VA_ARGS__]
//#define RFLogWarn(...) \
//[self level:RifleLogLevelWarn func:__func__ msg:__VA_ARGS__]
//#define RFLogError(...)  \
//[self level:RifleLogLevelError func:__func__ msg:__VA_ARGS__]

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

+ (void)setLevel:(RifleLogLevel)level consolePrint:(BOOL)consolePrint;
//+ (void)level:(RifleLogLevel)level func:(const char *)func msg:(NSString *)fmt, ...;
+ (void)level:(RifleLogLevel)level msg:(NSString *)fmt, ...;

@end

NS_ASSUME_NONNULL_END
