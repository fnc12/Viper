//
//  Util.hpp
//  Jako
//
//  Created by John Zakharov on 14.04.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef __VIPER_UTIL_H
#define __VIPER_UTIL_H

//#include "EnumUtil.hpp"
//#include "Selfish.hpp"

/**
 *  Macro for static vars declaration through static functions in header only classes.
 */
#define STATIC_VAR(type,name,value) static type& name(){ static type res(value); return res; }

#if defined(__ANDROID__) &&  !defined(DISABLE_ANDROID_LOG)
#include <android/log.h>

#define  LOG_TAG    "MitsokoLog"

#define  LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#else

#define  LOGV(...)
#define  LOGI(...)
#define  LOGD(...)
#define  LOGE(...)

#endif  //__ANDROID__

#endif /* __VIPER_UTIL_H */
