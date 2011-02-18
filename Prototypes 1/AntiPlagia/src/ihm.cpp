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
    m_document = new Document();
    m_document->setIhm(this);

    QObject::connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(traitement()));
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::~Ihm()
// Purpose:    Implementation of Ihm::~Ihm()
// Return:
////////////////////////////////////////////////////////////////////////

Ihm::~Ihm()
{
    delete ui;
    delete m_document;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::traitement()
// Purpose:    Implementation of Ihm::traitement()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::traitement()
{
    ui->label->setText("");

    m_document->traiterDocument();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::getText()
// Purpose:    Implementation of Ihm::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Ihm::getText(){
    return ui->lineEdit_3->text();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::result(bool plagier, QString url)
// Purpose:    Implementation of Ihm::result()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::result(bool plagier, QString url)
{
    QString reponse;
    if(plagier)
        reponse="<br/><h3>Ce text a été plagier</h3>\nSource :<a href=\"\""+url+"\">"+url+"</a>";
    else
        reponse="<br/><h3>Ce text n'a pas été plagier</h3>";

    ui->label->setText(reponse);
}
