
#pragma once

#include "AbsListView.hpp"
#include "Viper/TableListAdapter.hpp"

namespace android{
    namespace widget{
        struct ListView:public AbsListView{
            using AbsListView::AbsListView;
            STATIC_VAR(const std::string, signature, "android/widget/ListView");
#ifdef __ANDROID__
            ListAdapter getAdapter(){
                return this->sendMessage<ListAdapter>("getAdapter");
            }
            
            void setAdapter(const ListAdapter &adapter){
                this->sendMessage<void>("setAdapter",adapter);
            }
            
            /**
             *  This function doesn't exist in SDK. This is a special function used for
             *  settings a core crossplarform adapter to a listView.
             */
            Viper::TableListAdapter::AdapterId setAdapter(std::shared_ptr<Viper::AdapterBase> adapterPointer,
                                                          const content::Context &context)
            {
                if(auto java_env=java::lang::JNI::Env()){
                    if(auto clazz=java::lang::Class::find(java::lang::JNI::appNamespace()+"/ViperTableViewAdapter")){
//                    if(auto clazz=java_env->FindClass("kz/outlawstudio/groozim/ViperTableViewAdapter")){
                        auto signature=java::lang::Object::generateMethodSignature<void,ListView,content::Context>();
                        if(auto ctor = java_env->GetMethodID(clazz, "<init>", signature.c_str())){
                            ListAdapter adapter=java_env->NewObject(clazz, ctor, this->handle,context.handle);
                            this->setAdapter(adapter);
                            adapterPointer->activityHandle=context.handle;
                            return Viper::TableListAdapter::registerAdapter(this->handle, adapterPointer, java_env);
                        }else{
                            return 0;
                        }
                    }else{
                        return 0;
                    }
                }else{
                    return 0;
                }
            }
#endif
        };
    }
}
