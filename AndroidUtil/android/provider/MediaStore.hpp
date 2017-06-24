
#ifndef __VIPER__ANDROID_UTIL__ANDROID__PROVIDER__MEDIA_STORE__
#define __VIPER__ANDROID_UTIL__ANDROID__PROVIDER__MEDIA_STORE__

#include "AndroidUtil/java/lang/String.hpp"
#include "AndroidUtil/android/net/Uri.hpp"

namespace android {
    
    namespace provider {
        
        struct MediaStore : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static std::string ACTION_IMAGE_CAPTURE();
            
            struct Images : public java::lang::Object {
                
                using Object::Object;
                
                static const std::string signature;
                
                struct Media:public java::lang::Object{
                    
                    using Object::Object;
                    
                    static const std::string signature;
                    
                    static android::net::Uri EXTERNAL_CONTENT_URI();
                };
            };
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__PROVIDER__MEDIA_STORE__
