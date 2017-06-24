//
//  RelativeLayout.hpp
//  MyBusiness
//
//  Created by John Zakharov on 04.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#ifndef RelativeLayout_hpp
#define RelativeLayout_hpp

#include "AndroidUtil/android/view/ViewGroup.hpp"
#include "AndroidUtil/android/content/Context.hpp"

namespace android{
    
    namespace widget{
        
        struct RelativeLayout : public android::view::ViewGroup {
          
            using ViewGroup::ViewGroup;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static RelativeLayout create(const android::content::Context &context);
            
            struct LayoutParams : public android::view::ViewGroup::MarginLayoutParams {
                
                using MarginLayoutParams::MarginLayoutParams;
                
                static const std::string signature;
            };
            
#endif  //  __ANDROID__
            
        };
    }
    
}

#endif /* RelativeLayout_hpp */
