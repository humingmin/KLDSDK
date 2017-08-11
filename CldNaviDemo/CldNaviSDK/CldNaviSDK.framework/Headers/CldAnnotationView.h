/**
 *  CldAnnotationView.h
 *  标注视图
 *
 *  Created by careland on 16/1/25.
 *  Copyright © 2016年 Careland. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>
#import "CldPointAnnotation.h"

/// 表示标注视图
@interface CldAnnotationView : UIView
{
    UIImage * _image;   //!< 默认为水滴样式图片.
}
/**
 *  初始化并返回一个annotationView
 *
 *  @param annotation      关联的annotation对象
 *  @param reuseIdentifier 复用标识符，如果需要复用则传入一个字符串，否则为nil
 *
 *  @return 初始化成功并返回annotationView否则返回nil
 */
- (instancetype)initWithAnnotation:(id <CldAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier;

@property (nonatomic, readonly, copy) NSString * reuseIdentifier;  //!< 复用标识符.

@property (nonatomic, assign) id <CldAnnotation>annotation; //!< 标注.

/// 默认弹出泡泡view，可自定义
@property (nonatomic, strong) UIView * popView;

/// 默认为水滴样式图片，可任意更换图片
@property (nonatomic, strong) UIImage * image;

/// 默认情况下，annotationView的中心位于annotation的坐标位置，可以设置centerOffset改变view的位置，正的偏移使view向右下方移动，负的向左上方，单位是像素
@property (nonatomic, assign) CGPoint centerOffset;

/// 默认情况下，弹出的气泡view位于annotationView的正中上方，可以设置calloutViewOffset改变气泡view的位置，正的偏移使view向右下方移动，负的向左上方，单位是像素
@property (nonatomic, assign) CGPoint calloutViewOffset;

@property (nonatomic, getter=isEnabled) BOOL enabled;  //!< 是否可以响应触摸事件，默认YES.

@property (nonatomic, getter=isCanShowCallOut) BOOL canShowCallout; //!< 是否可以弹出气泡，默认为YES.

@end
