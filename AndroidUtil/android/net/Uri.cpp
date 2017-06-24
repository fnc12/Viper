//
//  Uri.cpp
//  Groozim
//
//  Created by John Zakharov on 17.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Uri.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string android::net::Uri::signature = "android/net/Uri";

auto android::net::Uri::parse(const std::string &uriString) -> Uri {
    auto str = java::lang::String::create(uriString);
    return std::move(Uri::parse(str));
}

auto android::net::Uri::parse(const java::lang::String &uriString) -> Uri {
    if(auto java_env=java::lang::JNI::Env()){
//        auto clazz = java_env->FindClass(signature().c_str());
        auto clazz = java::lang::Class::find<Uri>();
        auto methodSignature=generateMethodSignature<Uri,java::lang::String>();
        auto mid=java_env->GetStaticMethodID(clazz,"parse",methodSignature.c_str());
        return java_env->CallStaticObjectMethod(clazz,mid,(jobject)uriString.handle);
    }else{
        return {};
    }
}

#endif  //__ANDROID__
