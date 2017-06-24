//
//  NoCopySpan.hpp
//  Groozim
//
//  Created by John Zakharov on 06.09.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef __VIPER__ANDROUD_UTIL__ANDROID__TEXT__NO_COPY_SPAN__
#define __VIPER__ANDROUD_UTIL__ANDROID__TEXT__NO_COPY_SPAN__

#include "AndroidUtil/java/lang/Object.hpp"

namespace android {
    
    namespace text {
        
        struct NoCopySpan : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/text/NoCopySpan");
            
#endif  //__ANDROID__
            
        };
    }
}

#endif //__VIPER__ANDROUD_UTIL__ANDROID__TEXT__NO_COPY_SPAN__
