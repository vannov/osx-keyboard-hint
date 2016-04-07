#ifndef KEYEVENTHANDLER_H
#define KEYEVENTHANDLER_H

#include <QObject>
#include <QWindow>
#include <QTime>

class KeyEventHandler : public QObject
{
    Q_OBJECT
public:
    explicit KeyEventHandler(QWindow* window, QObject *parent = 0);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
signals:

public slots:

private:
    QWindow* qmlWindow;
};

#endif // KEYEVENTHANDLER_H
