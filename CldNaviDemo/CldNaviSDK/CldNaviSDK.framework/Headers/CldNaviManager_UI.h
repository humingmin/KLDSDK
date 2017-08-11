/**
 *  CldNaviManager_UI.h 
 *  导航管理器，处理进入导航及退出导航的任务
 *
 *  Created by lxf on 15/12/20.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

/// 进入导航类型
typedef enum
{
    Cld_NaviTypeReal,           //!< 驾车真实导航.
    Cld_NaviTypeSimulator,      //!< 驾车模拟导航.
    Cld_NaviTypeWalkReal,       //!< 步行导航
} Cld_NaviType;

/// 进入导航UI界面
typedef enum
{
    eNoRoute = -2,    //!< 没有规划路线或未选择路径.
    eParamError = -1, //!< 参数错误，delegate为空.
    eSuccess = 0      //!< 成功.
}ShowNaviUIError;


/// 导航UI管理器回调
@protocol CLDNaviUIManagerDelegate <NSObject>

@optional

/**
 *  退出导航页面回调
 *
 *  @param naviType 导航类型
 */
-(void)onExitNaviUI:(Cld_NaviType)naviType;

@end

/// 导航管理器
@interface CldNaviManager_UI : NSObject

/**
 *  获取导航管理单例对象
 *
 *  @return 单例对象
 */
+(id)sharedManager;

/**
 *  进入导航页面
 *
 *  @param eType           导航类型：真实导航或者模拟导航
 *  @param delegate        Deleagte
 *
 *  @return 进入导航界面结果，参照：ShowNaviUIError定义
 */
- (ShowNaviUIError)showNaviUI:(Cld_NaviType)eType delegete:(id<CLDNaviUIManagerDelegate>)delegate;

/**
 *  安静退出导航(无弾框)
 *
 *  @return YES：退出成功，NO：退出失败
 */
- (BOOL)exitNaviUI;

/**
 *  一键导航
 *
 *  @param naviNodes 算路节点参数
 *  @param delegate  Deleagte
 *
 *  @return 启动成功/失败
 */
- (BOOL)startNavi:(NSArray *)naviNodes Delegate:(id<CLDNaviUIManagerDelegate>)delegate;

/**
 *  一键模拟导航
 *
 *  @param naviNodes 算路节点参数
 *  @param delegate  Deleagte
 *
 *  @return 启动成功/失败
 */
- (BOOL)startEmuNavi:(NSArray *)naviNodes Delegate:(id<CLDNaviUIManagerDelegate>)delegate;

@end
