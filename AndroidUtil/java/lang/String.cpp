//
//  String.cpp
//  Groozim
//
//  Created by John Zakharov on 16.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "String.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string java::lang::String::signature = "java/lang/String";

const char* java::lang::String::c_str() const{
    if(auto env=JNI::Env()){
        return env->GetStringUTFChars(static_cast<jstring>(const_cast<void*>(this->handle)), JNI_FALSE);
    }else{
        return nullptr;
    }
}

auto java::lang::String::create(std::string str)->String{
    if(auto env=JNI::Env()){
        jbyteArray array = env->NewByteArray(str.size());
        env->SetByteArrayRegion(array, 0, str.size(), (const jbyte*)str.c_str());
        jstring strEncode = env->NewStringUTF("UTF-8");
//        jclass cls = env->FindClass(signature().c_str());
        auto cls = java::lang::Class::find<String>();
        jmethodID ctor = env->GetMethodID(cls, "<init>", "([BLjava/lang/String;)V");
        jstring object = (jstring) env->NewObject(cls, ctor, array, strEncode);
        return object;
    }else{
        return nullptr;
    }
}

#endif  //__ANDROID__
