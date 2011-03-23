/***********************************************************************
 * Module:  Bing.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Declaration of the class Bing
 ***********************************************************************/

#ifndef BING_H
#define BING_H

#include "MoteurRecherche.h"
#include <QString>
#include <QUrl>

class MoteurRecherche;

class Bing : public MoteurRecherche
{

public:
    Bing();
    ~Bing();
    bool rechercheText();
    void sendRequest();
    void recupUrl();
};

#endif /* BING_H */
