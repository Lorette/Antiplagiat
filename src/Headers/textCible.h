/***********************************************************************
 * Module:  TextCible.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class TextCible
 ***********************************************************************/

#ifndef TEXTCIBLE_H
#define TEXTCIBLE_H

/*!
 * \file TextCible.h
 * \brief Textes Cibles a tester.
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>

/*! \class TextCible
  * \brief Classe TextCible :
  *
  *  Classe qui gere et stocke le resultat des testes de plagiat.
  */

class TextCible
{
public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe TextCible.
     *  \param text : Texte cible a tester.
     */
    TextCible(QString text);
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe TextCible.
     */
    ~TextCible();
    /*!
     *  \brief Ajoute le résultat d'un moteur de recherche.
     *
     *  \param plagier : A true si le texte est plagier.
     *  \param url : Url d'ou provient le plagia.
     *  \param idMoteurRecherche : ID du Moteur de recherche qui ajout le resultat.
     */
    void setResult(bool plagier,QString url,int idMoteurRecherche = 0);
    /*!
     *  \brief Retourne le texte a tester.
     *
     *  \return QString contenant le texte.
     */
    QString getText();
    /*!
     *  \brief Determine d'apres l'ensemble des resultat, si le texte est plagie.
     *
     *  \return true si le texte est plagie, false sinon.
     */
    bool isPlagier();
    /*!
     *  \brief Retourne l'ULR d'ou provient le texte.
     *
     *  Si il y a plusieur URL, l'url retourne provient du moteur de recherche qui a le plus petit ID.
     *  \return QString contenan l'url.
     */
    QString getUrl();

private:
    QString m_text; /*!< Texte a tester*/
    QStringList m_url; /*!< List des url d'ou provient le texte*/
    QList<bool> m_plagier; /*!< List du resultat des teste qui determine si le texte est plagie*/
    QList<int> m_IdMoteurRecherche; /*!< List des ID des moteur de recherche ayant ajouter un resultat*/
};

#endif /* TEXTCIBLE_H */
