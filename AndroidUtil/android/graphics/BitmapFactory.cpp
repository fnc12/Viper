//
//  BitmapFactory.cpp
//  Groozim
//
//  Created by John Zakharov on 17.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "BitmapFactory.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string android::graphics::BitmapFactory::signature = "android/graphics/BitmapFactory";

const std::string android::graphics::BitmapFactory::Options::signature = "android/graphics/BitmapFactory$Options";

android::graphics::Bitmap android::graphics::BitmapFactory::decodeFile(const std::string &pathName) {
    auto s = java::lang::String::create(pathName);
    return decodeFile(s);
}

android::graphics::Bitmap android::graphics::BitmapFactory::decodeFile(const java::lang::String &pathName) {
    if(auto java_env=java::lang::JNI::Env()){
        auto clazz = java::lang::Class::find<BitmapFactory>();
        auto methodSignature=generateMethodSignature<Bitmap,java::lang::String>();
        auto mid=java_env->GetStaticMethodID(clazz, "decodeFile", methodSignature.c_str());
        return java_env->CallStaticObjectMethod(clazz,mid,(jobject)pathName.handle);
    }else{
        return {};
    }
}

android::graphics::Bitmap android::graphics::BitmapFactory::decodeByteArray(java::lang::Array<char> data, int offset, int length) {
    if(java::lang::Class cls = java::lang::Class::find<BitmapFactory>()){
        return cls.callStaticFunc<Bitmap>("decodeByteArray", data, offset, length);
    }else{
        return {};
    }
}

auto android::graphics::BitmapFactory::Options::create()->Options{
    return std::move(java::lang::Object::create<Options>());
}

#endif  //__ANDROID__
