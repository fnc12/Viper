
#ifndef __VIPER__ANDROID_UTIL__ANDROID__APP__ALERT_DIALOG__
#define __VIPER__ANDROID_UTIL__ANDROID__APP__ALERT_DIALOG__

#include "Dialog.hpp"
#include "AndroidUtil/android/content/Context.hpp"
#include "AndroidUtil/java/lang/String.hpp"
#include "AndroidUtil/android/content/DialogInterface.hpp"
#include "AndroidUtil/android/view/View.hpp"

#include <functional>
#include <map>

namespace android{
    
    namespace app{
        
        struct AlertDialog : public Dialog {
            
            using Dialog::Dialog;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            void show();
            
            struct Builder:public java::lang::Object{
                
                using Object::Object;
                
                static const std::string signature;
                
                typedef std::function<void(content::DialogInterface,int)> OnClickCallback;
                typedef std::map<int,OnClickCallback> OnClickMap;
                static OnClickMap onClickMap;
                
                static Builder create(const content::Context &context);
                
                /**
                 *  Fucntion called from NI.cpp when dialogOnClick happens.
                 *  Must not be called directly.
                 */
                static void alertDialogClickListener_onClick(int id,jobject dialogInterface,int which);
                
                AlertDialog create();
                
                Builder& setItems(const std::vector<std::string> &items, OnClickCallback cb);
                
                Builder& setMessage(const std::string &title);
                
                Builder& setMessage(const java::lang::CharSequence &title);
                
                Builder& setTitle(const std::string &title);
                
                Builder& setTitle(const java::lang::CharSequence &title);
                
                Builder& setPositiveButton(const std::string &text,OnClickCallback cb);
                
                Builder& setPositiveButton(const java::lang::CharSequence &text,OnClickCallback cb);
                
                Builder& setNegativeButton(const std::string &text,OnClickCallback cb);
                
                Builder& setNegativeButton(const java::lang::CharSequence &text,OnClickCallback cb);
                
                Builder& setView(const android::view::View &view);
            };
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__APP__ALERT_DIALOG__
