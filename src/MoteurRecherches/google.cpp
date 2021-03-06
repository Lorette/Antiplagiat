/***********************************************************************
 * Module:  Google.cpp
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Implementation of the class Google
 ***********************************************************************/

#include "google.h"


////////////////////////////////////////////////////////////////////////
// Name:       Google::Google()
// Purpose:    Implementation of Google::Google()
// Return:
////////////////////////////////////////////////////////////////////////

Google::Google() : MoteurRecherche()
{
    m_id=0;
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
    m_DOM=m_DOM.QString::replace("&#39;","'");
    bool b = m_DOM.contains("<em>"+m_text.toUtf8()+"</em>",Qt::CaseInsensitive);
    return b;
}


////////////////////////////////////////////////////////////////////////
// Name:       Google::sendRequest()
// Purpose:    Implementation of Google::sendRequest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Google::sendRequest()
{
    // Recup�re la page web de la requette google et la met dans m_DOM
    HttpRequest("http://www.google.fr/search?hl=fr&q=\""+m_text+"\"");
}

////////////////////////////////////////////////////////////////////////
// Name:       Google::recupUrl()
// Purpose:    Implementation of Google::recupUrl()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Google::recupUrl()
{
    int pos=m_DOM.indexOf("<em>"+m_text.toUtf8()+"</em>",0,Qt::CaseInsensitive);
    QString s(m_DOM);
    s.resize(pos);
    pos=0;
    while(pos != -1){
        pos=s.indexOf("<a",0,Qt::CaseInsensitive);
        s=s.right(s.size()-pos-2);
    }
    s=s.right(s.size()-6);

    pos=s.indexOf("\"",0,Qt::CaseInsensitive);
    s.resize(pos);

    m_url=s;
}
