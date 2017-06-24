
#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__FRAME_LAYOUT__
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__FRAME_LAYOUT__

#include "AndroidUtil/android/view/ViewGroup.hpp"

namespace android{
    
    namespace widget{
        
        struct FrameLayout : public view::ViewGroup {
            
            using ViewGroup::ViewGroup;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/widget/FrameLayout");
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__WIDGET__FRAME_LAYOUT__
