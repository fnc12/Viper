
#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__LINEAR_LAYOUT__
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__LINEAR_LAYOUT__

#include "AndroidUtil/android/view/ViewGroup.hpp"

namespace android{
    
    namespace widget{
        
        struct LinearLayout : public android::view::ViewGroup {
            
            using ViewGroup::ViewGroup;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/widget/LinearLayout");
            
            struct LayoutParams : public android::view::ViewGroup::MarginLayoutParams{
                
                using MarginLayoutParams::MarginLayoutParams;
                
                static const std::string signature;
//                STATIC_VAR(const std::string, signature, "android/widget/LinearLayout$LayoutParams");
                
                static LayoutParams create(int width, int height);
            };
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__WIDGET__LINEAR_LAYOUT__
