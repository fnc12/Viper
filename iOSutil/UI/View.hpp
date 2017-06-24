
#ifndef __VIPER__IOS_UTIL__UI__VIEW__
#define __VIPER__IOS_UTIL__UI__VIEW__

#include "Responder.hpp"
#include "iOSutil/CG/AffineTransform.hpp"
#include "iOSutil/CG/Rect.hpp"
#include "Color.hpp"

namespace UI {
    
    struct View : public UI::Responder {
        
        using Responder::Responder;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        static UI::View create();
        
        enum class ContentMode{
            ScaleToFill = UIViewContentModeScaleToFill,
            ScaleAspectFit = UIViewContentModeScaleAspectFit,
            ScaleAspectFill = UIViewContentModeScaleAspectFill,
            Redraw = UIViewContentModeRedraw,
            Center = UIViewContentModeCenter,
            Top = UIViewContentModeTop,
            Bottom = UIViewContentModeBottom,
            Left = UIViewContentModeLeft,
            Right = UIViewContentModeRight,
            TopLeft = UIViewContentModeTopLeft,
            TopRight = UIViewContentModeTopRight,
            BottomLeft = UIViewContentModeBottomLeft,
            BottomRight = UIViewContentModeBottomRight,
        };
        
        void addSubview(const UI::View &view);
        
        void setBackgroundColor(const UI::Color &newValue);
        
        UI::Color backgroundColor();
        
        void setFrame(const CG::Rect &newValue);
        
        CG::Rect frame();
        
        void setContentMode(ContentMode newValue);
        
        ContentMode contentMode();
        
        void setHidden(bool newValue);
        
        void setTransform(const CG::AffineTransform &newValue);
        
        CG::AffineTransform transform();
        
        void setTag(int value);
        
        int tag();
        
        void layoutSubviews();
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__VIEW__
