
#ifndef __VIPER__IOS_UTIL__MK__GEOMETRY__
#define __VIPER__IOS_UTIL__MK__GEOMETRY__

#ifdef __APPLE__
#import <MapKit/MapKit.h>

#include "iOSutil/CL/Location.hpp"

namespace MK {
    namespace Coordinate{
        
        struct Span : public MKCoordinateSpan {
            
            Span(MKCoordinateSpan s);
            
            static MK::Coordinate::Span make(CL::Location::Degrees latitudeDelta,CL::Location::Degrees longitudeDelta);
        };
        
        struct Region : public MKCoordinateRegion {
            
            Region(MKCoordinateRegion r);
            
            static MK::Coordinate::Region make(CL::Location::Coordinate2D centerCoordinate, MK::Coordinate::Span span);
            
            static MK::Coordinate::Region makeWithDistance(CL::Location::Coordinate2D centerCoordinate,
                                                           CL::Location::Distance latitudinalMeters,
                                                           CL::Location::Distance longitudinalMeters);
        };
    }
}
#endif  //__APPLE__

#endif  //__VIPER__IOS_UTIL__MK__GEOMETRY__
