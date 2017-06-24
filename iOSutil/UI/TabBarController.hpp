
#ifndef __VIPER__IOS_UTIL__UI__TAB_BAR_CONTROLLER__
#define __VIPER__IOS_UTIL__UI__TAB_BAR_CONTROLLER__

#include "NavigationController.hpp"
#include "iOSutil/NS/Array.hpp"

namespace UI{
    
    struct TabBarController : public _ViewController<NavigationController, TabBarController> {
        
        using _ViewController::_ViewController;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        void setViewControllers(const NS::Array &newValue);
        
        NS::Array viewControllers();
#endif

    };
}

#endif  //__VIPER__IOS_UTIL__UI__TAB_BAR_CONTROLLER__
