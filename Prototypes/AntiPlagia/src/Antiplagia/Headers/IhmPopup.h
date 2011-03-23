/***********************************************************************
 * Module:  IhmPopup.h
 * Author:  fabien
 * Modified: vendredi 11 f�vrier 2011 16:44:15
 * Purpose: Declaration of the class IhmPopup
 ***********************************************************************/


#ifndef IHMPOPUP_H
#define IHMPOPUP_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QTextBrowser>
#include <QGridLayout>
#include <QApplication>
#include <QDesktopWidget>
#include "ui_progress.h"
#include "ui_resultat.h"


class IhmPopup : public QWidget
{
    Q_OBJECT

public:
    explicit IhmPopup(QWidget *parent = 0);
    ~IhmPopup();
    void startDL();
    void result(QString text);

public slots:
    void progressDL(int valeur,QString text);
    void clickAnnuler();

signals:
    void annuler();

private:
    Ui::Progress *ui;
    Ui::Resultat *ui2;

};

#endif /* IHMPOPUP_H */
