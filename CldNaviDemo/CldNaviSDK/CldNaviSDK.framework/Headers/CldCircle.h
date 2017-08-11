/**
 *  CldCircle.h 
 *  覆盖物--圆
 *
 *  Created by linfengkun on 15/12/21.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef CldCircle_h
#define CldCircle_h

#import <Foundation/Foundation.h>
#import "CldTypes.h"

/// 表示一个圆
@interface CldCircle : NSObject

/// 圆心位置
@property (nonatomic, assign) CLLocationCoordinate2D center;
/// 半径长度(单位米)
@property (nonatomic, assign) CGFloat radius;
/// 边线宽度
@property (nonatomic, assign) int  borderWidth;
/// 边线颜色
@property (nonatomic, strong) UIColor * borderColor;
/// 填充颜色
@property (nonatomic, strong) UIColor * fillColor;

@end


#endif /* CldCircle_h */
