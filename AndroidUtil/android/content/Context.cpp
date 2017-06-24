//
//  Context.cpp
//  Groozim
//
//  Created by John Zakharov on 17.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Context.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string android::content::Context::signature = "android/content/Context";

auto android::content::Context::getResources() -> res::Resources {
    return this->sendMessage<res::Resources>("getResources");
}

auto android::content::Context::getPackageName() -> java::lang::String {
    return this->sendMessage<java::lang::String>("getPackageName");
}

std::string android::content::Context::INPUT_METHOD_SERVICE() {
    if(java::lang::Class cls = java::lang::Class::find<Context>()){
        return cls.getStaticField<java::lang::String>("INPUT_METHOD_SERVICE").c_str();
    }else{
        return {};
    }
}

#endif  //__ANDROID__
