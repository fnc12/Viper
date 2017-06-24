
#ifndef __VIPER__ANDROID_UTIL__ANDROID__WIDGET__IMAGE_VIEW__
#define __VIPER__ANDROID_UTIL__ANDROID__WIDGET__IMAGE_VIEW__

#include "AndroidUtil/android/view/View.hpp"
#include "AndroidUtil/android/graphics/Bitmap.hpp"

namespace android{
    
    namespace widget{
        
        struct ImageView : public view::View {
            
            using View::View;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            /**
             *  This method doesn't exist in SDK but it is created to
             *  allow user avoid requesting image resource id (just like android::view::View::findViewById).
             */
            void setImageResource(const std::string &resName, const content::Context &context);
            
            void setImageResource(int resId);
            
            void setImageBitmap(const android::graphics::Bitmap &bm);
            
            void setSelected(bool selected);
            
#endif  //__ANDROID__
            
        };
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__WIDGET__IMAGE_VIEW__
