/***********************************************************************
 * Module:  Google.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Declaration of the class Google
 ***********************************************************************/

#ifndef GOOGLE_H
#define	GOOGLE_H

/*!
 * \file Google.h
 * \brief Moteur de recherche Google
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

/*! \class Google
  * \brief Classe Google :
  *
  *  Classe qui gere toutes les specificites du moteur de recherche Google.
  */

class Google : public MoteurRecherche
{
    
public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe Google.
     */
   Google();
   /*!
    *  \brief Destructeur.
    *
    *  Destructeur de la classe Google.
    */
   ~Google();
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
    *  Envoie la requete au serveur Google en tenant compte de ces specificites et stocke la page web dans m_dom.
    */
   void sendRequest();
   /*!
    *  \brief Recupere l'url.
    *
    *  Recupere l'url d'ou provient le texte plagie et la stocke dans m_url.
    */
   void recupUrl();

};

#endif	/* GOOGLE_H */

