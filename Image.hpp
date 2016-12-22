//
//  Image.hpp
//  Groozim
//
//  Created by John Zakharov on 25.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef VIPER__IMAGE
#define VIPER__IMAGE

//#ifdef __APPLE__
#include "Viper/iOSutil/UI/Image.hpp"
//#else
#include "Viper/AndroidUtil/android/graphics/Bitmap.hpp"
//#endif  //__APPLE__

namespace Viper {
    
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

#endif  //VIPER__IMAGE