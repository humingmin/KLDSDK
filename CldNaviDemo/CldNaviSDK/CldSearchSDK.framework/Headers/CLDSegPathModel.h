/**
 *  SegPathModel.h
 *  CldProtocol
 *
 *  Created by Lynn on 15/6/9.
 *  Copyright (c) 2015年 apple. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "BusType.h"

/// 换乘段 候选线路信息
@interface CLDSegPathModel : NSObject

@property (nonatomic, strong) NSNumber *pathID;   //!< 线路ID.

@property (nonatomic, strong) NSString *pathName;  //!< 线路名.

@property (nonatomic) PathType type;   //!< 线路类型.

@property (nonatomic, strong) NSNumber *price;   //!< 线路总票价.

@property (nonatomic, strong) NSNumber *distance;  //!< 线路距离.

/// 线路开始运营时间(分),小时*60+分钟,如值为450,则换算成HH:MM就是,450/60:450%60=7:30
@property (nonatomic, strong) NSNumber *stime;

@property (nonatomic, strong) NSNumber *etime;   //!< 线路结束运行时间(分).

@property (nonatomic, strong) NSArray *stations; //!< 线路站点列表.

@property (nonatomic, strong) NSArray *shapeCoords;  //!< 线路形状点列表.


@end




