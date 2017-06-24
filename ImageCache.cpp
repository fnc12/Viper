//
//  ImageCache.cpp
//  Jako
//
//  Created by John Zakharov on 06.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "ImageCache.hpp"
#include "Url/Request.hpp"

#include <iostream>

Mitsoko::ImageCache Mitsoko::ImageCache::shared;

Mitsoko::ImageCache::Callback::Callback(type fun_,const Disposable &disposable):fun(fun_),disposableId(disposable.id){
    Disposable::subscribe(this);
}

Mitsoko::ImageCache::Callback::Callback(const Callback &other):fun(other.fun),shouldFire(other.shouldFire),disposableId(other.disposableId){
    Disposable::subscribe(this);
}

void Mitsoko::ImageCache::Callback::operator()(Image image) const{
    if(this->shouldFire){
        this->fun(image);
    }else{
        std::cerr<<"shouldFire is false"<<std::endl;
    }
}

void Mitsoko::ImageCache::Callback::disposableDidDispose(Disposable::Id id){
    if(id == this->disposableId){
        this->shouldFire = false;
    }
}

void Mitsoko::ImageCache::get(const std::string &url, Callback cb){
    std::string key, filepath;
    if(auto res = getCached(url, &key, &filepath)){
        cb(res);
    }else{
        auto it = this->callbacks.find(url);
        if(it == this->callbacks.end()){
            callbacks[url].push_back(cb);
            Url::Request request;
            request.url(url);
            request.performAsync<Image>([=](Url::Response response, Mitsoko::Image image, Url::Error error) {
                if(image) {
                    image.writeToFile(filepath);
                    putIntoRAM(key, image);
                    auto it = this->callbacks.find(url);
                    if(it != this->callbacks.end()) {
                        for(auto &cb : it->second) {
                            cb(image);
                        }
                        this->callbacks.erase(it);
                    }else{
                        std::cerr << "callback not found for url *" << url << "*" << std::endl;
                    }
                }else{
                    std::cerr << "image is null for url *" << url << "*" << std::endl;
                }
            });
        }else{
            callbacks[url].push_back(cb);
        }
    }
}

void Mitsoko::ImageCache::put(const std::string &url, Image image) {
    auto key = this->keyByUrl(url);
    auto filename = this->imageFileName(key);
    auto filepath = this->documentsPath() + '/' + filename;
    image.writeToFile(filepath);
    putIntoRAM(key, image);
}

Mitsoko::Image Mitsoko::ImageCache::getCached(const std::string &url, std::string *keyPointer, std::string *filepathPointer) {
    auto key = this->keyByUrl(url);
    if(keyPointer){
        *keyPointer = key;
    }
    auto res = getImageFromRAM(key);
    if(res){
        return res;
    }else{
        auto filename = this->imageFileName(key);
        auto filepath = this->documentsPath() + '/' + filename;
        if(filepathPointer) {
            *filepathPointer = filepath;
        }
        auto res = getImageFromFS(filepath);
        if(res) {
            putIntoRAM(key, res);
            return res;
        }else{
            return {};
        }
    }
}

std::string Mitsoko::ImageCache::keyByUrl(const std::string &url) const {
    sha256_t digest;
    ::sha256((unsigned char*)url.c_str(), url.length(), digest);
    return getHexRepresentation(digest, sizeof(digest));
}

void Mitsoko::ImageCache::documentsPath(const std::string &newValue){
    _documentsPath=newValue;
}

const std::string& Mitsoko::ImageCache::documentsPath(){
    if(_documentsPath.empty()){
#ifdef __APPLE__
        NSString *dp = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0];
        _documentsPath=dp.UTF8String;
#else
        _documentsPath = "/data/data/" + java::lang::JNI::appId;
#endif
    }
    return _documentsPath;
}

void Mitsoko::ImageCache::putIntoRAM(const std::string &key, Image image){
#ifdef __APPLE__
    auto keyString = CF::String::create(key);
    this->ramCache()[keyString] = image.get();
#else
    auto keyString = java::lang::String::create(key);
    this->ramCache().put(keyString, image.get());
#endif
}

Mitsoko::Image Mitsoko::ImageCache::getImageFromRAM(const std::string &key) {
#ifdef __APPLE__
    auto keyString = CF::String::create(key);
    return this->ramCache()[keyString].as<UI::Image>();
#else
    auto keyString = java::lang::String::create(key);
    return this->ramCache().get(keyString);
#endif
}

auto Mitsoko::ImageCache::getImageFromFS(const std::string &filepath) -> Image {
#ifdef __APPLE__
    return UI::Image::createWithContentsOfFile(filepath);
#else
    return android::graphics::BitmapFactory::decodeFile(filepath);
#endif
}

#ifdef __APPLE__

NS::MutableDictionary& Mitsoko::ImageCache::ramCache(){
    if(!_ramCache){
        _ramCache = NS::MutableDictionary::create();
    }
    return _ramCache;
}

#else

auto Mitsoko::ImageCache::ramCache()->decltype(_ramCache)&{
    if(!_ramCache){
        _ramCache = java::util::HashMap<java::lang::String, android::graphics::Bitmap>::create();
        _ramCache.handle = java::lang::JNI::Env()->NewGlobalRef((jobject)_ramCache.handle);
    }
    return _ramCache;
}

#endif

std::string Mitsoko::ImageCache::imageFileName(const std::string &key){
    return "image_"+key;
}

std::string Mitsoko::ImageCache::getHexRepresentation(const unsigned char *bytes, size_t length) const {
    std::ostringstream os;
    os.fill('0');
    os << std::hex;
    for(const unsigned char * ptr = bytes; ptr < bytes + length; ptr++)
        os << std::setw(2) << (unsigned int)*ptr;
    return os.str();
}
