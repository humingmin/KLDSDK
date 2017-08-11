/**
 *  ChangeSchemeModel.h
 *  CldProtocol
 *
 *  Created by Lynn on 15/6/9.
 *  Copyright (c) 2015年 apple. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 换乘方案
@interface CLDChangeSchemeModel : NSObject

@property (nonatomic, strong) NSArray *walkList;   //!< 步行信息列表.

@property (nonatomic, strong) NSArray *schemeSegmentList;  //!< 公交地铁换乘信息列表.

@property (nonatomic, strong) NSString *label;    //!< 名称.

@property (nonatomic, strong) NSString *startName; //!< 起点名称
@property (nonatomic, strong) NSString *destName;  //!< 终点名称

@end
