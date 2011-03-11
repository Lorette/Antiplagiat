/***********************************************************************
 * Module:  IhmPopup.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
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

class IhmPopup : public QWidget
{
    Q_OBJECT

public:
    explicit IhmPopup(QWidget *parent = 0);
    ~IhmPopup();
    void startDL();
    void result(QString text);

private slots:
    void progressDL(int valeur,QString text);

private:
    QLabel *m_label1;
    QLabel *m_label2;
    QProgressBar *m_progress;
    QTextBrowser *m_text;
    QGridLayout *m_layout;

};

#endif /* IHMPOPUP_H */
