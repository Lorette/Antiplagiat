/***********************************************************************
 * Module:  textodt.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class TextOdt
 ***********************************************************************/

#ifndef TEXTODT_H
#define TEXTODT_H

/*!
 * \file textodt.h
 * \brief Extension de fichier ODT
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QString>
#include <QProcess>
#include <QDir>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QList>
#include <QStringList>
#include <QMessageBox>
#include "xstring.h"
#include "extension.h"

#ifdef _WIN32
#define EXE_UNZIP ("miniunz.exe")
#define L_EXE_UNZIP ("miniunz.exe")
#else
#define EXE_UNZIP ("miniunz")
#define L_EXE_UNZIP ("./miniunz")
#endif

class Extension;

/*! \class TextOdt
  * \brief Classe TextOdt :
  *
  *  Classe qui gere l'extraction de texte pour l'extension ODT.
  */

class TextOdt : public Extension
{
public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe TextOdt.
     *  \param file : Nom du fichier.
     */
    TextOdt(QString file);
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe TextOdt.
     */
    ~TextOdt();
    /*!
     *  \brief Decompresse l'archive ODT.
     *
     *  Decompresse l'archive ODT et verifie si le fichier content.xml est present.
     *  \return true si le fichier content.xml est present, false sinon.
     */
    bool decompress();
    /*!
     *  \brief Extrait le texte du fichier content.xml est le place dans des XString.
     *
     */
    void extract_Text();
    /*!
     *  \brief Trie le fichier content.xml en recuperant le texte en fonction des preferences de l'utilisateur.
     *
     *  \param max_word : Nombre de mots par cible.
     *  \param tri_police : Active le tri par police a true.
     *  \param tri_size : Active le tri par taille a true.
     */
    void tri(int max_word = 10, bool tri_police = true, bool tri_size = true);
    /*!
     *  \brief Verifie si le fichier est valide, et extrait le fichier xml de l'archive.
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
    /*!
     *  \brief Supprime recursivement un dossier.
     *
     *  \param dir : Dossier a supprimer.
     */
    void removeDir(QString dir);

private:
    QString m_file; /*!< Nom du fichier*/
    QDomDocument *m_document; /*!< Conternu du document.xml*/
    QList <XString *> m_textCibles; /*!< Contenu texte du ficher avec sa police et sa taille*/
};

#endif // TEXTODT_H
