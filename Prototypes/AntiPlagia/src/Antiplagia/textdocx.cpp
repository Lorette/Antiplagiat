#include "textdocx.h"

TextDocx::TextDocx(QString file) : m_file(file)
{
    m_document = NULL;
    if(decompress())
        extract_Text();

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
    QString text = "";
    XString *x_string = NULL;
    QDomNodeList node = m_document->elementsByTagName("w:r");

    for(unsigned int i = 0; i< node.length();i++)
    {
        if(node.item(i).firstChildElement("w:t").text() != "")
        {
            if(x_string != NULL)
            {
                text = x_string->toString() + " ";
                delete x_string;
            }

            x_string = new XString(text +(node.item(i).firstChildElement("w:t").text()),node.item(i).firstChildElement("w:rPr").firstChildElement("w:rFonts").attribute("w:hAnsi"),node.item(i).firstChildElement("w:rPr").firstChildElement("w:sz").attribute("w:val"));
        }

        if(x_string != NULL && x_string->toString().size() > 10)
        {
            m_textCibles << x_string;
            x_string = NULL;
            text = "";
        }

    }

    // Pour tester
    for(int i = 0;i<m_textCibles.count();i++)
        QMessageBox::information(0,"hhh",m_textCibles.at(i)->toString());
}
