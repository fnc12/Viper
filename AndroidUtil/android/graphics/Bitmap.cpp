//
//  Bitmap.cpp
//  Groozim
//
//  Created by John Zakharov on 17.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Bitmap.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

using std::cout;
using std::endl;

#ifdef __ANDROID__

const std::string android::graphics::Bitmap::signature = "android/graphics/Bitmap";

const std::string android::graphics::Bitmap::CompressFormat::signature = "android/graphics/Bitmap$CompressFormat";

const std::string android::graphics::Bitmap::Config::signature = "android/graphics/Bitmap$Config";

void android::graphics::Bitmap::recycle(){
    this->sendMessage<void>("recycle");
}

int android::graphics::Bitmap::getWidth(){
    return this->sendMessage<int>("getWidth");
}

int android::graphics::Bitmap::getHeight(){
    return this->sendMessage<int>("getHeight");
}

auto android::graphics::Bitmap::CompressFormat::JPEG() -> CompressFormat {
    if(java::lang::Class cls = java::lang::Class::find<CompressFormat>()){
        return cls.getStaticField<CompressFormat>("JPEG");
    }else{
        LOGI("class CompressFormat not found");
        return {};
    }
}

int android::graphics::Bitmap::CompressFormat::PNG(){
    if(java::lang::Class cls = java::lang::Class::find<CompressFormat>()){
        return cls.getStaticField<int>("PNG");
    }else{
        return -1;
    }
}

int android::graphics::Bitmap::CompressFormat::WEBP(){
    if(java::lang::Class cls=java::lang::Class::find<CompressFormat>()){
        return cls.getStaticField<int>("WEBP");
    }else{
        return -1;
    }
}

int android::graphics::Bitmap::Config::ALPHA_8(){
    if(java::lang::Class cls=java::lang::Class::find<Config>()){
        return cls.getStaticField<int>("ALPHA_8");
    }else{
        return -1;
    }
}

int android::graphics::Bitmap::Config::RGB_565(){
    if(java::lang::Class cls=java::lang::Class::find<Config>()){
        return cls.getStaticField<int>("RGB_565");
    }else{
        return -1;
    }
}

int android::graphics::Bitmap::Config::ARGB_4444(){
    if(java::lang::Class cls=java::lang::Class::find<Config>()){
        return cls.getStaticField<int>("ARGB_4444");
    }else{
        return -1;
    }
}

int android::graphics::Bitmap::Config::ARGB_8888(){
    if(java::lang::Class cls=java::lang::Class::find<Config>()){
        return cls.getStaticField<int>("ARGB_8888");
    }else{
        return -1;
    }
}

bool android::graphics::Bitmap::compress(CompressFormat format, int quality, const java::io::OutputStream &stream) {
    return this->sendMessage<bool>("compress", format, quality, stream);
}

auto android::graphics::Bitmap::createScaledBitmap(const Bitmap &src, int dstWidth, int dstHeight, bool filter) -> Bitmap {
    if(java::lang::Class cls = java::lang::Class::find<Config>()){
        return cls.callStaticFunc<Bitmap>("createScaledBitmap", src, dstWidth, dstHeight, filter);
    }else{
        return {};
    }
    /*if(auto java_env = java::lang::JNI::Env()){
        auto clazz = java_env->FindClass(signature().c_str());
        auto methodSignature = generateMethodSignature<Bitmap,Bitmap,int,int,bool>();
        auto mid = java_env->GetStaticMethodID(clazz,
                                               "createScaledBitmap",
                                               methodSignature.c_str());
        return java_env->CallStaticObjectMethod(clazz,
                                                mid,
                                                src.handle,
                                                jint(dstWidth),
                                                jint(dstHeight),
                                                jboolean(filter));
    }else{
        return {};
    }*/
}

auto android::graphics::Bitmap::createBitmap(const Bitmap &source,
                                             int x,
                                             int y,
                                             int width,
                                             int height) -> Bitmap
{
    if(java::lang::Class cls = java::lang::Class::find<Config>()){
        return cls.callStaticFunc<Bitmap>("createBitmap", source, x, y, width, height);
    }else{
        return {};
    }
    /*if(auto java_env = java::lang::JNI::Env()){
        auto clazz = java_env->FindClass(signature().c_str());
        auto methodSignature = generateMethodSignature<Bitmap,Bitmap,int,int,int,int>();
        auto mid = java_env->GetStaticMethodID(clazz,
                                               "createBitmap",
                                               methodSignature.c_str());
        return java_env->CallStaticObjectMethod(clazz,
                                                mid,
                                                source.handle,
                                                jint(x),
                                                jint(y),
                                                jint(width),
                                                jint(height));
    }else{
        return {};
    }*/
}

#endif  //__ANDROID__
