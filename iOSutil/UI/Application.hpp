
#ifndef __VIPER__IOS_UTIL__UI__APPLICATION__
#define __VIPER__IOS_UTIL__UI__APPLICATION__

#include "iOSutil/NS/URL.hpp"

namespace UI {
    
    struct Application : public NS::Object {
        
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
//        STATIC_VAR(const std::string, className, "UIApplication");
        
        static Application sharedApplication();
        
        bool networkActivityIndicatorVisible();
        
        void setNetworkActivityIndicatorVisible(bool newValue);
        
        bool openURL(NS::URL url);
        
#endif  //__APPLE__
        
    };
}

#endif  //__VIPER__IOS_UTIL__UI__APPLICATION__
