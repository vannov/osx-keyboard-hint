TEMPLATE = app

QT += qml quick
QT += widgets
CONFIG += c++11
QMAKE_MAC_SDK = macosx10.11

SOURCES += \
    src/keyboardhelper.cpp \
    src/keyeventhandler.cpp \
    src/layout.cpp \
    src/layoutimpmac.cpp \
    src/main.cpp

RESOURCES += \
    src/qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/keyboardhelper.h \
    src/keyeventhandler.h \
    src/layout.h \
    src/layoutimp.h \
    src/layoutimpmac.h

LIBS += -framework CoreFoundation -framework Carbon
TARGET = KeyboardHelper

win32 {
    copyfiles.commands = @call copy <from> <to>
}
macx {
    copyfiles.commands = cp -r $$PWD/resources/keyboard_layout.json $$OUT_PWD/$$TARGET\.app/Contents/Resources
    #macdeployqt.commands = macdeployqt $$OUT_PWD/$$TARGET\.app -qmldir=src/qml -dmg -verbose=2
}
QMAKE_EXTRA_TARGETS += copyfiles
QMAKE_EXTRA_TARGETS += macdeployqt
POST_TARGETDEPS += copyfiles
POST_TARGETDEPS += macdeployqt
ICON = resources/icon.icns

DISTFILES += \
    resources/icon.icns

