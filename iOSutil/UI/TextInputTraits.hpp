
#ifndef __VIPER__IOS_UTIL_UI__TEXT_INPUT_TRAITS__
#define __VIPER__IOS_UTIL_UI__TEXT_INPUT_TRAITS__

#include "iOSutil/NS/Object.hpp"

namespace UI {
    
#ifdef __APPLE__
    enum class KeyboardType {
        Default = UIKeyboardTypeDefault,
        ASCIICapable = UIKeyboardTypeASCIICapable,
        NumbersAndPunctuation = UIKeyboardTypeNumbersAndPunctuation,
        URL = UIKeyboardTypeURL,
        NumberPad = UIKeyboardTypeNumberPad,
        PhonePad = UIKeyboardTypePhonePad,
        NamePhonePad = UIKeyboardTypeNamePhonePad,
        EmailAddress = UIKeyboardTypeEmailAddress,
        DecimalPad = UIKeyboardTypeDecimalPad,
        Twitter = UIKeyboardTypeTwitter,
        WebSearch = UIKeyboardTypeWebSearch,
//        UIKeyboardTypeAlphabet = UIKeyboardTypeASCIICapable, // Deprecated
    };
    
    enum class TextAutocapitalizationType {
        None = UITextAutocapitalizationTypeNone,
        Words = UITextAutocapitalizationTypeWords,
        Sentences = UITextAutocapitalizationTypeSentences,
        AllCharacters = UITextAutocapitalizationTypeAllCharacters,
    };
#endif
    /**
     *  Protocol.
     */
    struct TextInputTraits : public NS::Object {
        using Object::Object;
        
#ifdef __APPLE__
        
        static const std::string className;
        
        void setKeyboardType(UI::KeyboardType newValue);
        
        UI::KeyboardType keyboardType();
        
        void setAutocapitalizationType(TextAutocapitalizationType value);
        
        TextAutocapitalizationType autocapitalizationType();
        
        void setSecureTextEntry(bool value);
        
        bool isSecureTextEntry();
#endif
    };
}

#endif  //__VIPER__IOS_UTIL_UI__TEXT_INPUT_TRAITS__
