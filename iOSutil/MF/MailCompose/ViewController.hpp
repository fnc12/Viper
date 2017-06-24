
#ifndef __VIPER_APPLE_MC_VIEW_CONTROLLER_H
#define __VIPER_APPLE_MC_VIEW_CONTROLLER_H

#include "iOSutil/UI/NavigationController.hpp"

#include <map>
#include <ostream>

#ifdef __APPLE__

#import <MessageUI/MFMailComposeViewController.h>

#endif

namespace MF {
    
    namespace MailCompose {
        
#ifdef __APPLE__
        enum class Result {
            Cancelled = MFMailComposeResultCancelled,
            Saved = MFMailComposeResultSaved,
            Sent = MFMailComposeResultSent,
            Failed = MFMailComposeResultFailed,
        };
        
        std::ostream& operator<<(std::ostream &os, Result result);
#endif
        
        struct ViewController : public UI::NavigationController {
            
#ifdef __APPLE__
            static const std::string className;
            
            static bool canSendMail();
            
            static MF::MailCompose::ViewController create();
            
            void setSubject(const std::string &newValue);
            
            void setToRecipients(const std::vector<std::string> &value);
            
            void setMessageBody(const std::string &body, bool isHTML);
            
            typedef std::function<void(Result)> DidFinish;
            
            void setDidFinish(DidFinish didFinish);
            
            static void didFinishWithResult(const void *handle, Result result);
            
        private:
            typedef UI::NavigationController Super;
        public:
            using Super::Super;
        protected:
            typedef std::map<Handle, DidFinish> DidFinishMap;
            static DidFinishMap didFinishMap;
#endif
        };
    }
}

#endif /* __VIPER_APPLE_MC_VIEW_CONTROLLER_H */