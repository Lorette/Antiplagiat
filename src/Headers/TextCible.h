/***********************************************************************
 * Module:  TextCible.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
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
     *  Constructeur de la classe ListTextCicble.
     */
    TextCible(QString text);
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe ListTextCicble.
     */
    ~TextCible();
    void setResult(bool plagier,QString url,int idMoteurRecherche = 0);
    QString getText();
    bool isPlagier();
    QString getUrl();

private:
    QString m_text;
    QStringList m_url;
    QList<bool> m_plagier;
    QList<int> m_IdMoteurRecherche;
};

#endif /* TEXTCIBLE_H */
