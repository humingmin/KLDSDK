/**
 *  CldAnimatedAnnotationView.h
 *  动画标注视图
 *
 *  Created by careland on 16/1/26.
 *  Copyright © 2016年 Careland. All rights reserved.
 *
 */

#import "CldAnnotationView.h"

/// 表示动画视图
@interface CldAnimatedAnnotationView : CldAnnotationView

@property (nonatomic, strong) NSMutableArray * animatedImages;   //!< 播放动画的图片数组.
@property (nonatomic, strong) UIImageView * animatedImageView;   //!< 动画图像视图.

@end
