
#ifndef __VIPER__ANDROID_UTIL__JAVA__UTIL__MAP__
#define __VIPER__ANDROID_UTIL__JAVA__UTIL__MAP__

#include "AndroidUtil/java/lang/Object.hpp"

#include <type_traits>

namespace java {
    
    namespace util{
        
        template<class K, class V>
        
        struct Map : public java::lang::Object {
            
            using Object::Object;
            
#ifdef __ANDROID__
            
            static const std::string signature;
            
            static_assert(std::is_base_of<java::lang::Object,K>::value, "K must derive java::lang::Object");
            static_assert(std::is_base_of<java::lang::Object,V>::value, "V must derive java::lang::Object");
            
            void clear();
            
            bool containsKey(const java::lang::Object &key);
            
            bool containsValue(const java::lang::Object &value);
            
            bool equals(const java::lang::Object &object);
            
            V get(const java::lang::Object &key);
            
            int hashCode();
            
            bool isEmpty();
            
            V put(const K &key,const V &value);
            
            V remove(const java::lang::Object &key);
            
            int size();
            
#endif  //__ANDROID__
            
        };
        
#ifdef __ANDROID__
        template<class K, class V>
        const std::string Map<K, V>::signature = "java/util/Map";
#endif  //__ANDROID__
    }
}

#ifdef __ANDROID__

template<class K,class V>
void java::util::Map<K,V>::clear(){
    this->sendMessage<void>("clear");
}

template<class K,class V>
bool java::util::Map<K,V>::containsKey(const java::lang::Object &key){
    return this->sendMessage<bool>("containsKey",key);
}

template<class K,class V>
bool java::util::Map<K,V>::containsValue(const java::lang::Object &value){
    return this->sendMessage<bool>("containsValue",value);
}

template<class K,class V>
bool java::util::Map<K,V>::equals(const java::lang::Object &object){
    return this->sendMessage<bool>("equals",object);
}

template<class K,class V>
V java::util::Map<K, V>::get(const java::lang::Object &key){
    return (V)this->sendMessage<java::lang::Object>("get",key);
}

template<class K,class V>
int java::util::Map<K,V>::hashCode(){
    return this->sendMessage<int>("hashCode");
}

template<class K,class V>
bool java::util::Map<K,V>::isEmpty(){
    return this->sendMessage<bool>("isEmpty");
}

template<class K,class V>
V java::util::Map<K,V>::put(const K &key,const V &value){
    return (V)this->sendMessage<java::lang::Object>("put",(java::lang::Object)key,(java::lang::Object)value);
}

template<class K,class V>
V java::util::Map<K,V>::remove(const java::lang::Object &key){
    return (V)this->sendMessage<java::lang::Object>("remove",key);
}

template<class K,class V>
int java::util::Map<K,V>::size(){
    return this->sendMessage<int>("size");
}

#endif  //__ANDROID__

#endif  //__VIPER__ANDROID_UTIL__JAVA__UTIL__MAP__
