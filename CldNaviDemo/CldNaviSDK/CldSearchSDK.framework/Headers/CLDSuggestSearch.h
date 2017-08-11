/**
 *  CLDSuggestSearch.h
 *  CldSearchSDK
 *
 *  Created by Lynn on 16/3/3.
 *  Copyright © 2016年 CLD. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "CLDSuggestSearchOption.h"
#import "CLDSuggestType.h"
#import "BaseType.h"

/// suggest搜索回调
@protocol CLDSuggestSearchDelegate;

/// suggest信息检索
@interface CLDSuggestSearch : NSObject

@property (nonatomic, weak) id<CLDSuggestSearchDelegate> delegate;    //!< 检索模块的Delegate.

/**
 *  suggest搜索服务
 *
 *  @param option 检索信息类
 *
 *  @return 成功返回YES，否则返回NO
 */
- (BOOL)suggestSearch:(CLDSuggestSearchOption *)option;

@end


/// 搜索delegate，用于获取搜索结果
@protocol CLDSuggestSearchDelegate <NSObject>

@optional
/**
 *  搜索结果
 *
 *  @param searcher 信息检索
 *  @param result   检索结果
 *  @param error    错误号
 */
- (void)onGetSuggestionResult:(CLDSuggestSearch*)searcher result:(CLDSuggestResult *)result errorCode:(CLDErrorCode)error;

@end