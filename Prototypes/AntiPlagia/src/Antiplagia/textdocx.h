#ifndef TEXTDOCX_H
#define TEXTDOCX_H

#include <QString>
#include <QProcess>
#include <QDir>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class TextDocx
{
public:
    TextDocx(QString file);
    ~TextDocx();
    bool decompress();

private:
    QString m_file;
    QDomDocument *m_document;
};

#endif // TEXTDOCX_H
