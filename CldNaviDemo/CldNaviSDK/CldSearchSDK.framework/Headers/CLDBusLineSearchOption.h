/**
 *  CLDBusLineSearchOption.h
 *  CldSearchSDK
 *
 *  Created by Lynn on 16/1/21.
 *  Copyright © 2016年 CLD. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CLDPoiSearchOption.h"
#import <CoreLocation/CoreLocation.h>

/// 换乘交通工具
typedef enum:NSUInteger{
    CLDTrafficToolDefault = 0, //!< 默认全部.
    CLDTrafficToolBus,         //!< 公交.
    CLDTrafficToolMetro,       //!< 地铁.
}CLDTrafficTool;

/// 换乘偏好
typedef enum:NSUInteger{
    CLDPreferenceDefault = 0,       //!< 少换乘.
    CLDPreferenceLeastTime = 1,     //!< 时间短.
    CLDPreferenceLeastWalk = 2,     //!< 少步行.
    CLDPreferenceRecommend = 3,     //!< 推荐.
    CLDPreferenceMetroPriority = 4, //!< 地铁优先.
    CLDPreferenceExcludeMetro = 5,  //!< 不坐地铁.
}CLDPreference;

/// 公交站点搜索服务参数
@interface CLDBusStationSearchOption : CLDPoiSearchOption
@property (nonatomic, strong) NSString *city;    //!< 城市.
@end

/// 公交线搜索服务参数
@interface CLDBusLineSearchOption : CLDPoiSearchOption
@property (nonatomic, strong) NSString *city;    //!< 城市.
@end

/// 公交线详情搜索服务参数
@interface CLDBusLineDetailSearchOption : CLDPoiSearchOption
@property (nonatomic, copy) NSString *busLineId;    //!< 公交线路id.
@end

/// 公交线换乘段搜索服务参数
@interface CLDBusLineSegPathSearchOption : CLDPoiSearchOption
@property (nonatomic, assign) int cityID;        //!< 城市id
@property (nonatomic, assign) int pathID;        //!< 线路id
@property (nonatomic, assign) int sID;           //!< 起点站点id
@property (nonatomic, assign) int eID;           //!< 终点站点id
@end

/// 公交换乘方案服务参数
@interface CLDBusLinePlanSearchOption : NSObject
@property (nonatomic, assign) CLLocationCoordinate2D startCoordinate;    //!< 出发地坐标.
@property (nonatomic, strong) NSString *startName;    //!< 出发地名称
@property (nonatomic, assign) CLLocationCoordinate2D destCoordinate;    //!< 目的地坐标.
@property (nonatomic, strong) NSString *destName;    //!< 目的地名称
@property (nonatomic, assign) int cityID;    //!< 城市id.

@property (nonatomic, assign) CLDTrafficTool trafficTool;    //!< 交通工具.
@property (nonatomic, assign) CLDPreference preference;    //!< 偏好.

@property (nonatomic, assign) BOOL isGetAllPlan;    //!< 是否获取所有方案.
@property (nonatomic, copy) NSDate *startTime;    //!< 出发时间.

@end