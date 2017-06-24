//
//  UrlResponse.cpp
//  Groozim
//
//  Created by John Zakharov on 21.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Response.hpp"

#include "AndroidUtil/java/lang/String.hpp"
#include "AndroidUtil/java/lang/Class.hpp"
#include "AndroidUtil/java/util/List.hpp"
#include "AndroidUtil/java/util/Map.hpp"

Mitsoko::Url::Response::Response(decltype(response) response_):response(response_),headers{*this}{}

Mitsoko::Url::Response::Response(const Response& other):headers{*this}, response(other.response) {
    //..
}

Mitsoko::Url::Response::Response(Response &&other):headers{*this}, response(std::move(other.response)) {
    //..
}

int Mitsoko::Url::Response::statusCode() {
    
#ifdef __APPLE__
    return response.statusCode();
#else
//    LOGI("Mitsoko::Url::Response::statusCode, response = %p", response.handle);    
    auto res = response.sendMessage<int>("getStatusCode");
//    LOGI("/Mitsoko::Url::Response::statusCode %d", res);
    return res;
#endif  //__APPLE__
}

std::string Mitsoko::Url::Response::statusDescription() {
    
#ifdef __APPLE__
    if(auto res = NS::HTTPURLResponse::localizedStringForStatusCode(this->statusCode())){
        return res.UTF8String();
    }else{
        return {};
    }
#else
    if(auto res = response.sendMessage<java::lang::String>("getStatusDescription")){
        return res.c_str();
    }else{
        return {};
    }
#endif  //__APPLE__
    
}

Mitsoko::Url::Response::operator bool() const {
    return bool(response);
}

std::string Mitsoko::Url::Response::Headers::operator[](const std::string &key) {
#ifdef __APPLE__
    auto nsKey = NS::String::stringWithCString(key.c_str(), NS::String::Encoding::UTF8);
    auto headersDict = response.response.allHeaderFields();
    if(auto value = headersDict[nsKey].as<NS::String>()){
        return value.UTF8String();
    }else{
        return {};
    }
#else
    using namespace java::lang;
    using namespace java::util;
    LOGI("response.response = %p", response.response.handle);
    if(response){
        if(auto javaKey = String::create(key)){
            LOGI("javaKey = %p", javaKey.handle);
            if(auto res = response.response.sendMessage<String>("headerValueFor", javaKey)){
                return res.c_str();
            }else{
                return {};
            }
            /*if(auto headersMap = response.response.sendMessage<Map<String, List<String>>>("getHeaders")){
                LOGI("headersMap = %p", headersMap.handle);
                if(auto resList = headersMap.get(javaKey)){
                    LOGI("resList = %p", resList.handle);
                    if(resList.size()){
                        if(auto res = resList.get(0)){
                            return res.c_str();
                        }else{
                            return {};
                        }
                    }else{
                        return {};
                    }
                }else{
                    return {};
                }
            }else{
                LOGI("headersMap is null");
                return {};
            }*/
        }else{
            return {};
        }
    }else{
        return {};
    }
#endif
}
