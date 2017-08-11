/**
 *  CLDBusLineSearchType.h
 *  CldSearchSDK
 *
 *  Created by Lynn on 16/1/21.
 *  Copyright © 2016年 CLD. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class CLDAddressComponent;
@class CLDBusLineSpec;
@class CLDPoiInfo;
@class CLDGeoShape;

/// 公交站点搜索结果
@interface CLDBusStationResult : NSObject
@property (nonatomic, assign) int startIndex;                       //!< 起始索引.
@property (nonatomic, assign) int pageCount;                        //!< 每页数量.
@property (nonatomic, strong) NSArray<CLDPoiInfo *> *stationList;   //!< 公交站点列表.
@end

/// 公交线搜索结果
@interface CLDBusLineResult : NSObject
@property (nonatomic, assign) int startIndex;                       //!< 起始索引.
@property (nonatomic, assign) int pageCount;                        //!< 每页数量.
@property (nonatomic, strong) NSArray<CLDBusLineSpec *> *busLines;  //!< 公交线列表.
@end

/// 公交站台信息
@interface CLDBusPlatformSpec : NSObject
@property (nonatomic, strong) NSString               *busPlatformId;//!< 公交站台id.
@property (nonatomic, strong) NSString               *name;         //!< 公交站台名称.
@property (nonatomic, assign) CLLocationCoordinate2D xy;            //!< 坐标.
@property (nonatomic, strong) NSDictionary           *subways;      //!< key为地铁线路名，value为线路id.
@property (nonatomic, strong) NSArray                *busLineNameList;     //!< 公交线路名列表.
@end

/// 公交线信息
@interface CLDBusLineSpec : NSObject
@property (nonatomic, strong) CLDAddressComponent *city;               //!< 城市.
@property (nonatomic, strong) NSString            *busLineId;          //!< 公交路线id.
@property (nonatomic, strong) NSString            *name;               //!< 公交路线名称.
@property (nonatomic, strong) NSString            *price;              //!< 价格.
@property (nonatomic, strong) NSString            *type;               //!< 路线类型.
@property (nonatomic, strong) NSString            *startTime;          //!< 开始时间.
@property (nonatomic, strong) NSString            *endTime;            //!< 结束时间.
@property (nonatomic, strong) NSArray<CLDBusPlatformSpec *> *platforms;//!< 站台列表.
@property (nonatomic, strong) NSArray<CLLocation *> *shapes;           //!< 位置信息列表.
@property (nonatomic, assign) int nearest_platform;                    //!< 最近的站台数.
@property (nonatomic, strong) NSString *length;                        //!< 长度.
@end

