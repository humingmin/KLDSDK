/**
 *  CldMapNavigation.h 
 *  调起凯立德地图，进入凯立德地图
 *
 *  Created by huangzh on 16/1/4.
 *  Copyright © 2016年 Careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CldTypes.h"

/// 调起凯立德地图
@interface CldMapNavigation : NSObject

/**
 *  调起凯立德导航app定位
 *
 *  @param point 坐标
 *  @param name  名称
 *
 *  @return YES/NO
 */
+(BOOL)openCldMapLocation:(CLLocationCoordinate2D)point Name:(NSString *)name;

/**
 *  调起凯立德导航app导航
 *
 *  @param naviNodes    算路节点数组，参考RoutePlanNode,
 *                      出发地和目的地都必须传
 *
 *  @return YES/NO
 */
+(BOOL)openCldMapNavi:(NSArray *)naviNodes;

/**
 *  调起凯立德导航app搜索
 *
 *  @param keyWord 搜索关键字
 *
 *  @return YES/NO
 */
+(BOOL)openCldMapSearch:(NSString *)keyWord;

@end
