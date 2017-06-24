//
//  WebView.cpp
//  MyBusiness
//
//  Created by John Zakharov on 10.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#include "WebView.hpp"
#include "iOSutil/CF/String.hpp"

#ifdef __APPLE__

const std::string UI::WebView::className = "UIWebView";

void UI::WebView::loadRequest(const NS::URLRequest &request) {
    this->sendMessage<void>("loadRequest:", request.handle);
}

void UI::WebView::loadHTMLString(const std::string &str, const NS::URL &baseURL) {
    auto s = CF::String::create(str);
    this->sendMessage<void>("loadHTMLString:baseURL:", s.handle, baseURL.handle);
}

#endif  //  __APPLE__
