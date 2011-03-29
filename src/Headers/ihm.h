/***********************************************************************
 * Module:  Ihm.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class Ihm
 ***********************************************************************/

#ifndef IHM_H
#define IHM_H

/*!
 * \file ihm.h
 * \brief Interface Homme Machine
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QWebView>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTranslator>
#include "document.h"
#include "ihmPopup.h"
#include "settings.h"

namespace Ui {
    class Ihm;
}
class Document;
class IhmPopup;
class Settings;

/*! \class Ihm
  * \brief Classe Ihm :
  *
  *  Classe maitresse, interface avec l'utilisateur.
  */

class Ihm : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe Ihm.
     *  \param parent : pointeur sur le widget parent
     */
    explicit Ihm(QWidget *parent = 0);
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe Extension.
     */
    ~Ihm();
    /*!
     *  \brief Recupere la phrase dans le cas d'une entree par phrase.
     *
     *  \return la phrase.
     */
    QString getText();
    /*!
     *  \brief Recupere le nom du fichier dans le cas d'une entree par fichier.
     *
     *  \return le nom du fichier.
     */
    QString getNameFile();
    /*!
     *  \brief Recupere le texte dans le cas d'une entree par paragraphe.
     *
     *  \return le texte.
     */
    QString getDocument();
    /*!
     *  \brief Recupere le nom du dossier dans le cas d'une entree par dossier.
     *
     *  \return le nom du fichier.
     */
    QString getDir();
    /*!
     *  \brief Recupere l'onglet utilise.
     *
     *  \return l'id de la methode d'entree utilise.
     */
    int focusTab();
    /*!
     *  \brief Active/Desactive l'interaction utilisateur.
     *
     *  \param b : true pour activer, false pour desactiver.
     */
    void enabelDisabel(bool b);
    /*!
     *  \brief Verifie les conditions necessaires au lancement de la recherche.
     *
     *  \return true si il y'a des erreurs, false si il n'y en a pas.
     */
    bool erreurChamp();
    /*!
     *  \brief Verifie si un moteur de recherche est selectionne.
     *
     *  \param idMoteurRecherche : identifiant du moteur de recherche
     *  \return true si il est selectionne, false sinon.
     */
    bool isSelect(int idMoteurRecherche);
    /*!
     *  \brief Recupere le nombre de mots envoye par requete.
     *
     *  \return le nombre de mot.
     */
    int getNbMots();
    /*!
     *  \brief Verifie la selection par taille.
     *
     *  \return true si active, false sinon.
     */
    bool getParTaille();
    /*!
     *  \brief Verifie la selection par police.
     *
     *  \return true si active, false sinon.
     */
    bool getParPolice();
    /*!
     *  \brief Recupere le pourcentage de document a tester.
     *
     *  \return le pourcentage.
     */
    int getPrCentATester();
    /*!
     *  \brief Recupere le nombre maximum de requete.
     *
     *  \return le nombre maximum de requete.
     */
    int nbMaxRequete();

public slots:
    /*!
     *  \brief Slot pour lancer le traitement.
     *
     *  Enclenche le processus de tri et envoie les requetes.
     */
    void traitement();
    /*!
     *  \brief Slot pour afficher les informations sur le programme.
     *
     *  Ouvre une nouvelle fenetre affichant les informations sur le programme.
     */
    void aPropos();
    /*!
     *  \brief Slot pour afficher les options.
     *
     *  Ouvre une nouvelle fenetre affichant les preferences configurables par l'utilisateur.
     */
    void preference();
    /*!
     *  \brief Slot pour afficher la documentation.
     *
     *  Ouvre une nouvelle fenetre affichant la documentation technique.
     */
    void documentation();
    /*!
     *  \brief Slot pour selectionner un fichier.
     *
     *  Ouvre une nouvelle fenetre permettant de selectionner un fichier.
     */
    void selectFile();
    /*!
     *  \brief Slot pour selectionner un dossier.
     *
     *  Ouvre une nouvelle fenetre permettant de selectionner un dossier.
     */
    void selectDir();
    /*!
     *  \brief Slot pour afficher un resultat.
     *
     *  Affiche un resultat d'operation : erreur ou non.
     */
    void result(bool error = false , QString errorString = QString());
    /*!
     *  \brief Slot pour arreter le traitement.
     *
     *  Stoppe le traitement en cours.
     */
    void annulerTraitement();
    /*!
     *  \brief Slot de traduction Francais.
     *
     */
    void traductionFr();
    /*!
     *  \brief Slot de traduction Anglais.
     *
     */
    void traductionEn();
    /*!
     *  \brief Slot de traduction Allemand.
     *
     */
    void traductionDe();
    /*!
     *  \brief Slot de traduction Espagnol.
     *
     */
    void traductionEs();
    /*!
     *  \brief Slot de traduction Italien.
     *
     */
    void traductionIt();
    /*!
     *  \brief Slot de traduction Arabe.
     *
     */
    void traductionAr();
    void changeEvent(QEvent *event);

private:
    Ui::Ihm *ui; /*!< Interface de la classe*/
    Document *m_document; /*!< Instance de Document associee*/
    IhmPopup *m_popup; /*!< Instance de la popup de progression*/
    Settings *m_settings; /*!< Instance de la fenetre de preferences*/

};

#endif /* IHM_H */
