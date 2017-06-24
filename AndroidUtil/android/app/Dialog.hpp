
#ifndef __VIPER__ANDROID_UTIL__ANDROID__APP__DIALOG__
#define __VIPER__ANDROID_UTIL__ANDROID__APP__DIALOG__

#include "AndroidUtil/java/lang/Object.hpp"
#include "AndroidUtil/android/view/Window.hpp"

namespace android{
    
    namespace app{
        
        struct Dialog : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/app/Dialog");
            
            view::Window getWindow();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__APP__DIALOG__
