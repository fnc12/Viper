
#ifndef __VIPER__ANDROID_UTIL__ANDROID__OS__BASE_BUNDLE__
#define __VIPER__ANDROID_UTIL__ANDROID__OS__BASE_BUNDLE__

#include "AndroidUtil/java/lang/String.hpp"

namespace android{
    
    namespace os{
        
        struct BaseBundle : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/os/BaseBundle");
            
            java::lang::Object get(const char *key);
            
            java::lang::Object get(const std::string &key);
            
            java::lang::Object get(const java::lang::String &key);
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__OS__BASE_BUNDLE__
