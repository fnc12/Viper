//
//  Bundle.cpp
//  Groozim
//
//  Created by John Zakharov on 14.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Bundle.hpp"
#include "iOSutil/CF/String.hpp"

#ifdef __APPLE__

const std::string NS::Bundle::className="NSBundle";

NS::Bundle NS::Bundle::mainBundle(){
    auto cls=NS::getClass(className);
    assert(cls);
    return sendMessage<Handle>(cls, "mainBundle");
}

NS::Array NS::Bundle::preferredLocalizations(){
    return this->sendMessage<Handle>("preferredLocalizations");
}

std::string NS::Bundle::pathForResource(const std::string &name, const std::string &ext){
    auto n = CF::String::create(name);
    auto e = CF::String::create(ext);
    NS::String res = this->sendMessage<Handle>("pathForResource:ofType:", n.handle, e.handle);
    return res.UTF8String();
}

#endif  //__APPLE__
