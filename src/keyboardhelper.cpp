#include "keyboardhelper.h"

#include <QKeySequence>
#include <QFile>
#include <QTextCodec>
#include <QKeyEvent>
#include <QDebug>
#include <QGuiApplication>

#define TESTING 0

const QString KeyboardHelper::defaultJson =
"{"
"\"Groups\": [],"
"\"Rows\": []"
"}";

KeyboardHelper::KeyboardHelper(QObject *parent) : QObject(parent)
{
    QString filePath;
#if TESTING
    filePath = "/Users/Ivan/projects/vkeyboard/";
#else
    filePath = qApp->applicationDirPath();
    filePath.append("/../Resources/keyboard_layout.json");
    //qDebug() << "filePath: " << filePath;
#endif

    QFile jsonFile(filePath);
    if (jsonFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        jsonKeyboard = QTextCodec::codecForMib(106)->toUnicode(jsonFile.readAll());
        jsonFile.close();
    }
}

QString KeyboardHelper::getKeyText(int code) const
{
    QKeySequence sequence = QKeySequence(code);
    return sequence.toString();
}

QString KeyboardHelper::getJsonKeyboard() const
{
    return jsonKeyboard;
}

QString KeyboardHelper::getKeyboardLanguage() const
{
    std::string lang = mLayout.getKeyboardLanguageCode();
    return QString::fromStdString(lang);
}

bool KeyboardHelper::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        if (ke->key() == Qt::Key_Shift) {
            qDebug() << "Shift pressed!";
            return true;
        }
    }
    return false;
}

//int KeyboardHelper::getNativeCode(int qtKey) const
//{
//    QKeyEvent keyEvent(qtKey);
//    return keyEvent.nativeVirtualKey();
//}
