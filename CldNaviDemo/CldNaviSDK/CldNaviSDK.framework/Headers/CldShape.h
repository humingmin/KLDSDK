/**
 *  CldShape.h
 *  基于CldAnnotation的一个抽象类
 *
 *  Created by careland on 16/1/25.
 *  Copyright © 2016年 Careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CldAnnotation.h"

/// 该类为一个抽象类，定义了基于CldAnnotation的CldShape类的基本属性和行为，不能直接使用，必须子类化之后才能使用
@interface CldShape : NSObject <CldAnnotation>
{
    NSString * _title;    //!< 要显示的标题.
    NSString * _subtitle; //!< 要显示的副标题.
}

@property (nonatomic, copy) NSString * title;    //!< 要显示的标题.

@property (nonatomic, copy) NSString * subtitle; //!< 要显示的副标题.

@end
