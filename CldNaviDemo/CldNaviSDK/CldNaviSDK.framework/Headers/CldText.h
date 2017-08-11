/**
 *  CldText.h 
 *  地图上现实的文本
 *
 *  Created by linfengkun on 15/12/29.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef CldText_h
#define CldText_h

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

/// 覆盖物文本
@interface CldText : NSObject

/// 文本.
@property (nonatomic, copy)NSString *textString;
/// 字体颜色
@property (nonatomic, strong)UIColor * textColor;
/// 字体背景颜色
@property (nonatomic, strong)UIColor * textBkColor;
/// 字体大小
@property (nonatomic, assign)int textFont;
/// 平面旋转角度(逆时针)，>0有效
@property (nonatomic, assign)short rotationAngle;
/// 俯视旋转角度(预留，暂时不支持)
@property (nonatomic, assign)short lookDownAngle;
/// 文本的坐标
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

#endif /* CldText_h */
