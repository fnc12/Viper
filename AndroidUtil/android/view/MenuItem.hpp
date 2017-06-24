
#ifndef __VIPER__ANDROID_UTIL__ANDROID__VIEW__MENU_ITEM__
#define __VIPER__ANDROID_UTIL__ANDROID__VIEW__MENU_ITEM__

#include "AndroidUtil/java/lang/String.hpp"

namespace android{
    
    namespace view{
        
        struct MenuItem : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            MenuItem& setTitle(const std::string &title);
            
            MenuItem& setTitle(const java::lang::CharSequence &title);
            
            std::string getTitle();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__VIEW__MENU_ITEM__
