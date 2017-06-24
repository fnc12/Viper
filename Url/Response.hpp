//
//  UrlResponse.hpp
//  Groozim
//
//  Created by John Zakharov on 21.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef VIPER__URL_RESPONSE
#define VIPER__URL_RESPONSE

#include <string>

#ifdef __APPLE__
#include "iOSutil/NS/HTTPURLResponse.hpp"
#else
#include "AndroidUtil/java/lang/Object.hpp"
#endif  //__APPLE__

namespace Mitsoko {
    
    namespace Url {
        
        class Request;
        
        struct Response {
            
            struct Headers {
                Response &response;
                
                std::string operator[](const std::string &key);
            };
            
            int statusCode();
            
            std::string statusDescription();
            
            Headers headers;
            
            operator bool () const;
            
            Response(const Response& other);
            
            Response(Response &&other);
            
        public:
            
#ifdef __APPLE__
            NS::HTTPURLResponse response;
#else
            java::lang::Object response;
#endif
        protected:
            Response(decltype(response));
            
            friend class Request;
            
        };
    }
}

#endif //VIPER__URL_RESPONSE
