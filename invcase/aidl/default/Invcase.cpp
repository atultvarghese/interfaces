#define LOG_TAG "Invcase"

#include <utils/Log.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Invcase.h"
using namespace std;

string invertCase(const string& str) {
    string inverted;
    for (char c : str) {
        if (isupper(c)) {
            inverted += tolower(c);  // Convert uppercase to lowercase
        } else if (islower(c)) {
            inverted += toupper(c);  // Convert lowercase to uppercase
        } else {
            inverted += c;  // Keep non-alphabetic characters unchanged
        }
    }
    return inverted;
}

namespace aidl {
namespace android {
namespace hardware {
namespace invcase {

//String getChars();
ndk::ScopedAStatus Invcase::getChars(std::string* _aidl_return) {
   /*  std::ifstream invcase_dev;
    invcase_dev.open("/dev/invcase");
    if(invcase_dev.good()) {
        std::string line;
        invcase_dev >> line;
        ALOGD("Invcase service: getChars: %s", line.c_str());
        *_aidl_return =  line;
    } else {
        ALOGE("getChars: can not open /dev/invcase");
        return ndk::ScopedAStatus::fromServiceSpecificError(-1);
    } */

   // Hard-coded string response
    std::string hardCodedResponse = "This is a hard-coded response";
    
    // Set the output parameter to the hard-coded string
    *_aidl_return = hardCodedResponse;
    
    // Log the hard-coded response
    ALOGD("Invcase service: getChars: %s", hardCodedResponse.c_str());
    ALOGD("Invcase test log");
    
    return ndk::ScopedAStatus::ok();
}

//void putChars(in String msg);
ndk::ScopedAStatus Invcase::putChars(const std::string& in_msg) {
    std::ofstream invcase_dev;
    invcase_dev.open ("/dev/invcase");
    if(invcase_dev.good()) {
        invcase_dev << in_msg;
        ALOGD("Invcase service: putChars: %s", in_msg.c_str());
    } else {
        ALOGE("putChars: can not open /dev/invcase");
        return ndk::ScopedAStatus::ok();
        // return ndk::ScopedAStatus::fromServiceSpecificError(-1);
    }
    // Hard-coded string response
    
    // Log the hard-coded response
    ALOGD("Invcase service: putchars done");

    return ndk::ScopedAStatus::ok();
}

}  // namespace invcase
}  // namespace hardware
}  // namespace android
}  // namespace aidl
