/**
 *  CLDOfflineMap.h
 *  离线地图下载
 *
 *  Created by huangzh on 16/3/16.
 *  Copyright © 2016年 Careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CLDOfflineMapType.h"

///离线地图事件类型
enum  {
    TYPE_OFFLINE_UPDATE = 0,        ///<下载状态更新
    TYPE_OFFLINE_COMPLETE = 1,		///<下载完成（整个下载列表下载完成）
    TYPE_OFFLINE_STOP	= 2,        ///<暂停下载
    TYPE_OFFLINE_FAILED = 3,		///<下载失败
    TYPE_OFFLINE_SHITNET = 4,       ///<下载出错，但是会一值尝试
    TYPE_OFFLINE_START = 5,         ///<开始下载
    TYPE_OFFLINE_REMOVE = 6,        ///<删除下载任务
};

@protocol CLDOfflineMapDelegate;

///离线地图服务
@interface CLDOfflineMap : NSObject

///离线下载的Delegate，此处记得不用的时候需要置nil，否则可能会导致奔溃
@property (nonatomic, assign) id<CLDOfflineMapDelegate> delegate;

/**
 *启动下载指定城市id的离线地图
 *@param cityID 指定的城市id
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)start:(int)cityID;

/**
 *启动更新指定城市id的离线地图
 *@param cityID 指定的城市id
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)update:(int)cityID;

/**
 *暂停下载指定城市id的离线地图
 *@param cityID 指定的城市id
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)pause:(int)cityID;

/**
 *删除下载指定城市id的离线地图
 *@param cityID 指定的城市id
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)remove:(int)cityID;

/**
 *返回热门城市列表
 *@return 热门城市列表，数组元素为CLDOLSearchRecord
 */
- (NSArray*)getHotCityList;

/**
 *返回所有支持离线地图的城市列表
 *@return 支持离线地图的城市列表，数组元素为CLDOLSearchRecord
 */
- (NSArray*)getOfflineCityList;

/**
 *根据城市名搜索该城市离线地图记录
 *@param cityName 城市名
 *@return 该城市离线地图记录，数组元素为CLDOLSearchRecord
 */
- (NSArray*)searchCity:(NSString*)cityName;

/**
 *返回各城市离线地图更新信息
 *@return 各城市离线地图更新信息，数组元素为CLDOLUpdateElement
 */
- (NSArray*)getAllUpdateInfo;

/**
 *返回指定城市id离线地图更新信息
 *@param cityID 指定的城市id
 *@return 指定城市id离线地图更新信息
 */
- (CLDOLUpdateElement*)getUpdateInfo:(int)cityID;

@end


///离线地图delegate，用于获取通知
@protocol CLDOfflineMapDelegate<NSObject>
/**
 *  返回通知结果
 *
 *  @param state  地图状态
 *  @param cityID 城市ID
 */
- (void)onGetOfflineMapState:(int)state withCityID:(int)cityID;

@end
