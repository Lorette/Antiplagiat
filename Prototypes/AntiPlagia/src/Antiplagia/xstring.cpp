#include "xstring.h"

XString::XString()
{

}

XString::~XString()
{

}

XString::XString(QString string, QString police = "None", QString size = "") : m_text(string), m_police(police),m_size(size)
{
}

QString XString::toString()
{
    return m_text;
}

QString XString::get_m_police()
{
    return m_police;
}

QString XString::get_m_size()
{
    return m_size;
}

int XString::count_words()
{
    QStringList list = m_text.split(" ");
    return list.count();
}

void XString::setText(QString text)
{
    m_text = text;
}
