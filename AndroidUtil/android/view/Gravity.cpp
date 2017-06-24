//
//  Gravity.cpp
//  MyBusiness
//
//  Created by John Zakharov on 04.05.17.
//  Copyright © 2017 Mitsoko. All rights reserved.
//

#include "Gravity.hpp"
#include "AndroidUtil/java/lang/Class.hpp"

#ifdef __ANDROID__

const std::string android::view::Gravity::signature = "android/view/Gravity";

int android::view::Gravity::AXIS_CLIP() {
    java::lang::Class cls = java::lang::Class::find<Gravity>();
    return cls.getStaticField<int>("AXIS_CLIP");
}

int android::view::Gravity::BOTTOM() {
    java::lang::Class cls = java::lang::Class::find<Gravity>();
    return cls.getStaticField<int>("BOTTOM");
}

int android::view::Gravity::CENTER() {
    java::lang::Class cls = java::lang::Class::find<Gravity>();
    return cls.getStaticField<int>("CENTER");
}

#endif  //  __ANDROID__
