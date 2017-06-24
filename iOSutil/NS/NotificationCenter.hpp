
#ifndef __VIPER__IOS_UTIL__NS__NOTIFICATION_CENTER__
#define __VIPER__IOS_UTIL__NS__NOTIFICATION_CENTER__

#include "Object.hpp"
#include "Disposable.hpp"
#include "String.hpp"

#include <functional>
#include <map>

namespace NS {
    
    struct NotificationCenter : public NS::Object {
        
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
//        STATIC_VAR(const std::string, className, "NSNotificationCenter");
        
        static NotificationCenter defaultCenter();
        
        //  todo..
        void addObserver(const Mitsoko::Disposable &observer, std::function<void()> selector,NS::String name){
            
        }
        
    protected:
        
        
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__NS__NOTIFICATION_CENTER__
