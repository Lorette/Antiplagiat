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
#include <QObject>

class MoteurRecherche;
class Ihm;
class Google;

class Document : public QObject
{

Q_OBJECT

public:
   Document();
   ~Document();
   QString getText();
   void setText();
   void setIhm(Ihm* interface);
   void traiterDocument();

private:
   QString m_text;
   Google *m_moteurRecherche;
   Ihm *m_ihm;

public slots:
   void traiterReponse(bool error,QString errorString);

};

#endif	/* DOCUMENT_H */

