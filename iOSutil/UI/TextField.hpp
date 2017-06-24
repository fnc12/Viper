
#ifndef __VIPER__IOS_UTIL__UI__TEXT_FIELD__
#define __VIPER__IOS_UTIL__UI__TEXT_FIELD__

#include "Control.hpp"
#include "TextInput.hpp"
#include "iOSutil/CF/String.hpp"

namespace UI {
    
    struct TextField : public virtual UI::Control, public virtual UI::TextInput {
        
#ifdef __APPLE__
        static const std::string className;
        
        TextField();
        
        TextField(Handle handle);
        
        void setText(const std::string &newValue);
        
//        void setText(const CF::String &newValue);
        
        std::string text();
        
        void setPlaceholder(const std::string &newValue);
        
        std::string placeholder();
        
    private:
        typedef UI::Control Super;
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__TEXT_FIELD__
