
#ifndef __VIPER__IOS_UTIL__UI__BAR_BUTTON_ITEM__
#define __VIPER__IOS_UTIL__UI__BAR_BUTTON_ITEM__

#include "iOSutil/NS/Object.hpp"
#include "Disposable.hpp"
#include "Image.hpp"
#include "BarItem.hpp"

#include <functional>
#include <map>

namespace UI {
#ifdef __APPLE__
    enum class BarButtonSystemItem : NSInteger {
        Done = UIBarButtonSystemItemDone,
        Cancel = UIBarButtonSystemItemCancel,
        Edit = UIBarButtonSystemItemEdit,
        Save = UIBarButtonSystemItemSave,
        Add = UIBarButtonSystemItemAdd,
        FlexibleSpace = UIBarButtonSystemItemFlexibleSpace,
        FixedSpace = UIBarButtonSystemItemFixedSpace,
        Compose = UIBarButtonSystemItemCompose,
        Reply = UIBarButtonSystemItemReply,
        Action = UIBarButtonSystemItemAction,
        Organize = UIBarButtonSystemItemOrganize,
        Bookmarks = UIBarButtonSystemItemBookmarks,
        Search = UIBarButtonSystemItemSearch,
        Refresh = UIBarButtonSystemItemRefresh,
        Stop = UIBarButtonSystemItemStop,
        Camera = UIBarButtonSystemItemCamera,
        Trash = UIBarButtonSystemItemTrash,
        Play = UIBarButtonSystemItemPlay,
        Pause = UIBarButtonSystemItemPause,
        Rewind = UIBarButtonSystemItemRewind,
        FastForward = UIBarButtonSystemItemFastForward,
        Undo = UIBarButtonSystemItemUndo,
        Redo = UIBarButtonSystemItemRedo,
        PageCurl = UIBarButtonSystemItemPageCurl,
    };
#endif
    
    struct BarButtonItem : public UI::BarItem {
        
        using BarItem::BarItem;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        typedef std::function<void(UI::BarButtonItem)> Touched;
        
        enum class Style{
            Plain = UIBarButtonItemStylePlain,
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_8_0
            Bordered = UIBarButtonItemStyleBordered,
#endif
            Done = UIBarButtonItemStyleDone,
        };
        
        static UI::BarButtonItem create(const UI::Image &image,
                                        Style style,
                                        Touched f,
                                        const Mitsoko::Disposable *disposable);
        
        static UI::BarButtonItem create(const std::string &title,
                                        Style style,
                                        Touched f,
                                        const Mitsoko::Disposable *disposable);
        
        static UI::BarButtonItem create(BarButtonSystemItem systemItem,
                                        Touched f,
                                        const Mitsoko::Disposable *disposable);
        
        static void touched(Handle handle);
        
    protected:
        
        typedef std::map<Handle, Touched> TouchedMap;
        static TouchedMap touchedMap;
        
        typedef std::map<Mitsoko::Disposable::Id, Handle> DisposablesMap;
        static DisposablesMap disposablesMap;
        
        struct Observer : public Mitsoko::Disposable::Observer {
            
            virtual void disposableDidDispose(Mitsoko::Disposable::Id id) override;
        };
        
        static Observer observer;
        
        Handle initWithImage(const UI::Image &image,
                             Style style,
                             const NS::Object &target,
                             SEL action);
        
        Handle initWithTitle(const CF::String &title,
                             Style style,
                             const NS::Object &target,
                             SEL action);
        
        Handle initWithSystemItem(UI::BarButtonSystemItem systemItem,
                                  const NS::Object &target,
                                  SEL action);
        
#endif  //__APPLE__
        
    };
}

#endif  //__VIPER__IOS_UTIL__UI__BAR_BUTTON_ITEM__
