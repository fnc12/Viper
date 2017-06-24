
#ifndef __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V4__APP__FRAGMENT_ACTIVITY__
#define __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V4__APP__FRAGMENT_ACTIVITY__

#include "AndroidUtil/android/app/Activity.hpp"

namespace android{
    
    namespace support{
        
        namespace v4{
            
            namespace app{
                
                struct FragmentActivity : public android::app::Activity {
                    
                    using Activity::Activity;
                    
#ifdef __ANDROID__
                    
                    static const std::string signature;
//                    STATIC_VAR(const std::string, signature, "android/support/v4/app/FragmentActivity");
#endif  //__ANDROID__
                    
                };
            }
        }
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V4__APP__FRAGMENT_ACTIVITY__
