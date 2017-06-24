
#ifndef __VIPER__ANDROID_UTIL__ANDROID__APP__ACTIVITY__
#define __VIPER__ANDROID_UTIL__ANDROID__APP__ACTIVITY__

#include "AndroidUtil/android/content/Context.hpp"
#include "AndroidUtil/android/content/Intent.hpp"
#include "AndroidUtil/android/view/View.hpp"
#include "AndroidUtil/java/lang/Runnable.hpp"

namespace android{
    
    namespace app{
        
        struct Activity : public content::Context {
            
            using Context::Context;
            
#ifdef __ANDROID__
            
            static const std::string signature;
//            STATIC_VAR(const std::string, signature, "android/app/Activity");
            
            static int RESULT_CANCELED();
            
            static int RESULT_OK();
            
            static int RESULT_FIRST_USER();
            
            void finish();
            
            void startActivity(const content::Intent &intent);
            
            void startActivityForResult(const content::Intent &intent, int requestCode);
            
            void setResult(int resultCode);
            
            void setResult(int resultCode,const content::Intent &intent);
            
            void runOnUiThread(const java::lang::Runnable &runnable);
            
            java::lang::Object getSystemService(const std::string &name);
            
            android::view::View getCurrentFocus();
#endif  //__ANDROID__
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__APP__ACTIVITY__
