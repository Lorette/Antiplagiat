/***********************************************************************
 * Module:  MoteurRecherche.cpp
 * Author:  fabien
 * Modified: vendredi 11 f�vrier 2011 16:44:15
 * Purpose: Implementation of the class MoteurRecherche
 ***********************************************************************/

#include "MoteurRecherche.h"
#include "ihm.h"

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::MoteurRecherche()
// Purpose:    Implementation of MoteurRecherche::MoteurRecherche()
// Return:
////////////////////////////////////////////////////////////////////////

MoteurRecherche::MoteurRecherche()
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
// Name:       MoteurRecherche::setIhm(Ihm* interface)
// Purpose:    Implementation of MoteurRecherche:setIhm()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::setIhm(Ihm* interface)
{
   m_ihm = interface;
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
// Name:       MoteurRecherche::traiterDOM()
// Purpose:    Implementation of MoteurRecherche::traiterDOM()
// Return:     boolean
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::traiterDOM()
{
    m_ihm->result(rechercheText(),m_url);
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
    const QUrl url = QUrl(urlrequete); //On r�cup�re l'URL entr�e par l'utilisateur.
    const QNetworkRequest requete(url); //On cr�e notre requ�te
    QNetworkAccessManager *m = new QNetworkAccessManager;
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
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender()); //On r�cup�re la r�ponse du serveur

    if (!r->error()){
        // Cr�ation et ouverture du fichier
        //QFile file("tmp/google.html");
        //file.open(QIODevice::ReadWrite);

        m_DOM=r->readAll();//file.write(r->readAll()); //On lit la r�ponse du serveur que l'on met dans un fichier

        // Met la r�ponse dans m_DOM est suprime le fichier
        //setDOM(file);
        //file.remove();
        //file.close();

        r->deleteLater(); //Supprime la r�ponse.

        traiterDOM();
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       MoteurRecherche::downloadError(QNetworkReply::NetworkError)
// Purpose:    Implementation of MoteurRecherche::downloadError()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MoteurRecherche::downloadError(QNetworkReply::NetworkError){
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    QMessageBox::critical(0, "Erreur", "Erreur lors du chargement. V�rifiez votre connexion internet ou r�essayez plus tard <br /><br /> Code de l'erreur : <br /><em>" + r->errorString() + "</em>");
}
