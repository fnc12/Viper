//
//  UrlRequest.cpp
//  Groozim
//
//  Created by John Zakharov on 21.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Request.hpp"
#include "AndroidUtil/java/lang/Class.hpp"
#include "AndroidUtil/java/lang/String.hpp"

#include <iostream>
#include <sys/time.h>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

using std::cout;
using std::endl;

const std::string Mitsoko::Url::Request::crlf = "\r\n";

#ifdef __ANDROID__

static auto networkUrlRequestClassSignature = "kz/outlawstudio/viper/Network$UrlRequest";

#endif  //__ANDROID__

Mitsoko::Url::Request::Request(): headers({*this}){

#ifdef __APPLE__
    request = NS::MutableURLRequest::create();
#else
    request = java::lang::Object::create(networkUrlRequestClassSignature);
#endif  //__APPLE__

}

std::string Mitsoko::Url::Request::MultipartAdapter::body() {
    return this->stream.str();
}

const std::string& Mitsoko::Url::Request::MultipartAdapter::boundary() const {
    return _boundary;
}

void Mitsoko::Url::Request::MultipartAdapter::addFormField(const std::string &name, const std::string &value) {
    this->stream << "--" << _boundary << crlf;
    this->stream << "Content-Disposition: form-data; name=\"" << name << "\"" << crlf;
    this->stream << "Content-Type: text/plain; charset=" << this->charset << crlf;
    this->stream << crlf;
    this->stream << value << crlf;
}

void Mitsoko::Url::Request::MultipartAdapter::addFilePart(const std::string &fieldName,
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
//        this->stream << "Content-Transfer-Encoding: binary" << crlf;
        this->stream << crlf;
        stream_copy_n(file, count, this->stream);
        file.close();
        this->stream << crlf;
    }else{
        std::cerr << "failed to open file at *" << filepath << "*" << std::endl;
    }
}

Mitsoko::Url::Request::MultipartAdapter::MultipartAdapter():charset("UTF-8"){}

void Mitsoko::Url::Request::performAsync(std::function<void(Response, std::vector<char>, Error)> callback) {
    this->performAsync<std::vector<char>>(callback);
}

template<>
void Mitsoko::Url::Request::performAsync<std::vector<char>>(std::function<void(Response, std::vector<char>, Error)> callback) {
    
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
void Mitsoko::Url::Request::performAsync<Mitsoko::Image>(std::function<void(Response, Image, Error)> callback) {
#ifdef __APPLE__
    NS::URLConnection::sendAsynchronousRequest(request,
                                               NS::OperationQueue::mainQueue(),
                                               [=](NS::URLResponse response, NS::Data data, NS::Error error){
                                                   
                                                   //   create response wrapper..
                                                   Response r(response.as<NS::HTTPURLResponse>());
                                                   
                                                   //   create image from data..
                                                   auto image = UI::Image::create(data);
                                                   Mitsoko::Image i(image);
                                                   
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
    CallbackHolder<Mitsoko::Image>::callbacks.insert({requestId, callback});
#endif  //__APPLE__
}

std::string Mitsoko::Url::Request::url_encode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;
    
    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        std::string::value_type c = (*i);
        
        // Keep alphanumeric and other accepted characters intact
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }
        
        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }
    
    return escaped.str();
}

std::string Mitsoko::Url::Request::MultipartAdapter::generateBoundary() {
    struct timeval tv;
    ::gettimeofday(&tv, nullptr);
    std::stringstream ss;
    ss << "===" << tv.tv_sec << "_" << tv.tv_usec << "===";
    return ss.str();
//    return "Asrf456BGe4h";
}

void Mitsoko::Url::Request::MultipartAdapter::finish() {
//    this->stream << crlf;
    this->stream << "--" << _boundary << "--" << crlf;
    this->stream << crlf;
}

size_t Mitsoko::Url::Request::MultipartAdapter::fileSize(const std::string &filepath) {
    std::ifstream file(filepath, std::ios::binary | std::ios::ate);
    if(file) {
        return static_cast<size_t>(file.tellg());
    }else{
        return 0;
    }
}

void Mitsoko::Url::Request::MultipartAdapter::stream_copy_n(std::istream &in, std::size_t count, std::ostream &out) {
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

auto Mitsoko::Url::Request::body(std::function<void(MultipartAdapter&)> f) -> Request& {
    MultipartAdapter multipartAdapter;
    f(multipartAdapter);
    multipartAdapter.finish();
//    this->body(multipartAdapter.body());
    auto bodyString = multipartAdapter.body();
#ifdef __APPLE__
    auto bodyData = NS::Data::createWithBytes((const void *)bodyString.c_str(), int(bodyString.length()));
    cout << "bodyData len = " << bodyData.length() << endl;
    request.setHTTPBody(bodyData);
#else
    auto env = java::lang::JNI::Env();
    auto byteArray = env->NewByteArray(bodyString.length());
    env->SetByteArrayRegion(byteArray, 0, bodyString.length(), (const jbyte*)bodyString.c_str());
    auto arrayObject = java::lang::Array<char>(byteArray);
    request.setField("mBody", arrayObject);
#endif
    this->setValueForHTTPHeaderField("multipart/form-data; boundary=" + multipartAdapter.boundary(), "Content-Type");
    return *this;
}

auto Mitsoko::Url::Request::setValueForHTTPHeaderField(std::string value, std::string field) -> Request& {

#ifdef __APPLE__
    request.setValueForHTTPHeaderField(value, field);
#else
    auto v = java::lang::String::create(value);
    auto f = java::lang::String::create(field);
    request.sendMessage<void>("setValueForHTTPHeaderField", v, f);
#endif  //__APPLE__
    
    return *this;
}

auto Mitsoko::Url::Request::url(const std::string &value, std::vector<GetParameter> getParameters) -> Request& {
    std::stringstream ss;
    ss << value;
    const auto getParametersCount = getParameters.size();
    if(getParametersCount) {
        ss << "?";
        for(auto i=0; i<getParametersCount; ++i) {
            auto &getParameter = getParameters[i];
            ss << getParameter.value;
            if(i < getParametersCount-1) {
                ss << "&";
            }
        }
    }
    auto url = ss.str();
//    url = url_encode(url);
    ss.flush();
    
#ifdef __APPLE__
    auto nsUrl = NS::URL::create(url);
    request.setURL(nsUrl);
#else
    auto v = java::lang::String::create(url);
    request.sendMessage<void>("setUrl", v);
#endif  //__APPLE__
    return *this;

}

auto Mitsoko::Url::Request::url(const std::string &value) -> Request& {
    return this->url(value, {});
}

std::string Mitsoko::Url::Request::url() {
    
#ifdef __APPLE__
    return request.URL().absoluteString();
#else
    return request.sendMessage<java::lang::String>("getUrl").c_str();
#endif  //__APPLE__
    
}

auto Mitsoko::Url::Request::method(const std::string &value) -> Request& {
    
#ifdef __APPLE__
    request.setHTTPMethod(value);
#else
    auto v = java::lang::String::create(value);
    request.sendMessage<void>("setHttpMethod", v);
#endif  //__APPLE__
    return *this;
    
}

std::string Mitsoko::Url::Request::method() {
    
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

Mitsoko::Url::Request& Mitsoko::Url::Request::body(const std::string &s) {
    
#ifdef __APPLE__
//    cout << "s.len = " << s.length() << endl;
//    cout << "body = *" << s << "*" << endl;
//    auto str = NS::String::stringWithCString(s.c_str(), NS::String::Encoding::UTF8);
    auto str = [NSString stringWithUTF8String:s.c_str()];
//    NSLog(@"str len = %ld", (long)str.length);
//    str = [str stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    auto data = NS::String((__bridge const void*)str).dataUsingEncoding(NS::String::Encoding::UTF8);
    request.setHTTPBody(data);
    /*{
        auto body = request.HTTPBody();
        auto s = NS::String::create(body, NS::String::Encoding::UTF8);
        NSLog(@"s = %s", s.UTF8String());
    }*/
#else
    auto str = java::lang::String::create(s);
    request.sendMessage<void>("setBodyString", str);
#endif  //__APPLE__
    
    return *this;
}

#ifdef __ANDROID__

void Mitsoko::Url::Request::urlResponseReceived(int requestId,
                                              java::lang::Object response,
                                              jbyteArray data,
                                              java::lang::Object error)
{
    auto it = CallbackHolder<std::vector<char>>::callbacks.find(requestId);
    if(it != CallbackHolder<std::vector<char>>::callbacks.end()){
        if(auto callback = it->second){
            
//            LOGI("data = %p",data);
            
            //   create response wrapper..
            Response r(response);
//            LOGI("Response r(response);");
            
            //   copy data into vector..
            std::vector<char> d;
            if(auto env = java::lang::JNI::Env()){
                if(data){
//                    LOGI("env = %p", env);
                    auto buffer = env->GetByteArrayElements(data, NULL);
//                    LOGI("buffer = %p",buffer);
                    auto size = env->GetArrayLength(data);
//                    LOGI("size = %ld",long(size));
                    
                    auto dataBegin = buffer;
                    auto dataEnd = dataBegin + size;
                    
                    d.reserve(size);
                    std::copy(dataBegin,
                              dataEnd,
                              std::back_inserter(d));
                    
                    env->ReleaseByteArrayElements(data, buffer, JNI_ABORT);
                }
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
    
    void Mitsoko::Url::Request::urlResponseImageReceived(int requestId,
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
