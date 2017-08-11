/**
 *  CLDGeometry.h 
 *  地理坐标相关计算
 *
 *  Created by huangzh on 15/12/20.
 *  Copyright © 2015年 careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CldTypes.h"


/**
*  计算指定两点之间的距离
*
*  @param point1 第一个坐标点
*  @param point2 第二个坐标点
*
*  @return 两点之间的距离，单位:米
*/
UIKIT_EXTERN CLLocationDistance CLDMetersBetweenMapPoints(CLLocationCoordinate2D point1, CLLocationCoordinate2D point2);

/**
 *  判断指定点是否在某个多边形内
 *
 *  @param points 指定的多边形坐标的集合
 *  @param num    点得个数
 *  @param point  指定的点
 *
 *  @return 如果包含，返回YES，否则返回NO
 */
UIKIT_EXTERN BOOL CLDMapPointsContainsPoint(CLLocationCoordinate2D *points, int num, CLLocationCoordinate2D point);

/**
 *  计算指定两点之间的正北方向
 *
 *  @param point     要计算的坐标点
 *  @param center    相对的坐标坐标点
 *  @param direction 方向，==-1绝对方向，否则相对于该参数的方向
 *
 *  @return 正北方向
 */
UIKIT_EXTERN CldDirection CLDDirectionBetweenMapPoint(CLLocationCoordinate2D point, CLLocationCoordinate2D center, short direction);

/**
 *  坐标转换，从原始GPS坐标，mapbar坐标,google坐标，51地图坐标，mapabc坐标转换为凯立德坐标
 *
 *  @param coordinate 原坐标
 *  @param type       坐标类型
 *
 *  @return 凯立德地图坐标
 */
UIKIT_EXTERN CLLocationCoordinate2D CLDConvertCldCoorFrom(CLLocationCoordinate2D coordinate, CldCoordType type);

