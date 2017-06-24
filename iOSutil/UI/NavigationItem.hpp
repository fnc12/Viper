
#ifndef __VIPER__IOS_UTIL__UI__NAVIGATION_ITEM__
#define __VIPER__IOS_UTIL__UI__NAVIGATION_ITEM__

#include "iOSutil/NS/Object.hpp"
#include "BarButtonItem.hpp"

namespace UI {
    
    struct NavigationItem : public NS::Object {
        
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
//        STATIC_VAR(const std::string, className, "UINavigationItem");
        
        void setHidesBackButton(bool newValue);
        
        bool hidesBackButton();
        
        void setTitle(const std::string &newValue);
        
        void setBackBarButtonItem(const UI::BarButtonItem &newValue);
        
        UI::BarButtonItem backBarButtonItem();
        
        void setRightBarButtonItem(const UI::BarButtonItem &item);
        
        UI::BarButtonItem rightBarButtonItem();
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__NAVIGATION_ITEM__
