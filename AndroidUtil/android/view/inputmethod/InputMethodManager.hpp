//
//  InputMethodManager.hpp
//  GoZebra
//
//  Created by John Zakharov on 15.03.17.
//  Copyright © 2017 Outlaw Studio. All rights reserved.
//

#ifndef InputMethodManager_hpp
#define InputMethodManager_hpp

#include "Viper/AndroidUtil/java/lang/Object.hpp"
#include "Viper/AndroidUtil/android/os/IBinder.hpp"

namespace android {
    
    namespace view {
        
        namespace inputmethod {
            
            struct InputMethodManager : public java::lang::Object {
#ifdef __ANDROID__
                using Object::Object;
                
                //            const std::string signature;
                STATIC_VAR(const std::string, signature, "android/view/inputmethod/InputMethodManager");
                
                bool hideSoftInputFromWindow(const android::os::IBinder &windowToken, int flags);
                
                static int HIDE_IMPLICIT_ONLY();
                
                static int HIDE_NOT_ALWAYS();
                
                static int RESULT_HIDDEN();
                
                static int RESULT_SHOWN();
                
                static int RESULT_UNCHANGED_HIDDEN();
                
                static int RESULT_UNCHANGED_SHOWN();
                
                static int SHOW_FORCED();
                
                static int SHOW_IMPLICIT();
#endif
            };
        }
    }
}

#endif /* InputMethodManager_hpp */
