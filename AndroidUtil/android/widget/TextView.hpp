
#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__TEXT_VIEW__
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__TEXT_VIEW__

#include "AndroidUtil/android/view/View.hpp"
#include "AndroidUtil/java/lang/String.hpp"
#include "AndroidUtil/android/graphics/Color.hpp"
#include "AndroidUtil/android/text/TextWatcher.hpp"
#include "AndroidUtil/android/text/Editable.hpp"
#include "AndroidUtil/android/content/Context.hpp"
#include "Disposable.hpp"

#include <functional>
#include <map>
#include <vector>

namespace android{
    
    namespace widget{
        
        struct TextView : public view::View {
            
            using View::View;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static TextView create(const android::content::Context &context);
            
            typedef std::function<void(java::lang::CharSequence,int,int,int)> OnTextChanged;
            typedef std::function<void(java::lang::CharSequence,int,int,int)> BeforeTextChanged;
            typedef std::function<void(android::text::Editable)> AfterTextChanged;
            
            void setTextSize(float size);
            
            float getTextSize();
            
            void setGravity(int gravity);
            
            int getGravity();
            
            void setInputType(int type);
            
            void setTextColor(int color);
            
            void setText(const std::string &value);
            
            void setSelected(bool value);
            
            void setHint(const std::string &value);
            
            std::string getHint();
            
            void addTextChangedListener(const android::text::TextWatcher &watcher);
            
            /**
             *  This is a c++ adaptation of `addTextChangedListener` function. You do not
             *  have to create a TextWatcher object - just set lambdas and that's all. 
             *  Any lambda can be nullptr.
             */
            void addTextChangedListener(OnTextChanged onTextChanged,
                                        BeforeTextChanged beforeTextChanged,
                                        AfterTextChanged afterTextChanged,
                                        const Mitsoko::Disposable &disposable);
            
            struct TextWatcherEventHandler{
                typedef std::map<int,OnTextChanged> OnTextChangedMap;
                static OnTextChangedMap onTextChangedMap;
                
                typedef std::map<int,BeforeTextChanged> BeforeTextChangedMap;
                static BeforeTextChangedMap beforeTextChangedMap;
                
                typedef std::map<int,AfterTextChanged> AfterTextChangedMap;
                static AfterTextChangedMap afterTextChangedMap;
                
                typedef std::map<Mitsoko::Disposable::Id,std::vector<int>> DisposablesMap;
                static DisposablesMap disposablesMap;
                
                struct Observer : public Mitsoko::Disposable::Observer {
                    
                    Observer();
                    
                    virtual void disposableDidDispose(Mitsoko::Disposable::Id id) override;
                };
                
                static Observer observer;
                
                static void textViewOnTextChanged(int textWatcherId,jobject s,int start, int before, int count);
                
                static void textViewBeforeTextChanged(int textWatcherId,jobject s,int start, int before, int count);
                
                static void textViewAfterTextChanged(int textWatcherId,jobject e);
            };
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__WIDGET__TEXT_VIEW__
