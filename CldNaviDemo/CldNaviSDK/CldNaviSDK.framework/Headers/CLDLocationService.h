/**
 *  CLDLocationService.h
 *  定位服务管理器
 *
 *  Created by huangzh on 15/12/28.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef CLDLocationService_h
#define CLDLocationService_h

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class CLLocation;
/// 定位服务Delegate,调用startUserLocationService定位成功后，用此Delegate来获取定位数据
@protocol CLDLocationServiceDelegate <NSObject>

@optional
/**
 *  在将要启动定位时，会调用此函数
 */
- (void)willStartLocatingUser;

/**
 *  在停止定位后，会调用此函数
 */
- (void)didStopLocatingUser;

/**
 *  用户位置更新后，会调用此函数
 *
 *  @param location userLocation 新的用户位置
 */
- (void)didUpdateCLDUserLocation:(CLLocation *)location;

/**
 *  定位失败后，会调用此函数
 *
 *  @param error 错误号
 */
- (void)didFailToLocateUserWithError:(NSError *)error;

@end

/// 定位服务管理器
@interface CLDLocationService : NSObject

/// 当前用户位置，返回坐标为凯立德坐标
@property (nonatomic, readonly) CLLocationCoordinate2D userLocation;

/// 定位是否有效
@property (nonatomic,readonly) BOOL isLocationValid;


/// 定位服务Delegate,调用startUserLocationService定位成功后，用此Delegate来获取定位数据
@property (nonatomic, weak) id<CLDLocationServiceDelegate> delegate;

/**
 *  获取单例对象
 *
 *  @return CLDLocationService 单例对象
 */
+ (CLDLocationService*)GetInstance;

/**
 *  打开定位服务
 *  需要在info.plist文件中添加(以下二选一，两个都添加默认使用NSLocationWhenInUseUsageDescription)：
 *  NSLocationWhenInUseUsageDescription 允许在前台使用时获取GPS的描述
 *  NSLocationAlwaysUsageDescription 允许永远可获取GPS的描述
 */
-(void)startUserLocationService;

/**
 *  关闭定位服务
 */
-(void)stopUserLocationService;

/**
 *  启动更新罗盘信息
 */
-(void)startUpdatingHeading;

/**
 *  停止更新罗盘信息
 */
-(void)stopUpdatingHeading;

#pragma mark - 定位参数，具体含义可参考CLLocationManager相关属性的注释

/// 设定定位的最小更新距离。默认为kCLDistanceFilterNone
@property(nonatomic, assign) CLLocationDistance distanceFilter;

/// 设定定位精度。默认为kCLLocationAccuracyBest。
@property(nonatomic, assign) CLLocationAccuracy desiredAccuracy;

/// 指定定位是否会被系统自动暂停。默认为YES。只在iOS 6.0之后起作用。
@property(nonatomic, assign) BOOL pausesLocationUpdatesAutomatically;

/// 指定定位：是否允许后台定位更新。默认为NO。只在iOS 9.0之后起作用。设为YES时，Info.plist中 UIBackgroundModes 必须包含 "location"
@property(nonatomic, assign) BOOL allowsBackgroundLocationUpdates;

@end

#endif
