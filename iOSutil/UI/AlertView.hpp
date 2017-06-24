
#ifndef __VIPER__IOS_UTIL__UI__ALERT_VIEW__
#define __VIPER__IOS_UTIL__UI__ALERT_VIEW__

#include "View.hpp"
#include "iOSutil/CF/String.hpp"
#include "iOSutil/NS/String.hpp"
#include "TextField.hpp"

#include <experimental/optional>
#include <initializer_list>
#include <map>
#include <functional>

namespace UI {
    
    struct AlertView : public UI::View {
        
        typedef UI::View Super;
        
        using View::View;
        
#ifdef __APPLE__
        
        static const std::string className;
//        STATIC_VAR(const std::string, className, "UIAlertView");
        
        typedef std::function<void(UI::AlertView,int)> ClickedButtonAtIndex;
        typedef std::function<void(UI::AlertView,int)> WillDismissWithButtonIndex;
        typedef std::function<void(UI::AlertView,int)> DidDismissWithButtonIndex;
        
        void setDidDismissWithButtonIndex(DidDismissWithButtonIndex f);
        
        void setWillDismissWithButtonIndex(WillDismissWithButtonIndex f);
        
        void setClickedButtonAtIndex(ClickedButtonAtIndex f);
        
        enum class Style{
            Default = UIAlertViewStyleDefault,
            SecureTextInput = UIAlertViewStyleSecureTextInput,
            PlainTextInput = UIAlertViewStylePlainTextInput,
            LoginAndPasswordInput = UIAlertViewStyleLoginAndPasswordInput,
        };
        
        void setMessage(std::experimental::optional<std::string> newValue);
        
        void setMessage(const CF::String &newValue);
        
        std::string message();
        
        int addButtonWithTitle(const std::string &title);
        
//        int addButtonWithTitle(const CF::String &title);
        
        void setCancelButtonIndex(int newValue);
        
        int cancelButtonIndex();
        
        void setAlertViewStyle(Style newValue);
        
        Style alertViewStyle();
        
        void setTitle(const std::string &newValue);
        
        void setTitle(const CF::String &newValue);
        
        std::string title();
        
        void show();
        
        UI::TextField textFieldAtIndex(int index);
        
        static AlertView create(std::experimental::optional<std::string> title,
                                std::experimental::optional<std::string> message,
                                std::experimental::optional<std::string> cancelButtonTitle,
                                std::initializer_list<std::string> otherButtonTitles={});
        
        static AlertView create(const CF::String &title,
                                const CF::String &message,
                                const CF::String &cancelButtonTitle,
                                std::initializer_list<std::string> otherButtonTitles={});
        
        /**
         *  Class which implements all UIAlertViewDelegate callbacks. 
         *  Instance is created and stored per one UI::AlertView after user assigns
         *  any callback to UI::AlertView instance.
         */
        struct DelegateEventHandler {
            typedef std::map<Handle, DelegateEventHandler> DelegateEventHandlersMap;
            static DelegateEventHandlersMap delegateEventHandlers;
//            STATIC_VAR(DelegateEventHandlersMap, delegateEventHandlers, {});
            
            ClickedButtonAtIndex clickedButtonAtIndex;
            WillDismissWithButtonIndex willDismissWithButtonIndex;
            DidDismissWithButtonIndex didDismissWithButtonIndex;
            
            static DelegateEventHandler& getOrCreate(const void *aw);
            
            static DelegateEventHandler* get(const void *aw);
            
            static void remove(const void *aw);
            
            static void alertViewDidDismissWithButtonIndex(const void *aw,int buttonIndex);
            
            static void alertViewWillDismissWithButtonIndex(const void *aw,int buttonIndex);
            
            static void alertViewClickedButtonAtIndex(const void *aw,int buttonIndex);
        };
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__ALERT_VIEW__
