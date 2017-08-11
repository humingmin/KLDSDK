/**
 *  CldTypes.h 
 *  地图模式，地理坐标点
 *
 *  Created by linfengkun on 15/12/8.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef CldTypes_h
#define CldTypes_h

#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

/// 坐标类型
typedef enum
{
    CldCoordType_Gps = 0, //!< GPS设备采集的原始GPS坐标.
    CldCoordType_Common,  //!< google地图、soso地图、aliyun地图、国测局坐标、mapabc地图和amap地图所用坐标.
} CldCoordType;

/// 地图模式
typedef enum{
    CldMapViewMode_TrueNorth = 0,   //!< 2D地图正北模式.
    CldMapViewMode_Turned,          //!< 2D车头朝前模式.
    CldMapViewMode_3D,              //!< 3D车头朝前模式.
    CldMapViewMode_3DTN,            //!< 3D地图正北模式.
} CldMapViewMode;

/// 地理坐标点，用直角地理坐标表示
typedef struct {
    double x;	//!< 横坐标.
    double y;	//!< 纵坐标.
} CldMapPoint;

/// 矩形大小，用直角地理坐标表示
typedef struct {
    double width;	//!< 宽度.
    double height;	//!< 高度.
} CldMapSize;

/// 矩形，用直角地理坐标表示
typedef struct {
    CldMapPoint origin; //!< 屏幕左上点对应的直角地理坐标.
    CldMapSize size;	//!< 坐标范围.
} CldMapRect;

/// 表示一个经纬度区域
typedef struct {
    CLLocationCoordinate2D northEast;	///< 东北角点经纬度坐标
    CLLocationCoordinate2D southWest;	///< 西南角点经纬度坐标
} CldCoordinateBounds;

/// 白天/黑夜模式
typedef enum
{
    CldMapDisplayMode_Auto=0l,		///< 自动
    CldMapDisplayMode_Day,			///< 白天
    CldMapDisplayMode_Night,		///< 黑夜
} CldMapDisplayMode;

/// 方向
typedef enum
{
    CldDirection_None = 0,	  ///< 没有方向
    CldDirection_East,	      ///< 东
    CldDirection_South,	      ///< 南
    CldDirection_West,	      ///< 西
    CldDirection_North,	      ///< 北
    CldDirection_Southeast,	  ///< 东南
    CldDirection_Northeast,   ///< 东北
    CldDirection_Northwest,	  ///< 西北
    CldDirection_Southwest,	  ///< 西南
}CldDirection;

#endif /* CldTypes_h */












