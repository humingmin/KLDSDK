/**
 *  SchemeSegmentModel.h
 *  CldProtocol
 *
 *  Created by Lynn on 15/6/9.
 *  Copyright (c) 2015年 apple. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "BusType.h"

/// 公交地铁换乘段信息
@interface CLDSchemeSegmentModel : NSObject

@property (nonatomic, strong) NSNumber *distance;   //!< 总距离.

@property (nonatomic, strong) NSNumber *time;   //!< 总时间，单位秒.

@property (nonatomic, strong) NSNumber *pathID;   //!< 线路ID.

@property (nonatomic, copy) NSString *pathName;   //!< 线路名.

@property (nonatomic) PathType type;   //!< 线路类型.

@property (nonatomic, strong) NSArray *segPaths;    //!< 候选线路列表.

@property (nonatomic, strong) NSArray *stations;    //!< 经过站台列表.

@property (nonatomic, strong) NSArray *shapeCoords; //!< 形状点数据.

@end
