#ifndef LAYOUTIMP_H
#define LAYOUTIMP_H

#include <string>

class LayoutImp
{
private:
    LayoutImp(const LayoutImp&);
    LayoutImp& operator=(const LayoutImp&);
public:
    LayoutImp() {};
    virtual ~LayoutImp() {};
    virtual std::string getKeyboardLanguageCode() const = 0;
};

#endif // LAYOUTIMP_H
