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
#include "TextPdf.h"
#include "textodt.h"
#include <QWidget>
#include <QObject>
#include <QStringList>
#include <QtGlobal>

class MoteurRecherche;
class Ihm;
class Google;
class Yahoo;
class ListTextCicble;
class TextCible;
class Extension;
class TextDocx;
class TextPdf;
class TextOdt;

/**
 * \struct MemeSource
 * \brief Structure MemeSource :
 *
 * Structure utilise pour recupere un ensemble de texte ayant la
 * meme url comme source de plagia, puis stocker sa position
 * dans une liste.
 */
typedef struct MemeSource MemeSource;
struct MemeSource
{
    int position; /*!< Position dans la liste*/
    QString text; /*!< Texte plagie provenant de la meme source*/
};


class Document : public QObject
{

Q_OBJECT

public:
   Document(Ihm* interface);
   ~Document();
   QString getText();
   void setText(QString text);
   void traiterDocument();
   void traiterDossier();
   void traiterEnvoie(int idMoteurRecherche);
   void initialisation();
   void determinTextCible(int nbMots);
   bool textIsPlagier();
   bool setFile(QString file);
   QString getDocumentEnrichi(int mode);
   QString getUrlTextPlagier();
   void determinTextCibleFile(int nbMots, bool tri_police, bool tri_size);
   QList<MemeSource> getMemeSource(QString source);
   int getNbSource();
   int getPrCentPlagier();
   QString getListSource();
   void adaptNbCible(int prCent,int maxReq,int nbMotsParTest);
   void traiterEnvoieDossier();

private:
   QString m_text;
   Extension *m_file;
   int m_indiceCible[3];
   int m_nbRequet;
   int m_requet;
   bool m_annuler;
   ListTextCicble m_textCible;
   QList<MoteurRecherche*> m_moteurRecherche;
   Ihm *m_ihm;
   QDir m_dir;
   QStringList m_listFile;
   int m_indiceListFile;


public slots:
   void traiterReponse(int idMoteurRecherche);
   void annulerTraitement();
   void exportHtml(QString file);

signals:
    void traitementFini();
    void progress(int valeur,QString text = QString(""));

};

#endif	/* DOCUMENT_H */

