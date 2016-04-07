#include "layoutimpmac.h"

#include <CoreFoundation/CoreFoundation.h>
#include <Carbon/Carbon.h>
#include <string>

static const int LANG_STRING_SIZE = 64;

LayoutImpMac::LayoutImpMac()
{

}

std::string LayoutImpMac::getKeyboardLanguageCode() const
{
    TISInputSourceRef source = TISCopyCurrentKeyboardInputSource();
    CFArrayRef sourceLanguages = (CFArrayRef)(TISGetInputSourceProperty(source, kTISPropertyInputSourceLanguages));
    CFStringRef langCode = (CFStringRef)CFArrayGetValueAtIndex(sourceLanguages, 0);
    //const char* result = CFStringGetCStringPtr(langCode, kCFStringEncodingUTF8);
    char *buffer = (char *)malloc(LANG_STRING_SIZE);
    std::string result;
    if (CFStringGetCString(langCode, buffer, LANG_STRING_SIZE, kCFStringEncodingUTF8))
    {
        result = std::string(buffer);
    }
    free(buffer);
    return result;
}

void testOSXlang()
{
    CFLocaleRef loc = CFLocaleCopyCurrent();
    CFStringRef countryCode = (CFStringRef)CFLocaleGetValue (loc, kCFLocaleCountryCode);
    CFStringRef countryName = CFLocaleCopyDisplayNameForPropertyValue (loc, kCFLocaleCountryCode, countryCode);
    CFShow(countryCode);
    CFShow(countryName);
    CFArrayRef langs = CFLocaleCopyPreferredLanguages();
    CFStringRef langCode = (CFStringRef)CFArrayGetValueAtIndex (langs, 0);
    CFStringRef langName = CFLocaleCopyDisplayNameForPropertyValue (loc, kCFLocaleLanguageCode, langCode);
    CFShow(langCode);
    CFShow(langName);

    TISInputSourceRef source = TISCopyCurrentKeyboardInputSource();
    CFStringRef keyboardSource = (CFStringRef)(TISGetInputSourceProperty(source, kTISPropertyInputSourceLanguages));
    CFShow(keyboardSource);
}
