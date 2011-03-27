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
    *  Verifie si le moteur de recherche qui a terminer
    *  sa derniere requete a fini, et si il na pas fini effectue
    *  sa prochaine requete.
    *  \param idMoteurRecherche : Id du moteur de recherche qui a fini sa derniere requete.
    */
   void traiterEnvoie(int idMoteurRecherche);
   /*!
    *  \brief Initialise les varaible, object et détermine les cible.
    *
    */
   void initialisation();
   /*!
    *  \brief Détermine les bouts de texte a teste pour la section "Par paragraphe".
    *
    *  Détermine les cibles en fonction du nombres de mots pour chaque cible.
    *  \param nbMots : Nombre de mots par cible.
    */
   void determinTextCible(int nbMots);
   /*!
    *  \brief Pour la section "Par phrase" determine si cette phrase est plagie.
    *
    *  \return true si elle est plagie, false sinon.
    */
   bool textIsPlagier();
   /*!
    *  \brief Initialise le fichier a traiter, et teste si il est valide.
    *
    *  \param file : Nom du fichier.
    *  \return true si le fichier est valide, false sinon.
    */
   bool setFile(QString file);
   /*!
    *  \brief Retourne le document enrichie avec du HTML/CSS.
    *
    *  Retourne le document enrichie pour afficher en coleur les bouts de texte plagie.
    *  \param mode : 1 pour une seul couleur, 2 pour une couleur differente pour chaque source.
    *  \return QString contenant le texte enrichie..
    */
   QString getDocumentEnrichi(int mode);
   /*!
    *  \brief Pour la section "Par phrase" retourne l'URL d'ou provient le texte.
    *
    *  \return QString contenant l'URL.
    */
   QString getUrlTextPlagier();
   /*!
    *  \brief Détermine les bouts de texte a teste pour la section "Par Document" et "Par Dossier".
    *
    *  Détermine les cibles en fonction du nombres de mots, de la police et de la taille pour chaque cible.
    *  \param nbMots : Nombre de mots par cible.
    *  \param tri_police : Active la selection par police a true.
    *  \param tri_size : Active la selection par taille a true.
    */
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

