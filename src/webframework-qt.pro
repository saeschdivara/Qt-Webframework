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
    htmlelement/HeadElement.cpp \
    htmlelement/DivElement.cpp \
    htmlelement/InputElement.cpp \
    htmlelement/VideoElement.cpp \
    htmlelement/TextElement.cpp \
    css/ElementCss.cpp \
    htmlelement/FormElement.cpp \
    htmlelement/BreakElement.cpp \
    page/templates/AbstractTemplatePage.cpp \
    page/model/AbstractModel.cpp \
    page/model/AbstractListModel.cpp \
    internationalisation/I18nManager.cpp \
    page/resource/AbstractResource.cpp \
    page/resource/ImageResource.cpp \
    website/WebSession.cpp \
    internationalisation/LanguageTexts.cpp \
    page/templates/AbstractTranslatableTemplate.cpp \
    page/model/AbstractTranslatableModel.cpp \
    security/User.cpp \
    page/resource/DartResource.cpp \
    security/SecurityController.cpp \
    page/model/DirListModel.cpp \
    page/model/ImageModel.cpp \
    page/model/DirListMapModel.cpp \
    util/UserDataHelper.cpp \
    page/templates/tags/TemplateTag.cpp \
    page/templates/tags/TagRenderer.cpp \
    util/TemplateRenderHelper.cpp \
    util/TemplateOutputHelper.cpp \
    util/InteractivePageHelper.cpp \
    page/templates/tags/IfTag.cpp \
    util/DomOutputHelper.cpp

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
    htmlelement/HeadElement.h \
    htmlelement/DivElement.h \
    htmlelement/InputElement.h \
    htmlelement/VideoElement.h \
    htmlelement/TextElement.h \
    css/ElementCss.h \
    htmlelement/FormElement.h \
    htmlelement/BreakElement.h \
    page/templates/AbstractTemplatePage.h \
    page/templates/private/AbstractTemplatePage_p.h \
    page/model/AbstractModel.h \
    page/model/AbstractListModel.h \
    internationalisation/I18nManager.h \
    page/resource/AbstractResource.h \
    page/resource/private/AbstractResource_p.h \
    page/resource/ImageResource.h \
    website/WebSession.h \
    internationalisation/LanguageTexts.h \
    page/templates/AbstractTranslatableTemplate.h \
    page/templates/private/AbstractTranslatableTemplate_p.h \
    page/model/AbstractTranslatableModel.h \
    security/User.h \
    page/resource/DartResource.h \
    security/SecurityController.h \
    page/model/DirListModel.h \
    page/model/ImageModel.h \
    page/model/DirListMapModel.h \
    page/SecureContentInterface.h \
    security/Right.h \
    page/templates/tags/TagInterface.h \
    util/UserDataHelper.h \
    page/templates/tags/TemplateTag.h \
    page/templates/tags/TagRenderer.h \
    util/TemplateRenderHelper.h \
    page/templates/tags/private/TagInterfacePrivate.h \
    util/TemplateOutputHelper.h \
    util/InteractivePageHelper.h \
    page/templates/tags/IfTag.h \
    util/DomOutputHelper.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

INCLUDEPATH += $$PWD/../3rdparty/tufao/src
DEPENDPATH += $$PWD/../3rdparty/tufao/src

INCLUDEPATH += $$PWD/../../arangodb-driver/src
DEPENDPATH += $$PWD/../../arangodb-driver/src

CONFIG(release, debug|release) {
LIBS += -L$$PWD/../3rdparty/tufao-release/ -ltufao
LIBS += -L$$PWD/../3rdparty/Qt-Arango-DB-Driver-release/ -larangodb-driver
}
CONFIG(debug, debug|release) {
DEFINES += QT_WEBFRAMEWORK_DEBUG
LIBS += -L$$PWD/../3rdparty/tufao-debug/ -ltufao
LIBS += -L$$PWD/../3rdparty/Qt-Arango-DB-Driver-debug/ -larangodb-driver
}
