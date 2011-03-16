#include "xstring.h"

XString::XString()
{

}

XString::~XString()
{

}

XString::XString(QString string, QString police = "None", QString size = 0) : text(string), m_police(police),m_size(size)
{
}

QString XString::toString()
{
    return text;
}

QString XString::get_m_police()
{
    return m_police;
}

QString XString::get_m_size()
{
    return m_size;
}
