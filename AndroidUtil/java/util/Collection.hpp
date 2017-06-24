
#ifndef __VIPER__ANDROID_UTIL__JAVA__LANG__COLLECTION__
#define __VIPER__ANDROID_UTIL__JAVA__LANG__COLLECTION__

//#include "Iterable.hpp"
#include "AndroidUtil/java/lang/Iterable.hpp"

namespace java{
    
    namespace util{
        
        /**
         *  Generic interface.
         */
        struct Collection : public java::lang::Iterable {
            
            using Iterable::Iterable;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__JAVA__LANG__COLLECTION__
