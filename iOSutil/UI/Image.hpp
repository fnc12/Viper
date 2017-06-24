
#ifndef __VIPER__IOS_UTIL__UI__IMAGE__
#define __VIPER__IOS_UTIL__UI__IMAGE__

#include "View.hpp"
#include "iOSutil/NS/Data.hpp"
#include "iOSutil/CG/Size.hpp"
#include "iOSutil/CG/Image.hpp"

namespace UI {
    
    struct Image : public NS::Object {
        
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        static UI::Image create(const char *named);
        
        static UI::Image create(const std::string &named);
        
        static UI::Image create(const NS::Data &data);
        
        static UI::Image createWithContentsOfFile(const std::string &filename);
        
        static UI::Image createWithContentsOfFile(const CF::String &filename);
        
        static UI::Image createWithCGImage(const CG::Image &img);
        
        static NS::Data JPEGRepresentation(UI::Image image, CG::Float compressionQuality);
        
        CG::Size size();
        
        CG::Image CGImage();
        
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__IMAGE__
