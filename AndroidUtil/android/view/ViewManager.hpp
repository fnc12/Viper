
#ifndef __VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW_MANGER__
#define __VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW_MANGER__

#include "AndroidUtil/java/lang/Object.hpp"

namespace android{
    
    namespace view{
        
        struct ViewManager : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/view/ViewManager");
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW_MANGER__
