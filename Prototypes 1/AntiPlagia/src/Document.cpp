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
    indiceCible++;
    if(indiceCible == m_textCible.size()) // Toute les requete on été traiter
        emit traitementFini();//signal de fin
    else{
        m_moteurRecherche->setText(m_textCible[indiceCible].getText());
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
        m_textCible[indiceCible].setResult(b,m_moteurRecherche->getUrl(),idMoteurRecherche);
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
    indiceCible=-1;
    int focus=m_ihm->focusTab();
    if(focus == 1){//Par texte
        m_text=m_ihm->getText();
        m_textCible << TextCible(m_text);
    }
    else{
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
{
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

