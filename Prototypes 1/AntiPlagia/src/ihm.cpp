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
    m_document = new Document(this);

    QObject::connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(traitement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    QObject::connect(ui->buttonBox->button(QDialogButtonBox::Close), SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(ui->action_propos, SIGNAL(triggered()), this, SLOT(aPropos()));
    QObject::connect(ui->actionDocumentation,SIGNAL(triggered()),this,SLOT(documentation()));
    QObject::connect(ui->actionPr_f_rences,SIGNAL(triggered()),this,SLOT(preference()));
    QObject::connect(ui->toolButton_2,SIGNAL(clicked()),this,SLOT(selectFile()));
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
    enabelDisabel(false);
    ui->label->setText("");
    if(!erreurChamp()) // Si les champ son bien entrer
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
// Name:       Ihm::getDocument()
// Purpose:    Implementation of Ihm::getDocument()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Ihm::getDocument(){
    return ui->textEdit_2->toPlainText();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::getNameFile()
// Purpose:    Implementation of Ihm::getNameFile()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Ihm::getNameFile(){
    return ui->lineEdit_4->text();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::result(bool plagier, QString url)
// Purpose:    Implementation of Ihm::result()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::result(bool error, QString errorString)
{
    if (error)
        QMessageBox::critical(this, "Erreur", errorString);
    else{
        int n=focusTab();
        if(n == 1){ // Par text
            if(m_document->textIsPlagier()) // text plagier
                ui->label->setText("<br/><h3>Ce text a été plagier</h3>\nSource: <a href=\""+m_document->getUrlTextPlagier()+"\"> "+m_document->getUrlTextPlagier()+" </a>");
            else
                ui->label->setText("<br/><h3>Ce text n'a pas été plagier</h3>");
        }
        else // Par document ou fichier
            QMessageBox::critical(this, "Erreur", "Indisponible");

    }
    enabelDisabel(true);
}


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::aPropos()
// Purpose:    Implementation of Ihm::aPropos()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::aPropos()
{
}


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::preference()
// Purpose:    Implementation of Ihm::preference()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::preference()
{
}


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::documentation()
// Purpose:    Implementation of Ihm::documentation()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::documentation()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::focusTab()
// Purpose:    Implementation of Ihm::focusTab()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Ihm::focusTab(){
    QWidget *focus=ui->tabWidget->currentWidget();
    int n=0;

    if(focus == ui->tab_3)
        n=1;
    else if (focus == ui->tab_4)
        n=2;
    else if (focus == ui->tab_5)
        n=3;

    return n;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::selectFile()
// Purpose:    Implementation of Ihm::selectFile()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::selectFile()
{
    ui->lineEdit_4->setText(QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier (*.pdf *.doc)"));
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::enabelDisabel()
// Purpose:    Implementation of Ihm::enabelDisabel()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::enabelDisabel(bool b)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(b);
    ui->tabWidget->setEnabled(b);
    ui->groupBox->setEnabled(b);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::erreurChamp()
// Purpose:    Implementation of Ihm::erreurChamp()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Ihm::erreurChamp()
{
    bool b=false;
    int n=focusTab();
    if(n == 1 && ui->lineEdit_3->text() == ""){
        result(true,"Vous devez saisir un texte à tester");
        b=true;
    }
    else if (n == 2 && ui->textEdit_2->toPlainText() == ""){
        result(true,"Vous devez saisir le texte du document à tester");
        b=true;
    }
    else if (n == 3 && ui->lineEdit_4->text() == "" ){
        result(true,"Vous devez selectioné un fichier");
        b=true;
    }
    else if ( !ui->checkBox_4->isChecked() && !ui->checkBox_5->isChecked() && !ui->checkBox_6->isChecked()){
        result(true,"Aucun moteur de recheche sélectioné");
        b=true;
    }
    return b;
}
