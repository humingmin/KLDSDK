/**
 *  CLDCoreServices.h
 *  地图服务
 *
 *  Created by huangzh on 15/12/14.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 鉴权结果状态码
typedef enum
{
    E_PERMISSIONCHECK_ERROR = -1,   //!< 系统错误
    E_PERMISSIONCHECK_SUCCESS,      //!< 成功
    E_PERMISSIONCHECK_PARAM,        //!< 参数内容格式不合法
    E_PERMISSIONCHECK_KEYMATCHING,  //!< 安全码与访问密钥不匹配
    E_PERMISSIONCHECK_KEYNOEXIST,   //!< 访问密钥不存在或已删除
    E_PERMISSIONCHECK_NOREVIEW,     //!< 用户未审核
    E_PERMISSIONCHECK_NOPERMISSION, //!< 安全码无权限访问
}CLDPermissionCheckResultCode;

/// 地图核心服务协议
@protocol CLDCoreServicesProtocol <NSObject>

@optional
/**
 *  服务初始化完成
 */
-(void)servicesInitDidFinished;

/**
 *  返回授权验证错误码
 *
 *  @param error 错误码 : 为0时验证通过，具体参加CLDPermissionCheckResultCode
 */
- (void)onGetPermissionState:(int)error;

@end

/// 地图核心服务
@interface CLDCoreServices : NSObject

/**
 *  获取单例对象
 *
 *  @return CLDCoreServices 单例对象
 */
+ (CLDCoreServices*)GetInstance;

/**
 *  释放单例对象
 */
+ (void)ReleaseInstance;

/**
 *  启动服务,同步方法,会导致阻塞
 *
 *  @param key 注册的key
 *  @param delegate 代理类
 *
 *  @return YES:调用成功，NO:调用失败
 */
-(BOOL)startService:(NSString *)key Delegate:(id<CLDCoreServicesProtocol>)delegate;

/**
 *  启动服务,异步方法
 *
 *  @param key  注册的appKey
 *  @param delegate 代理类
 */
-(void)startServicesAsyn:(NSString *)key Delegate:(id<CLDCoreServicesProtocol>)delegate;

/**
 *  查询引擎是否初始化完成
 *
 *  @return 是否初始化完成
 */
-(BOOL)isServicesInited;

/**
 *  获取授权检测状态码
 *
 *  @return 状态码,参照：CLDPermissionCheckResultCode
 */
-(int)getAuthCheckStatus;

/**
 *  停止所有服务
 */
-(void)stopService;

@end





