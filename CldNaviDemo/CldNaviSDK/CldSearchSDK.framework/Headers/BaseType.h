/**
 * BaseType.h
 * CldSearchSDK
 *
 * Created by Lynn on 15/12/15.
 * Copyright © 2015年 CLD. All rights reserved.
 *
 */

/// 错误码
typedef enum : NSInteger {
    CLDErrorEngineNoInit = -1,  //!< 引擎还未初始化完成
    CLDErrorOK,                 //!< 正确.
    CLDErrorConnect,            //!< 网络连接错误.
    CLDErrorData,               //!< 数据错误.
    CLDErrorNotFound,           //!< 离线搜索无结果.
    CLDErrorPermissionFailure   //!< app key验证失败.
} CLDErrorCode;

