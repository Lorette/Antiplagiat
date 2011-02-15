/***********************************************************************
 * Module:  Ihm.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Implementation of the class Ihm
 ***********************************************************************/

#include "ihm.h"
#include "ui_ihm.h"


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::Ihm(QWidget *parent) : QMainWindow(parent),ui(new Ui::Ihm)
// Purpose:    Implementation of Ihm::Ihm()
// Return:
////////////////////////////////////////////////////////////////////////

Ihm::Ihm(QWidget *parent) : QMainWindow(parent), ui(new Ui::Ihm)
{
    ui->setupUi(this);
    setFixedSize(230, 120);

    m_boutonDialogue = new QPushButton("Test", this);
    m_boutonDialogue->move(30,80);

    m_QLineEdit = new QLineEdit(this);
    m_QLineEdit->move(30,30);

    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::~Ihm()
// Purpose:    Implementation of Ihm::~Ihm()
// Return:
////////////////////////////////////////////////////////////////////////

Ihm::~Ihm()
{
    delete ui;
    delete m_QLineEdit;
    delete m_boutonDialogue;
    delete m_document;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::ouvrirDialogue()
// Purpose:    Implementation of Ihm::ouvrirDialogue()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::ouvrirDialogue()
{
    m_document = new Document();
    m_document->setIhm(this);
    if (m_document->traiterDocument())
        QMessageBox::information(this, "Résultat", "Cette phrase à été plagié");
    else
        QMessageBox::information(this, "Résultat", "Ce n'est pas du plagia");
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::getText()
// Purpose:    Implementation of Ihm::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Ihm::getText(){
    return m_QLineEdit->text();
}
