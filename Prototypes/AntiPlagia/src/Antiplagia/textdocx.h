#ifndef TEXTDOCX_H
#define TEXTDOCX_H

#include <QString>
#include <QProcess>
#include <QDir>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QList>
#include <QMessageBox>
#include "xstring.h"

class TextDocx
{
public:
    TextDocx(QString file);
    ~TextDocx();
    bool decompress();
    void extract_Text();
    void tri();

private:
    void removeDir(QString dir);

private:
    QString m_file;
    QDomDocument *m_document;
    QList <XString *> m_textCibles;
};

#endif // TEXTDOCX_H
