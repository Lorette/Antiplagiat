/***********************************************************************
 * Module:  xstring.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class XString
 ***********************************************************************/

#ifndef XSTRING_H
#define XSTRING_H

/*!
 * \file xstring.h
 * \brief String ameliore.
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

/*! \class XString
  * \brief Classe XString :
  *
  *  String qui prend en compte la police et la taille d'un texte.
  */

class XString
{

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe XString.
     */
    XString();
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe XString.
     */
    ~XString();
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe XString.
     *  \param string : texte brut.
     *  \param police : police du texte.
     *  \param size : taille du texte.
     */
    XString(QString string, QString police = "None", QString size = "None");
    /*!
     *  \brief Retourne la police du texte.
     *
     *  \return QString contenant le nom de la police.
     */
    QString get_m_police();
    /*!
     *  \brief Retourne la taille du texte.
     *
     *  \return QString contenant la taile du texte.
     */
    QString get_m_size();
    /*!
     *  \brief Retourne le texte.
     *
     *  \return QString contenant le texte.
     */
    QString toString();
    /*!
     *  \brief Initialise le texte.
     *
     *  \param texte : Nouveau texte.
     */
    void setText(QString text);
    /*!
     *  \brief Retourne le nombre de mots du texte.
     *
     *  \return Nombre de mots.
     */
    int count_words();

private:
    QString m_text; /*!< Texte brut*/
    QString m_police; /*!< Police du texte*/
    QString m_size; /*!< Taille du texte*/
};

#endif // XSTRING_H
