/**
 * CLDGeocodeSearchOption.h
 * DevNetworking
 *
 * Created by Lynn on 15/12/7.
 * Copyright © 2015年 Lynn. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/// 地理编码检索参数
@interface CLDGeocodeSearchOption : NSObject

@property (nonatomic, strong) NSString *address; //!< 地址.

@property (nonatomic, strong) NSString *city;    //!< 城市.
@end


/// 反地理编码参数
@interface CLDReverseGeocodeSearchOption : NSObject
@property (nonatomic, assign) int  maxPoiCount;           //!< 地址周边poi最大个数,默认为1
@property (nonatomic, assign) CLLocationCoordinate2D pt;  //!< 坐标.
@end

/// 行政区域检索参数
@interface CLDGeocodeRegionSearchOption : NSObject

@property (nonatomic, copy) NSString *address;  //!< 地址.
@end