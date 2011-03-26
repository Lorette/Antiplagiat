/***********************************************************************
 * Module:  Bing.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Declaration of the class Bing
 ***********************************************************************/

#ifndef BING_H
#define BING_H

/*!
 * \file Bing.h
 * \brief Moteur de recherche Bing
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include "MoteurRecherche.h"
#include <QString>
#include <QUrl>

class MoteurRecherche;

/*! \class Bing
  * \brief Classe Bing :
  *
  *  Classe qui gere toutes les specificites du moteur de recherche Bing
  */

class Bing : public MoteurRecherche
{

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe Bing
     */
    Bing();
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe Bing
     */
    ~Bing();
    /*!
     *  \brief Recherche si le texte est plagie.
     *
     *  Recherche dans m_dom si le texte est plagie.
     *  \return true si le texte est plagie, false sinon.
     */
    bool rechercheText();
    /*!
     *  \brief Envoie la requete.
     *
     *  Envoie la requete au serveur Bing en tenant compte de ces specificites et stocke la page web dans m_dom.
     */
    void sendRequest();
    /*!
     *  \brief Recupere l'url.
     *
     *  Recupere l'url d'ou provient le texte plagie et la stocke dans m_url.
     */
    void recupUrl();
};

#endif /* BING_H */
