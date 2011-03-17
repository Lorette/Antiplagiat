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
    XString *x_string = NULL;
    QDomNodeList node = m_document->elementsByTagName("w:r");

    for(unsigned int i = 0; i< node.length();i++)
    {
        if(node.item(i).firstChildElement("w:t").text() != "")
        {
            x_string = new XString(node.item(i).firstChildElement("w:t").text(),node.item(i).firstChildElement("w:rPr").firstChildElement("w:rFonts").attribute("w:hAnsi"),node.item(i).firstChildElement("w:rPr").firstChildElement("w:sz").attribute("w:val"));
            m_textCibles << x_string;
        }
    }

    // Pour tester
    //for(int i = 0;i<m_textCibles.count();i++)
        //QMessageBox::information(0,"hhh",m_textCibles.at(i)->toString());
    tri();
}

void TextDocx::tri()
{
    QList <XString *> textCibles;
    XString aux;
    QString text = "";
    QStringList list;

    for(int i = 0;i < m_textCibles.count();i++)
    {
        if(text.count() != 0 && aux.get_m_police() == m_textCibles.at(i)->get_m_police() && aux.get_m_size() == m_textCibles.at(i)->get_m_size())
        {
            m_textCibles.at(i)->setText(text +m_textCibles.at(i)->toString());
            text = "";
        }
        else if(text.count() != 0)
        {
            textCibles << new XString(text,aux.get_m_police(),aux.get_m_size());
            text = "";
        }
        aux = *m_textCibles.at(i);
        list = aux.toString().split(" ");

        while(list.count() > 0)
        {

            text = text + list.takeFirst()+" ";
            if(text.split(" ").count() > 10)
            {
                textCibles << new XString(text,m_textCibles.at(i)->get_m_police(),m_textCibles.at(i)->get_m_size());
                text = "";
            }
        }
    }
    textCibles << new XString(text,aux.get_m_police(),aux.get_m_size());

    m_textCibles = textCibles;
}
