
#ifndef __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__DESIGN__WIDGET__TAB_LAYOUT__
#define __VIPER__ANDROID_UTIL__ANDROID__SUPPORT__DESIGN__WIDGET__TAB_LAYOUT__

#include "AndroidUtil/android/widget/HorizontalScrollView.hpp"
#include "AndroidUtil/java/lang/CharSequence.hpp"

namespace android {
    
    namespace support{
        
        namespace design{
            
            namespace widget{
                
                struct TabLayout : public android::widget::HorizontalScrollView {
                    
                    using HorizontalScrollView::HorizontalScrollView;
#ifdef __ANDROID__
                    
            static const std::string signature;
//                    STATIC_VAR(const std::string, signature, "android/support/design/widget/TabLayout");
                    
                    struct Tab:public java::lang::Object{
                        
                        using Object::Object;
                        
            static const std::string signature;
//                        STATIC_VAR(const std::string, signature, "android/support/design/widget/TabLayout$Tab");
                        
                        Tab& setText(const std::string &text);
                        
                        Tab& setText(const java::lang::CharSequence &text);
                    };
                    
                    static int GRAVITY_FILL();
                    
                    void setTabGravity(int gravity);
                    
                    Tab newTab();
                    
                    void addTab(const Tab &tab);
                    
                    Tab getTabAt(int index);
                    
#endif  //__ANDROID__
                    
                };
            }
        }
    }
}

#endif  //__VIPER__ANDROID_UTIL__ANDROID__SUPPORT__DESIGN__WIDGET__TAB_LAYOUT__
