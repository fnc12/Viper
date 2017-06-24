
#ifndef __VIPER__IOS_UTIL__UI__RESPONDER__
#define __VIPER__IOS_UTIL__UI__RESPONDER__

#include "iOSutil/NS/Object.hpp"

namespace UI {
    struct Responder:public NS::Object{
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        bool resignFirstResponder();
        
        bool becomeFirstResponder();
        
        bool canBecomeFirstResponder();
        
        UI::Responder nextResponder();
        
        bool canResignFirstResponder();
        
        bool isFirstResponder();
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__RESPONDER__
