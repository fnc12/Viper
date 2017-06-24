
#ifndef __VIPER__ANDROID_UTIL__ANDROID__OS__HANDLER__
#define __VIPER__ANDROID_UTIL__ANDROID__OS__HANDLER__

#include "AndroidUtil/java/lang/Object.hpp"
#include "AndroidUtil/java/lang/Runnable.hpp"

namespace android{
    
    namespace os{
        
        struct Handler : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/os/Handler");
            
            bool post(const java::lang::Runnable &runnable);
            
            static Handler create();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__OS__HANDLER__
