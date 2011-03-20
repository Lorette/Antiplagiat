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

#ifdef _WIN32
#define EXE_UNZIP ("miniunz.exe")
#define L_EXE_UNZIP ("miniunz.exe")
#else
#define EXE_UNZIP ("miniunz")
#define L_EXE_UNZIP ("./miniunz")
#endif


class TextDocx
{
public:
    TextDocx(QString file);
    ~TextDocx();
    bool decompress();
    void extract_Text();
    void tri(int max_word = 10, bool tri_police = true, bool tri_size = true);
    QList <XString *> getList();
    QString getText();

private:
    void removeDir(QString dir);

private:
    QString m_file;
    QDomDocument *m_document;
    QList <XString *> m_textCibles;
};

#endif // TEXTDOCX_H
