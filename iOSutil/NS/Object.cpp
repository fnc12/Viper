//
//  Object.cpp
//  Groozim
//
//  Created by John Zakharov on 14.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Object.hpp"
#include "iOSutil/NS/String.hpp"

#ifdef __APPLE__

const std::string NS::Object::className="NSObject";

Class NS::getClass(const std::string &className){
    return objc_getClass(className.c_str());
}

NS::Object::Object():Object(nullptr){}

NS::Object::Object(decltype(handle)handle_):
handle(handle_){
#ifdef __APPLE__
    if(this->handle){
        this->retain();
    }
#endif
}

NS::Object& NS::Object::operator=(const NS::Object &other){
    this->cleanUp();
    this->handle=other.handle;
#ifdef __APPLE__
    if(this->handle){
        this->retain();
    }
#endif
    return *this;
}

NS::Object::Object(Object &&object):handle(object.handle){
    object.handle=nullptr;
    //            object.shouldClearOnDestroy=false;
}

NS::Object& NS::Object::operator=(Object &&object){
    this->cleanUp();
    this->handle=object.handle;
    object.handle=nullptr;
    return *this;
}

NS::Object::~Object(){
    this->cleanUp();
}

std::string NS::Object::description(){
    NS::String s=this->sendMessage<Handle>("description");
//    return s.sendMessage<const char*>("UTF8String");
    if(s){
        return s.UTF8String();
    }else{
        return "(null)";
    }
}

Class NS::Object::getClass(){
    return this->sendMessage<Class>("class");
}

NS::Object::operator bool() const{
    return this->handle != nullptr;
}

NS::Object::operator Handle() const{
    return this->handle;
}

void NS::Object::retain(){
    CFRetain(CFTypeRef(this->handle));
}

void NS::Object::release(){
    CFRelease(CFTypeRef(this->handle));
}

int NS::Object::retainCount(){
    return int(CFGetRetainCount(CFTypeRef(this->handle)));
}

void NS::Object::cleanUp(){
    if(this->handle){
        this->release();
        this->handle=nullptr;
    }
}

std::ostream& NS::operator<<(std::ostream &os,NS::Object &obj){
    os<<obj.description();
    return os;
}

#endif  //__APPLE__
