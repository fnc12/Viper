//
//  MailComposeViewController.cpp
//  GoZebra
//
//  Created by John Zakharov on 24.03.17.
//  Copyright © 2017 Outlaw Studio. All rights reserved.
//

#include "ViewController.hpp"
#include "iOSutil/NS/MutableArray.hpp"

#ifdef __APPLE__

#import <MessageUI/MessageUI.h>

MF::MailCompose::ViewController::DidFinishMap MF::MailCompose::ViewController::didFinishMap;

const std::string MF::MailCompose::ViewController::className = "MFMailComposeViewController";

MF::MailCompose::ViewController MF::MailCompose::ViewController::create() {
    return NS::Object::create<MF::MailCompose::ViewController>(className);
}

bool MF::MailCompose::ViewController::canSendMail() {
    auto cls = NS::getClass(className);
    assert(cls);
    return NS::Object::sendMessage<BOOL>(cls, "canSendMail");
//    return [MFMailComposeViewController canSendMail];
}

void MF::MailCompose::ViewController::setSubject(const std::string &newValue) {
    auto s = CF::String::create(newValue);
    this->sendMessage<void>("setSubject:", s.handle);
}

void MF::MailCompose::ViewController::setToRecipients(const std::vector<std::string> &value) {
    auto ar = NS::MutableArray::createWithCapacity(int(value.size()));
    for(auto &to : value) {
        auto s = CF::String::create(to);
        ar.addObject(s);
    }
    this->sendMessage<void>("setToRecipients:", ar.handle);
}

void MF::MailCompose::ViewController::setMessageBody(const std::string &body, bool isHTML) {
    auto str = CF::String::create(body);
    this->sendMessage<void>("setMessageBody:isHTML:", str.handle, isHTML);
}

void MF::MailCompose::ViewController::setDidFinish(DidFinish didFinish) {
    auto it = didFinishMap.find(this->handle);
    if(it == didFinishMap.end()){
        didFinishMap.insert({this->handle, didFinish});
        auto cls = NS::getClass("MFMailComposeViewControllerDelegateEventHandler");
        auto shared = NS::Object::sendMessage<Handle>(cls, "shared");
        this->sendMessage<void>("setMailComposeDelegate:", shared);
    }else{
        it->second = didFinish;
    }
}

void MF::MailCompose::ViewController::didFinishWithResult(const void *handle, Result result) {
    auto it = didFinishMap.find(handle);
    if(it != didFinishMap.end()){
        if(it->second){
            it->second(result);
            didFinishMap.erase(it);
        }
    }
}

std::ostream& MF::MailCompose::operator<<(std::ostream &os, Result result) {
    switch(result){
        case Result::Cancelled:return os << "Cancelled";
        case Result::Failed:return os << "Failed";
        case Result::Saved:return os << "Saved";
        case Result::Sent:return os << "Sent";
    }
}

#endif
