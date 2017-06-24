//
//  AsyncTask.hpp
//  Groozim
//
//  Created by John Zakharov on 21.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef VIPER__ANDROID_UTIL__ANDROID__OS__ASYNC_TASK
#define VIPER__ANDROID_UTIL__ANDROID__OS__ASYNC_TASK

#include "AndroidUtil/java/lang/Object.hpp"

namespace android{
    
    namespace os{
        
        struct AsyncTask : public java::lang::Object {
            
            using Object::Object;
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/os/AsyncTask");
            
#endif  //__ANDROID__
        };
    }
}

#endif  //VIPER__ANDROID_UTIL__ANDROID__OS__ASYNC_TASK
