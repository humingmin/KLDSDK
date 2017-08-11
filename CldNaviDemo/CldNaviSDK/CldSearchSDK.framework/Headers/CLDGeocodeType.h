/**
 * CLDGeocodeType.h
 * CldSearchSDK
 *
 * Created by Lynn on 15/12/11.
 * Copyright © 2015年 CLD. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "CLDPoiType.h"


/// 地理编码结果
@interface CLDGeocodeResult : NSObject

@property (nonatomic, assign) CLLocationCoordinate2D location;      //!< 坐标.
@property (nonatomic, strong) NSString *address;                    //!< 地理编码地址.
@property (nonatomic, strong) NSArray *shapes;                      //!< 形状点集合.

@end


/// 反地理编码结果
@interface CLDReverseGeocodeResult : NSObject

@property (nonatomic, assign) CLLocationCoordinate2D location;      //!< 地址坐标.
@property (nonatomic, strong) NSString *address;                    //!< 地址名称.
@property (nonatomic, strong) CLDAddressComponent *addressDetail;   //!< 层次化地址信息.
@property (nonatomic, strong) NSArray<CLDPoiInfo *>* poiList;       //!< 地址周边POI信息.
@property (nonatomic, strong) NSString* businessCircle;             //!< 商圈名称.
@property (nonatomic, strong) NSString *street;                     //!< 街道.
@property (nonatomic, strong) NSString *streetNumber;               //!< 门牌号.

@end
