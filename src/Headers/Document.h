/***********************************************************************
 * Module:  Document.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Declaration of the class Document
 ***********************************************************************/

#ifndef DOCUMENT_H
#define	DOCUMENT_H

/*!
 * \file Document.h
 * \brief Class pricipale.
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

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


/*! \class Document
  * \brief Classe Document :
  *
  *  Classe principal du logiciel qui gere et organise
  *  tout le traitement des taches a effectue.
  */

class Document : public QObject
{

Q_OBJECT

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe Document.
     *  \param interface : Interface de l'utilisateur
     */
   Document(Ihm* interface);
   /*!
    *  \brief Destructeur.
    *
    *  Destructeur de la classe Document.
    */
   ~Document();
   /*!
    *  \brief Retourne le texte du document.
    *
    *  \return QString contenant le texte.
    */
   QString getText();
   /*!
    *  \brief Initialise le texte du document.
    *
    *  \param text : Nouveau texte.
    */
   void setText(QString text);
   /*!
    *  \brief Traitement complet du document.
    *
    *  Recupere les information saisie par l'utilisateur depuis l'IHM,
    *  initialise toute les variable et object, détermine les cible puis
    *  envoie les requetes avec les differents moteur de recherche.
    */
   void traiterDocument();
   /*!
    *  \brief Traitement complet d'un dossier.
    *
    *  Fait appele a traiterDocument pour tout les fichier du dossier,
    *  puis enregistre le résultat au forma HTM.
    */
   void traiterDossier();
   /*!
    *  \brief Traite l'envoi le la prochaine requete.
    *
    *  pour un moteur de recherche
    *  \param idMoteurRecherche : Id du moteur de recherche
    */
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

