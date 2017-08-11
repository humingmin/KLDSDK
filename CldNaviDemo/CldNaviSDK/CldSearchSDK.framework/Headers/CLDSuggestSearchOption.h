/**
 *  CLDSuggestSearchOption.h
 *  CldSearchSDK
 *
 *  Created by Lynn on 16/3/3.
 *  Copyright © 2016年 CLD. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/// suggest信息检索类
@interface CLDSuggestSearchOption : NSObject

@property (nonatomic, strong) NSString *keyword;   //!< 搜索关键字.

@property (nonatomic, strong) NSString *cityname;  //!< 城市名.

@property (nonatomic, assign) CLLocationCoordinate2D center;  //!< 中心点.

@property (nonatomic, assign) CLLocationCoordinate2D leftBottom; //!< 矩形区域，左下角的坐标.

@property (nonatomic, assign) CLLocationCoordinate2D rightTop;   //!< 矩形区域，右上角的坐标.

@end
