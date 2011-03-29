/***********************************************************************
 * Module:  IhmPopup.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class IhmPopup
 ***********************************************************************/


#ifndef IHMPOPUP_H
#define IHMPOPUP_H

/*!
 * \file IhmPopup.h
 * \brief IHM de resultat.
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QWidget>
#include <QFileDialog>
#include "ui_progress.h"
#include "ui_resultat.h"

/*! \class IhmPopup
  * \brief Classe IhmPopup :
  *
  *  Classe qui gere l'affichage des resultats.
  */

class IhmPopup : public QWidget
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe IhmPopup.
     *  \param parent : Widget parent.
     */
    explicit IhmPopup(QWidget *parent = 0);
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe IhmPopup.
     */
    ~IhmPopup();
    /*!
     *  \brief Initialise l'affichage de la barre de progression.
     *
     */
    void startDL();
    /*!
     *  \brief Affiche une fenetre contenant le resultat du traitement.
     *
     *  \param text1 : texte enrichie avec couleur simple.
     *  \param text2 : texte enrichie avec couleur multiple.
     *  \param listSource : texte enrichie contenant toutes les sources.
     *  \param nbSource : Nombres de sources differentes.
     *  \param prCenPlagier : Pourcentage du texte plagie.
     */
    void result(QString text1,QString text2,QString listSource,int nbSource,int prCenPlagier);

public slots:
    /*!
     *  \brief Slot pour modifier la barre de progression.
     *
     *  \param valeur : Pourcentage de progression.
     *  \param text : texte afficher en bas de la bare de progression.
     */
    void progressDL(int valeur,QString text);
    /*!
     *  \brief Slot pour annuler le traitement en cours.
     *
     */
    void clickAnnuler();
    /*!
     *  \brief Slot pour changer le mode de couleur du texte.
     *
     */
    void changeMode();
    /*!
     *  \brief Slot pour exporter le resultat en HTML.
     *
     */
    void clickExportHtml();
    void changeEvent(QEvent *event);

signals:
    /*!
     *  \brief Signal emit lorsque l'utilisateur click sur le boutton pour annuler le traitement.
     *
     */
    void annuler();
    /*!
     *  \brief Signal emit lorsque l'utilisateur veut exporter le resultat en HTML.
     *
     *  \param file : Nom du ficher HTML;
     */
    void exportHtml(QString file);

private:
    Ui::Progress *ui; /*!< Formulaire pour la bare de progression*/
    Ui::Resultat *ui2; /*!< Formulaire pour le resultat du traitement*/
    QString m_text1; /*!< Texte enrichie avec une couleur*/
    QString m_text2; /*!< Texte enrichie avec plusieur couleurs*/
    int m_idText; /*!< Texte enrichie actuelement afficher*/

};

#endif /* IHMPOPUP_H */
