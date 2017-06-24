
#ifndef ANDROID_UTIL_H
#define ANDROID_UTIL_H

#include "Mitsoko/Util.hpp"

#include "java/lang/Array.hpp"
#include "java/lang/CharSequence.hpp"
#include "java/lang/Class.hpp"
#include "java/lang/Iterable.hpp"
#include "java/lang/JavaRuntime.hpp"
#include "java/lang/JNI.hpp"
#include "java/lang/Object.hpp"
#include "java/lang/Runnable.hpp"
#include "java/lang/String.hpp"
#include "java/lang/Thread.hpp"

#include "java/io/BufferedOutputStream.hpp"
#include "java/io/ByteArrayOutputStream.hpp"
#include "java/io/File.hpp"
#include "java/io/FileOutputStream.hpp"
#include "java/io/FilterOutputStream.hpp"
#include "java/io/OutputStream.hpp"

#include "java/util/AbstractMap.hpp"
#include "java/util/Calendar.hpp"
#include "java/util/Collection.hpp"
#include "java/util/Date.hpp"
#include "java/util/HashMap.hpp"
#include "java/util/Locale.hpp"
#include "java/util/List.hpp"
#include "java/util/Map.hpp"

#include "android/app/Activity.hpp"
#include "android/app/Fragment.hpp"
#include "android/app/Dialog.hpp"
#include "android/app/AlertDialog.hpp"
#include "android/app/DatePickerDialog.hpp"

#include "android/content/res/Resources.hpp"

#include "android/content/Context.hpp"
#include "android/content/Intent.hpp"
#include "android/content/DialogInterface.hpp"

#include "android/graphics/Bitmap.hpp"
#include "android/graphics/BitmapFactory.hpp"
#include "android/graphics/Color.hpp"

#include "android/net/Uri.hpp"

#include "android/os/BaseBundle.hpp"
#include "android/os/Bundle.hpp"
#include "android/os/Handler.hpp"

#include "android/provider/MediaStore.hpp"

#include "android/support/design/widget/TabLayout.hpp"

#include "android/support/v4/app/FragmentActivity.hpp"
#include "android/support/v4/app/Fragment.hpp"

#include "android/support/v7/app/AppCompatActivity.hpp"
#include "android/support/v7/app/ActionBar.hpp"

#include "android/text/Editable.hpp"
#include "android/text/InputType.hpp"

#include "android/view/Gravity.hpp"
#include "android/view/MenuItem.hpp"
#include "android/view/View.hpp"
#include "android/view/ViewGroup.hpp"
#include "android/view/ViewManager.hpp"
#include "android/view/Window.hpp"
#include "android/view/WindowManager.hpp"

#include "android/view/inputmethod/InputMethodManager.hpp"

#include "android/widget/AbsListView.hpp"
#include "android/widget/AbsoluteLayout.hpp"
#include "android/widget/Adapter.hpp"
#include "android/widget/AdapterView.hpp"
#include "android/widget/BaseAdapter.hpp"
#include "android/widget/Button.hpp"
#include "android/widget/CheckBox.hpp"
#include "android/widget/CompoundButton.hpp"
#include "android/widget/EditText.hpp"
#include "android/widget/FrameLayout.hpp"
#include "android/widget/HorizontalScrollView.hpp"
#include "android/widget/ImageButton.hpp"
#include "android/widget/ImageView.hpp"
#include "android/widget/LinearLayout.hpp"
#include "android/widget/ListAdapter.hpp"
#include "android/widget/ListView.hpp"
#include "android/widget/RelativeLayout.hpp"
#include "android/widget/Switch.hpp"
#include "android/widget/TabHost.hpp"
#include "android/widget/TextView.hpp"

#include "android/webkit/WebView.hpp"

#if defined(__ANDROID__) &&  !defined(DISABLE_ANDROID_LOG)

#include <android/log.h>

/**
 *  This is a cool class that allows redirecting std::cout to
 *  android log.
 */
class androidbuf : public std::streambuf {
public:
    enum { bufsize = 128 }; // ... or some other suitable buffer size
    androidbuf() { this->setp(buffer, buffer + bufsize - 1); }
    
private:
    int overflow(int c)
    {
        if (c == traits_type::eof()) {
            *this->pptr() = traits_type::to_char_type(c);
            this->sbumpc();
        }
        return this->sync()? traits_type::eof(): traits_type::not_eof(c);
    }
    
    int sync()
    {
        int rc = 0;
        if (this->pbase() != this->pptr()) {
            char writebuf[bufsize+1];
            memcpy(writebuf, this->pbase(), this->pptr() - this->pbase());
            writebuf[this->pptr() - this->pbase()] = '\0';
            
            rc = __android_log_write(ANDROID_LOG_INFO, "std", writebuf) > 0;
            this->setp(buffer, buffer + bufsize - 1);
        }
        return rc;
    }
    
    char buffer[bufsize];
};
#endif

/*#ifdef __ANDROID__
 #undef TYPE_SIGNATURE
 #endif*/
 
#endif /* ANDROID_UTIL_H */
