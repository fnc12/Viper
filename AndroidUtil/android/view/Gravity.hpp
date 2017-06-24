//
//  Gravity.hpp
//  MyBusiness
//
//  Created by John Zakharov on 04.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#ifndef Gravity_hpp
#define Gravity_hpp

#include "AndroidUtil/java/lang/String.hpp"

namespace android{
    
    namespace view{
        
        struct Gravity : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static int AXIS_CLIP();
            
            static int BOTTOM();
            
            static int CENTER();
            
#endif  //  __ANDROID__
        };
        
    }
    
}

#endif /* Gravity_hpp */
