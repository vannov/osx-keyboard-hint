#include "layout.h"

#if __APPLE__
#include "layoutimpmac.h"
#elif
//#include "layoutimpwin.h"
#endif

Layout::Layout()
{
#if __APPLE__
    imp = new LayoutImpMac();
#else
    //imp = new LayoutImpWin();
#endif
}

Layout::~Layout()
{
    delete imp;
}

std::string Layout::getKeyboardLanguageCode() const
{
    return imp->getKeyboardLanguageCode();
}
