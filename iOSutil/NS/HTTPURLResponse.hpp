//
//  HTTPURLResponse.hpp
//  Groozim
//
//  Created by John Zakharov on 12.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef HTTPURLResponse_hpp
#define HTTPURLResponse_hpp

#include "URLResponse.hpp"
#include "String.hpp"
#include "iOSutil/NS/Dictionary.hpp"

namespace NS {
    
    struct HTTPURLResponse : public NS::URLResponse {
        
        using URLResponse::URLResponse;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        int statusCode();
        
        NS::Dictionary allHeaderFields();
        
        static NS::String localizedStringForStatusCode(int statusCode);
        
#endif  //__APPLE__
        
    };
}

#endif /* HTTPURLResponse_hpp */
