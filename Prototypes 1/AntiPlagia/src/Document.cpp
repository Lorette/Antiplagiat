/***********************************************************************
 * Module:  Document.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Implementation of the class Document
 ***********************************************************************/


#include "Document.h"


////////////////////////////////////////////////////////////////////////
// Name:       Document::Document()
// Purpose:    Implementation of Document::Document()
// Return:
////////////////////////////////////////////////////////////////////////

Document::Document(Ihm* interface) : QObject()
{
    m_moteurRecherche = new Google();
    m_ihm = interface;

    // Quand la requete est terminer, execute traiterReponse
    QObject::connect(m_moteurRecherche, SIGNAL(requetFini(int)), this, SLOT(traiterReponse(int)));
    // Quand le traitement est fini
    QObject::connect(this, SIGNAL(traitementFini()), m_ihm, SLOT(result()));
    // Si il y a une erreur lors de la requete
    QObject::connect(m_moteurRecherche, SIGNAL(erreurRequet(bool,QString)), m_ihm, SLOT(result(bool,QString)));
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::~Document()
// Purpose:    Implementation of Document::~Document()
// Return:
////////////////////////////////////////////////////////////////////////

Document::~Document()
{
       delete m_moteurRecherche;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getText()
// Purpose:    Implementation of Document::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getText()
{
   return m_text;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::setText(QString text)
// Purpose:    Implementation of Document::setText()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::setText(QString text)
{
   m_text = text;
}


////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterDocument()
// Purpose:    Implementation of Document::traiterDocument()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterDocument()
{
    // Récupere les donné de l'ihm
    initialisation();
    // traite l'envoi la 1er requete
    traiterEnvoie();

}

////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterEnvoie()
// Purpose:    Implementation of Document::traiterEnvoie()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterEnvoie()
{
    m_indiceCible++;
    if(m_indiceCible == m_textCible.size()) // Toute les requete on été traiter
        emit traitementFini();//signal de fin
    else{
        //QMessageBox::critical(0, "Erreur", QString::number(5+m_indiceCible/m_textCible.size()*90));
        if(m_ihm->focusTab() != 1)
            emit progress(5+(int)((float)m_indiceCible/(float)m_textCible.size()*90),"Envoi des requetes... "+QString::number(m_indiceCible)+"/"+QString::number(m_textCible.size()));
        m_moteurRecherche->setText(m_textCible[m_indiceCible].getText());
        // Envoi la requette
        m_moteurRecherche->sendRequest();
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterReponse(bool error,QString errorString)
// Purpose:    Implementation of Document::traiterReponse()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterReponse(int idMoteurRecherche)
{
        // Détermine si le texte est plagier
        bool b=m_moteurRecherche->traiterDOM();
        // Stock le résulta
        m_textCible[m_indiceCible].setResult(b,m_moteurRecherche->getUrl(),idMoteurRecherche);
        // Passe a la requete suivante
        traiterEnvoie();
}


////////////////////////////////////////////////////////////////////////
// Name:       Document::initialisation()
// Purpose:    Implementation of Document::initialisation()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::initialisation()
{
    m_textCible.clear();
    m_text="";
    m_indiceCible=-1;
    int focus=m_ihm->focusTab();
    if(focus == 1){//Par texte
        m_text=m_ihm->getText();
        m_textCible << TextCible(m_text.trimmed());
    }
    else{
        emit progress(0,"Selection des texts cible...");
        if(focus == 2) // Par document
            m_text=m_ihm->getDocument();
        else  // Par fichier
            extractTextFile();
        determinTextCible();
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::extractTextFile()
// Purpose:    Implementation of Document::extractTextFile()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::extractTextFile()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::determinTextCible()
// Purpose:    Implementation of Document::determinTextCible()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::determinTextCible()
{/*
    QStringList list = m_text.split(".");
    for(int i=0;i < list.size();i++)
        m_textCible << TextCible(list[i]);*/

        QStringList list = m_text.split(".");
        QStringList listFinal;
        QStringList list2;
        int n;
        QString s;

        for(int i=0;i<list.size();i++){
            list2=(list[i]).split(" ");
            n=list2.size()/10;
            for(int j=0;j < n ;j++){
                s="";
                for(int h=0;h<10;h++)
                    s+=list2[j*10+h]+" ";
                listFinal << s;
            }/*
            s="";
            for(int h=(10*n);h<list2.size();h++)
                s+=list2[h]+" ";
            listFinal << s;*/
            list2.clear();
        }

        for(int i=0;i < listFinal.size();i++){
            m_textCible << TextCible((listFinal[i]).trimmed());
        }
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::textIsPlagier()
// Purpose:    Implementation of Document::textIsPlagier()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Document::textIsPlagier()
{
    return m_textCible[0].isPlagier();
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getUrlTextPlagier()
// Purpose:    Implementation of Document::getUrlTextPlagier()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getUrlTextPlagier()
{
    return m_textCible[0].getUrl();
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getTextEnrichi()
// Purpose:    Implementation of Document::getTextEnrichi()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getDocumentEnrichi(){
    QString doc=m_text;
    emit progress(95,"Traitement des résultats... ");
    for(int i=0;i<m_textCible.size();i++)
        if(m_textCible[i].isPlagier())
            doc.replace(m_textCible[i].getText(),"<a style=\"text-decoration:none;background:yellow;color:black;\" href=\""+m_textCible[i].getUrl()+"\" >"+m_textCible[i].getText()+"</a>");
    return doc;
}


