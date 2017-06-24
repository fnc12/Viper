//
//  AbsoluteLayout.hpp
//  MyBusiness
//
//  Created by John Zakharov on 10.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#ifndef AbsoluteLayout_hpp
#define AbsoluteLayout_hpp

#include "AndroidUtil/android/view/ViewGroup.hpp"

namespace android{
    
    namespace widget{
        
        struct AbsoluteLayout : public android::view::ViewGroup {
            
            using ViewGroup::ViewGroup;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
#endif  //__ANDROID__
            
        };
    }
}

#endif /* AbsoluteLayout_hpp */
