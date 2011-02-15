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

Document::Document()
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
   return text;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::setText()
// Purpose:    Implementation of Document::setText()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::setText()
{
   text = m_ihm->getText();
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
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool Document::traiterDocument()
{
    m_moteurRecherche = new Google();
    setText();
    bool b = false;
    if(m_moteurRecherche->sendRequest(getText()))
        b=m_moteurRecherche->traiterDOM(getText());
    return b;
}
