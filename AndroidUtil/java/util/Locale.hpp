
#ifndef __VIPER__ANDROID_UTIL__JAVA__UTIL__LOCALE__
#define __VIPER__ANDROID_UTIL__JAVA__UTIL__LOCALE__

#include "AndroidUtil/java/lang/Object.hpp"
#include "AndroidUtil/java/lang/String.hpp"

namespace java{
    
    namespace util{
        
        struct Locale final : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "java/util/Locale");
            
            void start();
            
            java::lang::String getLanguage();
            
            static Locale getDefault();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__JAVA__UTIL__LOCALE__
