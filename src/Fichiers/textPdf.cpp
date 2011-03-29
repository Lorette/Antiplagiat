/***********************************************************************
 * Module:  TextPdf.cpp
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Implementation of the class TextPdf
 ***********************************************************************/


#include "textPdf.h"

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
    if(!QFile().exists(EXE_TTOPDF))
    {
        emit error(true,QObject::tr("Le programme nécessaire pour lire ce type de ficier est absent.\n\nVeuillez réinstaller l'application pour corriger le problème"));
        return false;
    }

    QProcess::execute(QString(EXE_TTOPDF) +" \""+m_file +"\" tmp.txt");

    QFile file("tmp.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        emit error(true,QObject::tr("Le fichier est endommagé ou d'un format inconnu. Impossible de continuer"));
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        m_text += in.readLine()+"\n";
    }
    file.close();
    file.remove("tmp.txt");

    if(m_text != "")
        return true;
    else{
        emit error(true,QObject::tr("Le fichier est endommagé ou d'un format inconnu. Impossible de continuer"));
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       TextPdf::getText()
// Purpose:    Implementation of TextPdf::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString TextPdf::getText()
{
    m_text.replace(QRegExp(" +")," ");
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
