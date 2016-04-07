#ifndef KEYBOARDHELPER_H
#define KEYBOARDHELPER_H

#include <QObject>
#include <QString>

#include "layout.h"

class KeyboardHelper : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString jsonButtons READ jsonButtons)
    //QString jsonButtons;
public:
    explicit KeyboardHelper(QObject *parent = 0);

    Q_INVOKABLE QString getJsonKeyboard() const;
    Q_INVOKABLE QString getKeyboardLanguage() const;
    //Q_INVOKABLE int getNativeCode(int qtKey) const;
    QString getKeyText(int code) const;

    bool event(QEvent *event);
    static const QString defaultJson;
signals:

public slots:
    //void localeChanged();

private:
    QString jsonKeyboard;
    Layout mLayout;
};

#endif // KEYBOARDHELPER_H
