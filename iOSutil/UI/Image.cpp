//
//  Image.cpp
//  Groozim
//
//  Created by John Zakharov on 14.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Image.hpp"

#ifdef __APPLE__

const std::string UI::Image::className = "UIImage";

UI::Image UI::Image::create(const char *named) {
    return create(std::string(named));
}

UI::Image UI::Image::create(const std::string &named){
    auto cls = NS::getClass(className);
    auto str = CF::String::create(named);
    return NS::Object::sendMessage<Handle>(cls,"imageNamed:", str.handle);
}

UI::Image UI::Image::create(const NS::Data &data) {
    auto cls = NS::getClass(className);
    return NS::Object::sendMessage<Handle>(cls, "imageWithData:", data.handle);
}

UI::Image UI::Image::createWithContentsOfFile(const std::string &filename){
    auto s = CF::String::create(filename);
    return createWithContentsOfFile(s);
}

UI::Image UI::Image::createWithContentsOfFile(const CF::String &filename){
    auto cls = NS::getClass(className);
    return NS::Object::sendMessage<Handle>(cls,"imageWithContentsOfFile:", filename.handle);
}

UI::Image UI::Image::createWithCGImage(const CG::Image &img) {
    auto cls = NS::getClass(className);
    return NS::Object::sendMessage<Handle>(cls, "imageWithCGImage:", img.handle);
}

NS::Data UI::Image::JPEGRepresentation(UI::Image image, CG::Float compressionQuality){
    image.retain();
    auto res = CFBridgingRetain(UIImageJPEGRepresentation(CFBridgingRelease(image.handle), CGFloat(compressionQuality)));
    CFRelease(res);
    return res;
}

CG::Size UI::Image::size(){
    return this->sendMessage<CGSize>("size");
}

CG::Image UI::Image::CGImage() {
    return this->sendMessage<CG::Image::Ref>("CGImage");
}

#endif  //__APPLE__
