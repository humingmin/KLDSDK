/**
 *  NaviRoutePlanModel.h 
 *  路径规划节点数据结构类
 *
 *  Created by huangzh on 15/12/18.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef NaviRoutePlanModel_h
#define NaviRoutePlanModel_h

#import <CoreLocation/CoreLocation.h>

/// 路径坐标类型
typedef enum
{
    Coordinate_Gps = 0,         //!< GPS设备采集的原始GPS坐标.
    Coordinate_Common = 1,      //!< google地图、soso地图、aliyun地图、国测局坐标、mapabc地图和amap地图所用坐标.
    Coordinate_CldMapSDK = 2,   //!< 凯立德地图坐标.
}Coordinate_Type;

/// 节点类型
typedef enum
{
    RouteNode_Start  = 0, //!< 出发地.
    RouteNode_Pass = 1,   //!< 经由地.
    RouteNode_Dest = 2    //!< 目的地.
}RouteNode_Type;

/// 路径计算类型
typedef enum
{
    RoutePlanMode_Invalid = 0X00000000, //!< 无效.
    RoutePlanMode_Recommend = 0X00000001, //!< 系统推荐.
    RoutePlanMode_Highway = 0X00000002,   //!< 高速优先.
    RoutePlanMode_ShortestDistance = 0X00000008, //!< 最短距离.
    RoutePlanMode_LeastToll = 0X00000010, //!< 最少收费.
}RoutePlanMode;

/// 位置点结构
@interface Position : NSObject

@property(nonatomic,assign) CLLocationCoordinate2D coord;  //!< 地理坐标.
@property(nonatomic,assign) Coordinate_Type eType;   //!< 坐标类型.

@end

/// 路径规划节点
@interface RoutePlanNode : NSObject

@property(nonatomic,retain) Position *pos;   //!< 位置点结构.
@property(nonatomic,assign) RouteNode_Type nodeType;   //!< 节点类型.
@property(nonatomic,copy) NSString *title;   //!< 节点名称.


@end

#endif /* NaviRoutePlanModel_h */
