
#ifndef __VIPER__IOS_UTIL__CF__STRING__
#define __VIPER__IOS_UTIL__CF__STRING__

#include "iOSutil/NS/Object.hpp"

#include <experimental/optional>

namespace CF {
    
    struct String : public NS::Object {
        
        using Object::Object;
        
#ifdef __APPLE__
        
        static String create(std::experimental::optional<std::string> str);
        
        static String create(const std::string &str);
        
        static String create(const char *cString);
#endif
    };
}

#endif  //  __VIPER__IOS_UTIL__CF__STRING__
