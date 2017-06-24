
#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__ADAPTER__
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__ADAPTER__

#include "AndroidUtil/java/lang/Object.hpp"

namespace android{
    
    namespace widget{
        
        struct Adapter : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/widget/Adapter");
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__WIDGET__ADAPTER__
