#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T13:47:35
#
#-------------------------------------------------

QT       -= gui

TARGET = webframework-qt
TEMPLATE = lib

DEFINES += WEBFRAMEWORKQT_LIBRARY

SOURCES += \
    website/AbstractWebsite.cpp

HEADERS +=\
        webframework-qt_global.h \
    website/AbstractWebsite.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
