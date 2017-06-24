
#ifndef __VIPER__ANDROID_UTIL__ANDROID__CONTENT__DIALOG_INTERFACE__
#define __VIPER__ANDROID_UTIL__ANDROID__CONTENT__DIALOG_INTERFACE__

#include "AndroidUtil/java/lang/Object.hpp"

namespace android{
    
    namespace content{
        
        /**
         *  Interface.
         */
        struct DialogInterface : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/content/DialogInterface");
            
            void cancel();
            
            void dismiss();
            
            struct OnClickListener : public java::lang::Object {
                
                using Object::Object;
                
                static const std::string signature;
//                STATIC_VAR(const std::string, signature, "android/content/DialogInterface$OnClickListener");
                
            };
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__CONTENT__DIALOG_INTERFACE__
