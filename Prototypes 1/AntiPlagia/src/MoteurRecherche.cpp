/***********************************************************************
 * Module:  MoteurRecherche.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Implementation of the class MoteurRecherche
 ***********************************************************************/

#include "MoteurRecherche.h"

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::MoteurRecherche()
// Purpose:    Implementation of MoteurRecherche::MoteurRecherche()
// Return:
////////////////////////////////////////////////////////////////////////

MoteurRecherche::MoteurRecherche() : QObject()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::~MoteurRecherche()
// Purpose:    Implementation of MoteurRecherche::~MoteurRecherche()
// Return:
////////////////////////////////////////////////////////////////////////

MoteurRecherche::~MoteurRecherche()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::getDOM()
// Purpose:    Implementation of MoteurRecherche::getDOM()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString MoteurRecherche::getDOM()
{
   return m_DOM;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::setDOM(QString dom)
// Purpose:    Implementation of MoteurRecherche::setDOM()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::setDOM(QString dom)
{
    m_DOM=dom;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::setText(QString text)
// Purpose:    Implementation of MoteurRecherche::setText()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::setText(QString text)
{
    m_text=text;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::getText()
// Purpose:    Implementation of MoteurRecherche::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString MoteurRecherche::getText()
{
    return m_text;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::setUrl(QString url)
// Purpose:    Implementation of MoteurRecherche::setUrl()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::setUrl(QString url)
{
    m_url=url;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::getUrl()
// Purpose:    Implementation of MoteurRecherche::getUrl()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString MoteurRecherche::getUrl()
{
    return m_url;
}


////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::sendRequest()
// Purpose:    Implementation of MoteurRecherche::sendRequest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::sendRequest()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::recupUrl()
// Purpose:    Implementation of MoteurRecherche::recupUrl()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::recupUrl()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::traiterDOM()
// Purpose:    Implementation of MoteurRecherche::traiterDOM()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

bool MoteurRecherche::traiterDOM()
{
    setUrl("");
    bool b = rechercheText();
    if ( b )
        recupUrl();// recupere l'url d'ou vien le plagia
    return b;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::rechercheText()
// Purpose:    Implementation of MoteurRecherche::rechercheText()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool MoteurRecherche::rechercheText()
{
    return false;
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::HttpRequest(QString urlrequete)
// Purpose:    Implementation of MoteurRecherche::HttpRequest()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::HttpRequest(QString urlrequete)
{
    const QUrl url = QUrl(urlrequete); //On récupère l'URL entrée par l'utilisateur.
    QNetworkRequest requete(url); //On crée notre requête
    QNetworkAccessManager *m = new QNetworkAccessManager;
    requete.setRawHeader("Charset","utf-8;");
    requete.setRawHeader("Accept-Charset","iso-8859-1,utf-8;q=0.7,*;q=0.7");
    QNetworkReply *r = m->get(requete);
    connect(r, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(downloadError(QNetworkReply::NetworkError)));
    connect(r, SIGNAL(finished()), this, SLOT(downloadFinish()));

}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::downloadFinish()
// Purpose:    Implementation of MoteurRecherche::downloadFinish()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::downloadFinish()
{
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender()); //On récupère la réponse du serveur

    if (!r->error()){

        m_DOM=r->readAll();//On lit la réponse du serveur que l'on met dans m_DOM
        r->deleteLater(); //Supprime la réponse.

        emit requetFini(m_id);
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::downloadError(QNetworkReply::NetworkError)
// Purpose:    Implementation of MoteurRecherche::downloadError()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::downloadError(QNetworkReply::NetworkError){
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    emit erreurRequet(true,"Erreur lors du chargement. Vérifiez votre connexion internet ou réessayez plus tard <br /><br /> Code de l'erreur : <br /><em>" + r->errorString()+"</em>");
}
