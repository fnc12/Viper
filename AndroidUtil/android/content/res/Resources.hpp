
#ifndef __VIPER__ANDROID_UTIL__ANDROID__CONTENT__RES__RESOURCES__
#define __VIPER__ANDROID_UTIL__ANDROID__CONTENT__RES__RESOURCES__

#include "AndroidUtil/java/lang/Object.hpp"

namespace android{
    
    namespace content{
        
        namespace res{
            
            struct Resources:public java::lang::Object{
                
                using Object::Object;
                
#ifdef __ANDROID__
                
                static const std::string signature;
//                STATIC_VAR(const std::string, signature, "android/content/res/Resources");
#endif  //__ANDROID__
            };
        }
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__CONTENT__RES__RESOURCES__
