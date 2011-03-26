/***********************************************************************
 * Module:  TextOdt.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Implementation of the class TextOdt
 ***********************************************************************/

#include "textodt.h"

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::TextOdt()
// Purpose:    Implementation of TextOdt::TextOdt()
// Return:
////////////////////////////////////////////////////////////////////////

TextOdt::TextOdt(QString file) : m_file(file)
{
    m_document = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::~TextOdt()
// Purpose:    Implementation of TextOdt::~TextOdt()
// Return:
////////////////////////////////////////////////////////////////////////

TextOdt::~TextOdt()
{
    if(m_document != NULL) delete m_document;
    removeDir("tmp");
    for(int i=0; i < m_textCibles.size();i++)
        delete m_textCibles[i];
}

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::fileIsValid()
// Purpose:    Implementation of TextOdt::fileIsValid()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool TextOdt::fileIsValid()
{
    return decompress();
}

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::getText()
// Purpose:    Implementation of TextOdt::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString TextOdt::getText()
{
    QString s="";
    QDomNodeList node = m_document->elementsByTagName("office:text");
    QDomNodeList node2;

    for(int i=0;i<node.size();i++){
        node2 = node.item(i).childNodes();//toDocument().elementsByTagName("w:r");
        for(int j = 0; j< node2.size();j++)
            s+=node2.item(j).firstChildElement("text:span").text();
        s+="<br/>";
    }

    return s;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::getCible(int max_word, bool tri_police, bool tri_size)
// Purpose:    Implementation of TextOdt::getCible()
// Return:     QStringList
////////////////////////////////////////////////////////////////////////

QStringList TextOdt::getCible(int max_word, bool tri_police, bool tri_size)
{
    for(int i=0; i < m_textCibles.size();i++)
        delete m_textCibles[i];
    m_textCibles.clear();
    extract_Text();
    tri(max_word,tri_police,tri_size);

    QStringList cible;

    for(int i=0; i < m_textCibles.size();i++)
        cible << m_textCibles[i]->toString();

    return cible;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::decompress()
// Purpose:    Implementation of TextOdt::decompress()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool TextOdt::decompress()
{
    m_document = new QDomDocument();

    if(!QFile().exists(EXE_UNZIP))
    {
        QMessageBox::warning(0,"Fichier manquant","Le programme nécessaire pour lire ce type de ficier est absent.\n\nVeuillez réinstaller l'application pour corriger le problème");
        return false;
    }

    if(!QDir().exists("tmp"))
        QDir().mkdir("tmp");

    QProcess::execute(QString(L_EXE_UNZIP) +" -o \""+m_file +"\" -d tmp");

    QFile file("tmp/content.xml");

    if(!file.exists("tmp/content.xml"))
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

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::removeDir(QString dir)
// Purpose:    Implementation of TextOdt::removeDir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void TextOdt::removeDir(QString dir)
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

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::extract_Text()
// Purpose:    Implementation of TextOdt::extract_Text()
// Return:     void
////////////////////////////////////////////////////////////////////////

void TextOdt::extract_Text()
{
    XString *x_string = NULL;
    QDomNodeList node = m_document->elementsByTagName("text:p");

    for(unsigned int i = 0; i< node.length();i++)
    {
        if(node.item(i).firstChildElement("text:span").text() != "")
        {
            x_string = new XString(node.item(i).firstChildElement("text:span").text());
            m_textCibles << x_string;
        }
    }

    // Pour tester
    //for(int i = 0;i<m_textCibles.count();i++)
        //QMessageBox::information(0,"hhh",m_textCibles.at(i)->toString());
}

////////////////////////////////////////////////////////////////////////
// Name:       TextOdt::tri(int max_word, bool tri_police, bool tri_size)
// Purpose:    Implementation of TextOdt::tri()
// Return:     void
////////////////////////////////////////////////////////////////////////

void TextOdt::tri(int max_word, bool tri_police, bool tri_size)
{
    int tri_ = 0;
    (tri_police == true) ? tri_++ : tri_;
    (tri_size == true) ? tri_++ : tri_;

    int tri;
    QList <XString *> textCibles;
    XString aux;
    QString text = "";
    QStringList list;

    for(int i = 0;i < m_textCibles.count();i++)
    {
        if(text.count() != 0)
        {
            tri = 0;
            if(tri_police && aux.get_m_police() == m_textCibles.at(i)->get_m_police())
                tri++;
            if(tri_size && aux.get_m_size() == m_textCibles.at(i)->get_m_size())
                tri++;

            if(tri == tri_)
            {
                m_textCibles.at(i)->setText(text +m_textCibles.at(i)->toString());
                text = "";
            }

        }

        if(text.count() != 0)
        {
            textCibles << new XString(text,aux.get_m_police(),aux.get_m_size());
            text = "";
        }

        aux = *m_textCibles.at(i);
        list = aux.toString().split(" ");

        while(list.count() > 0)
        {

            text = text + list.takeFirst()+" ";
            if(text.split(" ").count() > max_word)
            {
                textCibles << new XString(text,m_textCibles.at(i)->get_m_police(),m_textCibles.at(i)->get_m_size());
                text = "";
            }
        }
    }
    textCibles << new XString(text,aux.get_m_police(),aux.get_m_size());

    m_textCibles = textCibles;

}


