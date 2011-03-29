/***********************************************************************
 * Module:  MoteurRecherche.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class MoteurRecherche
 ***********************************************************************/

#ifndef MOTEURRECHERCHE_H
#define	MOTEURRECHERCHE_H

/*!
 * \file MoteurRecherche.h
 * \brief Moteur de recherche
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

/*! \class MoteurRecherche
  * \brief Classe MoteurRecherche :
  *
  *  Classe qui gere toutes les acces reseau commun a tous les moteurs de recherche.
  */

class MoteurRecherche : public QObject
{

Q_OBJECT

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe MoteurRecherche.
     */
   MoteurRecherche();
   /*!
    *  \brief Destructeur.
    *
    *  Destructeur de la classe MoteurRecherche.
    */
   ~MoteurRecherche();
   /*!
    *  \brief Retourne la page web.
    *
    *  \return le contenu de m_dom.
    */
   QString getDOM();
   /*!
    *  \brief Initialise la page web.
    *
    *  \param dom : nouvelle page web.
    */
   void setDOM(QString dom);
   /*!
    *  \brief Initialise le texte a tester.
    *
    *  \param dom : nouveau texte.
    */
   void setText(QString text);
   /*!
    *  \brief Retourne le texte a tester.
    *
    *  \return le contenu de m_text.
    */
   QString getText();
   /*!
    *  \brief Initialise l'url d'ou provient le texte.
    *
    *  \param url : nouvelle url.
    */
   void setUrl(QString url);
   /*!
    *  \brief Retourne l'url d'ou provient le texte.
    *
    *  \return le contenu de m_url.
    */
   QString getUrl();
   /*!
    *  \brief A reimplementer selon le moteur de recherche utilise.
    *
    *  Envoie la requete en tenant compte des specificites du moteur de recherche.
    */
   virtual void sendRequest();
   /*!
    *  \brief Traite la page web.
    *
    *  Verifie si le texte a ete plagier, et si oui recupere l'url d'ou provient le texte.
    *  \return true si le texte est plagie, false sinon.
    */
   bool traiterDOM();
   /*!
    *  \brief A reimplementer selon le moteur de recherche utilise.
    *
    *  Recupere l'url d'ou provient le texte plagie et la stocke dans m_url.
    */
   virtual void recupUrl();
   /*!
    *  \brief A reimplementer selon le moteur de recherche utilise.
    *
    *  Recherche dans m_dom si le texte est plagie.
    *  \return true si le texte est plagie, false sinon.
    */
   virtual bool rechercheText();
   /*!
    *  \brief Envoie une requete HTTP.
    *
    *  \param urlrequete : requete a envoyee.
    */
   void HttpRequest(QString urlrequete);

public slots :
   /*!
    *  \brief Slot pour une requete qui c'est terminer sans erreur.
    *
    *  Traite la reponse du serveur, et met le contenue de la page web dans m_dom.
    */
   void downloadFinish();
   /*!
    *  \brief Slot pour une requete qui c'est terminer avec une erreur.
    *
    *  \param QNetworkReply::NetworkError : Erreur de la requete.
    */
   void downloadError(QNetworkReply::NetworkError);

signals:
   /*!
    *  \brief Signal emit lorsque la requete est terminer et sans erreur.
    *
    *  \param idMoteurRecherche : ID du moteur de recherche d'ou provient la requete
    */
    void requetFini(int idMoteurRecherche);
    /*!
     *  \brief Signal emit lorsque la requete c'est terminer avec une erreur.
     *
     *  \param error : a true car il y a une erreur.
     *  \param errorString : Contenue de l'erreur du serveur.
     */
    void erreurRequet(bool error,QString errorString);

protected:
   QString m_DOM; /*!< Contenue de la page web*/
   QString m_text; /*!< Texte a tester*/
   QString m_url; /*!< Url d'ou provient le texte plagie*/
   int m_id; /*!< ID du moteur de recherche*/

};

#endif	/* MOTEURRECHERCHE_H */

