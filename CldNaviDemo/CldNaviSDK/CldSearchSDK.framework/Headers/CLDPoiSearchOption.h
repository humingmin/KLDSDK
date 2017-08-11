/**
 * CLDSearchOption.h
 * DevNetworking
 *
 * Created by Lynn on 15/12/7.
 * Copyright © 2015年 Lynn. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


/// Poi搜索基本参数
@interface CLDPoiSearchOption : NSObject

@property (nonatomic, assign) int      start;       //!< 分页开始索引.
@property (nonatomic, assign) int      count;       //!< 分页数量.
@property (nonatomic, strong) NSString *keyword;    //!< 搜索关键字.
@property (nonatomic, strong) NSString *category;   //!<  分类，例：西餐厅|餐馆.

@end


/// 城市搜索参数
@interface CLDCitySearchOption : CLDPoiSearchOption
@property (nonatomic, strong) NSString *city;    //!< 城市名.
@property (nonatomic, assign) CLLocationCoordinate2D center;     //!< 中心点.
@property (nonatomic, assign) CLLocationCoordinate2D leftBottom; //!< 矩形区域，左下角的坐标.
@property (nonatomic, assign) CLLocationCoordinate2D rightTop;   //!< 矩形区域，右上角的坐标.
@property (nonatomic, assign) BOOL no_jump;    /**< 城市跳转,默认为YES */

@end


/// 周边搜索参数
@interface CLDNearbySearchOption : CLDPoiSearchOption
@property (nonatomic, assign) CLLocationCoordinate2D center;    //!<  中心点.
@property (nonatomic, assign) int                    range;     //!< 范围,周边搜索的半径.
@end


/// 区域搜索参数
@interface CLDBoundSearchOption : CLDPoiSearchOption
@property (nonatomic, assign) CLLocationCoordinate2D leftBottom; //!< 矩形区域，左下角的坐标.
@property (nonatomic, assign) CLLocationCoordinate2D rightTop;   //!< 矩形区域，右上角的坐标.
@end

