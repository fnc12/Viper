//
//  EdgeInsets.hpp
//  MyBusiness
//
//  Created by John Zakharov on 20.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#ifndef EdgeInsets_hpp
#define EdgeInsets_hpp

#ifdef __APPLE__
#import <UIKit/UIGeometry.h>
#endif

#include "iOSutil/CG/CG.hpp"

namespace UI {
    
#ifdef __APPLE__
    struct EdgeInsets : public UIEdgeInsets {
        
        EdgeInsets(const UIEdgeInsets &value) : UIEdgeInsets(value){}
        
        EdgeInsets() : UIEdgeInsets{0, 0, 0, 0} {}
        
        EdgeInsets(CG::Float top, CG::Float left, CG::Float bottom, CG::Float right) : UIEdgeInsets{top, left, bottom, right} {}
    };
#endif
}

#endif /* EdgeInsets_hpp */
