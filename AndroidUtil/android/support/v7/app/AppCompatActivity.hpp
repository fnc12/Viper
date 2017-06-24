
#ifndef __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V7__APP__APP_COMBAT_ACTIVITY__
#define __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V7__APP__APP_COMBAT_ACTIVITY__

#include "AndroidUtil/android/support/v4/app/FragmentActivity.hpp"
#include "ActionBar.hpp"

namespace android{
    
    namespace support{
        
        namespace v7{
            
            namespace app{
                
                struct AppCompatActivity : public android::support::v4::app::FragmentActivity {
                    
                    using FragmentActivity::FragmentActivity;
                    
#ifdef __ANDROID__
                    
                    static const std::string signature;
//                    STATIC_VAR(const std::string, signature, "android/support/v7/app/AppCompatActivity");
                    
                    ActionBar getSupportActionBar();
                    
                    void invalidateOptionsMenu();
                    
#endif  //__ANDROID__
                    
                };
            }
        }
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V7__APP__APP_COMBAT_ACTIVITY__
