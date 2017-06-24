
#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__EDIT_TEXT__
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__EDIT_TEXT__

#include "TextView.hpp"
#include "AndroidUtil/android/content/Context.hpp"
#include "AndroidUtil/android/text/Editable.hpp"

namespace android{
    
    namespace widget{
        
        struct EditText : public TextView {
            
            using TextView::TextView;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static EditText create(const content::Context &context);
            
            android::text::Editable getText();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__WIDGET__EDIT_TEXT__
