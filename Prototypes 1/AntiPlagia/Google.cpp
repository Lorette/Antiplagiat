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

Google::Google()
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
// Name:       Google::rechercheText(QString text)
// Purpose:    Implementation of Google::rechercheText()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool Google::rechercheText(QString text)
{
    return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       Google::traiterDOM(QString text)
// Purpose:    Implementation of Google::traiterDOM()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool Google::traiterDOM(QString text)
{
    bool b=rechercheText(text);
    return b;
}

////////////////////////////////////////////////////////////////////////
// Name:       Google::HttpRequest(QString requete)
// Purpose:    Implementation of Google::HttpRequest()
// Return:     QFile
////////////////////////////////////////////////////////////////////////

QFile Google::HttpRequest(QString requete)
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Google::sendRequest(QString text)
// Purpose:    Implementation of Google::sendRequest()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool Google::sendRequest(QString text)
{
    HttpRequest("http://www.google.fr/search?hl=fr&q=%22"+text+"%22");
    return true;
}
