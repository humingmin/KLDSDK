/**
 *  CldOverlay.h 
 *  覆盖物
 *
 *  Created by linfengkun on 15/12/16.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef CldOverlay_h
#define CldOverlay_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// 表示一个覆盖物
@interface CldOverlay : NSObject

/// 覆盖物的坐标串 类型为CGPoint
@property (nonatomic, retain) NSArray *overlayPoints;
/// 边线宽度
@property (nonatomic, assign) int  borderWidth;
/// 边线颜色
@property (nonatomic, strong) UIColor * borderColor;  
/// 填充颜色
@property (nonatomic, strong) UIColor * fillColor;

@end

/// 表示一个线覆盖物
@interface CldOverlayLine : CldOverlay
/// 线图片,使用图片画线
@property (nonatomic, strong) UIImage * image;
@end

/// 表示一个多边形覆盖物
@interface CldOverlayPolygon : CldOverlay

@end

#endif /* CldOverlay_h */
