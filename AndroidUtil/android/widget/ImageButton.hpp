//
//  ImageButton.hpp
//  GoZebra
//
//  Created by John Zakharov on 09.03.17.
//  Copyright © 2017 Outlaw Studio. All rights reserved.
//

#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__ImageButton_hpp
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__ImageButton_hpp

#include "AndroidUtil/android/widget/ImageView.hpp"

namespace android{
    
    namespace widget{
        
        struct ImageButton : public ImageView {
            
            using ImageView::ImageView;
            
#ifdef __ANDROID__
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/widget/ImageButton");
            
            
            
#endif  //  __ANDROID__
        };
    }
}

#endif /* __VIPER__ANDROID_UTIL__ANDROID__WIDGET__ImageButton_hpp */
