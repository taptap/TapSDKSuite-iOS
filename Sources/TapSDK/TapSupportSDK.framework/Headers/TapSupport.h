//
//  TapSupport.h
//  TapSupportSDK
//
//  Created by Bottle K on 2021/9/14.
//

#import <Foundation/Foundation.h>
#import <TapSupportSDK/TapSupportConfig.h>
NS_ASSUME_NONNULL_BEGIN

#define TapSupportSDK                @"TapSupport"
#define TapSupportSDK_VERSION_NUMBER @"30500001"
#define TapSupportSDK_VERSION        @"3.5.0"

extern NSString *const TAP_SUPPORT_PATH_HOME;
extern NSString *const TAP_SUPPORT_PATH_CATEGORY;
extern NSString *const TAP_SUPPORT_PATH_TICKET_HISTORY;
extern NSString *const TAP_SUPPORT_PATH_TICKET_NEW;

@interface TapSupport : NSObject
@property (nonatomic, strong) TapSupportConfig *config;
@property (nonatomic, strong) NSDictionary *defaultMetaData;
@property (nonatomic, strong) NSDictionary *defaultFieldsData;
@property (nonatomic, copy) NSString *anonymousId;

+ (instancetype)shareInstance;

/// 匿名用户登录
/// @param anonymousId 匿名用户id，不提供的话会默认生成
+ (void)loginAnonymously:(nullable NSString *)anonymousId;

/// 获取网页地址
+ (NSString *)getSupportWebUrl;

/// 获取网页地址
/// @param path 路径
+ (NSString *)getSupportWebUrl:(nullable NSString *)path;

/// 获取网页地址
/// @param path 路径
/// @param metaData meta 参数
/// @param fieldsData fields 参数
+ (NSString *)getSupportWebUrl:(nullable NSString *)path
                   metaData:(nullable NSDictionary *)metaData
                 fieldsData:(nullable NSDictionary *)fieldsData;

/// 开始轮询获取未读状态
+ (void)resume;

/// 结束轮询获取未读状态
+ (void)pause;

/// 单次获取未读状态
+ (void)fetchUnreadStatus;

@end

NS_ASSUME_NONNULL_END
