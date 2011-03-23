/***********************************************************************
 * Module:  textodt.h
 * Author:  fabien
 * Modified: vendredi 20 mars 2011 19:37:28
 * Purpose: Declaration of the class TextOdt
 ***********************************************************************/

#ifndef TEXTODT_H
#define TEXTODT_H

#include <QString>
#include <QProcess>
#include <QDir>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QList>
#include <QStringList>
#include <QMessageBox>
#include "xstring.h"
#include "Extension.h"

#ifdef _WIN32
#define EXE_UNZIP ("miniunz.exe")
#define L_EXE_UNZIP ("miniunz.exe")
#else
#define EXE_UNZIP ("miniunz")
#define L_EXE_UNZIP ("./miniunz")
#endif

class Extension;


class TextOdt : public Extension
{
public:
    TextOdt(QString file);
    ~TextOdt();
    bool decompress();
    void extract_Text();
    void tri(int max_word = 10, bool tri_police = true, bool tri_size = true);
    bool fileIsValid();
    QString getText();
    QStringList getCible();

private:
    void removeDir(QString dir);

private:
    QString m_file;
    QDomDocument *m_document;
    QList <XString *> m_textCibles;
};

#endif // TEXTODT_H
