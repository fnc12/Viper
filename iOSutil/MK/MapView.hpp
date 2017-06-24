
#ifndef __VIPER__IOS_UTIL__MK__MAP_VIEW__
#define __VIPER__IOS_UTIL__MK__MAP_VIEW__

#include "iOSutil/UI/View.hpp"
#include "Geometry.hpp"
#include "Annotation.hpp"

namespace MK {
    
    struct MapView : public UI::View {
        
        using View::View;
        
#ifdef __APPLE__
        static const std::string className;
//        STATIC_VAR(const std::string, className, "MKMapView");
        
        void addAnnotation(const MK::Annotation &annotation);
        
        void setRegion(const MK::Coordinate::Region &newValue);
        
        MK::Coordinate::Region region();
#endif  //__APPLE__
    };
}

#endif  //__VIPER__IOS_UTIL__MK__MAP_VIEW__
