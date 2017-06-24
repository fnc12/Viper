//
//  Activity.cpp
//  Groozim
//
//  Created by John Zakharov on 14.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Activity.hpp"
#include "AndroidUtil/java/lang/String.hpp"

#ifdef __ANDROID__

const std::string android::app::Activity::signature = "android/app/Activity";

java::lang::Object android::app::Activity::getSystemService(const std::string &name) {
    auto str = java::lang::String::create(name);
    return this->sendMessage<java::lang::Object>("getSystemService", str);
}

int android::app::Activity::RESULT_CANCELED(){
    if(java::lang::Class cls=java::lang::Class::find<Activity>()){
        return cls.getStaticField<int>("RESULT_CANCELED");
    }else{
        return -1;
    }
}

int android::app::Activity::RESULT_OK(){
    if(java::lang::Class cls = java::lang::Class::find<Activity>()){
        return cls.getStaticField<int>("RESULT_OK");
    }else{
        return -1;
    }
}

int android::app::Activity::RESULT_FIRST_USER(){
    if(java::lang::Class cls=java::lang::Class::find<Activity>()){
        return cls.getStaticField<int>("RESULT_FIRST_USER");
    }else{
        return -1;
    }
}

void android::app::Activity::finish(){
    this->sendMessage<void>("finish");
}

void android::app::Activity::startActivity(const content::Intent &intent){
    this->sendMessage<void>("startActivity",intent);
}

void android::app::Activity::startActivityForResult(const content::Intent &intent, int requestCode){
    this->sendMessage<void>("startActivityForResult",intent,requestCode);
}

void android::app::Activity::setResult(int resultCode){
    this->sendMessage<void>("setResult",resultCode);
}

void android::app::Activity::setResult(int resultCode,const content::Intent &intent){
    this->sendMessage<void>("setResult",resultCode,intent);
}

void android::app::Activity::runOnUiThread(const java::lang::Runnable &runnable){
    this->sendMessage<void>("runOnUiThread",runnable);
}

android::view::View android::app::Activity::getCurrentFocus() {
    return this->sendMessage<android::view::View>("getCurrentFocus");
}

#endif  //__ANDROID__
