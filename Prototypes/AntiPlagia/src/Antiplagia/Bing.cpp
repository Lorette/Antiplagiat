/***********************************************************************
 * Module:  Bing.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Implementation of the class Bing
 ***********************************************************************/

#include "Bing.h"


////////////////////////////////////////////////////////////////////////
// Name:       Bing::Bing()
// Purpose:    Implementation of Bing::Bing()
// Return:
////////////////////////////////////////////////////////////////////////

Bing::Bing() : MoteurRecherche()
{
    m_id=2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Bing::~Bing()
// Purpose:    Implementation of Bing::~Bing()
// Return:
////////////////////////////////////////////////////////////////////////

Bing::~Bing()
{
}


////////////////////////////////////////////////////////////////////////
// Name:       Bing::rechercheText()
// Purpose:    Implementation of Bing::rechercheText()
// Return:     boolean
////////////////////////////////////////////////////////////////////////



bool Bing::rechercheText()
{
    //m_DOM=m_DOM.QString::replace("&#39;","'");
    bool b = m_DOM.contains("<strong>"+m_text.toUtf8()+"</strong>",Qt::CaseInsensitive);
    return b;
}


////////////////////////////////////////////////////////////////////////
// Name:       Bing::sendRequest()
// Purpose:    Implementation of Bing::sendRequest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Bing::sendRequest()
{
    // Recupère la page web de la requette Bing et la met dans m_DOM
    HttpRequest("http://www.bing.com/search?q=\""+m_text+"\"");
}

////////////////////////////////////////////////////////////////////////
// Name:       Bing::recupUrl()
// Purpose:    Implementation of Bing::recupUrl()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Bing::recupUrl()
{
    int pos=m_DOM.indexOf("<strong>"+m_text.toUtf8()+"</strong>",0,Qt::CaseInsensitive);
    QString s(m_DOM);
    s.resize(pos);
    pos=0;
    while(pos != -1){
        pos=s.indexOf("<a",0,Qt::CaseInsensitive);
        s=s.right(s.size()-pos-2);
    }
    s=s.right(s.size()-6);
    pos=0;
    while(pos != -1){
        pos=s.indexOf("\"",0,Qt::CaseInsensitive);
        if (pos != -1 )s.resize(pos);
    }
    m_url=s;
}
