/***********************************************************************
 * Module:  Settings.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Declaration of the class Settings
 ***********************************************************************/

#ifndef SETTINGS_H
#define SETTINGS_H


/*!
 * \file Settings.h
 * \brief Gere les configuration
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QWidget>
#include <QSettings>

namespace Ui {
    class Settings;
}


/*! \class Settings
  * \brief Classe Settings :
  *
  *  Classe graphique qui gere toutes les preferences de l'utilisateur et les enregistre avec la class QStrings.
  */

class Settings : public QWidget
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe Settings.
     *  \param parent : pointeur sur le widget parent
     */
    explicit Settings(QWidget *parent = 0);
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe Settings.
     */
    ~Settings();
    /*!
     *  \brief Ecrit les preferences.
     *
     *  Ecrit les preferences de l'utilisateur dans QSettings("Lorette Inc", "Anti-Plagia")
     */
    void writeSettings();
    /*!
     *  \brief Recupere les preferences.
     *
     *  Recupere les preferences de l'utilisateur de QSettings("Lorette Inc", "Anti-Plagia")
     */
    void readSettings();
    /*!
     *  \brief Retourne le nombre de mots.
     *
     *  Methode qui retourne le nombres de mots d'un teste.
     *  \return Le nombre de mots saisie.
     */
    int getNbMots();
    /*!
     *  \brief Retourne le choix de l'utilisateur pour la selection par taille.
     *
     *  Methode qui retourne le choix de l'utilisateur pour la selection par taille lors du choix des bouts de texte a tester.
     *  \return true si l'utilisateur veut le prendre en compte, false sinon.
     */
    bool getParTaille();
    /*!
     *  \brief Retourne le choix de l'utilisateur pour la selection par police.
     *
     *  Methode qui retourne le choix de l'utilisateur pour la selection par police lors du choix des bouts de texte a tester.
     *  \return true si l'utilisateur veut le prendre en compte, false sinon.
     */
    bool getParPolice();
    /*!
     *  \brief Retourne le pourcentage du texte a tester.
     *
     *  \return nombre entre 10 et 100.
     */
    int getPrCentATester();
    /*!
     *  \brief Retourne le nombre de requete maximum.
     *
     *  \return 0 pour un nombre illimite, le nombre sinon.
     */
    int nbMaxRequete();
    /*!
     *  \brief Redefinie la fermeture de la fenetre.
     *
     *  Lors de la fermeture de la fenetre, les preferences sont enregistre.
     *  \param event : Event de fermeture de Qt
     */
    void closeEvent(QCloseEvent *event);

public slots:
    /*!
     *  \brief Slot pour le boutton fermer.
     *
     *  Lors de la fermeture de la fenetre, les preferences sont enregistre.
     */
    void click_close();

private:
    Ui::Settings *ui; /*!< Formulaire de l'affichage*/
};

#endif // SETTINGS_H
