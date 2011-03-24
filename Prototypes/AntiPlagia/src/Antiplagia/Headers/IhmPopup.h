/***********************************************************************
 * Module:  IhmPopup.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Declaration of the class IhmPopup
 ***********************************************************************/


#ifndef IHMPOPUP_H
#define IHMPOPUP_H

#include <QWidget>
#include <QFileDialog>
#include "ui_progress.h"
#include "ui_resultat.h"


class IhmPopup : public QWidget
{
    Q_OBJECT

public:
    explicit IhmPopup(QWidget *parent = 0);
    ~IhmPopup();
    void startDL();
    void result(QString text1,QString text2,QString listSource,int nbSource,int prCenPlagier);

public slots:
    void progressDL(int valeur,QString text);
    void clickAnnuler();
    void changeMode();
    void clickExportHtml();

signals:
    void annuler();
    void exportHtml(QString file);

private:
    Ui::Progress *ui;
    Ui::Resultat *ui2;
    QString m_text1;
    QString m_text2;
    int m_idText;

};

#endif /* IHMPOPUP_H */
