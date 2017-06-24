//
//  URL.hpp
//  Groozim
//
//  Created by John Zakharov on 29.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef __VIPER__IOS_UTIL__NS__URL__
#define __VIPER__IOS_UTIL__NS__URL__

#include "iOSutil/NS/String.hpp"
#include "iOSutil/CF/String.hpp"

namespace NS {
    
    struct URL : public NS::Object {
        
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        static NS::URL create(const std::string &str);
        
        std::string absoluteString();
        
    protected:
        
        void initWithString(const CF::String &str);
        
#endif  //__APPLE__
    };
}

#endif  //__VIPER__IOS_UTIL__NS__URL__
