//
//  Calendar.cpp
//  Groozim
//
//  Created by John Zakharov on 22.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Calendar.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string java::util::Calendar::signature = "java/util/Calendar";

void java::util::Calendar::setTime(const Date &date){
    this->sendMessage<void>("setTime",date);
}

auto java::util::Calendar::getInstance() -> Calendar {
    if(java::lang::Class cls = java::lang::Class::find<Calendar>()){
        return cls.callStaticFunc<Calendar>("getInstance");
    }else{
        return {};
    }
    /*if(auto java_env=java::lang::JNI::Env()){
        auto clazz = java_env->FindClass(signature().c_str());
        auto mid=java_env->GetStaticMethodID(clazz,"getInstance",generateMethodSignature<Calendar>().c_str());
        return java_env->CallStaticObjectMethod(clazz,mid);
    }else{
        return {};
    }*/
}

#endif  //__ANDROID__
