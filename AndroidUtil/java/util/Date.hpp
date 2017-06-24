
#ifndef __VIPER__ANDROID_UTIL__JAVA__UTIL__DATE__
#define __VIPER__ANDROID_UTIL__JAVA__UTIL__DATE__

#include "AndroidUtil/java/lang/Object.hpp"

namespace java{
    
    namespace util{
        
        struct Date:public java::lang::Object{
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "java/util/Date");
            
            static Date create(long milliseconds);
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__JAVA__UTIL__DATE__
