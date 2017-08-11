//
//  CldTruckUtil.h
//  CldNaviSDK
//
//  Created by huangzh on 17/4/17.
//  Copyright © 2017年 Careland. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 货车参数
@interface CLDTruckParams : NSObject

@property (nonatomic) float truckHeight;     //!< 车高 单位:米.
@property (nonatomic) float truckWidth;      //!< 车宽 单位:米.
@property (nonatomic) float truckWeight;     //!< 车重 单位:吨.
@property (nonatomic) int weightJoinRoute;   //!< 回避限重 0:不回避限重,仅提醒,1:回避限重,2:不回避限重,也不提醒.
@property (nonatomic) int truckVehicleType;  //!< 车种类型,1:微型车辆，2:轻型车辆，3:中型车辆，4:重型车辆.
@property (nonatomic) int truckNumAxles;     //!< 车轴数,2,3,4,5,6.
@end

/// 货车参数工具类
@interface CldTruckUtil : NSObject
/**
 *  设置货运规划是否忽略限行，重新规划路线后生效
 *
 *  @param bIgnoreRestrictions YES/NO，YES:忽略，NO:不忽略
 */
+ (void)setIgnoreRestrictions:(BOOL)bIgnoreRestrictions;

/**
 *  获取是否忽略限行
 *
 *  @return YES/NO，YES:忽略，NO:不忽略
 */
+ (BOOL)getIgnoreRestrictions;

/**
 *  设置货车参数
 *
 *  @param params 货车参数，车宽，车高，车重等值都要大于0
 *
 *  @return YES/NO YES:成功，NO:失败
 */
+ (BOOL)setTruckParams:(CLDTruckParams *) params;

/**
 *  获取货车参数
 *
 *  @return 货车参数
 */
+ (CLDTruckParams *)getTruckParams;

/**
 *  画路径上窄路图标
 */
+ (void)drawNarrowRoadIcons;

/**
 *  画路径上限行图标
 */
+ (void)drawLimitIcons;

/**
 *  画路径上检查站图标
 */
+ (void)drawCheckIcons;

/**
 *  清除已绘制的图标
 */
+ (void)clearDrawIcons;

/**
 *  获取规划路径已自动回避的限行个数
 *
 *  @return 个数
 */
+ (int)getAvoidLimitNum;

/**
 *  获取规划路径限行个数
 *
 *  @return 个数
 */
+ (int)getLimitNum;

@end
