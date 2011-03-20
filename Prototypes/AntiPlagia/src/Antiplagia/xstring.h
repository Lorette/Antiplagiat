/***********************************************************************
 * Module:  xstring.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Declaration of the class XString
 ***********************************************************************/

#ifndef XSTRING_H
#define XSTRING_H

#include <QString>
#include <QStringList>

class XString
{

public:
    XString();
    ~XString();
    XString(QString string, QString police, QString size);
    QString get_m_police();
    QString get_m_size();
    QString toString();
    void setText(QString text);
    int count_words();

private:
    QString m_text;
    QString m_police;
    QString m_size;
};

#endif // XSTRING_H
