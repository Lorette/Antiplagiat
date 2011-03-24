/***********************************************************************
 * Module:  TextPdf.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Declaration of the class TextPdf
 ***********************************************************************/

#ifndef TEXTPDF_H
#define TEXTPDF_H

#include <QString>
#include <QStringList>
#include <QFile>
#include <QMessageBox>
#include <QProcess>
#include <QTextStream>
#include "Extension.h"

class Extension;

class TextPdf : public Extension
{

public:
    TextPdf(QString file);
    ~TextPdf();
    bool fileIsValid();
    QString getText();
    QStringList getCible(int max_word, bool tri_police, bool tri_size);

private:
    QString m_file;
    QString m_text;

};

#endif // TEXTPDF_H
