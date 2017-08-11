/**
 *  CldMapView.h
 *  凯立德地图
 *
 *  Created by linfengkun on 15/12/8.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#ifndef CldMapView_h
#define CldMapView_h

#import "CldTypes.h"
#import "CldOverlay.h"
#import "CldAnnotation.h"
#import "CldAnimatedAnnotationView.h"
#import "CldPointAnnotationView.h"
#import "CldText.h"
#import "CldCircle.h"

/// 凯立德地图代理协议
@protocol CldMapViewDelegate;

/// 点击地图标注返回数据结构
@interface CldMapPoi : NSObject

@property (nonatomic,strong) NSString* text;   //!< 点标注的名称.
@property (nonatomic,assign) CLLocationCoordinate2D pt;  //!< 点标注的凯立德坐标.

@end

/// 地图View类，使用此View可以显示地图窗口，并且对地图进行相关的操作
@interface CldMapView : UIView

/// 地图View的Delegate，此处记得不用的时候需要置nil，否则影响内存的释放
@property (nonatomic, weak) id<CldMapViewDelegate> delegate;

/// 当前地图的中心点，改变该值时，地图的比例尺级别不会发生变化
@property (nonatomic) CLLocationCoordinate2D centerCoord;

/// 用户当前位置
@property (nonatomic,readonly) CLLocationCoordinate2D userLocation;

/// 用户当前位置是否有效
@property (nonatomic,readonly) BOOL isLocationValid;

/// 设定是否显示用户位置，默认为YES
@property (nonatomic) BOOL showsUserLocation;

/// 当前地图的视图模式
@property (nonatomic) CldMapViewMode   mapViewMode;

/// 当前的地图比例尺级别
@property (nonatomic) float zoomLevel;
/// 地图的自定义最小比例尺级别
@property (nonatomic, readonly) float minZoomLevel;
/// 地图的自定义最大比例尺级别
@property (nonatomic, readonly) float maxZoomLevel;

/// 地图旋转角度，在手机上当前可使用的范围为0～359度
@property (nonatomic) short rotation;

/// 地图最大俯视角度，3D模式下有效
@property (nonatomic,readonly) short maxLookAngle;

/// 地图俯视角度，3D模式下有效，范围为：0～max度，max通过maxLookAngle获取
@property (nonatomic) short lookAngle;

/// 设定地图是否现显示3D楼块效果
@property(nonatomic, getter=isBuildingsEnabled) BOOL buildingsEnabled;

/// 设定地图是否显示底图poi标注，默认YES
@property(nonatomic, assign) BOOL showMapPoi;

/// 设定地图是否打开路况图层
@property(nonatomic, getter=isTrafficEnabled) BOOL trafficEnabled;

/// 设定地图View能否支持用户多点缩放(双指)
@property(nonatomic, getter=isZoomEnabled) BOOL zoomEnabled;
/// 设定地图View能否支持用户缩放(单指双击或双指单击)
@property(nonatomic, getter=isZoomEnabledWithTap) BOOL zoomEnabledWithTap;
/// 设定地图View能否支持用户移动地图
@property(nonatomic, getter=isScrollEnabled) BOOL scrollEnabled;
/// 设定地图View能否支持旋转
@property(nonatomic, getter=isRotateEnabled) BOOL rotateEnabled;
/// 设定地图View能否支持点选POI
@property(nonatomic, getter=isTouchOnEnabled) BOOL touchOnEnabled;
/// 设定地图View能否支持用户长按
@property(nonatomic, getter=isLongPressEnabled) BOOL longPressEnabled;
/// 设定地图View能否支持用户下拉和上推切换地图模式
@property(nonatomic, getter=isUpDownEnable) BOOL upDownEnabled;

/// 设定是否显式比例尺
@property (nonatomic) BOOL showMapScaleBar;
/// 设定是否显示放大缩小按钮
@property (nonatomic) BOOL showZoomButton;

/// 比例尺的位置，设定坐标以CldMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint mapScaleBarPosition;

/// 放大缩小按钮的位置，设定坐标以CldMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint zoomBtnPosition;

/// 指南针按钮的位置，设定坐标以CldMapView左上角为原点，向右向下增长
@property (nonatomic) CGPoint compassBtnPosition;

/**
 *  当应用即将进入后台时调用，停止一切调用opengl相关的操作.
 */
+(void)willEnterBackGround;

/**
 *  当应用恢复前台状态时调用.
 */
+(void)didReturnForeGround;

/**
 *  获取当前设置的白天黑夜模式
 *
 *  @return 白天黑夜模式
 */
+(CldMapDisplayMode)getMapDisplayMode;

/**
 *  设置白天黑夜模式
 *
 *  @param displayMode 白天黑夜模式
 */
+(void)setMapDisplayMode:(CldMapDisplayMode)displayMode;

/**
 *  设置路径上出发地，经由地，目的地图标是否显示
 *
 *  @param bDisplay 是否显示
 */
+(void)setRouteSymbolDisplay:(BOOL)bDisplay;

/**
 *  获取路径上是否显示出发地，经由地，目的地图标
 */
+(BOOL)getRouteSymbolDisplay;

/**
 *  当CldMapView即将被显示的时候调用，恢复之前存储的CldMaoView状态.
 */
-(void)mapViewWillAppear;

/**
 *  当CldMapView即将被隐藏的时候调用，存储当前CldMapView的状态.
 */
-(void)mapViewWillDisappear;

/**
 *  强制刷新mapview.
 */
- (void)mapForceRefresh;

/**
 *  放大一级比例尺.
 *
 *  @return 是否成功
 */
- (BOOL)zoomIn;

/**
 *  缩小一级比例尺.
 *
 *  @return 是否成功
 */
- (BOOL)zoomOut;

/**
 *  设定地图中心点坐标.
 *
 *  @param point    要设定的地图中心点坐标，用凯立德坐标表示
 *  @param animated 是否采用动画效果
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)point animated:(BOOL)animated;

/**
 *  设定地图中心点坐标
 *  @param coord 要设定的地图中心点坐标，用凯立德坐标表示
 *  @param animated 是否采用动画效果
 *  @param completion 完成回调
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coord animated:(BOOL)animated completion:(void(^)(BOOL finised))completion;

/**
 *  移动到当前定位位置，会判断定位状态，如果定位失败，不会移动.
 *
 *  @param completion 完成回调block
 */
-(void)returnToLocatedPosition:(void (^)(BOOL finised))completion;

/**
 *  移动到车标位置.
 *
 *  @param completion 完成回调block
 */
-(void)returnToCarPosition:(void (^)(BOOL finised))completion;


/**
 *  设置地图比例尺级别.
 *
 *  @param level    地图级别
 *  @param animated 是否采用动画效果
 */
-(void)setZoomLevel:(short)level animated:(BOOL)animated;

/**
 *  设置当前地图的视图模式.
 *
 *  @param mode     视图模式
 *  @param animated 是否需要动画
 */
- (void)setMapViewMode:(int)mode animated:(BOOL)animated;

/**
 *  将凯立德坐标转换为View坐标.
 *
 *  @param coordinate 待转换的凯立德坐标
 *  @param view       指定相对的View
 *
 *  @return 转换后的View坐标
 */
- (CGPoint)convertCldCoor:(CLLocationCoordinate2D)coordinate toPointToView:(UIView *)view;

/**
 *  将View坐标转换成凯立德坐标.
 *
 *  @param point 待转换的View坐标
 *  @param view  point坐标所在的view
 *
 *  @return 转换后的凯立德坐标
 */
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCldCoorFromView:(UIView *)view;

/**
 *  将经纬度转换为opengles可以直接使用的坐标.
 *
 *  @param coordinate 坐标
 *
 *  @return 直接支持的坐标
 */
- (CGPoint)glPointForMapPoint:(CLLocationCoordinate2D)coordinate;

/**
 *  批量将CLLocationCoordinate2D转换为opengles可以直接使用的坐标.
 *
 *  @param mapPoints CLLocationCoordinate2D坐标数据指针
 *  @param count     个数,count不能大于数组长度
 *
 *  @return 直接支持的坐标数据指针(需要调用者手动释放)
 */
- (CGPoint *)glPointsForMapPoints:(CLLocationCoordinate2D *)mapPoints count:(NSUInteger)count;

/**
 *  设置地图中心点在地图中的屏幕坐标位置.
 *
 *  @param ptInScreen 要设定的地图中心点位置，为屏幕坐标，设置的中心点不能超过屏幕范围，否则无效
 */
- (void)setMapCenterToScreenPt:(CGPoint)ptInScreen;

/**
 *  获取地图视野经纬度范围(左下右上)
 *
 *  @return 经纬度区域范围
 */
- (CldCoordinateBounds)getMapViewBounds;

/**
 *  缩放到合适比例尺，将传入的点坐标都显示出来
 *
 *  @param coords 点坐标
 *  @param count  点坐标个数
 */
- (void)zoomToSpan:(CLLocationCoordinate2D *)coords coordCount:(NSUInteger)count;

/**
 *  缩放到合适比例尺，将传入的点坐标都显示出来
 *
 *  @param coords 点坐标
 *  @param count  点坐标个数
 *  @param animated  是否采用动画效果
 */
- (void)zoomToSpan:(CLLocationCoordinate2D *)coords coordCount:(NSUInteger)count animated:(BOOL)animated;

@end

#pragma mark -
#pragma mark 在地图上画文本
/// 自定义文本
@interface CldMapView (TextAPI)

@property (nonatomic, readonly) NSArray *texts;   //!< 文本标注数组.

/**
 *  添加一个文本标注
 *
 *  @param text 文本标注
 */
- (void)addText:(CldText*)text;

/**
 *  移除一个文本标注
 *
 *  @param text 文本标注
 */
- (void)removeText:(CldText*)text;

/**
 *  清空文本标注
 */
- (void)clearTexts;

@end


#pragma mark -
#pragma mark 自定义标注
@class CldPointAnnotation;
/// 自定义标注
@interface CldMapView (AnnotationAPI)

/// 当前地图View的已经添加的标注数组
@property (nonatomic, readonly) NSArray *annotations;

/// 设定是否总让选中的annotaion置于最前面
@property (nonatomic, assign) BOOL isSelectedAnnotationViewFront;

/**
 *  向地图窗口添加标注，需要实现CldMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 *
 *  @param annotation 要添加的标注
 */
- (void)addAnnotation:(id<CldAnnotation>)annotation;

/**
 *  向地图窗口添加一组标注，需要实现CldMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 *
 *  @param annotations 要添加的标注数组
 */
- (void)addAnnotations:(NSArray<id<CldAnnotation>> *)annotations;

/**
 *  根据指定标识查找一个可被复用的标注view，一般在delegate中使用，用来代替新申请一个view
 *
 *  @param identifier 指定标识
 *
 *  @return 返回可被复用的标注view
 */
- (CldAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;

/**
 *  移除标注
 *
 *  @param annotation 要移除的标注
 */
- (void)removeAnnotation:(id<CldAnnotation>)annotation;

/**
 *  移除一组标注
 *
 *  @param annotations 要移除的标注数组
 */
- (void)removeAnnotations:(NSArray<id<CldAnnotation>> *)annotations;

/**
 *  清除所有标注
 */
- (void)clearAnnotations;

/**
 *  移除所选中标注视图弹出的气泡view
 */
- (void)removePopView;

/**
 *  设置标注显示或隐藏
 *
 *  @param annotation 要显示或隐藏的标注
 *  @param hidden     是否显示
 */
- (void)setAnnotation:(id<CldAnnotation>)annotation hidden:(BOOL)hidden;

/**
 *  设置一组标注显示或隐藏
 *
 *  @param annotations 要显示或隐藏的标注数组
 *  @param hidden      是否显示
 */
- (void)setAnnotations:(NSArray <id<CldAnnotation>> *)annotations hidden:(BOOL)hidden;

/**
 *  设置所有标注显示或隐藏
 *
 *  @param hidden 是否显示
 */
- (void)setAnnotationsHidden:(BOOL)hidden;

/**
 *  选中指定的标注
 *
 *  @param annotation 指定的标注
 *  @param animated   是否有动画效果
 */
- (void)selectAnnotation:(id<CldAnnotation>)annotation animated:(BOOL)animated;

/**
 *  取消指定的标注选中状态
 *
 *  @param annotation 指定的标注
 *  @param animated   是否有动画效果
 */
- (void)deselectAnnotation:(id<CldAnnotation>)annotation animated:(BOOL)animated;

@end


#pragma mark - 
#pragma mark 覆盖物
///地图View类(和Overlay操作相关的接口)
@interface CldMapView (OverlaysAPI)

/**
*  向地图窗口添加Overlay
*
*  @param overlay 要添加的overlay
*/
- (void)addOverlay:(CldOverlay*)overlay;

/**
 *  向地图窗口添加一组Overlay
 *
 *  @param overlays 要添加的overlay数组
 */
- (void)addOverlays:(NSArray<CldOverlay*> *)overlays;

/**
 *  移除Overlay
 *
 *  @param overlay 要移除的overlay
 */
- (void)removeOverlay:(CldOverlay*)overlay;

/**
 *  移除一组Overlay
 *
 *  @param overlays 要移除的overlay数组
 */
- (void)removeOverlays:(NSArray<CldOverlay*> *)overlays;

/**
 *  添加一个圆
 *
 *  @param circle 要添加的圆
 */
- (void)addCircle:(CldCircle*)circle;

/**
 *  移除Circle
 *
 *  @param circle 要移除的Circle
 */
- (void)removeCircle:(CldCircle*)circle;

/**
 *  清除地图上的所有覆盖物
 */
- (void)clearOverlays;

/// 当前mapView中已经添加的Overlay数组
@property (nonatomic, readonly) NSArray *overlays;

@end


#pragma mark -
#pragma mark 地图协议
/// MapView的Delegate，mapView通过此类来通知用户对应的事件
@protocol CldMapViewDelegate <NSObject>
@optional

/**
 *  点中地图标注后会回调此接口
 *
 *  @param mapView 地图View
 *  @param mapPoi  标注点信息
 */
- (void)mapView:(CldMapView *)mapView onClickedMapPoi:(CldMapPoi *)mapPoi;

/**
 *  点中地图空白处会回调此接口
 *
 *  @param mapView       地图View
 *  @param cldCoordinate 空白处凯立德坐标
 */
- (void)mapView:(CldMapView *)mapView onClickedMapBlank:(CLLocationCoordinate2D)cldCoordinate;

/**
 *  点击地图会回调此接口
 *
 *  @param mapView       地图View
 *  @param cldCoordinate 点击处凯立德坐标
 *
 *  @return 是否需要内部再处理,如果返回NO，不需要内部再处理，就不会再回调上面两个接口了
 */
- (BOOL)mapView:(CldMapView *)mapView onClickedMap:(CLLocationCoordinate2D)cldCoordinate;


/**
 *  双击地图时会回调此接口
 *
 *  @param mapView       地图View
 *  @param cldCoordinate 返回双击处坐标点得凯立德坐标
 */
- (void)mapView:(CldMapView *)mapView onDoubleClick:(CLLocationCoordinate2D)cldCoordinate;

/**
 *  长按地图时会回调此接口
 *
 *  @param mapView       地图View
 *  @param cldCoordinate 返回长按事件坐标点得凯立德坐标
 */
- (void)mapView:(CldMapView *)mapView onLongClick:(CLLocationCoordinate2D)cldCoordinate;

/**
 *  地图比例尺改变时会回调此接口
 *
 *  @param mapView   地图View
 *  @param zoomLevel 返回当前地图比例尺
 */
- (void)mapView:(CldMapView *)mapView onZoomLevelChange:(float)zoomLevel;

/**
 *  地图旋转角度改变时会回调此接口
 *
 *  @param mapView   地图View
 *  @param ration 返回当前地图旋转角度
 */
- (void)mapView:(CldMapView *)mapView onRotateChange:(short)ration;

/**
 *  地图倾斜角度改变时会回调此接口
 *
 *  @param mapView   地图View
 *  @param overLookAngle 返回当前倾斜角度
 */
- (void)mapView:(CldMapView *)mapView onDoubleFingerOverLookAngleChange:(short)overLookAngle;


/**
 *  双指操作时地图模式发生改变时会回调此接口，如双指下拉上推，双指旋转地图
 *
 *  @param mapView   地图View
 *  @param mapStatusType 返回当前地图模式
 */
- (void)mapView:(CldMapView *)mapView  onDoubleFingerMapStatusTypeChange:(CldMapViewMode)mapStatusType;

/**
 *  根据annotation生成对应的View
 *
 *  @param mapView    地图View
 *  @param annotation 指定的标注
 *
 *  @return 生成的标注View
 */
- (CldAnnotationView*)mapView:(CldMapView*)mapView viewForAnnotation:(id<CldAnnotation>)annotation;

/**
 *当选中一个annotation view时，调用此接口
 *@param mapView 地图View
 *@param view 选中的annotation view
 */
- (void)mapView:(CldMapView *)mapView didSelectAnnotationView:(CldAnnotationView *)view;

/**
 *当取消选中一个annotation view时，调用此接口
 *@param mapView 地图View
 *@param view 取消选中的annotation view
 */
- (void)mapView:(CldMapView *)mapView didDeselectAnnotationView:(CldAnnotationView *)view;

/**
 *  地图浏览模式切换时调用
 */
- (void)onCursorChanged;

/**
 *  指南针隐藏，地图模式更新
 */
- (void)compassHide;

@end

#endif /* CldMapView_h */
