//
//  CLDTTSPlayer.h
//  libNaviOne
//  TTS文案播放器
//  Created by huangzh on 16/6/24.
//  Copyright © 2016年 careland. All rights reserved.
//

#import <Foundation/Foundation.h>

///TTS文案播放器
@interface CLDTTSPlayer : NSObject

/**
 *  TTS播报文案
 *
 *  @param speech 播报文案
 *
 *  @return 成功返回YES，否则返回NO
 */
+ (BOOL)playTTSText:(NSString *)speech;

/**
 *  停止TTS播报
 */
+ (void)stopTTSText;

/**
 *  获取TTS播报状态
 *
 *  @return  正在播报返回YES，否则返回NO
 */
+ (BOOL)getTTSState;

@end
