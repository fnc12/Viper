
#ifndef __VIPER__IOS_UTIL__UI__SEGMENTED_CONTROL__
#define __VIPER__IOS_UTIL__UI__SEGMENTED_CONTROL__

#include "Control.hpp"
#include "iOSutil/CF/String.hpp"
#include "Color.hpp"

namespace UI {
    
    struct SegmentedControl : public UI::Control {
        
        using Control::Control;
        
#ifdef __APPLE__
        
        static const std::string className;
//        STATIC_VAR(const std::string, className, "UISegmentedControl");
        
        void setTintColor(const UI::Color &newValue);
        
        UI::Color tintColor();
        
        void setSelectedSegmentIndex(int newValue);
        
        int selectedSegmentIndex();
        
        void setTitle(const std::string &title,int segment);
        
        void setTitle(const CF::String &title,int segment);
        
        std::string titleForSegmentAtIndex(int segment);
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__SEGMENTED_CONTROL__
