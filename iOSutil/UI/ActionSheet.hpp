
#ifndef __VIPER__IOS_UTIL__UI__ACTION_SHEET__
#define __VIPER__IOS_UTIL__UI__ACTION_SHEET__

#include "View.hpp"
#include "iOSutil/NS/String.hpp"
#include "iOSutil/CF/String.hpp"

#include <map>

namespace UI {
    
    struct ActionSheet : public UI::View {
        
        using View::View;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        typedef std::function<void(UI::ActionSheet,int)> ClickedButtonAtIndex;
        typedef std::function<void(UI::ActionSheet,int)> WillDismissWithButtonIndex;
        typedef std::function<void(UI::ActionSheet,int)> DidDismissWithButtonIndex;
        
        static UI::ActionSheet create();
        
        void setDidDismissWithButtonIndex(DidDismissWithButtonIndex f);
        
        void setWillDismissWithButtonIndex(WillDismissWithButtonIndex f);
        
        void setClickedButtonAtIndex(ClickedButtonAtIndex f);
        
        void showInView(const UI::View &view);
        
        void setDestructiveButtonIndex(int newValue);
        
        int destructiveButtonIndex();
        
        void setCancelButtonIndex(int newValue);
        
        int cancelButtonIndex();
        
        int numberOfButtons();
        
        NS::String buttonTitleAtIndex(int index);
        
        int addButtonWithTitle(const std::string &t);
        
//        int addButtonWithTitle(const CF::String &t);
        
        void setTitle(const std::string &newValue);
        
        void setTitle(const CF::String &newValue);
        
        std::string title();
        
        /**
         *  Class which implements all UIActionSheetDelegate callbacks.
         *  Instance is created and stored per one UI::ActionSheet after user assigns
         *  any callback to UI::ActionSheet instance.
         */
        struct DelegateEventHandler{
            typedef std::map<Handle, DelegateEventHandler> DelegateEventHandlersMap;
            static DelegateEventHandlersMap delegateEventHandlers;
//            STATIC_VAR(DelegateEventHandlersMap, delegateEventHandlers, {});
            
            ClickedButtonAtIndex clickedButtonAtIndex;
            WillDismissWithButtonIndex willDismissWithButtonIndex;
            DidDismissWithButtonIndex didDismissWithButtonIndex;
            
            static DelegateEventHandler& getOrCreate(const void *as);
            
            static DelegateEventHandler* get(const void *as);
            
            static void remove(const void *as);
            
            static void actionSheetDidDismissWithButtonIndex(const void *as,int buttonIndex);
            
            static void actionSheetWillDismissWithButtonIndex(const void *as,int buttonIndex);
            
            static void actionSheetClickedButtonAtIndex(const void *as,int buttonIndex);
        };

#endif  //__APPLE__
    
    };
}

#endif  //__VIPER__IOS_UTIL__UI__ACTION_SHEET__
