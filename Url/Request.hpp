//
//  UrlRequest.hpp
//  Groozim
//
//  Created by John Zakharov on 21.11.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef VIPER__URL_REQUEST
#define VIPER__URL_REQUEST

#ifdef __APPLE__
#include "iOSutil/NS/MutableURLRequest.hpp"
#include "iOSutil/NS/URLConnection.hpp"
#else
#include "AndroidUtil/java/lang/Object.hpp"
#endif  //__APPLE__

#include "Response.hpp"
#include "Error.hpp"
#include "Image.hpp"

#include <vector>
#include <map>
#include <fstream>
#include <iostream>

namespace Mitsoko {
    
    namespace Url {
        
        struct Request {
            
            Request();
            
            /**
             *  Get parameter is a class for storing get parameters temporary.
             *  It takes two parametes in contructor: name and value, and transfers it into url string
             *  like `name=foo` or `names[]=foo&names[]=bar`.
             */
            struct GetParameter {
                
                template<class T>
                GetParameter(const std::string &name,T t):value(std::move(StringValueAdapter<T>{name,t}())){}
                
                const std::string value;
                
            protected:
                
                template<class T>
                struct StringValueAdapter{
                    const std::string name;
                    const T value;
                    
                    std::string operator()() const {
                        std::stringstream ss;
                        ss << this->name << "=" << this->value;
                        return ss.str();
                    }
                };
                
                /**
                 *  Partial specialization for std::vector of T.
                 *  Transfers name and vector into `name[]=value1&name[]=value2...name[]=valuen`.
                 */
                template<class T>
                struct StringValueAdapter<std::vector<T>>{
                    const std::string name;
                    const std::vector<T> value;
                    
                    std::string operator()() const {
                        std::stringstream ss;
                        for(auto i=0; i<this->value.size(); ++i){
                            const auto &obj = this->value[i];
                            ss << this->name << "[]="<< obj;
                            if(i < this->value.size()-1) {
                                ss << "&";
                            }
                        }
                        return ss.str();
                    }
                };
            };
            
            struct Headers {
                Request &request;
                
                struct HeaderAdapter {
                    Headers &headers;
                    std::string key;
                    
                    inline void operator=(const std::string &value) {
                        headers.request.setValueForHTTPHeaderField(value, this->key);
                    }
                };
                
                inline HeaderAdapter operator[](const std::string &key) {
                    return {*this, key};
                }
            };
            
            Headers headers;
            
            static const std::string crlf;
            
            /**
             *  This is a cute class used to help in creating a multipart request.
             */
            struct MultipartAdapter{
                
                std::string body();
                
                const std::string& boundary() const;
                
                void addFormField(const std::string &name, const std::string &value);
                
                void addFilePart(const std::string &fieldName,
                                 const std::string &filepath,
                                 const std::string &fileName,
                                 const std::string &mimeType);
                
            protected:
                
                friend class Request;
                
                MultipartAdapter();
                
                std::stringstream stream;
                std::string charset;
                std::string _boundary = generateBoundary();
                
                static std::string generateBoundary();
                
                void finish();
                
                size_t fileSize(const std::string &filepath);
                
                void stream_copy_n(std::istream &in, std::size_t count, std::ostream &out);
            };
            
            Request& setValueForHTTPHeaderField(std::string value, std::string field);
            
            //  URL setter & getter..
            
            Request& url(const std::string &value);
            
            Request& url(const std::string &value, std::vector<GetParameter> getParameters);
            
            std::string url();
            
            //  HTTP method setter & getter (`GET` by default)..
            
            Request& method(const std::string &value);
            
            std::string method();
            
            Request& body(const std::string &s);
            
            /**
             *  Sets body as multipart data (interface stolen from AFNetworking lib).
             *  Also adds `Content-type: multipart/form-data; boundary=%s` header.
             */
            Request& body(std::function<void(MultipartAdapter&)> f);
            
            
            template<class R>
            void performAsync(std::function<void(Response, R, Error)> callback);
            
            void performAsync(std::function<void(Response, std::vector<char>, Error)> callback);
            
            static std::string url_encode(const std::string &value);
            
#ifdef __ANDROID__
            
            static void urlResponseReceived(int requestId,
                                            java::lang::Object response,
                                            jbyteArray data,
                                            java::lang::Object error);
            
            static void urlResponseImageReceived(int requestId,
                                                 java::lang::Object response,
                                                 android::graphics::Bitmap bitmap,
                                                 java::lang::Object error);
            
#endif  //__ANDROID__
            
        protected:
#ifdef __APPLE__
            NS::MutableURLRequest request;
#else
            java::lang::Object request;
#endif  //__APPLE__
            
#ifdef __ANDROID__
            
            template<class R>
            struct CallbackHolder{
                static std::map<int, std::function<void(Response, R, Error)>> callbacks;
            };
            
#endif  //__ANDROID__
            
            
        };
        
        template<>
        void Request::performAsync<std::vector<char>>(std::function<void(Response, std::vector<char>, Error)> callback);
        
        template<>
        void Request::performAsync<Image>(std::function<void(Response, Image, Error)> callback);
        
        /*template<>
        void Request::performAsync<std::string>(std::function<void(Response, std::string, Error)> callback);*/
    }
}

#ifdef __ANDROID__

template<class R>
std::map<int, std::function<void(Mitsoko::Url::Response, R, Mitsoko::Url::Error)>> Mitsoko::Url::Request::CallbackHolder<R>::callbacks;

#endif  //__ANDROID__


#endif  //VIPER__URL_REQUEST
