#include "textdocx.h"

TextDocx::TextDocx(QString file) : m_file(file)
{

}

TextDocx::~TextDocx()
{

}

bool TextDocx::decompress()
{
    m_document = new QDomDocument();

    if(!QDir().exists(".tmp"))
        QDir().mkdir(".tmp");
    if(!QFile().exists("miniunz.exe"))
        return false;

    QProcess::execute("miniunz.exe -o "+m_file +" -d .tmp");

    QFile file(".tmp/word/document.xml");

    if(!file.exists(".tmp/word/document.xml"))
        QMessageBox::information(0,"Faux","1");

    file.open(QFile::ReadOnly);
    m_document->setContent(&file);
    file.close();
    QDir().rmdir(".tmp"); // ? fonctionne pas (dossier en cours d'utilisation) ?
    QMessageBox::information(0,"jjkj",m_document->toString());

}
