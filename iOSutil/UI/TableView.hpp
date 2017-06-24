
#ifndef __VIPER__IOS_UTIL__UI__TABLE_VIEW__
#define __VIPER__IOS_UTIL__UI__TABLE_VIEW__

#include "ScrollView.hpp"
#include "TableListAdapter.hpp"
#include "ImageView.hpp"
#include "Label.hpp"
#include "iOSutil/NS/IndexSet.hpp"
#include "iOSutil/UI/EdgeInsets.hpp"

namespace UI {
    
    struct TableView:public UI::ScrollView{
        using ScrollView::ScrollView;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        enum class RowAnimation{
            Fade = UITableViewRowAnimationFade,
            Right = UITableViewRowAnimationRight,
            Left = UITableViewRowAnimationLeft,
            Top = UITableViewRowAnimationTop,
            Bottom = UITableViewRowAnimationBottom,
            None = UITableViewRowAnimationNone,
            Middle = UITableViewRowAnimationMiddle,
            Automatic = UITableViewRowAnimationAutomatic,
        };
        
        void reloadSections(const NS::IndexSet &indexSet, RowAnimation animation);
        
        void reloadData();
        
        void beginUpdates();
        
        /**
         *  This function doesn't exist in UIKit. This is a special function 
         *  for settings a crossplatform adapter. This function also exists for
         *  android::widget::ListView with two arguments where second argument is
         *  android::content::Context.
         */
        template<class T>
        Mitsoko::TableListAdapter::AdapterId setAdapter(T ad){
            auto pointer = std::make_shared<T>(std::move(ad));
            return this->setAdapter(pointer);
        }
        
        template<class T>
        Mitsoko::TableListAdapter::AdapterId setAdapter(std::shared_ptr<T> pointer){
            auto adapterPointer = std::dynamic_pointer_cast<Mitsoko::AdapterBase>(pointer);
            auto adapterId = Mitsoko::TableListAdapter::registerAdapter(this->handle, adapterPointer);
            auto sharedAdapterClass = NS::getClass("ViperTableViewAdapter");
            auto sharedAdapter = NS::Object::sendMessage<Handle>(sharedAdapterClass,"shared");
            this->sendMessage<void>("setDataSource:", sharedAdapter);
            this->sendMessage<void>("setDelegate:", sharedAdapter);
            return adapterId;
        }
        
        UI::View tableFooterView();
        
        void setTableFooterView(const UI::View &value);
        
        UI::Color separatorColor();
        
        void setSeparatorColor(const UI::Color &value);
        
        struct Cell : public UI::View {
            
            using View::View;
            
            static const std::string className;
            
            enum class AccessoryType{
                None = UITableViewCellAccessoryNone,
                DisclosureIndicator = UITableViewCellAccessoryDisclosureIndicator,
                DetailDisclosureButton = UITableViewCellAccessoryDetailDisclosureButton,
                Checkmark = UITableViewCellAccessoryCheckmark,
                DetailButton = UITableViewCellAccessoryDetailButton,
            };
            
            enum class SelectionStyle : NSInteger {
                None = UITableViewCellSelectionStyleNone,
                Blue = UITableViewCellSelectionStyleBlue,
                Gray = UITableViewCellSelectionStyleGray,
                Default = UITableViewCellSelectionStyleDefault,
            };
            
            void setSelectionStyle(SelectionStyle newValue);
            
            SelectionStyle selectionStyle();
            
            UI::ImageView imageView();
            
            UI::Label detailTextLabel();
            
            UI::Label textLabel();
            
            void setAccessoryType(AccessoryType newValue);
            
            AccessoryType accessoryType();
            
            void setSeparatorInset(const UI::EdgeInsets &value);
            
            UI::EdgeInsets separatorInset();
        };
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__TABLE_VIEW__
