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
#include "ihm.h"
#include "Google.h"
#include "Yahoo.h"
#include "Bing.h"
#include "ListTextCicble.h"
#include "TextCible.h"
#include "textdocx.h"
#include <QWidget>
#include <QObject>
#include <QStringList>

class MoteurRecherche;
class Ihm;
class Google;
class Yahoo;
class ListTextCicble;
class TextCible;
class TextDocx;

class Document : public QObject
{

Q_OBJECT

public:
   Document(Ihm* interface);
   ~Document();
   QString getText();
   void setText(QString text);
   void traiterDocument();
   void traiterEnvoie(int idMoteurRecherche);
   void initialisation();
   void extractTextFile();
   void determinTextCible();
   bool textIsPlagier();
   bool setFile(QString file);
   QString getDocumentEnrichi();
   QString getUrlTextPlagier();
   void triTextFile();
   void determinDocxCible();

private:
   QString m_text;
   TextDocx *m_docx;
   int m_indiceCible[3];
   int m_nbRequet;
   int m_requet;
   ListTextCicble m_textCible;
   QList<MoteurRecherche*> m_moteurRecherche;
   Ihm *m_ihm;


public slots:
   void traiterReponse(int idMoteurRecherche);

signals:
    void traitementFini();
    void progress(int valeur,QString text = QString(""));

};

#endif	/* DOCUMENT_H */

