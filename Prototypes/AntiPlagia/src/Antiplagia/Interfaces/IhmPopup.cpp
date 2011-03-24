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
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(clickAnnuler()));
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
// Name:       IhmPopup::result(QString text1,QString text2,QString listSource,int nbSource,int prCenPlagier)
// Purpose:    Implementation of IhmPopup::result()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::result(QString text1,QString text2,QString listSource,int nbSource,int prCenPlagier)
{
    ui2 = new Ui::Resultat();
    ui2->setupUi(this);
    ui2->textBrowser->setText(text1);
    ui2->label_2->setText("<strong>Nombres de sources: "+QString::number(nbSource)+"</strong>");
    ui2->label->setText("<strong>Texte plagié à "+QString::number(prCenPlagier)+"% </strong>");
    ui2->textBrowser_2->setText(listSource);
    m_text1=text1;
    m_text2=text2;
    m_idText = 1;
    QObject::connect(ui2->pushButton_2,SIGNAL(clicked()),this,SLOT(changeMode()));
    QObject::connect(ui2->pushButton,SIGNAL(clicked()),this,SLOT(clickExportHtml()));
    show();
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::clickAnnuler()
// Purpose:    Implementation of IhmPopup::clickAnnuler()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::clickAnnuler()
{
    emit annuler();
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::changeMode()
// Purpose:    Implementation of IhmPopup::changeMode()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::changeMode()
{
    if(m_idText == 1){
        ui2->textBrowser->setText(m_text2);
        m_idText=2;
    }
    else{
        ui2->textBrowser->setText(m_text1);
        m_idText=1;
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::clickExportHtml()
// Purpose:    Implementation of IhmPopup::clickExportHtml()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::clickExportHtml()
{
    QString file = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.html)");
    if (file != "")
        emit exportHtml(file);
}
