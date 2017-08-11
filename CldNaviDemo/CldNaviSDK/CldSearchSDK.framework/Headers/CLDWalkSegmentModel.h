/**
 *  WalkSegmentModel.h
 *  CldProtocol
 *
 *  Created by Lynn on 15/6/9.
 *  Copyright (c) 2015年 apple. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 步行段信息
@interface CLDWalkSegmentModel : NSObject

@property (nonatomic, strong) NSNumber *distance;   //!< 总距离.

@property (nonatomic, strong) NSNumber *time;      //!< 总时间，单位秒.

@property (nonatomic, strong) NSNumber *shapeNum;  //!< 形状点数.

@property (nonatomic, strong) NSArray  *shapeCoords;  //!< 形状点数据.

@end
