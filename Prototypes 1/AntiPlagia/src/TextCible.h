/***********************************************************************
 * Module:  TextCible.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Declaration of the class TextCible
 ***********************************************************************/

#ifndef TEXTCIBLE_H
#define TEXTCIBLE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>

class TextCible
{
public:
    TextCible(QString text);
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
