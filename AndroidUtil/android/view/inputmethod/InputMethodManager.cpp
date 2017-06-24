//
//  InputMethodManager.cpp
//  GoZebra
//
//  Created by John Zakharov on 15.03.17.
//  Copyright © 2017 Outlaw Studio. All rights reserved.
//

#include "InputMethodManager.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string android::view::inputmethod::InputMethodManager::signature = "android/view/inputmethod/InputMethodManager";

bool android::view::inputmethod::InputMethodManager::hideSoftInputFromWindow(const android::os::IBinder &windowToken, int flags) {
    return this->sendMessage<bool>("hideSoftInputFromWindow", windowToken, flags);
}

bool android::view::inputmethod::InputMethodManager::showSoftInput(const android::view::View &v, int flags) {
    return this->sendMessage<bool>("showSoftInput", v, flags);
}

int android::view::inputmethod::InputMethodManager::HIDE_IMPLICIT_ONLY() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("HIDE_IMPLICIT_ONLY");
    }else{
        return -1;
    }
}

int android::view::inputmethod::InputMethodManager::HIDE_NOT_ALWAYS() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("HIDE_NOT_ALWAYS");
    }else{
        return -1;
    }
}

int android::view::inputmethod::InputMethodManager::RESULT_HIDDEN() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("RESULT_HIDDEN");
    }else{
        return -1;
    }
}

int android::view::inputmethod::InputMethodManager::RESULT_SHOWN() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("RESULT_SHOWN");
    }else{
        return -1;
    }
}

int android::view::inputmethod::InputMethodManager::RESULT_UNCHANGED_HIDDEN() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("RESULT_UNCHANGED_HIDDEN");
    }else{
        return -1;
    }
}

int android::view::inputmethod::InputMethodManager::RESULT_UNCHANGED_SHOWN() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("RESULT_UNCHANGED_SHOWN");
    }else{
        return -1;
    }
}

int android::view::inputmethod::InputMethodManager::SHOW_FORCED() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("SHOW_FORCED");
    }else{
        return -1;
    }
}

int android::view::inputmethod::InputMethodManager::SHOW_IMPLICIT() {
    if(java::lang::Class cls = java::lang::Class::find<android::view::inputmethod::InputMethodManager>()){
        return cls.getStaticField<int>("SHOW_IMPLICIT");
    }else{
        return -1;
    }
}

#endif
