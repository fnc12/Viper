
#ifndef __VIPER__ANDROID_UTIL__ANDROID__CONTENT__INTENT__
#define __VIPER__ANDROID_UTIL__ANDROID__CONTENT__INTENT__

#include "AndroidUtil/java/lang/Object.hpp"
#include "AndroidUtil/java/lang/String.hpp"
#include "AndroidUtil/android/net/Uri.hpp"
#include "AndroidUtil/android/os/Bundle.hpp"
#include "AndroidUtil/android/net/Uri.hpp"
#include "AndroidUtil/java/lang/Class.hpp"
#include "Context.hpp"

#include <vector>
#include <initializer_list>

namespace android{
    
    namespace content{
        
        struct Intent : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static Intent create(const Context &context, const java::lang::Class &cls);
            
            static Intent create(const std::string &action, const android::net::Uri &uri);
            
            static Intent create(const std::string &action);
            
            static std::string ACTION_PICK();
            
            static std::string ACTION_CALL();
            
            static std::string ACTION_SEND();
            
            static std::string EXTRA_EMAIL();
            
            static std::string EXTRA_SUBJECT();
            
            static std::string EXTRA_TEXT();
            
            static Intent createChooser(const Intent &target, const std::string &title);
            
            Intent& setType(const std::string &type);
            
            android::net::Uri getData();
            
            android::os::Bundle getExtras();
            
            Intent& putExtra(const std::string &name, const std::string &value);
            
            Intent& putExtra(const std::string &name, const std::vector<std::string> &value);
            
            Intent& setData(const android::net::Uri &data);
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__CONTENT__INTENT__
