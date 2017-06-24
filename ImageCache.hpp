#ifndef __VIPER_IMAGECACHE_H
#define __VIPER_IMAGECACHE_H

#include "iOSutil/iOSutil.hpp"
#include "AndroidUtil/AndroidUtil.hpp"

#include <functional>
#include <fstream>
#include <iomanip>

#include "sha256.hpp"
#include "Dispatch.hpp"
#include "Image.hpp"

namespace Mitsoko {
    
    struct ImageCache{
        
        static ImageCache shared;
        
        struct Callback : Mitsoko::Disposable::Observer {
            typedef std::function<void(Mitsoko::Image)> type;
            
            type fun;
            bool shouldFire = true;
            Mitsoko::Disposable::Id disposableId;
            
            Callback(type fun_,const Mitsoko::Disposable &disposable);
            
            Callback(const Callback &other);
            
            void operator()(Mitsoko::Image image) const;
            
            virtual void disposableDidDispose(Mitsoko::Disposable::Id id) override;
        };
        
        /**
         *  Should be called from main thread only. Otherwise data races may occur.
         */
        void get(const std::string &url, Callback cb);
        
        /**
         *  Explicitly puts image with a given URL to RAM and FS
         */
        void put(const std::string &url, Mitsoko::Image image);
        
        /**
         *  Returns cached image from RAM or FS or null if one isn't cached.
         *  Doesn't perform request.
         */
        Mitsoko::Image getCached(const std::string &url, std::string *keyPointer = nullptr, std::string *filepathPointer = nullptr);
        
        std::string keyByUrl(const std::string &url) const;
        
        
        /**
         *  Documents path is an absolute path of a diretory where client
         *  is able to save cache and other files. Must not have '/' at the end.
         */
        void documentsPath(const std::string &newValue);
        
        const std::string& documentsPath();
        
    protected:
        std::map<std::string, std::vector<Callback>> callbacks;
        
        void putIntoRAM(const std::string &key, Mitsoko::Image image);
        
        Mitsoko::Image getImageFromRAM(const std::string &key);
        
        Mitsoko::Image getImageFromFS(const std::string &filepath);
        
#ifdef __APPLE__
        NS::MutableDictionary _ramCache;
        
        NS::MutableDictionary& ramCache();
#else
        java::util::HashMap<java::lang::String, android::graphics::Bitmap> _ramCache;
        
        decltype(_ramCache)& ramCache();
#endif
        std::string imageFileName(const std::string &key);
        
        std::string getHexRepresentation(const unsigned char *bytes, size_t length) const;
        
        std::string _documentsPath;
    };
}
#endif /* __VIPER_IMAGECACHE_H */