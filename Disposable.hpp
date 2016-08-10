//
//  Disposable.hpp
//  Jako
//
//  Created by John Zakharov on 20.03.16.
//  Copyright © 2016 Outlaw Studio. All rights reserved.
//

#ifndef Disposable_h
#define Disposable_h

#include <mutex>
#include <vector>
#include <algorithm>
#include <iostream>

namespace Viper{
//    using std::cout;
//    using std::endl;
    
    struct Disposable{
        
        /**
         *  Every disposable has unique id. Once disposed every observer receives callback with id 
         *  of disposable which disposed.
         */
        typedef unsigned Id;
        
        const Id id;
        
        struct Observer{
            virtual void disposableDidDispose(Id id)=0;
            
            virtual ~Observer();
        };
        
        Disposable();
        
        virtual void dispose();
        
        static void subscribe(Observer *observer);
        
        static void unsubscribe(Observer *observer);
        
    protected:
        
        static std::mutex observersMutex;
        /*static std::mutex& observersMutex(){
            static std::mutex res;
            return res;
        }*/
        
        static std::vector<Observer*> observers;
        
        /*static std::vector<Observer*>& observers(){
            static std::vector<Observer*> res;
            return res;
        }*/
        
        static Id generateId();
    };
}

#endif /* Disposable_h */
