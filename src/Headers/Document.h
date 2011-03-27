/***********************************************************************
 * Module:  Document.h
 * Author:  fabien
 * Modified: vendredi 11 fevrier 2011 16:33:13
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
    *  initialise toute les variable et object, determine les cible puis
    *  envoie les requetes avec les differents moteur de recherche.
    */
   void traiterDocument();
   /*!
    *  \brief Traitement complet d'un dossier.
    *
    *  Fait appele a traiterDocument pour tout les fichier du dossier,
    *  puis enregistre le resultat au forma HTM.
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
    *  \brief Initialise les varaible, object et determine les cible.
    *
    */
   void initialisation();
   /*!
    *  \brief Determine les bouts de texte a teste pour la section "Par paragraphe".
    *
    *  Determine les cibles en fonction du nombres de mots pour chaque cible.
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
    *  \brief Determine les bouts de texte a tester pour la section "Par Document" et "Par Dossier".
    *
    *  Determine les cibles en fonction du nombres de mots, de la police et de la taille pour chaque cible.
    *  \param nbMots : Nombre de mots par cible.
    *  \param tri_police : Active la selection par police a true.
    *  \param tri_size : Active la selection par taille a true.
    */
   void determinTextCibleFile(int nbMots, bool tri_police, bool tri_size);
   /*!
    *  \brief Renvoi une liste de toute des sources pour le document.
    *
    *  Determine les sources du document par comparaison avec toutes les sources des requetes envoyees.
    *  \param source : source du document.
    *  \return la liste des sources unifies.
    */
   QList<MemeSource> getMemeSource(QString source);
   /*!
    *  \brief Determine le nombre de sources du document.
    *
    *  Determine le nombre de source uniques du document.
    *  \return le nombre de source.
    */
   int getNbSource();
   /*!
    *  \brief Determine le pourcentage du document plagie.
    *
    *  Calcul le pourcentage de texte plagie dans le document courant.
    *  \return le pourcentage de texte plagie.
    */
   int getPrCentPlagier();
   /*!
    *  \brief Recupere la liste de toute les sources.
    *
    *  Renvoie la liste de toutes les sources uniques ou non.
    *  \return toutes les sources du document.
    */
   QString getListSource();
   /*!
    *  \brief Adapte le nombre de cible.
    *
    *  Adapte le nombre de cibles a tester en fonction des options du programme.
    *  \param prCent : le pourcetage de document a tester
    *  \param maxReq : le nombre maximum de requete autorisees
    *  \param nbMotsParTest : nombre de mots par requete
    */
   void adaptNbCible(int prCent,int maxReq,int nbMotsParTest);
   /*!
    *  \brief Traite le dossier pour la section "Par Dossier".
    *
    *  Parcours le dossier et traite chaque fichier rencontre.
    */
   void traiterEnvoieDossier();

private:
   QString m_text; /*!< Texte du document*/
   Extension *m_file; /*!< Fichier a traiter*/
   int m_indiceCible[3]; /*!< Indice de texte cible courant par moteur de recherche*/
   int m_nbRequet; /*!< Nombre de requete totale*/
   int m_requet; /*!< Requete courante*/
   bool m_annuler; /*!< Action a annuler*/
   ListTextCicble m_textCible; /*!< Liste de tout les textes a traiter*/
   QList<MoteurRecherche*> m_moteurRecherche; /*!< Liste des moteurs de recherches*/
   Ihm *m_ihm; /*!< Interface homme machine associee*/
   QDir m_dir; /*!< Dossier a traiter*/
   QStringList m_listFile; /*!< Liste de tout les fichiers dans le dossier*/
   int m_indiceListFile; /*!< Iterateur de liste pour m_listFile*/


public slots:
   /*!
    *  \brief Slot de traitement.
    *
    *  Traite la reponse du moteur de recherche donne.
    *  \param idMoteurRecherche : identifiant moteur de rec<herche
    */
   void traiterReponse(int idMoteurRecherche);
   /*!
    *  \brief Slot d'Annulation.
    *
    *  Stop toutes les actions entreprises
    */
   void annulerTraitement();
   /*!
    *  \brief Slot d'export en HTML.
    *
    *  Exporte en html le resultat dans un fichier "file"
    *  \param file : nom du fichier
    */
   void exportHtml(QString file);

signals:
    /*!
     *  \brief Signal emit lorsque le traitement est fini.
     */
    void traitementFini();
    /*!
     *  \brief Signal emit lorsque la progression du traitement avance.
     *
     *  \param valeur : valeur de progression
     *  \param text : texte associe a la valeur de progression
     */
    void progress(int valeur,QString text = QString(""));

};

#endif	/* DOCUMENT_H */

