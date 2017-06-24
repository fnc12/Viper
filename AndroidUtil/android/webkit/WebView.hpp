//
//  WebView.hpp
//  MyBusiness
//
//  Created by John Zakharov on 10.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#ifndef __android__webkit__WebView_hpp
#define __android__webkit__WebView_hpp

#include "AndroidUtil/android/widget/AbsoluteLayout.hpp"
#include "AndroidUtil/java/lang/String.hpp"

namespace android {
    
    namespace webkit {
        
        struct WebView : public android::widget::AbsoluteLayout {
            
            using AbsoluteLayout::AbsoluteLayout;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            void loadUrl(const java::lang::String &url);
            
            void loadData(const std::string &data,
                          const std::string &mimeType,
                          const std::string &encoding);
            
#endif  //  __ANDROID__
            
        };
    }
}

#endif /* __android__webkit__WebView_hpp */
