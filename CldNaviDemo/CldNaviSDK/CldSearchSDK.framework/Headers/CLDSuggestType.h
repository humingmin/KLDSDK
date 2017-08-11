/**
 *  CLDSuggestType.h
 *  CldSearchSDK
 *
 *  Created by Lynn on 16/3/3.
 *  Copyright © 2016年 CLD. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CLDPoiType.h"

/// suggest结果
@interface CLDSuggestResult : NSObject

@property (nonatomic, strong) NSArray<CLDPoiInfo *> *pois;  //!< 信息点列表.
@property (nonatomic) UInt32 adcode;  //!< 编码.

@end
