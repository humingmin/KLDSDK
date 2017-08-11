/**
 *  CldPointAnnotation.h
 *  点标注
 *
 *  Created by careland on 16/1/25.
 *  Copyright © 2016年 Careland. All rights reserved.
 *
 */

#import "CldShape.h"
#import "CldTypes.h"

/// 表示一个点的标注
@interface CldPointAnnotation : CldShape
{
    CLLocationCoordinate2D _coordinate;   //!< 该点的坐标.
}
/// 该点的坐标
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

/**
 *  判断是否与创建的点标注相同
 *
 *  @param object 传进来的点得标注
 *
 *  @return YES/NO
 */
- (BOOL)isEqualToCldPointAnnotation:(CldPointAnnotation*)object;


@end
