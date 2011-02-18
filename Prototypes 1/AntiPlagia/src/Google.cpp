/***********************************************************************
 * Module:  Google.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Implementation of the class Google
 ***********************************************************************/

#include "Google.h"


////////////////////////////////////////////////////////////////////////
// Name:       Google::Google()
// Purpose:    Implementation of Google::Google()
// Return:
////////////////////////////////////////////////////////////////////////

Google::Google() : MoteurRecherche()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Google::~Google()
// Purpose:    Implementation of Google::~Google()
// Return:
////////////////////////////////////////////////////////////////////////

Google::~Google()
{
}


////////////////////////////////////////////////////////////////////////
// Name:       Google::rechercheText()
// Purpose:    Implementation of Google::rechercheText()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool Google::rechercheText()
{
    //QMessageBox::critical(0, "Contenu DOM", m_DOM);
    bool b = m_DOM.contains("<em>"+m_text+"</em>",Qt::CaseInsensitive);
    return b;
}


////////////////////////////////////////////////////////////////////////
// Name:       Google::sendRequest()
// Purpose:    Implementation of Google::sendRequest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Google::sendRequest()
{
    // Recupère la page web de la requette google et la met dans m_DOM
    HttpRequest("http://www.google.fr/search?hl=fr&q=\""+m_text+"\"");
}


