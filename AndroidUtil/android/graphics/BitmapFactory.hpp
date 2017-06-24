
#ifndef __VIPER__ANDROID_UTIL__ANDROID__GRAPHICS__BITMAP_FACTORY__
#define __VIPER__ANDROID_UTIL__ANDROID__GRAPHICS__BITMAP_FACTORY__

#include "AndroidUtil/java/lang/String.hpp"
#include "Bitmap.hpp"
#include "AndroidUtil/java/lang/Array.hpp"

namespace android {
    
    namespace graphics {
        
        struct BitmapFactory : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static Bitmap decodeFile(const std::string &pathName);
            
            static Bitmap decodeFile(const java::lang::String &pathName);
            
            static Bitmap decodeByteArray(java::lang::Array<char> data, int offset, int length);
            
            struct Options : public java::lang::Object {
                
                using Object::Object;
                
                static const std::string signature;
                
                static Options create();
                
            };
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__GRAPHICS__BITMAP_FACTORY__
