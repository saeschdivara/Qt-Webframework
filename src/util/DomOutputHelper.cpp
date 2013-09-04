/********************************************************************************
 ** The MIT License (MIT)
 **
 ** Copyright (c) 2013 Sascha Ludwig Häusler
 **
 ** Permission is hereby granted, free of charge, to any person obtaining a copy of
 ** this software and associated documentation files (the "Software"), to deal in
 ** the Software without restriction, including without limitation the rights to
 ** use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 ** the Software, and to permit persons to whom the Software is furnished to do so,
 ** subject to the following conditions:
 **
 ** The above copyright notice and this permission notice shall be included in all
 ** copies or substantial portions of the Software.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 ** FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 ** COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 ** IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 ** CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *********************************************************************************/

#include "DomOutputHelper.h"

namespace web
{
namespace util
{

QString DomOutputHelper::subElementsToString(QDomElement ele)
{
    QString subElementsString;

    QDomNodeList childNodes = ele.childNodes();
    const int total = childNodes.size();
    for (int i = 0; i < total; ++i) {
        QDomNode node = childNodes.at(i);
        if ( !node.isElement() ) continue;

        QDomElement childElement = node.toElement();
        if ( i == 0 ) {
            subElementsString = elementToString(childElement);
        }
        else {
            subElementsString += QChar('\n') + elementToString(childElement);
        }
    }

    return subElementsString;
}

QString DomOutputHelper::elementToString(QDomElement ele)
{
    QString elementString("<%1 %2>%3</%1>");
    QString subElementsString;

    QString attributesString = elementAttributesToString(ele.attributes());

    QDomNodeList childNodes = ele.childNodes();
    const int total = childNodes.size();
    for (int i = 0; i < total; ++i) {
        QDomNode node = childNodes.at(i);
        if ( node.isElement() ) {
            QDomElement childElement = node.toElement();

            if ( i == 0 ) {
                subElementsString = elementToString(childElement);
            }
            else {
                subElementsString += QChar('\n') + elementToString(childElement);
            }
        }
        else if ( node.isText() ) {
            QDomText textElement = node.toText();

            if ( i == 0 ) {
                subElementsString = textElementToString(textElement);
            }
            else {
                subElementsString += QChar('\n') + textElementToString(textElement);
            }
        }
    }

    return elementString.arg(ele.tagName(), attributesString, subElementsString);
}

QString DomOutputHelper::textElementToString(QDomText text)
{
    //
}

QString DomOutputHelper::elementAttributesToString(QDomNamedNodeMap attributes)
{
    QString attributesString;
    const int total = attributes.size();
    for (int i = 0; i < total; ++i) {
        QDomNode node = attributes.item(i);
        if ( i == 0 ) {
            attributesString = attributeToString(node);
        }
        else {
            attributesString += QChar(' ') + attributeToString(node);
        }
    }

    return attributesString;
}

QString DomOutputHelper::attributeToString(QDomNode attrNode)
{
    QString attributeString("%1=\"%2\"");
    QDomAttr attribute = attrNode.toAttr();
    return attributeString.arg(attribute.name(), attribute.value());
}

}
}