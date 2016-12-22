//
//  UrlRequest.cpp
//  Groozim
//
//  Created by John Zakharov on 21.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Request.hpp"
#include "Viper/AndroidUtil/java/lang/Class.hpp"
#include "Viper/AndroidUtil/java/lang/String.hpp"

#include <iostream>
#include <sys/time.h>

using std::cout;
using std::endl;

const std::string Viper::Url::Request::crlf = "\r\n";

#ifdef __ANDROID__

static auto networkUrlRequestClassSignature = "kz/outlawstudio/viper/Network$UrlRequest";

//std::map<int, Viper::Url::Request::Callback> Viper::Url::Request::callbacks;

#endif  //__ANDROID__

Viper::Url::Request::Request(){

#ifdef __APPLE__
    request = NS::MutableURLRequest::create();
#else
    request = java::lang::Object::create(networkUrlRequestClassSignature);
#endif  //__APPLE__

}

std::string Viper::Url::Request::MultipartAdapter::body() {
    return this->stream.str();
}

const std::string& Viper::Url::Request::MultipartAdapter::boundary() const {
    return _boundary;
}

void Viper::Url::Request::MultipartAdapter::addFormField(const std::string &name, const std::string &value) {
    this->stream << "--" << _boundary << crlf;
    this->stream << "Content-Disposition: form-data; name=\"" << name << "\"" << crlf;
    this->stream << "Content-Type: text/plain; charset=" << this->charset << crlf;
    this->stream << crlf;
    this->stream << value << crlf;
}

void Viper::Url::Request::MultipartAdapter::addFilePart(const std::string &fieldName,
                                                        const std::string &filepath,
                                                        const std::string &fileName,
                                                        const std::string &mimeType)
{
    auto count = fileSize(filepath);
    std::ifstream file(filepath);
    if(file) {
        this->stream << "--" << _boundary << crlf;
        this->stream << "Content-Disposition: form-data; name=\"" << fieldName << "\"; filename=\"" << fileName << "\"" << crlf;
        this->stream << "Content-Type: " << mimeType << crlf;
        this->stream << "Content-Transfer-Encoding: binary" << crlf;
        this->stream << crlf;
        stream_copy_n(file, count, this->stream);
        file.close();
        this->stream << crlf;
    }else{
        std::cerr << "failed to open file at *" << filepath << "*" << std::endl;
    }
}

Viper::Url::Request::MultipartAdapter::MultipartAdapter():charset("UTF-8"){}

void Viper::Url::Request::performAsync(std::function<void(Response, std::vector<char>, Error)> callback) {
    this->performAsync<std::vector<char>>(callback);
}

template<>
void Viper::Url::Request::performAsync<std::vector<char>>(std::function<void(Response, std::vector<char>, Error)> callback) {
    
#ifdef __APPLE__
    NS::URLConnection::sendAsynchronousRequest(request,
                                               NS::OperationQueue::mainQueue(),
                                               [=](NS::URLResponse response, NS::Data data, NS::Error error){
                                                   
                                                   //   create response wrapper..
                                                   Response r(response.as<NS::HTTPURLResponse>());
                                                   
                                                   //   copy data into vector..
                                                   std::vector<char> d;
                                                   auto dataLength = data.length();
                                                   if(dataLength){
                                                       d.reserve(dataLength);
                                                       auto dataBegin = (const char*)data.bytes();
                                                       auto dataEnd = dataBegin + dataLength;
                                                       std::copy(dataBegin,
                                                                 dataEnd,
                                                                 std::back_inserter(d));
                                                   }
                                                   
                                                   //   create error wrapper..
                                                   Error e(error);
                                                   
                                                   if(callback){
                                                       callback(std::move(r), std::move(d), std::move(e));
                                                   }
                                                   
                                               });
#else
    auto requestId = request.sendMessage<int>("getId");
    request.sendMessage<void>("perform");
    CallbackHolder<std::vector<char>>::callbacks.insert({requestId, callback});
#endif  //__APPLE__
    
}

template<>
void Viper::Url::Request::performAsync<Viper::Image>(std::function<void(Response, Image, Error)> callback) {
#ifdef __APPLE__
    NS::URLConnection::sendAsynchronousRequest(request,
                                               NS::OperationQueue::mainQueue(),
                                               [=](NS::URLResponse response, NS::Data data, NS::Error error){
                                                   
                                                   //   create response wrapper..
                                                   Response r(response.as<NS::HTTPURLResponse>());
                                                   
                                                   //   create image from data..
                                                   auto image = UI::Image::create(data);
                                                   Viper::Image i(image);
                                                   /*std::vector<char> d;
                                                   auto dataLength = data.length();
                                                   if(dataLength){
                                                       d.reserve(dataLength);
                                                       auto dataBegin = (const char*)data.bytes();
                                                       auto dataEnd = dataBegin + dataLength;
                                                       std::copy(dataBegin,
                                                                 dataEnd,
                                                                 std::back_inserter(d));
                                                   }*/
                                                   
                                                   //   create error wrapper..
                                                   Error e(error);
                                                   
                                                   if(callback){
                                                       callback(std::move(r), std::move(i), std::move(e));
                                                   }
                                                   
                                               });
#else
    auto requestId = request.sendMessage<int>("getId");
    request.sendMessage<void>("perform");
    request.sendMessage<void>("setReturnType", 2);      //  2 means image..
    CallbackHolder<Viper::Image>::callbacks.insert({requestId, callback});
#endif  //__APPLE__
}

/*template<>
void Viper::Url::Request::performAsync<std::string>(std::function<void(Response, std::string, Error)> callback) {
    
}*/

std::string Viper::Url::Request::MultipartAdapter::generateBoundary() {
    struct timeval tv;
    ::gettimeofday(&tv, nullptr);
    std::stringstream ss;
    ss << "===" << tv.tv_sec << "_" << tv.tv_usec << "===";
    return ss.str();
}

void Viper::Url::Request::MultipartAdapter::finish() {
    this->stream << crlf;
    this->stream << "--" << _boundary << "--" << crlf;
}

size_t Viper::Url::Request::MultipartAdapter::fileSize(const std::string &filepath) {
    std::ifstream file(filepath, std::ios::binary | std::ios::ate);
    if(file) {
        return file.tellg();
    }else{
        return 0;
    }
}

void Viper::Url::Request::MultipartAdapter::stream_copy_n(std::istream &in, std::size_t count, std::ostream &out) {
    const std::size_t buffer_size = 4096;
    char buffer[buffer_size];
    while(count > buffer_size) {
        in.read(buffer, buffer_size);
        out.write(buffer, buffer_size);
        count -= buffer_size;
    }
    
    in.read(buffer, count);
    out.write(buffer, count);
}

auto Viper::Url::Request::body(std::function<void(MultipartAdapter&)> f) -> Request& {
    MultipartAdapter multipartAdapter;
    f(multipartAdapter);
    multipartAdapter.finish();
    this->body(multipartAdapter.body());
//    _body=std::move(multipartAdapter.body());
    this->setValueForHTTPHeaderField("multipart/form-data; boundary=" + multipartAdapter.boundary(), "Content-Type");
//    _headers.push_back("Content-Type: multipart/form-data; boundary="+multipartAdapter.boundary());
    return *this;
}

auto Viper::Url::Request::setValueForHTTPHeaderField(std::string value, std::string field) -> Request&{

#ifdef __APPLE__
    request.setValueForHTTPHeaderField(value, field);
#else
    /*if(auto java_env = java::lang::JNI::Env()) {
        auto cls = request.getClass();
        auto mid = java_env->
    }else{
        cout<<"java env is null"<<endl;
    }*/
    auto v = java::lang::String::create(value);
    auto f = java::lang::String::create(field);
    request.sendMessage<void>("setValueForHTTPHeaderField", v, f);
#endif  //__APPLE__
    
    return *this;
}

auto Viper::Url::Request::url(const std::string &value, std::vector<GetParameter> getParameters) -> Request& {
    
//    auto url = value;
    
    std::stringstream ss;
    ss << value;
    const auto getParametersCount = getParameters.size();
    if(getParametersCount) {
        ss << "?";
        for(auto i=0; i<getParametersCount; ++i) {
            auto &getParameter = getParameters[i];
            //                ss<<getParameter.first<<"="<<getParameter.second.value;
            ss << getParameter.value;
            if(i < getParametersCount-1) {
                ss << "&";
            }
        }
    }
    auto url = ss.str();
    ss.flush();
    
#ifdef __APPLE__
    request.setURL(NS::URL::create(url));
#else
    auto v = java::lang::String::create(url);
    request.sendMessage<void>("setUrl", v);
#endif  //__APPLE__
    return *this;

}

auto Viper::Url::Request::url(const std::string &value) -> Request& {
    return this->url(value, {});
}

std::string Viper::Url::Request::url() {
    
#ifdef __APPLE__
    return request.URL().absoluteString();
#else
    return request.sendMessage<java::lang::String>("getUrl").c_str();
#endif  //__APPLE__
    
}

auto Viper::Url::Request::method(const std::string &value) -> Request& {
    
#ifdef __APPLE__
    request.setHTTPMethod(value);
#else
    auto v = java::lang::String::create(value);
    request.sendMessage<void>("setHttpMethod", v);
#endif  //__APPLE__
    return *this;
    
}

std::string Viper::Url::Request::method() {
    
#ifdef __APPLE__
    if(auto res = request.HTTPMethod()){
        return res.UTF8String();
    }else{
        return {};
    }
#else
    return request.sendMessage<java::lang::String>("getHttpMethod").c_str();
#endif  //__APPLE__
    
}

auto Viper::Url::Request::body(const std::string &s) -> Request& {
    
#ifdef __APPLE__
    auto str = NS::String::stringWithCString(s.c_str(), NS::String::Encoding::UTF8);
    request.setHTTPBody(str.dataUsingEncoding(NS::String::Encoding::UTF8));
#else
    auto str = java::lang::String::create(s);
    request.sendMessage<void>("setBodyString", str);
#endif  //__APPLE__
    
    return *this;
}

//void Viper::Url::Request::performAsync(std::function<void(Response, std::vector<char>, Error)> callback) 

#ifdef __ANDROID__

void Viper::Url::Request::urlResponseReceived(int requestId,
                                              java::lang::Object response,
                                              jbyteArray data,
                                              java::lang::Object error)
{
    auto it = CallbackHolder<std::vector<char>>::callbacks.find(requestId);
    if(it != CallbackHolder<std::vector<char>>::callbacks.end()){
        if(auto callback = it->second){
            
            //   create response wrapper..
            Response r(response);
            
            //   copy data into vector..
            std::vector<char> d;
            if(auto env = java::lang::JNI::Env()){
                auto buffer = env->GetByteArrayElements(data, NULL);
                auto size = env->GetArrayLength(data);
                
                /*for(int i = 0; i < size; i++) {
                    printf("%c", buffer[i]);
                }*/
                
                auto dataBegin = buffer;
                auto dataEnd = dataBegin + size;
                
                d.reserve(size);
                std::copy(dataBegin,
                          dataEnd,
                          std::back_inserter(d));
                
                env->ReleaseByteArrayElements(data, buffer, JNI_ABORT);
            }
            
            //   create error wrapper..
            Error e(error);
            
            callback(std::move(r), std::move(d), std::move(e));
        }
        CallbackHolder<std::vector<char>>::callbacks.erase(it);
    }else{
        cout<<"callback not found for url request with id "<<requestId<<endl;
    }
}
    
    void Viper::Url::Request::urlResponseImageReceived(int requestId,
                                                       java::lang::Object response,
                                                       android::graphics::Bitmap bitmap,
                                                       java::lang::Object error)
    {
        auto it = CallbackHolder<Image>::callbacks.find(requestId);
        if(it != CallbackHolder<Image>::callbacks.end()){
            if(auto callback = it->second){
                
                //   create response wrapper..
                Response r(response);
                
                //   create image..
                Image i(bitmap);
                
                //   create error wrapper..
                Error e(error);
                
                callback(std::move(r), std::move(i), std::move(e));
            }
            CallbackHolder<Image>::callbacks.erase(it);
        }else{
            cout<<"callback not found for url request with id "<<requestId<<endl;
        }
    }

#endif  //__ANDROID__