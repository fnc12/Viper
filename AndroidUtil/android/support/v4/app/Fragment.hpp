
#ifndef __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V4__APP__FRAGMENT__
#define __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V4__APP__FRAGMENT__

#include "AndroidUtil/java/lang/Object.hpp"
#include "AndroidUtil/android/content/Intent.hpp"
#include "AndroidUtil/android/support/v4/app/FragmentActivity.hpp"

namespace android{
    
    namespace support{
        
        namespace v4{
            
            namespace app{
                
                struct Fragment : public java::lang::Object {
                    
                    using Object::Object;
                    
#ifdef __ANDROID__
                    
                    static const std::string signature;
//                    STATIC_VAR(const std::string, signature, "android/support/v4/app/Fragment");
                    
                    FragmentActivity getActivity();
                    
                    void startActivityForResult(const android::content::Intent &intent, int requestCode);
                    
#endif  //__ANDROID__
                    
                };
            }
        }
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__SUPPORT__V4__APP__FRAGMENT__
