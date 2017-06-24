
#ifndef __VIPER__ANDROID_UTIL__ANDROID__APP__FRAGMENT__
#define __VIPER__ANDROID_UTIL__ANDROID__APP__FRAGMENT__

#include "AndroidUtil/java/lang/Object.hpp"
#include "Activity.hpp"

namespace android{
    
    namespace app{
        
        struct Fragment : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/app/Fragment");
            
            Activity getActivity();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__APP__FRAGMENT__
