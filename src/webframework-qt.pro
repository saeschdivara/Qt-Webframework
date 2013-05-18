#-------------------------------------------------
#
# Project created by QtCreator 2013-05-12T13:47:35
#
#-------------------------------------------------

QT       -= gui
QT       += network

TARGET = webframework-qt
TEMPLATE = lib

QMAKE_CXXFLAGS += -std=c++11

DEFINES += WEBFRAMEWORKQT_LIBRARY

SOURCES += \
    website/AbstractWebsite.cpp \
    page/SimplePage.cpp \
    page/AbstractSocketPage.cpp \
    js/JsCode.cpp \
    page/AbstractRenderedPage.cpp \
    htmlelement/AbstractHtmlElement.cpp \
    htmlelement/HtmlElement.cpp \
    htmlelement/BodyElement.cpp \
    htmlelement/ImageElement.cpp \
    htmlelement/HeadElement.cpp

HEADERS +=\
        webframework-qt_global.h \
    website/AbstractWebsite.h \
    page/PageInterface.h \
    page/StatefulPageInterface.h \
    page/SimplePage.h \
    website/private/AbstractWebsite_p.h \
    page/InteractivePageInterface.h \
    page/AbstractSocketPage.h \
    page/private/AbstractSocketPage_p.h \
    js/JsCode.h \
    page/AbstractRenderedPage.h \
    page/private/AbstractRenderedPage_p.h \
    htmlelement/AbstractHtmlElement.h \
    htmlelement/private/AbstractHtmlElement_p.h \
    htmlelement/HtmlElement.h \
    htmlelement/BodyElement.h \
    htmlelement/ImageElement.h \
    htmlelement/HeadElement.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3rdparty/tufao-debug/release/ -ltufao
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3rdparty/tufao-debug/debug/ -ltufao
else:unix:!macx: LIBS += -L$$PWD/../3rdparty/tufao-debug/ -ltufao

INCLUDEPATH += $$PWD/../3rdparty/tufao/src
DEPENDPATH += $$PWD/../3rdparty/tufao/src
