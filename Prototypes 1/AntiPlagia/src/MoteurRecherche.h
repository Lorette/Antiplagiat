/***********************************************************************
 * Module:  MoteurRecherche.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Declaration of the class MoteurRecherche
 ***********************************************************************/

#ifndef MOTEURRECHERCHE_H
#define	MOTEURRECHERCHE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>


class MoteurRecherche : public QObject
{

Q_OBJECT

public:
   MoteurRecherche();
   ~MoteurRecherche();
   QString getDOM();
   void setDOM(QString dom);
   void setText(QString text);
   QString getText();
   void setUrl(QString url);
   QString getUrl();
   virtual void sendRequest();
   bool traiterDOM();
   virtual bool rechercheText();
   void HttpRequest(QString urlrequete);

public slots :
   void downloadFinish();
   void downloadError(QNetworkReply::NetworkError);

signals:
    void requetFini(bool error,QString errorString = QString());

protected:
   QString m_DOM;
   QString m_text;
   QString m_url;

};

#endif	/* MOTEURRECHERCHE_H */

