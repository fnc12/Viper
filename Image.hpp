//
//  Image.hpp
//  Groozim
//
//  Created by John Zakharov on 25.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef __VIPER_VIPER__IMAGE
#define __VIPER_VIPER__IMAGE

#include "iOSutil/UI/Image.hpp"
#include "AndroidUtil/android/graphics/Bitmap.hpp"

namespace Mitsoko {
    
    struct Image {
        
#ifdef __APPLE__
        UI::Image image;
#else
        android::graphics::Bitmap image;
#endif  //__APPLE__
        
        Image();
        
        Image(decltype(image));
        
        operator bool () const;
        
        operator decltype(image) ();
        
        void writeToFile(const std::string &filepath);
        
        decltype(image) get();
    };
}

#endif  //__VIPER_VIPER__IMAGE
