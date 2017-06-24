//
//  Annotation.cpp
//  Jako
//
//  Created by John Zakharov on 06.08.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#include "Annotation.hpp"
#include "iOSutil/CF/String.hpp"

#include <iostream>

#ifdef __APPLE__

MK::Annotation MK::Annotation::create(CL::Location::Coordinate2D coordinate,
                                      std::experimental::optional<std::string> title,
                                      std::experimental::optional<std::string> subtitle)
{
    if(auto newAnnotation = NS::Object::create<Annotation>("ViperMKAnnotation")){
        newAnnotation.sendMessage<void>("setCoordinate:", CLLocationCoordinate2D(coordinate));
        auto t = CF::String::create(title);
        newAnnotation.sendMessage<void>("setTitle:", t.handle);
        auto s = CF::String::create(subtitle);
        newAnnotation.sendMessage<void>("setSubtitle:", s.handle);
        return newAnnotation;
    }else{
        std::cerr<<"newAnnotation is nil"<<std::endl;
        return {};
    }
}

CL::Location::Coordinate2D MK::Annotation::coordinate(){
    return this->sendMessage<CLLocationCoordinate2D>("coordinate");
}

#endif
