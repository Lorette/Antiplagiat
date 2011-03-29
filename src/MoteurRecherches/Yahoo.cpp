/***********************************************************************
 * Module:  Yahoo.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Implementation of the class Yahoo
 ***********************************************************************/

#include "yahoo.h"


////////////////////////////////////////////////////////////////////////
// Name:       Yahoo::Yahoo()
// Purpose:    Implementation of Yahoo::Yahoo()
// Return:
////////////////////////////////////////////////////////////////////////

Yahoo::Yahoo() : MoteurRecherche()
{
    m_id=1;
}

////////////////////////////////////////////////////////////////////////
// Name:       Yahoo::~Yahoo()
// Purpose:    Implementation of Yahoo::~Yahoo()
// Return:
////////////////////////////////////////////////////////////////////////

Yahoo::~Yahoo()
{
}


////////////////////////////////////////////////////////////////////////
// Name:       Yahoo::rechercheText()
// Purpose:    Implementation of Yahoo::rechercheText()
// Return:     boolean
////////////////////////////////////////////////////////////////////////



bool Yahoo::rechercheText()
{
    bool b = m_DOM.contains("<b>"+m_text.toUtf8()+"</b>",Qt::CaseInsensitive);
    return b;
}


////////////////////////////////////////////////////////////////////////
// Name:       Yahoo::sendRequest()
// Purpose:    Implementation of Yahoo::sendRequest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Yahoo::sendRequest()
{
    // Recupère la page web de la requette Yahoo et la met dans m_DOM
    HttpRequest("http://fr.search.yahoo.com/search?p=\""+m_text+"\"");
}

////////////////////////////////////////////////////////////////////////
// Name:       Yahoo::recupUrl()
// Purpose:    Implementation of Yahoo::recupUrl()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Yahoo::recupUrl()
{
    int pos=m_DOM.indexOf("<b>"+m_text.toUtf8()+"</b>",0,Qt::CaseInsensitive);
    QString s(m_DOM);
    s.resize(pos);
    pos=0;
    while(pos != -1){
        pos=s.indexOf("<a",0,Qt::CaseInsensitive);
        s=s.right(s.size()-pos-2);
    }
    pos=s.indexOf("href",0,Qt::CaseInsensitive);
    s=s.right(s.size()-pos-6);

    pos=s.indexOf("\"",0,Qt::CaseInsensitive);
    s.resize(pos);

    pos=0;
    while(pos != -1){
        pos=s.indexOf("http",0,Qt::CaseInsensitive);
        if (pos != -1 )s=s.right(s.size()-pos-7);
    }
    m_url="http:"+s;
}
