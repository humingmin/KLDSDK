/**
 * CLDSearch.h
 * DevNetworking
 *
 * Created by Lynn on 15/12/7.
 * Copyright © 2015年 Lynn. All rights reserved.
 *
 */

#import "CLDRequest.h"
#import "CLDPoiType.h"
#import "CLDPoiSearchOption.h"
#import "BaseType.h"

/// poi搜索回调协议
@protocol CLDPoiSearchDelegate;

/// 搜索服务
@interface CLDPoiSearch : NSObject

@property (nonatomic, weak) id<CLDPoiSearchDelegate> delegate;    //!< 结果回调.


/**
 *  周边搜索
 *  @param option 搜索参数
 *  @return 成功返回YES，失败返回NO
 */
- (BOOL)poiSearchNearBy:(CLDNearbySearchOption *)option;

/**
 *  区域搜索
 *  @param option 搜索参数
 *  @return 成功返回YES，失败返回NO
 */
- (BOOL)poiSearchInBounds:(CLDBoundSearchOption *)option;

/**
 *  城市搜索 指定城市的关键字搜索
 *  @param option 搜索参数
 *  @return 成功返回YES，失败返回NO
 */
- (BOOL)poiSearchInCity:(CLDCitySearchOption *)option;

@end

/// POI搜索回调协议
@protocol CLDPoiSearchDelegate <NSObject>

/**
 *  返回poi搜索信息搜索结果
 *
 *  @param searcher  搜索对象
 *  @param poiResult 搜索结果
 *  @param errorCode 错误码
 */
- (void)onGetPoiResult:(CLDPoiSearch *)searcher result:(CLDPoiResult*)poiResult errorCode:(CLDErrorCode)errorCode;

@end