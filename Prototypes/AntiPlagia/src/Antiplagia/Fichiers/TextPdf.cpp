/***********************************************************************
 * Module:  TextPdf.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Implementation of the class TextPdf
 ***********************************************************************/


#include "TextPdf.h"

////////////////////////////////////////////////////////////////////////
// Name:       TextPdf::TextPdf()
// Purpose:    Implementation of TextPdf::TextPdf()
// Return:
////////////////////////////////////////////////////////////////////////

TextPdf::TextPdf(QString file)
{
    m_file = file;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextPdf::~TextPdf()
// Purpose:    Implementation of TextPdf::~TextPdf()
// Return:
////////////////////////////////////////////////////////////////////////

TextPdf::~TextPdf()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       TextPdf::fileIsValid()
// Purpose:    Implementation of TextPdf::fileIsValid()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool TextPdf::fileIsValid()
{
    if(!QFile().exists("pdftotext.exe"))
    {
        QMessageBox::warning(0,"Fichier manquant","Le programme nécessaire pour lire ce type de ficier est absent.\n\nVeuillez réinstaller l'application pour corriger le problème");
        return false;
    }

    QProcess::execute("pdftotext.exe -eol dos \""+m_file +"\" tmp.txt");

    QFile file("tmp.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        m_text += in.readLine()+"\n";
    }
    file.close();
    file.remove("tmp.txt");

    if(m_text != "")
        return true;
    else
        return false;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextPdf::getText()
// Purpose:    Implementation of TextPdf::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString TextPdf::getText()
{
    return m_text;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextPdf::getCible(int max_word, bool tri_police, bool tri_size)
// Purpose:    Implementation of TextPdf::getCible()
// Return:     QStringList
////////////////////////////////////////////////////////////////////////

QStringList TextPdf::getCible(int max_word, bool tri_police, bool tri_size)
{
    QStringList list = m_text.split(".");
    QStringList listFinal;
    QStringList list2;
    int n;
    QString s;

    for(int i=0;i<list.size();i++){
        list2=(list[i]).split(" ");
        n=list2.size()/max_word;
        for(int j=0;j < n ;j++){
            s="";
            for(int h=0;h<max_word;h++)
                s += list2[j*max_word+h]+" ";
            listFinal << s;

        }
        list2.clear();
    }

    return listFinal;
}
