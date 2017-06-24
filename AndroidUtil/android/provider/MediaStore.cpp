//
//  MediaStore.cpp
//  Groozim
//
//  Created by John Zakharov on 17.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "MediaStore.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string android::provider::MediaStore::signature = "android/provider/MediaStore";

const std::string android::provider::MediaStore::Images::signature = "android/provider/MediaStore$Images";

const std::string android::provider::MediaStore::Images::Media::signature = "android/provider/MediaStore$Images$Media";

std::string android::provider::MediaStore::ACTION_IMAGE_CAPTURE(){
    if(java::lang::Class cls=java::lang::Class::find<MediaStore>()){
        if(auto res = cls.getStaticField<java::lang::String>("ACTION_IMAGE_CAPTURE")){
            return res.c_str();
        }else{
            return {};
        }
    }else{
        return {};
    }
}

android::net::Uri android::provider::MediaStore::Images::Media::EXTERNAL_CONTENT_URI(){
    if(java::lang::Class cls = java::lang::Class::find<Media>()) {
        return cls.getStaticField<android::net::Uri>("EXTERNAL_CONTENT_URI");
    }else{
        return {};
    }
}

#endif  //__ANDROID__
