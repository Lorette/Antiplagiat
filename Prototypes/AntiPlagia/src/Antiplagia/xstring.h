#ifndef XSTRING_H
#define XSTRING_H

#include <QString>

class XString : public QString
{

public:
    XString(QString string, QString police, int size);

private:
    QString text;
    QString m_police;
    int m_size;
};

#endif // XSTRING_H
