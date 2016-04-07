#ifndef LAYOUT_H
#define LAYOUT_H

#include <string>

#include "layoutimp.h"

class Layout
{
private:
    Layout(const Layout&);
    Layout& operator=(const Layout&);
public:
    Layout();
    ~Layout();
    std::string getKeyboardLanguageCode() const;
private:
    LayoutImp *imp;
};

#endif // LAYOUT_H
