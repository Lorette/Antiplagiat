#ifndef TEXTDOCX_H
#define TEXTDOCX_H

#include <QString>
#include <stdio.h>
#include <assert.h>

#include "includes/zlib/zlib.h"

class TextDocx
{
public:
    TextDocx(QString file);
    int decompress();

private:
    QString m_file;
};

#endif // TEXTDOCX_H
