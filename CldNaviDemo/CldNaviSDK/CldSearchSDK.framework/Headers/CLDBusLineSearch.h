/**
 *  CLDBusLineSearch.h
 *  CldSearchSDK
 *
 *  Created by Lynn on 16/1/21.
 *  Copyright © 2016年 CLD. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "BaseType.h"
#import "CLDBusLineSearchOption.h"
#import "CLDBusLineSearchType.h"

/// 公交路线检索回调
@protocol CLDBusLineSearchDelegate;

/// busline搜索服务
@interface CLDBusLineSearch : NSObject

@property (nonatomic, weak) id<CLDBusLineSearchDelegate> delegate;    //!< 搜索Delgate.

/**
 *  公交站点查询(根据站点名)
 *
 *  @param busLineSearchOption 公交站点检索信息类
 *
 *  @return 成功返回YES，否则返回NO
 */
- (BOOL)busStationSearch:(CLDBusStationSearchOption *)busLineSearchOption;

/**
 *  公交线路检索(根据线路查询)
 *
 *  @param busLineSearchOption 公交线路检索信息类
 *
 *  @return 成功返回YES，否则返回NO
 */
- (BOOL)busLineSearch:(CLDBusLineSearchOption *)busLineSearchOption;

/**
 *  公交线路详情查询
 *
 *  @param option 公交线路详情检索信息类
 *
 *  @return 成功返回YES，否则返回NO
 */
- (BOOL)busLineDetailSerach:(CLDBusLineDetailSearchOption *)option;

/**
 *  公交换乘方案检索(根据起点终点，查询公交线路)
 *
 *  @param busLineSearchOption 公交换乘方案信息类
 *
 *  @return 成功返回YES， 否则返回NO
 */
- (BOOL)busLinePlanSearch:(CLDBusLinePlanSearchOption *)busLineSearchOption;

/**
 *  公交线路换乘段检索
 *
 *  @param CLDBusLineSegPathSearchOption 公交线路换乘段检索信息类
 *  @param searchPhrases 检索短语，多个短语可用"-"分隔，检索短语如果为空，则检索所有的线路
 *
 *  @return 成功返回YES，否则返回NO
 */
- (BOOL)busLineSegPathSearch:(CLDBusLineSegPathSearchOption *)busLineSegPathSearchOption searchPhrases:(NSString *)searchphrases;

@end


/// 搜索delegate，用于获取搜索结果
@protocol CLDBusLineSearchDelegate<NSObject>

@optional
/**
 *  返回公交站点查询搜索结果
 *
 *  @param searcher         搜索对象
 *  @param busStationResult 搜索结果
 *  @param error            错误号
 */
- (void)onGetBusStationResult:(CLDBusLineSearch *)searcher result:(CLDBusStationResult *)busStationResult errorCode:(CLDErrorCode)error;

/**
 *  公交线路查询搜索结果
 *
 *  @param searcher      搜索对象
 *  @param busLineResult 搜索结果
 *  @param error         错误号
 */
- (void)onGetBusLineResult:(CLDBusLineSearch *)searcher result:(CLDBusLineResult *)busLineResult errorCode:(CLDErrorCode)error;

/**
 *  公交线路详情查询搜索结果
 *
 *  @param searcher      搜索对象
 *  @param busLineResult 搜多结果
 *  @param error         错误号
 */
- (void)onGetBusLineDetailResult:(CLDBusLineSearch *)searcher result:(CLDBusLineResult *)busLineResult errorCode:(CLDErrorCode)error;

/**
 *  返回公交换乘搜索结果
 *
 *  @param searcher      搜多对象
 *  @param busLineResult 搜索结果
 *  @param error         错误号
 */
- (void)onGetBusLinePlanResult:(CLDBusLineSearch *)searcher result:(NSArray *)busLineResult errorCode:(CLDErrorCode)error;

/**
 *  返回公交线路换乘段搜索结果
 *
 *  @param searcher      搜索对象
 *  @param busLineResult 搜索结果
 *  @param error         错误号
 */
- (void)onGetBusLineSegPathResult:(CLDBusLineSearch *)searcher result:(NSArray *)busLineSegPathResult errorCode:(CLDErrorCode)error;

@end
