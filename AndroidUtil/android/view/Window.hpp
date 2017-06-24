
#ifndef __VIPER__ANDROID_UTIL__ANDROID__VIEW__WINDOW__
#define __VIPER__ANDROID_UTIL__ANDROID__VIEW__WINDOW__

#include "AndroidUtil/java/lang/Object.hpp"

namespace android{
    
    namespace view{
        
        struct Window : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/view/Window");
            
            void setSoftInputMode(int mode);
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__VIEW__WINDOW__
