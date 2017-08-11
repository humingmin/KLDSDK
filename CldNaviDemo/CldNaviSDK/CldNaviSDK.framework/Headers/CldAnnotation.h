/**
 *  CldAnnotation.h 
 *  地图标注
 *
 *  Created by linfengkun on 15/12/16.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef CldAnnotation_h
#define CldAnnotation_h

#import <Foundation/Foundation.h>
#import "CldTypes.h"

/// 该类为标注点的protocol，提供了标注类的基本信息函数
@protocol CldAnnotation <NSObject>

@property (nonatomic, readonly) CLLocationCoordinate2D coordinate; //!< 标注view中心坐标.

@optional
/**
 *  获取annotation标题
 *
 *  @return 返回annotation的标题
 */
- (NSString *)title;

/**
 *  获取annotation副标题
 *
 *  @return 返回annotation的副标题
 */
- (NSString *)subtitle;

/**
 *  设置标注的坐标，在拖拽时会被调用
 *
 *  @param newCoordinate newCoordinate新的坐标值
 */
- (void)setCoordinate:(CLLocationCoordinate2D)newCoordinate;

@end

#endif /* CldAnnotation_h */
