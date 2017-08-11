/**
 * CLDGeocodeSearch.h
 * DevNetworking
 *
 * Created by Lynn on 15/12/7.
 * Copyright © 2015年 Lynn. All rights reserved.
 *
 */

#import "CLDRequest.h"
#import "CLDGeocodeSearchOption.h"
#import "CLDGeocodeType.h"
#import "BaseType.h"

/// 地理编码搜索回调协议
@protocol CLDGeocodeSearchDelegate;

///地理编码搜索
@interface CLDGeocodeSearch : CLDRequest

@property (nonatomic, weak) id<CLDGeocodeSearchDelegate> delegate; //!< 结果回调.

/**
 *  根据地址名称获取地理信息
 *
 *  @param geoCodeOption geo检索信息类
 *
 *  @return 成功返回YES，否则返回NO
 */
- (BOOL)geoCode:(CLDGeocodeSearchOption *)geoCodeOption;

/**
 *  根据地理坐标获取地址信息
 *
 *  @param reverseGeoCodeOption geo检索信息类
 *
 *  @return 成功返回YES，否则返回NO
 */
- (BOOL)reverseGeoCode:(CLDReverseGeocodeSearchOption *)reverseGeoCodeOption;

/**
 *  行政区域搜索
 *
 *  @param option 搜索参数
 *
 *  @return 成功返回YES，失败返回NO
 */
- (BOOL)geoCodeRegion:(CLDGeocodeRegionSearchOption *)option;

@end


///地理编码搜索回调协议
@protocol CLDGeocodeSearchDelegate <NSObject>

@optional

/**
 *  返回地址信息搜索结果
 *
 *  @param searcher  搜索对象
 *  @param result    搜索CldGeoCodeSearch结果
 *  @param errorCode 错误号，@see CLDErrorCode
 */
- (void)onGetGeoCodeResult:(CLDGeocodeSearch *)searcher result:(CLDGeocodeResult *)result errorCode:(CLDErrorCode)errorCode;

/**
 *  返回地理编码搜索结果
 *
 *  @param searcher  搜索对象
 *  @param result    搜索结果
 *  @param errorCode 错误号，@see CLDErrorCode
 */
- (void)onGetReverseGeoCodeResult:(CLDGeocodeSearch *)searcher result:(CLDReverseGeocodeResult *)result errorCode:(CLDErrorCode)errorCode;

/**
 *  返回行政区域搜索结果
 *
 *  @param searcher  搜索对象
 *  @param result    搜索结果
 *  @param errorCode 错误号，@see CLDErrorCode
 */
- (void)onGetGeoCodeRegionResult:(CLDGeocodeSearch *)searcher result:(CLDGeocodeResult *)result errorCode:(CLDErrorCode)errorCode;

@end