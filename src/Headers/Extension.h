/***********************************************************************
 * Module:  Extension.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class Extension
 ***********************************************************************/

#ifndef EXTENSION_H
#define EXTENSION_H

/*!
 * \file Extension.h
 * \brief Extension de fichier
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QString>
#include <QStringList>
#include <QObject>

/*! \class Extension
  * \brief Classe Extension :
  *
  *  Classe qui uniformise la gestion des extensions avec 3 methodes a reimplementer.
  */

class Extension : public QObject
{

Q_OBJECT

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe Extension.
     */
    Extension();
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe Extension.
     */
    ~Extension();
    /*!
     *  \brief A reimplementer selon le moteur de recherche utilise.
     *
     *  Verifie si le fichier est valide, et extrait le texte du ficher.
     *  \return true si le fichier est valide, false sinon.
     */
    virtual bool fileIsValid();
    /*!
     *  \brief A reimplementer selon le moteur de recherche utilise.
     *
     *  Retourne le texte contenue dans le fichier.
     *  \return String contenant le texte du fichier.
     */
    virtual QString getText();
    /*!
     *  \brief A reimplementer selon le moteur de recherche utilise.
     *
     *  Retourne la liste des bouts de texte a tester, en fonction des preferences de l'utilisateur.
     *  \param max_word : Nombre de mots par cible.
     *  \param tri_police : Active la selection par police a true.
     *  \param tri_size : Active la selection par taille a true.
     *  \return Liste de String contenant les textes a tester.
     */
    virtual QStringList getCible(int max_word, bool tri_police, bool tri_size);

signals:
    /*!
     *  \brief Signal emit lorsque le fichier est invalide.
     *
     *  \param error : a true car il y a une erreur.
     *  \param errorString : Contenue de l'erreur de l'extraction du texte du fichier.
     */
    void error(bool error,QString errorString);

};

#endif // EXTENSION_H
