#include "keyeventhandler.h"
#include <QKeyEvent>
#include <QDebug>

KeyEventHandler::KeyEventHandler(QWindow* window, QObject *parent)
    : qmlWindow(window),
      QObject(parent)
{

}

bool KeyEventHandler::eventFilter(QObject *obj, QEvent *event)
{
    //qDebug() << event->type();
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //qDebug() << "key pressed" << keyEvent->text();
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //qDebug() << "key released" << keyEvent->text();
    }
    else if (event->type() == QEvent::Resize)
    {
//        if (qmlWindow)
//        {
//            if (qmlWindow->property("loaded").toBool())
//            {
//                float width = qmlWindow->width();
//                {
//                    float initialWidth = qmlWindow->property("initial_width").toFloat();
//                    float scale = width/initialWidth;
//                    qDebug() << "scale: " << scale;
//                    qmlWindow->setProperty("scale", scale);
//                    return false;
//                }
//            }
//        }
    }

    // standard event processing
    return QObject::eventFilter(obj, event);
}
