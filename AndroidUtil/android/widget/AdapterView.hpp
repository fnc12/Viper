
#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__ADAPTER_VIEW__
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__ADAPTER_VIEW__

#include "AndroidUtil/android/view/ViewGroup.hpp"

namespace android{
    
    namespace widget{
        
        struct AdapterView : public view::ViewGroup {
            
            using ViewGroup::ViewGroup;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/widget/AdapterView");
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__WIDGET__ADAPTER_VIEW__
