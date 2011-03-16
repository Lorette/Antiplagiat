#include "textdocx.h"

TextDocx::TextDocx(QString file) : m_file(file)
{
    m_document = NULL;
}

TextDocx::~TextDocx()
{
    if(m_document != NULL) delete m_document;
    removeDir("tmp");
}

bool TextDocx::decompress()
{
    m_document = new QDomDocument();

    if(!QFile().exists("miniunz.exe"))
    {
        QMessageBox::warning(0,"Fichier manquant","Le programme nécessaire pour lire ce type de ficier est absent.\n\nVeuillez réinstaller l'application pour corriger le problème");
        return false;
    }

    if(!QDir().exists("tmp"))
        QDir().mkdir("tmp");

    QProcess::execute("miniunz.exe -o \""+m_file +"\" -d tmp");

    QFile file("tmp/word/document.xml");

    if(!file.exists("tmp/word/document.xml"))
    {
        QMessageBox::information(0,"Fichier incorrect","Le fichier est endommagé ou d'un format inconnu. Impossible de continuer");
        return false;
    }
    file.open(QFile::ReadOnly);
    m_document->setContent(&file);
    file.close();
    removeDir("tmp");
    return true;
}

void TextDocx::removeDir(QString dir)
{
    {
        QDir dossier(dir);
        QFileInfoList listElem = dossier.entryInfoList(QDir::AllEntries);

        for(int i=2; i<listElem.size(); i++)
        {
            QFileInfo fi(listElem.at(i));

            if(fi.isFile())
                QFile().remove(fi.filePath());

            else if(fi.isDir())
            {
                removeDir(fi.filePath());
                QDir().rmdir(fi.filePath());
            }

        }

        QDir().rmdir(dossier.absolutePath());
    }
}

void TextDocx::extract_Text()
{

}
