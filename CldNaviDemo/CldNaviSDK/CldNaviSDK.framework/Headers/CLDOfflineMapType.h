/**
 *  CLDOfflineMap.h
 *  离线地图下载类型定义
 *
 *  Created by huangzh on 16/3/16.
 *  Copyright © 2016年 Careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 地图下载任务的状态
typedef enum _enumMAPDLTASK_STATUS
{
    MAPDLTASK_STATUS_WAIT        = 1<<0,          ///<等待下载
    MAPDLTASK_STATUS_PAUSE       = 1<<1,          ///<暂停下载
    MAPDLTASK_STATUS_DOWNLOADING = 1<<2,          ///<下载中
    MAPDLTASK_STATUS_DLFAIL      = 1<<3,          ///<下载失败
    MAPDLTASK_STATUS_COMPLETE    = 1<<4,          ///<下载完成
    MAPDLTASK_STATUS_DLHASNEW    = 1<<5,          ///<下载中有更新
    MAPDLTASK_STATUS_HASNEW      = 1<<6,          ///<下载完成有更新
    
}MAPDLTASK_STATUS;

///离线地图搜索城市记录结构
@interface CLDOLSearchRecord : NSObject
///城市名称
@property (nonatomic, retain) NSString* cityName;
///数据包总大小，单位：字节
@property (nonatomic) int size;
///城市ID
@property (nonatomic) int cityID;
///子城市列表
@property (nonatomic, retain) NSArray*  childCities;


@end


///离线地图更新信息
@interface CLDOLUpdateElement : NSObject
///城市名称
@property (nonatomic, retain) NSString* cityName;
///城市ID
@property (nonatomic) int cityID;
///已下载数据大小，单位：字节
@property (nonatomic) int size;
///服务端数据包总大小，单位：字节
@property (nonatomic) int serversize;
///下载比率，100为下载完成
@property (nonatomic) int ratio;
///下载状态
@property (nonatomic) MAPDLTASK_STATUS status;

@end


