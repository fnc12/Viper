
#ifndef __VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW__
#define __VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW__

#include "AndroidUtil/java/lang/Class.hpp"
#include "AndroidUtil/android/content/Context.hpp"
#include "AndroidUtil/android/os/IBinder.hpp"
#include "Disposable.hpp"

#include <functional>
#include <map>

namespace android {
    
    namespace view {
        
        struct View : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            typedef std::function<void(Handle)> OnClick;
            
            typedef std::map<int,OnClick> OnClickMap;
            static OnClickMap onClickMap;
            
            typedef std::map<Mitsoko::Disposable::Id,int> DisposablesMap;
            static DisposablesMap disposablesMap;
            
            struct OnClickListener : public java::lang::Object {
                
                using Object::Object;
                
                static const std::string signature;
            };
            
            static void onClick(int id,android::view::View v);
            
            void setOnClickListener(OnClick cb,const Mitsoko::Disposable &disposable);
            
            /**
             *  Implemented in ViewGroup.hpp"
             */
            template<class T>
            void setLayoutParams(const T &params);
            
            View findViewById(int id);
            
            /**
             *  This function actually doesn't exist in SDK but it is created
             *  to simplify developers finding a subview by string identifier from xml-file.
             *  =========
             *  Also it's body contains call to 'getResourseId' static function call instead of
             *  android native context.getResources.getIdentifier("view_id","id",context.getPackageName());.
             *  This is done because calling context.getResources.getIdentifier from C++ always returns
             *  incorrect id. The reason is still unknown so I decided to transfer this logic into
             *  client side. If you know the reason why context.getResources.getIdentifier doesn't work
             *  correctly please contact me fnc12@me.com. Thanks
             */
            View findViewById(const std::string &idString,const content::Context &context);
            
            void setVisibility(int visibility);
            
            void setBackgroundColor(int color);
            
            void setEnabled(bool enabled);
            
            bool isEnabled();
            
            int getWidth();
            
            int getHeight();
            
            android::os::IBinder getWindowToken();
            
            View getRootView();
            
            static int VISIBLE();
            
            static int INVISIBLE();
            
            static int GONE();
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__VIEW__VIEW__
