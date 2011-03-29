/***********************************************************************
 * Module:  TextPdf.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Declaration of the class TextPdf
 ***********************************************************************/

#ifndef TEXTPDF_H
#define TEXTPDF_H

/*!
 * \file TextPdf.h
 * \brief Extension de fichier PDF
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
#include <QFile>
#include <QMessageBox>
#include <QProcess>
#include <QTextStream>
#include "extension.h"

class Extension;

/*! \class TextPdf
  * \brief Classe TextPdf :
  *
  *  Classe qui gere l'extraction de texte pour l'extension PDF.
  */

class TextPdf : public Extension
{

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe TextPdf.
     *  \param file : Nom du fichier.
     */
    TextPdf(QString file);
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe TextPdf.
     */
    ~TextPdf();
    /*!
     *  \brief Verifie si le fichier est valide, et extrait le texte du ficher.
     *
     *  \return true si le fichier est valide, false sinon.
     */
    bool fileIsValid();
    /*!
     *  \brief Retourne le texte contenue dans le fichier.
     *
     *  \return String contenant le texte du fichier.
     */
    QString getText();
    /*!
     *  \brief Retourne la liste des bouts de texte a tester, en fonction des preferences de l'utilisateur.
     *
     *  \param max_word : Nombre de mots par cible.
     *  \param tri_police : Active la selection par police a true.
     *  \param tri_size : Active la selection par taille a true.
     *  \return Liste de String contenant les textes a tester.
     */
    QStringList getCible(int max_word, bool tri_police, bool tri_size);

private:
    QString m_file; /*!< Nom du fichier*/
    QString m_text; /*!< Contenue texte du fichier*/

};

#endif // TEXTPDF_H
