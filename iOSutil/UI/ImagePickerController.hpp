
#ifndef __VIPER__IOS_UTIL__UI__IMAGE_PICKER_CONTROLLER__
#define __VIPER__IOS_UTIL__UI__IMAGE_PICKER_CONTROLLER__

#include "NavigationController.hpp"
#include "iOSutil/NS/Array.hpp"
#include "iOSutil/NS/Dictionary.hpp"

#include <map>
#include <functional>

namespace UI {
    
    struct ImagePickerController : public UI::NavigationController {
        
        using NavigationController::NavigationController;
        
#ifdef __APPLE__
        
        static const std::string className;
//        STATIC_VAR(const std::string, className, "UIImagePickerController");
        
        typedef std::function<void(UI::ImagePickerController)> DidCancel;
        typedef std::function<void(UI::ImagePickerController,NS::Dictionary)> DidFinishPickingMediaWithInfo;
        
        enum class SourceType{
            PhotoLibrary = UIImagePickerControllerSourceTypePhotoLibrary,
            Camera = UIImagePickerControllerSourceTypeCamera,
            SavedPhotosAlbum = UIImagePickerControllerSourceTypeSavedPhotosAlbum,
        };
        
        static UI::ImagePickerController create();
        
        static bool isSourceTypeAvailable(UI::ImagePickerController::SourceType sourceType);
        
        static NS::Array availableMediaTypesForSourceType(UI::ImagePickerController::SourceType sourceType);
        
        static NS::String OriginalImage();
        
        void setDidCancel(DidCancel f);
        
        void setDidFinishPickingMediaWithInfo(DidFinishPickingMediaWithInfo f);
        
        void setMediaTypes(const NS::Array &newValue);
        
        NS::Array mediaTypes();
        
        void setSourceType(UI::ImagePickerController::SourceType newValue);
        
        SourceType sourceType();
        
        struct DelegateEventHandler{
            DidCancel didCancel;
            DidFinishPickingMediaWithInfo didFinishPickingMediaWithInfo;
            
            static void imagePickerControllerDidCancel(const void *sender);
            
            static void imagePickerControllerDidFinishPickingMediaWithInfo(const void *sender,const void *info);
            
            static DelegateEventHandler& getOrCreate(const void *sender);
            
            static DelegateEventHandler* get(const void *aw);
            
        protected:
            typedef std::map<Handle, DelegateEventHandler> DelegateEventHandlersMap;
            static DelegateEventHandlersMap delegateEventHandlers;
            
            static void remove(const void *aw);
        };
        
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__UI__IMAGE_PICKER_CONTROLLER__
