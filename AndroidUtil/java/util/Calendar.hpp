
#ifndef __VIPER__ANDROID_UTIL__JAVA__UTIL__CALENDAR__
#define __VIPER__ANDROID_UTIL__JAVA__UTIL__CALENDAR__

#include "AndroidUtil/java/lang/Object.hpp"
#include "Date.hpp"

namespace java{
    
    namespace util{
        
        struct Calendar:public java::lang::Object{
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "java/util/Calendar");
            
            void setTime(const Date &date);
            
            static Calendar getInstance();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__JAVA__UTIL__CALENDAR__
