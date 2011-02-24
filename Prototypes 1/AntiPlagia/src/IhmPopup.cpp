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
    m_layout = new QGridLayout();
    setLayout(m_layout);
    m_label1 = NULL;
    m_label2 = NULL;
    m_progress = NULL;
    m_text = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::~IhmPopup()
// Purpose:    Implementation of IhmPopup::~IhmPopup()
// Return:
////////////////////////////////////////////////////////////////////////

IhmPopup::~IhmPopup()
{
    if (m_label1 != NULL)
        delete m_label1;
    if (m_label2 != NULL )
        delete m_label2;
    if (m_progress != NULL)
        delete m_progress;
    if (m_text != NULL)
        delete m_text;
    delete m_layout;
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::startDL()
// Purpose:    Implementation of IhmPopup::startDL()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::startDL()
{
    if(m_label1 != NULL){
        delete m_label1;
        m_label1 = NULL;
    }
    if(m_label2 != NULL){
        delete m_label2;
        m_label2 = NULL;
    }
    if(m_progress != NULL){
        delete m_progress;
        m_progress = NULL;
    }
    if(m_text != NULL){
        delete m_text;
        m_text = NULL;
    }

    m_label1 = new QLabel("<h3>Traitement en cours</h3>",this);
    m_progress = new QProgressBar(this);
    m_label2 = new QLabel(this);
    m_layout->addWidget(m_label1,0,1);
    m_layout->addWidget(m_progress,1,0,1,3);
    m_layout->addWidget(m_label2,2,0,1,3);
    setMinimumSize(450,90);
    setMaximumSize(450,90);
    show();
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::progressDL(int valeur,QString text)
// Purpose:    Implementation of IhmPopup::progressDL()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::progressDL(int valeur,QString text)
{
    m_progress->setValue(valeur);
    m_label2->setText("<h5>"+text+"</h5>");
}

////////////////////////////////////////////////////////////////////////
// Name:       IhmPopup::result(QString text)
// Purpose:    Implementation of IhmPopup::result()
// Return:     void
////////////////////////////////////////////////////////////////////////

void IhmPopup::result(QString text)
{
    if(m_label2 != NULL){
        delete m_label2;
        m_label2 = NULL;
    }
    if(m_progress != NULL){
        delete m_progress;
        m_progress = NULL;
    }
    if(m_label1 != NULL){
        delete m_label1;
        m_label1 = NULL;
    }
    if(m_text != NULL){
        delete m_text;
        m_text = NULL;
    }

    m_text = new QTextBrowser();
    m_text->setOpenExternalLinks(true);
    m_layout->addWidget(m_text,0,0);
    m_text->setText(text);
    setMinimumSize(0,0);
    setMaximumSize(QApplication::desktop()->width(),QApplication::desktop()->height());
    resize(450,450);
}

