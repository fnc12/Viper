
#ifndef __VIPER__IOS_UTIL__UI__LABEL__
#define __VIPER__IOS_UTIL__UI__LABEL__

#include "View.hpp"
#include "iOSutil/UI/Color.hpp"
#include "iOSutil/CF/String.hpp"
#include "Util.hpp"
#include "iOSutil/NS/TextAlignment.hpp"

namespace UI {
    
    struct Label : public UI::View {
        
        using View::View;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        void setText(const std::string &newValue);
        
        void setTextColor(const UI::Color &newValue);
        
        UI::Color textColor();
        
        void setTextAlignment(NS::TextAlignment value);
        
        NS::TextAlignment textAlignment();
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__LABEL__
