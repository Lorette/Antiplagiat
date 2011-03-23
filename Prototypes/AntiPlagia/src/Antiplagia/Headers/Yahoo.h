/***********************************************************************
 * Module:  Yahoo.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Declaration of the class Yahoo
 ***********************************************************************/

#ifndef YAHOO_H
#define YAHOO_H

#include "MoteurRecherche.h"
#include <QString>
#include <QUrl>

class MoteurRecherche;

class Yahoo : public MoteurRecherche
{

public:
    Yahoo();
    ~Yahoo();
    bool rechercheText();
    void sendRequest();
    void recupUrl();

};

#endif /* YAHOO_H */
