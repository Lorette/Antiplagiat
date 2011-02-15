/***********************************************************************
 * Module:  MoteurRecherche.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Implementation of the class MoteurRecherche
 ***********************************************************************/

#include "MoteurRecherche.h"


////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::MoteurRecherche()
// Purpose:    Implementation of MoteurRecherche::MoteurRecherche()
// Return:
////////////////////////////////////////////////////////////////////////

MoteurRecherche::MoteurRecherche()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::~MoteurRecherche()
// Purpose:    Implementation of MoteurRecherche::~MoteurRecherche()
// Return:
////////////////////////////////////////////////////////////////////////

MoteurRecherche::~MoteurRecherche()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::getDOM()
// Purpose:    Implementation of MoteurRecherche::getDOM()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString MoteurRecherche::getDOM()
{
   return m_DOM;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::setDOM(QFile file)
// Purpose:    Implementation of MoteurRecherche::setDOM()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::setDOM(QFile file)
{
    
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::sendRequest(QString text)
// Purpose:    Implementation of MoteurRecherche::sendRequest()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool MoteurRecherche::sendRequest(QString text)
{
    return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::traiterDOM(QString text)
// Purpose:    Implementation of MoteurRecherche::traiterDOM()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool MoteurRecherche::traiterDOM(QString text)
{
    return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::HttpRequest(QString requete)
// Purpose:    Implementation of MoteurRecherche::HttpRequest()
// Return:     QFile
////////////////////////////////////////////////////////////////////////

QFile MoteurRecherche::HttpRequest(QString requete)
{
}
