//
//  CLDServerStart.m
//  CldNaviDemo
//
//  Created by Ivan on 2017/8/11.
//  Copyright © 2017年 Careland. All rights reserved.
//

#import "CLDServerStart.h"

@implementation CLDServerStart

/**
 启动服务，异步方法
 
 @param key 注册的appKey
 @param delegate 代理类
 */
- (void)cldServicesAsyn:(NSString *)key delegate:(id <CLDCoreServicesProtocol>)delegate {
    [[CLDCoreServices GetInstance] startServicesAsyn:key Delegate:self];
}

/** 进入后台 */
- (void)cldWillEnterBackGround {
    [CldMapView willEnterBackGround];
}

/** 进入前台 */
- (void)cldDidReturnForeGround {
    [CldMapView didReturnForeGround];
}

/** 服务初始化完成 */
- (void)servicesInitDidFinished {
    if ([[CLDCoreServices GetInstance] isServicesInited])
        NSLog(@"引擎初始化已完成");
}

/**
 返回授权验证错误码
 
 @param error 错误码：为0时验证通过，具体参加CLDPermissionCheckResultCode
 */
- (void)onGetPermissionState:(int)error {
    if(error == E_PERMISSIONCHECK_SUCCESS)
        NSLog(@"授权检测成功！");
    else
        NSLog(@"授权检测失败，错误码：%d", error);
}

@end
