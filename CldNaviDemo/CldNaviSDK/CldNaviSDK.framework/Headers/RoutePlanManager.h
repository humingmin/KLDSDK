/**
 *  RoutePlanManager.h 
 *  路劲计算管理
 *
 *  Created by huangzh on 15/12/18.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "NaviRoutePlanModel.h"
#import "RoutePlanDelegate.h"
#import "CldRoutePlanType.h"

/// 此类为路径计算管理类
@interface RoutePlanManager : NSObject

/**
 *  获取单例对象
 *
 *  @return RoutePlanManager 单例对象
 */
+ (RoutePlanManager*)GetInstance;

/**
 *  发起驾车算路
 *
 *  @param eMode     算路方式，定义见RoutePlanMode
 *  @param bAvoid    是否躲避拥堵
 *  @param naviNodes 算路节点数组,起点，途径点，终点，节点信息为RoutePlanNode结构
 *                   起点为可选项，缺省时起点为当前位置，途径点最多可设置两个
 *  @param delegate  算路委托，用于回调
 *  @param userInfo  用户需要传人的参数
 *
 *  @return 发起驾车算路结果，参照：StartRoutePlanError定义
 */
- (StartRoutePlanError)startNaviRoutePlan:(RoutePlanMode)eMode
                avoidTrafficJam:(BOOL)bAvoid
                naviNodes:(NSArray *)naviNodes
                 delegate:(id<RoutePlanDelegate>)delegate
                 userInfo:(NSDictionary *)userInfo;

/**
 *  发起步行算路
 *
 *  @param routeNodes 算路节点数组,起点，途径点，终点，节点信息为RoutePlanNode结构
 *                   起点为可选项，缺省时起点为当前位置，途径点最多可设置两个
 *  @param delegate  算路委托，用于回调
 *  @param userInfo  用户需要传人的参数
 *
 *  @return 发起步行算路结果，参照：StartRoutePlanError定义
 */
- (StartRoutePlanError)startWalkRoutePlan:(NSArray *)routeNodes
                                delegate:(id<RoutePlanDelegate>)delegate
                                userInfo:(NSDictionary *)userInfo;

/**
 *  发起货车导航路线规划，规划前要先设置货车参数
 *
 *  @param eMode     算路方式，定义见RoutePlanMode
 *  @param bAvoid    是否躲避拥堵
 *  @param naviNodes 算路节点数组,起点，途径点，终点，节点信息为RoutePlanNode结构
 *                   起点为可选项，缺省时起点为当前位置，途径点最多可设置两个
 *  @param delegate  算路委托，用于回调
 *  @param userInfo  用户需要传人的参数
 *
 *  @return 发起驾车算路结果，参照：StartRoutePlanError定义
 */
- (StartRoutePlanError)startTruckNaviRoutePlan:(RoutePlanMode)eMode
                          avoidTrafficJam:(BOOL)bAvoid
                                naviNodes:(NSArray *)naviNodes
                                 delegate:(id<RoutePlanDelegate>)delegate
                                 userInfo:(NSDictionary *)userInfo;

/**
 *  获取当前节点总数
 *
 *  @return 当前节点总数
 */
- (NSInteger)getCurNodeCount;

/**
 *  获取当前路径规划方式
 *  @param bAvoidTrafficJam 输出是否躲避拥堵
 *  @return 当前路径规划方式
 */
- (int)getCurRoutePlanMode:(BOOL *)bAvoidTrafficJam;

/**
 *  获取第index个节点
 *
 *  @param index 节点序号
 *
 *  @return 第index个节点
 */
- (RoutePlanNode *)getNaviNodeAtIndex:(NSInteger)index;

/**
 *  取消路径计算，取消成功后会回调onRoutePlanCancel
 */
- (void)cancelRoutePlan;

/**
 *  删除路径
 */
- (void)cleanRoute;

/**
 *  获取当前驾车行程信息
 *
 *  @return 驾车路线信息
 */
- (CLDDrivingRouteLine *)getDrivingRouteInfo;

/**
 *  获取当前步行行程信息
 *
 *  @return 步行路线信息
 */
- (CLDWalkRouteLine *)getWalkRouteInfo;

/**
 *  全程浏览（宽或高为0时取消全程浏览）
 *
 *  @param isShow  是否显示全程概览
 */
- (void)showWholeRoute:(BOOL)isShow;

/**
 *  设置是否支持多路径，默认为NO
 *
 *  @param bSupport 是否支持多路径
 */
- (void)setSupportMutiRoute:(BOOL)bSupport;

/**
 *  获取路径条数，支持多路径时使用
 *
 *  @return 路径条数
 */
- (short)getRouteNums;

/**
 *  选择一条路径
 *
 *  @param index 路径索引，从1开始
 */
- (void)selectRouteAtIndex:(int)index;

/**
 *  高亮显示一条路径
 *
 *  @param index 路径索引，从1开始
 */
- (void)hightRouteAtIndex:(int)index;

/**
 *  获取当前高亮路径索引
 *
 *  @return 路径索引
 */
- (int)getHightRouteIndex;

/**
 *  获取路径经过道路描述信息
 *
 *  @param index 路径索引，从1开始
 *
 *  @return 经过的道路信息描述
 */
- (NSString *)getRdRoadDescAtIndex:(int)index;

/**
 *  获取路径的总距离和总时间
 *
 *  @param index 路径索引，从1开始
 *
 *  @return 总距离和总时间
 */
- (CLDRouteLineDistanceTime *)getTotalDistanceAndTimeAtIndex:(int)index;

/**
 *  恢复多路径，多路径选择一条路径后，需要再显示多路径时调用
 */
- (void) recoverMutiRoute;

/**
 *  获取路径分享链接
 *
 *  @return 分享链接
 */
- (NSString *) getRouteShareUrl;

/**
 *  根据路径索引获取路径上红绿灯个数，路径未选择前有效
 *
 *  @param index 路径索引，从1开始
 *
 *  @return 红绿灯个数
 */
- (int)getTrafficLightCountAtIndex:(int)index;

/**
 *  获取选择路径上红绿灯个数
 *
 *
 *  @return 红绿灯个数
 */
- (int)getTrafficLightCount;

@end
