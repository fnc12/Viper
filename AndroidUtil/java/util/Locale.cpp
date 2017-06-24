//
//  Locale.cpp
//  Groozim
//
//  Created by John Zakharov on 22.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Locale.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string java::util::Locale::signature = "java/util/Locale";

void java::util::Locale::start(){
    this->sendMessage<void>("start");
}

java::lang::String java::util::Locale::getLanguage() {
    return this->sendMessage<java::lang::String>("getLanguage");
}

auto java::util::Locale::getDefault() -> Locale {
//    if(auto java_env=java::lang::JNI::Env()){
//        auto clazz = java_env->FindClass(signature().c_str());
    if(java::lang::Class clazz = java::lang::Class::find<Locale>()){
        return clazz.callStaticFunc<Locale>("getDefault");
    }else{
        return {};
    }
        /*auto mid=java_env->GetStaticMethodID(clazz, "getDefault", generateMethodSignature<Locale>().c_str());
        return java_env->CallStaticObjectMethod(clazz,mid);*/
    /*}else{
        return {};
    }*/
}

#endif  //__ANDROID__
