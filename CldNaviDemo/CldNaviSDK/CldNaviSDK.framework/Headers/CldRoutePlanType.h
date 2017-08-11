/**
 *  CldRoutePlanType.h 
 *  路径规划方式
 *
 *  Created by huangzh on 15/12/20.
 *  Copyright © 2015年 Careland. All rights reserved.
 *
 */

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import "CldMapView.h"

/// 行程说明方向类型
typedef enum
{
    eGDDirectType_Dest = 0l,	//!< 目的地.
    eGDDirectType_Pass,	    //!< 经由地.
    eGDDirectType_Start,	//!< 出发地.
    eGDDirectType_Stright,	//!< 直行.
    eGDDirectType_HalfRight,	//!< 右前方.
    eGDDirectType_JustRight,	//!< 向右.
    eGDDirectType_MuchRight,	//!< 右后方.
    eGDDirectType_Uturn,	//!< 调头.
    eGDDirectType_JustLeft,	//!< 向左.
    eGDDirectType_HalfLeft,	//!< 左前方.
    eGDDirectType_None,	    //!< 方向不确定.
    eGDDirectType_SAPA,	    //!< 服务区入口.
    eGDDirectType_ENTEXP,	//!< 高速公路/快速道路入口.
    eGDDirectType_EXITEXP,	//!< 高速公路/快速道路出口.
    eGDDirectType_JC,	//!< JC 高速公路分叉口.
    eGDDirectType_IC,	//!< TG 收费站.
    eGDDirectType_TG,	//!< IC 下高速出口.
    eGDDirectType_Walkway_Footbridge,	//!< 人行天桥.
    eGDDirectType_Walkway_Passageway,	//!< 人行通道.
    eGDDirectType_Walkway_Subway,       //!< 地下通道.
}GDDirectType;

/// 发起算路错误类型
typedef enum
{
    eTruckNoSupport = -5,     //!< 不支持货运规划
    eTruckParamsInvalid = -4, //!< 货车参数无效.
    eRouteNodeError = -3, //!< 算路节点参数错误.
    eAuthCheckError = -2, //!< 授权未完成获取失败.
    eServiceNoInit = -1,  //!< 引擎未完成初始化.
    eStartSuccess = 0     //!< 发起算路成功.
}StartRoutePlanError;

/// 此类表示路线中的一节点，节点包括：路线起终点，公交站点等
@interface CLDRouteNode : NSObject{
    NSString*              _title;    //!< 该节点的名称.
    CLLocationCoordinate2D _location; //!< 该节点的地图坐标.
}

@property (nonatomic, strong) NSString* title;  //!< 该节点的名称.
@property (nonatomic) CLLocationCoordinate2D location;  //!< 该节点的地图坐标.

@end


/// 此类表示路线中的一个路段（基类）
@interface CLDRouteStep : NSObject{
    GDDirectType            _direction;  //!< 该路段起点方向.
    int                     _distance;   //!< 路段长度 单位:米.
    NSString                *_title;     //!< 路段名称.
    CLLocationCoordinate2D  _point;      //!< 路段起点地理坐标.
    BOOL                    _isPass;     //!< 是否已走过.
}

@property (nonatomic) GDDirectType direction;   //!< 该路段起点方向.
@property (nonatomic) int distance;   //!< 路段长度 单位:米.
@property (nonatomic,strong) NSString *title;   //!< 路段名称.
@property (nonatomic) CLLocationCoordinate2D point;   //!< 路段起点地理坐标.
@property (nonatomic) BOOL isPass;      //!< 是否已走过.

@end

/// 此类表示驾车路线中的一个路段
@interface CLDDrivingStep : CLDRouteStep{
    BOOL                  _hasRestrictions;  //!< 是否有限行.
}
@property (nonatomic) BOOL hasRestrictions;  //!<是否有限行
@end

/// 此类表示步行路线中的一个路段
@interface CLDWalkStep : CLDRouteStep{
    
}
@end

/// 此类表示路线数据结构的基类，表示一条路线，一般关注其子类对象即可，无需直接生成该类对象
@interface CLDRouteLine : NSObject{
    int                  _distance;   //!< 路线长度 单位:米.
    int                  _duration;   //!< 路线耗时 单位:秒.
    CLDRouteNode*        _start;      //!< 路线起点信息.
    CLDRouteNode*        _dest;       //!< 路线终点信息.
    NSString*            _title;      //!< 路线名称(预留字段，现为空).
    NSArray*             _steps;      //!< 路线中的所有路段，成员类型为CLDDrivingStep,CLDWalkStep.
}
@property (nonatomic) int distance;   //!< 路线长度 单位:米.
@property (nonatomic) int duration;   //!< 路线耗时 单位:秒.
@property (nonatomic, strong) CLDRouteNode* start; //!< 路线起点信息.
@property (nonatomic, strong) CLDRouteNode* dest;  //!< 路线终点信息.
@property (nonatomic, strong) NSString* title;     //!< 路线名称(预留字段，现为空).
@property (nonatomic, strong) NSArray* steps;  //!< 路线中的所有路段，成员类型为CLDDrivingStep,CLDWalkStep.

@end

/// 此类表示一条驾车路线
@interface CLDDrivingRouteLine : CLDRouteLine{
    int                 _routePlanMode;  //!< 路线规划方式.
    NSArray*            _passPoints;     //!< 路线途经点列表，成员类型为CLDPlanNode.
}

@property (nonatomic) int routePlanMode;   //!< 路线规划方式.
@property (nonatomic) BOOL bAvoidTrafficJam; //!< 是否躲避拥堵
@property (nonatomic, strong) NSArray* passPoints;   //!< 路线途经点列表，成员类型为CLDPlanNode.

@end

/// 此类表示一条步行路线
@interface CLDWalkRouteLine : CLDRouteLine{

}
@end

/// 此类表示一条路线的长度和时间
@interface CLDRouteLineDistanceTime : NSObject
{
    int                  _distance;   //!< 路线长度 单位:米.
    int                  _duration;   //!< 路线耗时 单位:秒.
}
@property (nonatomic) int distance;   //!< 路线长度 单位:米.
@property (nonatomic) int duration;   //!< 路线耗时 单位:秒.
@end
