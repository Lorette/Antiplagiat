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

Document::Document() : QObject()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::~Document()
// Purpose:    Implementation of Document::~Document()
// Return:
////////////////////////////////////////////////////////////////////////

Document::~Document()
{
   delete m_ihm;
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
// Name:       Document::setText()
// Purpose:    Implementation of Document::setText()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::setText()
{
   m_text = m_ihm->getText();
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::setIhm(Ihm* interface)
// Purpose:    Implementation of Document:setIhm()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::setIhm(Ihm* interface)
{
   m_ihm = interface;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterDocument()
// Purpose:    Implementation of Document::traiterDocument()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterDocument()
{
    // Initialiser les varriables et objets
    m_moteurRecherche = new Google();
    setText();
    m_moteurRecherche->setText(m_text);
    QObject::connect(m_moteurRecherche, SIGNAL(requetFini(bool,QString)), this, SLOT(traiterReponse(bool,QString)));
    // Envoi la requette est si elle c'est bien dérouler elle traite la réponse
    m_moteurRecherche->sendRequest();
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterReponse(bool error,QString errorString)
// Purpose:    Implementation of Document::traiterReponse()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterReponse(bool error,QString errorString){

    if(!error){
        bool b=m_moteurRecherche->traiterDOM();
        m_ihm->result(b,m_moteurRecherche->getUrl());
    }
    else
        QMessageBox::critical(0, "Erreur", "Erreur lors du chargement. Vérifiez votre connexion internet ou réessayez plus tard <br /><br /> Code de l'erreur : <br /><em>" + errorString + "</em>");
}
