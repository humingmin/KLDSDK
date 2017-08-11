//
//  CLDNaviVersion.h
//  CldNaviSDK
//
//  Created by huangzh on 16/10/12.
//  Copyright © 2016年 Careland. All rights reserved.
//
#ifndef CLDNaviVersion_h
#define CLDNaviVersion_h

#import <UIKit/UIKit.h>

/**
 *重要：
 *navi SDK的版本和base SDK的版本必须一致，否则不能正常使用
 */

/**
 *获取当前地图navi SDK的版本号
 *return  返回当前navi SDK的版本号
 */
UIKIT_EXTERN NSString* CLDGetNaviSDKVersion();

#endif /* CLDNaviVersion_h */