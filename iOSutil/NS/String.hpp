
#ifndef __VIPER__IOS_UTIL__NS__STRING__
#define __VIPER__IOS_UTIL__NS__STRING__

#include "Object.hpp"
#include "Util.hpp"
#include "Data.hpp"

namespace NS {
    
    struct String : public NS::Object {
        
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        enum class Encoding : NSStringEncoding{
            ASCII = NSASCIIStringEncoding,
            NEXTSTEP = NSNEXTSTEPStringEncoding,
            JapaneseEUC = NSJapaneseEUCStringEncoding,
            UTF8 = NSUTF8StringEncoding,
            ISOLatin1 = NSISOLatin1StringEncoding,
            Symbol = NSSymbolStringEncoding,
            NonLossyASCII = NSNonLossyASCIIStringEncoding,
            ShiftJIS = NSShiftJISStringEncoding,
            ISOLatin2 = NSISOLatin2StringEncoding,
            Unicode = NSUnicodeStringEncoding,
            WindowsCP1251 = NSWindowsCP1251StringEncoding,
            WindowsCP1252 = NSWindowsCP1252StringEncoding,
            WindowsCP1253 = NSWindowsCP1253StringEncoding,
            WindowsCP1254 = NSWindowsCP1254StringEncoding,
            WindowsCP1250 = NSWindowsCP1250StringEncoding,
            ISO2022JP = NSISO2022JPStringEncoding,
            MacOSRoman = NSMacOSRomanStringEncoding,
            
            UTF16 = NS::String::Encoding::Unicode,
            
            UTF16BigEndian = NSUTF16BigEndianStringEncoding,
            UTF16LittleEndian = NSUTF16LittleEndianStringEncoding,
            
            UTF32 = NSUTF32StringEncoding,
            UTF32BigEndian = NSUTF32BigEndianStringEncoding,
            UTF32LittleEndian = NSUTF32LittleEndianStringEncoding,
        };
        
        const char* UTF8String();
        
        NS::Data dataUsingEncoding(Encoding encoding);
        
        NS::String stringByAddingPercentEscapesUsingEncoding(NS::String::Encoding enc);
        
        static NS::String stringWithCString(const char *cStr, NS::String::Encoding encoding);
        
        static NS::String create(const NS::Data &data, NS::String::Encoding encoding);
        
    protected:
        
        void initWithData(const NS::Data &data, NS::String::Encoding encoding);
#endif
    };
}

#endif  //__VIPER__IOS_UTIL__NS__STRING__
