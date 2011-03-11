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
#include "ListTextCicble.h"
#include "TextCible.h"
#include <QWidget>
#include <QObject>
#include <QStringList>

class MoteurRecherche;
class Ihm;
class Google;
class ListTextCicble;
class TextCible;

class Document : public QObject
{

Q_OBJECT

public:
   Document(Ihm* interface);
   ~Document();
   QString getText();
   void setText(QString text);
   void traiterDocument();
   void traiterEnvoie();
   void initialisation();
   void extractTextFile();
   void determinTextCible();
   bool textIsPlagier();
   QString getDocumentEnrichi();
   QString getUrlTextPlagier();

private:
   QString m_text;
   int m_indiceCible;
   ListTextCicble m_textCible;
   MoteurRecherche *m_moteurRecherche;
   Ihm *m_ihm;

public slots:
   void traiterReponse(int idMoteurRecherche);

signals:
    void traitementFini();
    void progress(int valeur,QString text = QString(""));

};

#endif	/* DOCUMENT_H */

