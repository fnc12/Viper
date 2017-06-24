
#ifndef __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V7__APP__ACTION_BAR__
#define __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V7__APP__ACTION_BAR__

#include "AndroidUtil/java/lang/Object.hpp"
#include "AndroidUtil/java/lang/String.hpp"

namespace android{
    
    namespace support{
        
        namespace v7{
            
            namespace app{
                
                struct ActionBar : public java::lang::Object {
                    
                    using Object::Object;
                    
#ifdef __ANDROID__
                    
                    static const std::string signature;
//                    STATIC_VAR(const std::string, signature, "android/support/v7/app/ActionBar");
                    
                    java::lang::CharSequence getTitle();
                    
                    void setTitle(const std::string &title);
                    
//                    void setTitle(const java::lang::CharSequence &title);
                    
                    void hide();
                    
#endif  //__ANDROID__
                    
                };
            }
        }
    }
}

#endif//    __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V7__APP__ACTION_BAR__
