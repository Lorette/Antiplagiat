/***********************************************************************
 * Module:  Document.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Declaration of the class Document
 ***********************************************************************/

#ifndef DOCUMENT_H
#define	DOCUMENT_H

#include <QString>
#include "MoteurRecherche.h"
#include "Ihm.h"
#include "Google.h"
#include <QWidget>

class MoteurRecherche;
class Ihm;

class Document
{
    
public:
   Document();
   ~Document();
   QString getText();
   void setText();
   void setIhm(Ihm* interface);
   bool traiterDocument();

private:
   QString text;
   MoteurRecherche *m_moteurRecherche;
   Ihm *m_ihm;

};

#endif	/* DOCUMENT_H */

