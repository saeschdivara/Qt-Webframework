#-------------------------------------------------
#
# Project created by QtCreator 2013-10-20T18:38:22
#
#-------------------------------------------------

QT       += core network xml

QT       -= gui

# C++11 support is needed
QMAKE_CXXFLAGS += -std=c++11

TARGET = HelloWorld
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# Libraries
# Release
CONFIG(release, debug|release) {
LIBS += -L$$PWD/../../dist/release/ -lwebframework-qt
LIBS += -L$$PWD/../../3rdparty/tufao-release/ -ltufao
LIBS += -L$$PWD/../../3rdparty/Qt-Arango-DB-Driver-release/ -larangodb-driver
}
# Debug
CONFIG(debug, debug|release) {
LIBS += -L$$PWD/../../dist/debug/ -lwebframework-qt
LIBS += -L$$PWD/../../3rdparty/tufao-debug/ -ltufao
LIBS += -L$$PWD/../../3rdparty/Qt-Arango-DB-Driver-debug/ -larangodb-driver
}

# Including and depending on the libraries
# Webframework-qt
INCLUDEPATH += $$PWD/../../src
DEPENDPATH += $$PWD/../../src
# Tufao webserver
INCLUDEPATH += $$PWD/../../3rdparty/tufao/src/
DEPENDPATH += $$PWD/../../3rdparty/tufao/src/
# ArangoDB driver
INCLUDEPATH += $$PWD/../../3rdparty/Qt-Arango-DB-Driver/src
DEPENDPATH += $$PWD/../../3rdparty/Qt-Arango-DB-Driver/src

SOURCES += main.cpp \
    TestWebsite.cpp \
    pages/IndexPage.cpp

HEADERS += \
    TestWebsite.h \
    pages/IndexPage.h
