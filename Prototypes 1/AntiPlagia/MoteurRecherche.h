/***********************************************************************
 * Module:  MoteurRecherche.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Declaration of the class MoteurRecherche
 ***********************************************************************/

#ifndef MOTEURRECHERCHE_H
#define	MOTEURRECHERCHE_H

#include <QString>
#include <QFile>

class MoteurRecherche
{

public:
   MoteurRecherche();
   ~MoteurRecherche();
   QString getDOM();
   void setDOM(QFile file);
   bool sendRequest(QString text);
   bool traiterDOM(QString text);
   QFile HttpRequest(QString requete);

private:
   QString m_DOM;

};

#endif	/* MOTEURRECHERCHE_H */

