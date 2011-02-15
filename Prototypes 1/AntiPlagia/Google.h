/***********************************************************************
 * Module:  Google.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Declaration of the class Google
 ***********************************************************************/

#ifndef GOOGLE_H
#define	GOOGLE_H

#include <MoteurRecherche.h>
#include <QString>
#include <QFile>

class Google : public MoteurRecherche
{
    
public:
   Google();
   ~Google();
   bool rechercheText(QString text);
   bool traiterDOM(QString text);
   QFile HttpRequest(QString requete);
   bool sendRequest(QString text);


};

#endif	/* GOOGLE_H */

