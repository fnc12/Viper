//
//  ByteArrayOutputStream.hpp
//  MyBusiness
//
//  Created by John Zakharov on 23.06.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#ifndef ByteArrayOutputStream_hpp
#define ByteArrayOutputStream_hpp

#include "OutputStream.hpp"
#include "AndroidUtil/java/lang/Array.hpp"

namespace java {
    
    namespace io {
        
        struct ByteArrayOutputStream : public OutputStream {
            
            using OutputStream::OutputStream;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            java::lang::Array<char> toByteArray();
            
            static ByteArrayOutputStream create();
            
#endif  //  __ANDROID__
        };
    }
}

#endif /* ByteArrayOutputStream_hpp */
