//
//  Error.hpp
//  Groozim
//
//  Created by John Zakharov on 22.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef VIPER__URL__ERROR
#define VIPER__URL__ERROR

#ifdef __APPLE__
#include "iOSutil/NS/Error.hpp"
#else
#include "AndroidUtil/java/lang/Object.hpp"
#endif  //__APPLE__

namespace Mitsoko {
    
    namespace Url {
        
        class Request;
        
        struct Error {
            
            int code();
            
            std::string message();
            
            operator bool () const;
            
        public:
            
#ifdef __APPLE__
            NS::Error error;
#else
            java::lang::Object error;
#endif  //__APPLE__
            
        protected:
            Error(decltype(error));
            
            friend class Request;
        };
    }
}

#endif  //VIPER__URL__ERROR
