
#ifndef __VIPER__ANDROID_UTIL__JAVA__IO__OUTPUT_STREAM__
#define __VIPER__ANDROID_UTIL__JAVA__IO__OUTPUT_STREAM__

#include "AndroidUtil/java/lang/String.hpp"

namespace java {
    
    namespace io {
        
        struct OutputStream : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "java/io/OutputStream");
            
            void close();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__JAVA__IO__OUTPUT_STREAM__
