/***********************************************************************
 * Module:  MoteurRecherche.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
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
  *  Classe qui gere toutes les acces reseau commun a tous les moteurs de recherche
  */

class MoteurRecherche : public QObject
{

Q_OBJECT

public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe MoteurRecherche
     */
   MoteurRecherche();
   /*!
    *  \brief Destructeur.
    *
    *  Destructeur de la classe MoteurRecherche
    */
   ~MoteurRecherche();
   /*!
    *  \brief Retourne la page web.
    *
    *  \return le contenu de m_dom.
    */
   QString getDOM();
   void setDOM(QString dom);
   void setText(QString text);
   QString getText();
   void setUrl(QString url);
   QString getUrl();
   virtual void sendRequest();
   bool traiterDOM();
   virtual void recupUrl();
   virtual bool rechercheText();
   void HttpRequest(QString urlrequete);

public slots :
   void downloadFinish();
   void downloadError(QNetworkReply::NetworkError);

signals:
    void requetFini(int idMoteurRecherche);
    void erreurRequet(bool error,QString errorString);

protected:
   QString m_DOM;
   QString m_text;
   QString m_url;
   int m_id;

};

#endif	/* MOTEURRECHERCHE_H */

