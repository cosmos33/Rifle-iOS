## 高级功能

### 自定义日志

SDK提供自定义日志接口，用户可用于记录一些关键的调试信息，用于分析crash或自定义错误发生时的上下文环境。

```
    RifleConfig *config = [RifleConfig new];
    
    //设置自定义日志的上报级别，默认不上报
    [config setReportLogLevel:RifleLogLevelWarn];
    
    [Rifle startWithAppId:@"app-id" config:config];
```

自定义日志接口如下：

```
RFLogDebug(fmt, ...)

RFLogInfo(fmt, ...)  

RFLogWarning(fmt, ...)  

RFLogError(fmt, ...)  
```


### 接口声明

#### 配置接口

<pre>
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
</pre>

#### 功能接口

<pre>
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
+ (void)startWithAppId:(NSString * RIFLE_NULLABLE)appId
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
</pre>