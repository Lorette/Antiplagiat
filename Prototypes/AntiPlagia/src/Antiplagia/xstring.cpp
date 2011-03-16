#include "xstring.h"

XString::XString(QString string, QString police = "None", int size = 0) : QString(string), m_police(police),m_size(size)
{
}
