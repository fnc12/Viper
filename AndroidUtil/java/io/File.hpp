
#ifndef __VIPER__ANDROID_UTIL__JAVA__IO__FILE__
#define __VIPER__ANDROID_UTIL__JAVA__IO__FILE__

#include "AndroidUtil/java/lang/String.hpp"

namespace java {
    
    namespace io {
        
        struct File : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "java/io/File");
            
            static File create(const std::string &path);
            
            static File create(const java::lang::String &path);
#endif
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__JAVA__IO__FILE__
