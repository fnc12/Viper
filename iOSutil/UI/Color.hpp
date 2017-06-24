
#ifndef __VIPER__IOS_UTIL__UI__COLOR__
#define __VIPER__IOS_UTIL__UI__COLOR__

#include "iOSutil/NS/Object.hpp"
#include "iOSutil/CG/CG.hpp"

namespace UI {
    
    struct Color : public NS::Object {
        using Object::Object;
#ifdef __APPLE__
        static const std::string className;
        
        static UI::Color colorWithRedGreenBlueAlpha(CG::Float red, CG::Float green, CG::Float blue, CG::Float alpha);
        
#define COLOR_UI_STATIC_FUNC(name) static UI::Color name(){\
    auto cls=NS::getClass(className);\
    return NS::Object::sendMessage<Handle>(cls,#name);\
}
        COLOR_UI_STATIC_FUNC(blackColor)
        COLOR_UI_STATIC_FUNC(darkGrayColor)
        COLOR_UI_STATIC_FUNC(lightGrayColor)
        COLOR_UI_STATIC_FUNC(whiteColor)
        COLOR_UI_STATIC_FUNC(grayColor)
        COLOR_UI_STATIC_FUNC(redColor)
        COLOR_UI_STATIC_FUNC(greenColor)
        COLOR_UI_STATIC_FUNC(blueColor)
        COLOR_UI_STATIC_FUNC(cyanColor)
        COLOR_UI_STATIC_FUNC(yellowColor)
        COLOR_UI_STATIC_FUNC(magentaColor)
        COLOR_UI_STATIC_FUNC(orangeColor)
        COLOR_UI_STATIC_FUNC(purpleColor)
        COLOR_UI_STATIC_FUNC(brownColor)
        COLOR_UI_STATIC_FUNC(clearColor)
#undef COLOR_UI_STATIC_FUNC
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__COLOR__
