/**
 *  StationModel.h
 *  CldProtocol
 *
 *  Created by Lynn on 15/6/9.
 *  Copyright (c) 2015年 apple. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "BusType.h"

/// 站台信息模型
@interface CLDStationModel : NSObject

@property (nonatomic, copy) NSNumber *stationID; //!< 站点ID.

@property (nonatomic, copy) NSString *name;   //!< 站点名称.

@property (nonatomic) CGPoint point;   //!< 坐标.

@property (nonatomic) PathType type;   //!< 线路类型.

@property (nonatomic, copy) NSNumber *passNum;  //!< 途径线路个数.

@property (nonatomic, strong) NSArray *passList;  //!< 途经站.

@end






