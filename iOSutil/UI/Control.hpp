
#ifndef __VIPER__IOS_UTIL__UI__CONTROL__
#define __VIPER__IOS_UTIL__UI__CONTROL__

#include "View.hpp"
#include "Util.hpp"
#include "Disposable.hpp"

#include <functional>
#include <map>

namespace UI {
    
    struct Control : public UI::View {
        
        using View::View;

#ifdef __APPLE__
        
        enum class State : UIControlState {
            Normal = UIControlStateNormal,
            Highlighted = UIControlStateHighlighted,
            Disabled = UIControlStateDisabled,
            Selected = UIControlStateSelected,
            Focused = UIControlStateFocused,
            Application = UIControlStateApplication,
            Reserved = UIControlStateReserved,
        };
        
        static const std::string className;
        
        typedef std::function<void(Handle)> Callback;
        
        void setEnabled(bool newValue);
        
        bool enabled();
        
        void setSelected(bool value);
        
        bool isSelected();
        
        void setOnValueChanged(Callback cb, Mitsoko::Disposable &target);
        
        void setOnTouchUpInside(Callback cb, Mitsoko::Disposable *target);
        
        struct Events{
            struct TouchDown{};
            struct TouchDownRepeat{};
            struct TouchDragInside{};
            struct TouchDragOutside{};
            struct TouchDragEnter{};
            struct TouchDragExit{};
            struct TouchUpInside{};
            struct TouchUpOutside{};
            struct TouchCancel{};
            struct ValueChanged{};
            struct PrimaryActionTriggered{};
            struct EditingDidBegin{};
            struct EditingChanged{};
            struct EditingDidEnd{};
            struct EditingDidEndOnExit{};
        };
        
        template<class T>
        struct EventHandler{
            typedef EventHandler<T> Self;
            
            typedef std::map<Handle, Callback> Callbacks;
            
            static Callbacks callbacks;
            
            /**
             *  Assumes *cb* ≠ null.
             */
            static void add(Handle handle, Callback cb){
                auto it = Self::callbacks.find(handle);
                if(it != Self::callbacks.end()){
                    it->second=cb;
                }else{
                    Self::callbacks.insert({handle,cb});
                }
            }
            
            static Callback get(Handle handle){
                auto it = Self::callbacks.find(handle);
                if(it != Self::callbacks.end()){
                    return it->second;
                }else{
                    return {};
                }
            }
            
            static void remove(Handle handle){
                auto it = Self::callbacks.find(handle);
                if(it != Self::callbacks.end()){
                    Self::callbacks.erase(it);
                }else{
                    //..
                }
            }
            
            static void actionDidHappen(Handle sender){
                if(auto cb = Self::get(sender)){
                    cb(sender);
                }
            }
        };
        
#endif  //__APPLE__
        
    };
}

#ifdef __APPLE__

template<class T>
typename UI::Control::EventHandler<T>::Callbacks UI::Control::EventHandler<T>::callbacks;

#endif  //__APPLE__

#endif  //__VIPER__IOS_UTIL__UI__CONTROL__
