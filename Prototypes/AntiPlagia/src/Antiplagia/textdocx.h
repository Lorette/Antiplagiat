#ifndef TEXTDOCX_H
#define TEXTDOCX_H

#include <QString>

class TextDocx
{
public:
    TextDocx(QString file);
    int decompress();

private:
    QString m_file;
};

#endif // TEXTDOCX_H
