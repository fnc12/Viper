
#ifndef __VIPER__ANDROID_UTIL__ANDROID__GRAPHICS__COLOR__
#define __VIPER__ANDROID_UTIL__ANDROID__GRAPHICS__COLOR__

#include "AndroidUtil/java/lang/Class.hpp"

namespace android {
    
    namespace graphics {
        
        struct Color : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static int BLACK();
            
            static int DKGRAY();
            
            static int GRAY();
            
            static int LTGRAY();
            
            static int WHITE();
            
            static int RED();
            
            static int GREEN();
            
            static int BLUE();
            
            static int YELLOW();
            
            static int CYAN();
            
            static int MAGENTA();
            
            static int TRANSPARENT();
            
//#define STATIC_FINAL_INT(name) static int name(){ if(java::lang::Class cls=java::lang::Class::find<Color>()){ return cls.getStaticField<int>(#name); }else{ return -1; } }
            
//            STATIC_FINAL_INT(BLACK)
//            STATIC_FINAL_INT(DKGRAY)
//            STATIC_FINAL_INT(GRAY)
//            STATIC_FINAL_INT(LTGRAY)
//            STATIC_FINAL_INT(WHITE)
//            STATIC_FINAL_INT(RED)
//            STATIC_FINAL_INT(GREEN)
//            STATIC_FINAL_INT(BLUE)
//            STATIC_FINAL_INT(YELLOW)
//            STATIC_FINAL_INT(CYAN)
//            STATIC_FINAL_INT(MAGENTA)
//            STATIC_FINAL_INT(TRANSPARENT)
            
//#undef STATIC_FINAL_INT
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__GRAPHICS__COLOR__
