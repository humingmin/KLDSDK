/**
 *  HourGlass.h 
 *  自定义漏斗控件
 *
 *  Created by huangzh on 14-6-16.
 *  Copyright (c) 2014年 careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 协议代理，如果漏斗有取消按钮，需要实现代理，外面处理取消逻辑
@protocol HourGlassDelegate<NSObject>

@optional
/**
 *  取消操作
 */
- (void)cacelPerformOperation;

/**
 *  取消操作
 *
 *  @param tag tag值
 */
- (void)cacelPerformOperation:(int)tag;
@end

/// 漏斗控件
@interface HourGlass : UIView
{
    id <HourGlassDelegate> delegate;  //!< 代理.
}

/**
 *  显示漏斗
 *
 *  @param text     文本
 *  @param isShow   是否显示
 *  @param delegate delegate
 */
+ (void)showHourglass:(NSString *)text ShowCancel:(BOOL)isShow Delegate:(id)delegate;

/**
 *  显示漏斗
 *
 *  @param text     文本
 *  @param isShow   是否显示
 *  @param delegate delegate
 *  @param tag      tag值
 */
+ (void)showHourglass:(NSString *)text ShowCancel:(BOOL)isShow Delegate:(id)delegate Tag:(int)tag;

/**
 *  设置漏斗文本
 *
 *  @param text 文本
 */
+ (void)setHourglassText:(NSString *)text;

/**
 *  隐藏漏斗
 */
+ (void)hideHourglass;


@end




