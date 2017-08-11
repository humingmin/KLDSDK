/**
 *  PassPathInfoModel.h
 *  CldProtocol
 *
 *  Created by Lynn on 15/6/12.
 *  Copyright (c) 2015年 apple. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 公交站点途经路信息结构
@interface CLDPassPathInfoModel : NSObject

@property (nonatomic, copy) NSNumber *pathID;   //!< 线路ID.

@property (nonatomic, copy) NSString *pathName; //!< 线路名.

@property (nonatomic, copy) NSNumber *startTime; //!< 运营开始时间.

@property (nonatomic, copy) NSNumber *endTime;   //!< 运营结束时间.

@property (nonatomic, copy) NSNumber *stationNumber;   //!< 站点数.

@property (nonatomic, copy) NSNumber *distance;   //!< 距离.

@end
