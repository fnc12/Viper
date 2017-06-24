//
//  IBinder.hpp
//  GoZebra
//
//  Created by John Zakharov on 15.03.17.
//  Copyright © 2017 Outlaw Studio. All rights reserved.
//

#ifndef IBinder_hpp
#define IBinder_hpp

#include "AndroidUtil/java/lang/Object.hpp"

namespace android {
    
    namespace os {
        
        struct IBinder : public java::lang::Object {
#ifdef __ANDROID__
            using Object::Object;
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/os/IBinder");
            
#endif  //  __ANDROID__
        };
    }
}

#endif /* IBinder_hpp */
