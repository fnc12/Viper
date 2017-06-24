//
//  WebView.hpp
//  MyBusiness
//
//  Created by John Zakharov on 10.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#ifndef WebView_hpp
#define WebView_hpp

#include "iOSutil/UI/View.hpp"
#include "iOSutil/NS/URLRequest.hpp"

namespace UI {
    
    struct WebView : public UI::View {
        
        using View::View;
        
#ifdef __APPLE__
        static const std::string className;
        
        void loadRequest(const NS::URLRequest &request);
        
        void loadHTMLString(const std::string &str, const NS::URL &baseURL);
#endif
        
    };
}

#endif /* WebView_hpp */
