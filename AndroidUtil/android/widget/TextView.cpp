//
//  TextView.cpp
//  Groozim
//
//  Created by John Zakharov on 18.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "TextView.hpp"
#include "AndroidUtil/android/text/TextWatcher.hpp"

#ifdef __ANDROID__

const std::string android::widget::TextView::signature = "android/widget/TextView";

android::widget::TextView::TextWatcherEventHandler::OnTextChangedMap android::widget::TextView::TextWatcherEventHandler::onTextChangedMap;

android::widget::TextView::TextWatcherEventHandler::BeforeTextChangedMap android::widget::TextView::TextWatcherEventHandler::beforeTextChangedMap;

android::widget::TextView::TextWatcherEventHandler::AfterTextChangedMap android::widget::TextView::TextWatcherEventHandler::afterTextChangedMap;

android::widget::TextView::TextWatcherEventHandler::DisposablesMap android::widget::TextView::TextWatcherEventHandler::disposablesMap;

android::widget::TextView::TextWatcherEventHandler::Observer android::widget::TextView::TextWatcherEventHandler::observer;

android::widget::TextView android::widget::TextView::create(const android::content::Context &context) {
    return java::lang::Object::create<TextView>(context);
}

void android::widget::TextView::setTextSize(float size) {
    this->sendMessage<void>("setTextSize", size);
}

float android::widget::TextView::getTextSize() {
    return this->sendMessage<float>("getTextSize");
}

void android::widget::TextView::setGravity(int gravity) {
    this->sendMessage<void>("setGravity", gravity);
}

int android::widget::TextView::getGravity() {
    return this->sendMessage<int>("getGravity");
}

void android::widget::TextView::setSelected(bool value) {
    this->sendMessage<void>("setSelected", value);
}

void android::widget::TextView::setInputType(int type){
    this->sendMessage<void>("setInputType",type);
}

void android::widget::TextView::setTextColor(int color){
    this->sendMessage<void>("setTextColor",color);
}

void android::widget::TextView::setText(const std::string &value){
    auto str = java::lang::String::create(value);
//    this->setText(str);
    this->sendMessage<void>("setText", (java::lang::CharSequence)str);
}

void android::widget::TextView::setHint(const std::string &value) {
    auto str = java::lang::String::create(value);
    this->sendMessage<void>("setHint", (java::lang::CharSequence)str);
}

std::string android::widget::TextView::getHint() {
    auto cs = this->sendMessage<java::lang::CharSequence>("getHint");
    return cs.toString().c_str();
}

/*void android::widget::TextView::setText(const java::lang::String &str){
    this->sendMessage<void>("setText",(java::lang::CharSequence)str);
}*/

void android::widget::TextView::addTextChangedListener(const android::text::TextWatcher &watcher){
    this->sendMessage<void>("addTextChangedListener", watcher);
}

void android::widget::TextView::addTextChangedListener(OnTextChanged onTextChanged,
                                                       BeforeTextChanged beforeTextChanged,
                                                       AfterTextChanged afterTextChanged,
                                                       const Mitsoko::Disposable &disposable)
{
//    android::text::TextWatcher textWatcher;
    auto classSignature="kz/outlawstudio/viper/EventHandlers$TextViewTextChangedListener";
    auto textWatcherObject=java::lang::Object::create(classSignature);
    auto textWatcherId=textWatcherObject.getField<int>("mId");
    if(onTextChanged){
        TextWatcherEventHandler::onTextChangedMap.insert({textWatcherId,onTextChanged});
    }
    if(beforeTextChanged){
        TextWatcherEventHandler::beforeTextChangedMap.insert({textWatcherId,beforeTextChanged});
    }
    if(afterTextChanged){
        TextWatcherEventHandler::afterTextChangedMap.insert({textWatcherId,afterTextChanged});
    }
    TextWatcherEventHandler::disposablesMap[disposable.id].push_back(textWatcherId);
//    this->sendMessage<void>("addTextChangedListener",textWatcher);
    this->addTextChangedListener((android::text::TextWatcher)textWatcherObject);
}

android::widget::TextView::TextWatcherEventHandler::Observer::Observer(){
    //  this object must be subscribed forever..
    Mitsoko::Disposable::subscribe(&TextWatcherEventHandler::observer);
}

void android::widget::TextView::TextWatcherEventHandler::Observer::disposableDidDispose(Mitsoko::Disposable::Id id){
    auto it=TextWatcherEventHandler::disposablesMap.find(id);
    if(it != TextWatcherEventHandler::disposablesMap.end()){
        auto &textWatcherIds=it->second;
        for(auto textWatcherId:textWatcherIds){
            auto onTextChangedIt=TextWatcherEventHandler::onTextChangedMap.find(textWatcherId);
            if(onTextChangedIt != TextWatcherEventHandler::onTextChangedMap.end()){
                TextWatcherEventHandler::onTextChangedMap.erase(onTextChangedIt);
            }
            auto beforeTextChangedIt=TextWatcherEventHandler::beforeTextChangedMap.find(textWatcherId);
            if(beforeTextChangedIt != TextWatcherEventHandler::beforeTextChangedMap.end()){
                TextWatcherEventHandler::beforeTextChangedMap.erase(beforeTextChangedIt);
            }
            auto afterTextChangedIt=TextWatcherEventHandler::afterTextChangedMap.find(textWatcherId);
            if(afterTextChangedIt != TextWatcherEventHandler::afterTextChangedMap.end()){
                TextWatcherEventHandler::afterTextChangedMap.erase(afterTextChangedIt);
            }
        }
        TextWatcherEventHandler::disposablesMap.erase(it);
    }
}

void android::widget::TextView::TextWatcherEventHandler::textViewOnTextChanged(int textWatcherId,jobject s,int start, int before, int count){
    auto onTextChangedIt=TextWatcherEventHandler::onTextChangedMap.find(textWatcherId);
    if(onTextChangedIt != TextWatcherEventHandler::onTextChangedMap.end()){
        if(onTextChangedIt->second){
            onTextChangedIt->second(java::lang::CharSequence(s), start, before, count);
        }
    }
}

void android::widget::TextView::TextWatcherEventHandler::textViewBeforeTextChanged(int textWatcherId,jobject s,int start, int before, int count){
    auto beforeTextChangedIt=TextWatcherEventHandler::beforeTextChangedMap.find(textWatcherId);
    if(beforeTextChangedIt != TextWatcherEventHandler::beforeTextChangedMap.end()){
        if(beforeTextChangedIt->second){
            beforeTextChangedIt->second(s, start, before, count);
        }
    }
}

void android::widget::TextView::TextWatcherEventHandler::textViewAfterTextChanged(int textWatcherId,jobject e){
    auto afterTextChangedIt=TextWatcherEventHandler::afterTextChangedMap.find(textWatcherId);
    if(afterTextChangedIt != TextWatcherEventHandler::afterTextChangedMap.end()){
        if(afterTextChangedIt->second){
            afterTextChangedIt->second(e);
        }
    }
}

#endif  //__ANDROID__
