/***********************************************************************
 * Module:  IhmPopup.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Implementation of the class IhmPopup
 ***********************************************************************/

#include "IhmPopup.h"

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::IhmPopup(QWidget *parent) : QWidget(parent)
// Purpose:    Implementation of IhmPopup::IhmPopup()
// Return:
////////////////////////////////////////////////////////////////////////

IhmPopup::IhmPopup(QWidget *parent): QWidget(parent)
{
    ui2 = NULL;
    ui = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::~IhmPopup()
// Purpose:    Implementation of IhmPopup::~IhmPopup()
// Return:
////////////////////////////////////////////////////////////////////////

IhmPopup::~IhmPopup()
{
    if ( ui != NULL)
        delete ui;
    if ( ui2 != NULL)
        delete ui2;
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::startDL()
// Purpose:    Implementation of IhmPopup::startDL()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::startDL()
{
    ui = new Ui::Progress();
    ui->setupUi(this);
    show();
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::progressDL(int valeur,QString text)
// Purpose:    Implementation of IhmPopup::progressDL()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::progressDL(int valeur,QString text)
{
    ui->progressBar->setValue(valeur);
    ui->label_2->setText("<h5>"+text+"</h5>");
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::result(QString text)
// Purpose:    Implementation of IhmPopup::result()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::result(QString text)
{
    ui2 = new Ui::Resultat();
    ui2->setupUi(this);
    ui2->textBrowser->setText(text);
    show();
}

