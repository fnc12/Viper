
#ifndef __VIPER__ANDROID_UTIL__ANDROID__NET__URI__
#define __VIPER__ANDROID_UTIL__ANDROID__NET__URI__

#include "AndroidUtil/java/lang/String.hpp"

namespace android {
    
    namespace net{
        
        struct Uri : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/net/Uri");
            
            static Uri parse(const std::string &uriString);
            
            static Uri parse(const java::lang::String &uriString);
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__NET__URI__
