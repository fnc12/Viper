//
//  String.cpp
//  Groozim
//
//  Created by John Zakharov on 14.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "String.hpp"
#include "iOSutil/CF/String.hpp"

#include <iostream>

using std::cout;
using std::endl;

#ifdef __APPLE__

const std::string NS::String::className = "NSString";

const char* NS::String::UTF8String(){
    return this->sendMessage<const char*>("UTF8String");
}

NS::Data NS::String::dataUsingEncoding(Encoding encoding) {
    return this->sendMessage<Handle>("dataUsingEncoding:", NSStringEncoding(encoding));
}

NS::String NS::String::stringWithCString(const char *cStr, NS::String::Encoding encoding) {
    auto cls = NS::getClass(className);
    assert(cls);
    return sendMessage<Handle>(cls, "stringWithCString:encoding:", cStr, NSStringEncoding(encoding));
}

NS::String NS::String::create(const NS::Data &data, NS::String::Encoding encoding) {
    return (__bridge Handle)[[NSString alloc] initWithData:(__bridge id)data.handle encoding:(NSStringEncoding)encoding];
}

void NS::String::initWithData(const NS::Data &data, NS::String::Encoding encoding) {
    this->sendMessage<Handle>("initWithData:encoding:", data.handle, NSStringEncoding(encoding));
}

NS::String NS::String::stringByAddingPercentEscapesUsingEncoding(NS::String::Encoding enc) {
    return this->sendMessage<Handle>("stringByAddingPercentEscapesUsingEncoding:", NSStringEncoding(enc));
}

#endif  //__APPLE__
