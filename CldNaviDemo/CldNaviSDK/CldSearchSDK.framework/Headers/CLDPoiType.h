/**
 * CLDSearchType.h
 * DevNetworking
 *
 * Created by Lynn on 15/12/7.
 * Copyright © 2015年 Lynn. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/// 搜索结果类型
typedef enum : NSUInteger {
    SearchResultTypeRouting = 1,    /// 路径搜索结果
    SearchResultTypeLocation,       /// 地理编码结果或城市跳转
    SearchResultTypeSearch,         /// poi搜索结果
    SearchResultTypeRgeo,           /// geo搜索结果
} SearchResultType;

/// 级别
typedef  enum : NSUInteger{
    LocationLevelCountry = 1,    /// 国家
    LocationLevelProvince,       /// 省
    LocationLevelCity,           /// 市
    LocationLevelCounty,         /// 区，县
} LocationLevel;

/// 省市区地址信息
@interface CLDAddressComponent : NSObject

@property (nonatomic, assign) int      adcode;      //!< 区域编码.
@property (nonatomic, strong) NSString *province;   //!< 省.
@property (nonatomic, strong) NSString *city;       //!< 市.
@property (nonatomic, strong) NSString *district;   //!< 区.

@end

/// Poi信息
@interface CLDPoiInfo : NSObject

@property (nonatomic, strong) NSString               *poiId;    //!< poi id.
@property (nonatomic, strong) NSString               *name;     //!< poi名称.
@property (nonatomic, strong) CLDAddressComponent    *pcd;      //!< 所在行政区.
@property (nonatomic, strong) NSString               *address;  //!< 地址.
@property (nonatomic, strong) NSString               *tel_num;  //!< 电话.
@property (nonatomic, strong) NSString               *type_name;//!< 分类名.
@property (nonatomic, strong) NSNumber               *type_code;//!< 分类码.
@property (nonatomic, assign) CLLocationCoordinate2D pt;        //!< 坐标.

@end

/// location信息
@interface CLDLocationInfo : NSObject

@property (nonatomic, strong) NSString               *name;     //!< 名称.
@property (nonatomic, assign) LocationLevel          level;     //!< 级别
@property (nonatomic, strong) CLDAddressComponent    *pcd;      //!< 所在行政区.
@property (nonatomic, assign) CLLocationCoordinate2D pt;        //!< 坐标.
@property (nonatomic, strong) NSArray *shapes;                  //!< 形状点集合.

@end


/// 搜索结果
@interface CLDPoiResult : NSObject

@property (nonatomic, assign) int startIndex;    //!< 起始索引.
@property (nonatomic, assign) int pageCount;    //!< 每页数量.
@property (nonatomic,assign) BOOL show_map;     //!< 是否默认显示地图.
@property (nonatomic,strong) NSArray *bounds;   //!< 地图范围,左下右上.
@property (nonatomic, assign) SearchResultType resultType;    //!< 搜索结果类型.
@property (nonatomic, strong) NSArray<CLDPoiInfo *> *poiInfoList;    //!< poi信息列表.
@property (nonatomic, strong) CLDLocationInfo *locationInfo;     //!<location信息.

@end

