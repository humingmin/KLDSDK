//
//  CLDServerStart.h
//  CldNaviDemo
//
//  Created by Ivan on 2017/8/11.
//  Copyright © 2017年 Careland. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CldSDK_Base/CldSDK_Base.h"
#import "CldNaviSDK/CldNaviSDK.h"
#import "CldSearchSDK/CldSearchSDK.h"

@interface CLDServerStart : NSObject <CLDCoreServicesProtocol>

/**
 启动服务，异步方法

 @param key 注册的appKey
 @param delegate 代理类
 */
- (void)cldServicesAsyn:(NSString *)key delegate:(id <CLDCoreServicesProtocol>)delegate;

/** 进入后台 */
- (void)cldWillEnterBackGround;

/** 进入前台 */
- (void)cldDidReturnForeGround;

@end
