/**
 *  RoutePlanDelegate.h 
 *  路径计算协议，结果回调
 *
 *  Created by huangzh on 15/12/18.
 *  Copyright © 2015年 careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 路径计算协议
@protocol RoutePlanDelegate <NSObject>

@required
/**
 *  算路成功回调
 *
 *  @param userInfo 用户需要传人的参数
 */
- (void)onRoutePlanSuccess:(NSDictionary *)userInfo;

@optional
/**
 *  开始算路回调
 *
 *  @param userInfo 用户需要传人的参数
 */
- (void)onRoutePlanStart:(NSDictionary *)userInfo;

/**
 *  取消算路回调
 *
 *  @param userInfo 用户需要传人的参数
 */
- (void)onRoutePlanCancel:(NSDictionary *)userInfo;

/**
 *  算路失败回调
 *
 *  @param error    错误码
 *  @param userInfo 用户需要传人的参数
 */
- (void)onRoutePlanFailed:(NSError *)error andUserInfo:(NSDictionary *)userInfo;
@end
