#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QtQml>
#include <QInputMethod>
#include <QtQuick>

#include "keyboardhelper.h"
#include "keyeventhandler.h"

void testKeyHelper()
{
    KeyboardHelper keyHelper;
    qDebug() << "key string: " << keyHelper.getKeyText(Qt::Key_P);
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    KeyboardHelper keyHelper;
    qmlRegisterType<KeyboardHelper>("KeyboardHelper", 1, 0, "KeyboardHelper");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QWindow *qmlWindow = qobject_cast<QWindow*>(engine.rootObjects().at(0));
    qmlWindow->setFlags(Qt::WindowStaysOnTopHint | Qt::Tool);

    app.installEventFilter(new KeyEventHandler(qmlWindow));

    return app.exec();
}
