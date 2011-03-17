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
<<<<<<< HEAD
    m_popup = NULL;
    m_file = NULL;

=======
    m_popup = new IhmPopup();
    m_TextDocx = NULL;
    QObject::connect(m_document,SIGNAL(progress(int,QString)),m_popup,SLOT(progressDL(int,QString)));
>>>>>>> 184c75a39e5bf0deb9cf857409b212ba6e9095d2
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
<<<<<<< HEAD
    if (m_popup != NULL )
        delete m_popup;
    if (m_file != NULL )
        delete m_file;
=======
    delete m_popup;
    if(m_TextDocx != NULL) delete m_TextDocx;
>>>>>>> 184c75a39e5bf0deb9cf857409b212ba6e9095d2
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
    if (m_popup != NULL )
        delete m_popup;

    if(!erreurChamp()){ // Si les champ son bien entrer
        if(focusTab() != 1){
            m_popup = new IhmPopup();
            QObject::connect(m_document,SIGNAL(progress(int,QString)),m_popup,SLOT(progressDL(int,QString)));
            m_popup->startDL();
        }
        m_document->traiterDocument();
    }
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
        else{// Par document
            QObject::disconnect(m_document,SIGNAL(progress(int,QString)),m_popup,SLOT(progressDL(int,QString)));
            delete m_popup;
            if(n == 3){ // Par fichier
                QMessageBox::critical(this, "Erreur", "Indisponible ");
                m_popup = NULL;
            }
            else{
                m_popup = new IhmPopup();
                m_popup->result(m_document->getDocumentEnrichi());
            }
        }
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
    QDialog* action_propos = new QDialog (this);
    QVBoxLayout *layout = new QVBoxLayout;
    QString propos = "<strong>Projet Antiplagia</strong>:<br/><br/><u><i>Réalisé par</i></u>:<ul><li>Fabien RONGIARD</li><li>Brice DUREUIL</li><li>Elkader FATNI</li><li>Soufi&egrave;ne NAJAR</li><li>Thomas CRESSON</li></ul><br/><u><i>Langage de programmation utilisé</u></i>:<ul><li>Langage C++</li></ul><br/><u><i>Framework utilisée</u></i>:<ul><li>Qt 4.7</li></ul><br/><br/>Pour de plus amples informations visitez notre <a href=\"http://94.23.244.98/antiplagia/\">site web</a>.";
    QLabel *text = new QLabel(propos);
    layout->addWidget(text);
    action_propos->setLayout(layout);
    action_propos->setFixedSize(300,350);
    action_propos->show();
}


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::preference()
// Purpose:    Implementation of Ihm::preference()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::preference()
{
    QMessageBox::critical(this, "Indisponible", "Disponible prochainement !");

}


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::documentation()
// Purpose:    Implementation of Ihm::documentation()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::documentation()
{
    QMessageBox::critical(this, "Indisponible", "Disponible prochainement !");
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
<<<<<<< HEAD
    QString file = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier (*.pdf *.doc *.docx)");
=======
    QString file = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier (*.pdf *.docx)");

>>>>>>> 184c75a39e5bf0deb9cf857409b212ba6e9095d2
    if(file != "")
    {
        if(m_TextDocx != NULL) delete m_TextDocx;
        m_TextDocx = new TextDocx(file);
        ui->lineEdit_4->setText(file);
    }
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


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::isSelect(int idMoteurRecherche)
// Purpose:    Implementation of Ihm::isSelect()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Ihm::isSelect(int idMoteurRecherche)
{
    bool b;
    switch(idMoteurRecherche){
    case 0:
        b=ui->checkBox_6->isChecked();
        break;
    case 1:
        b=ui->checkBox_5->isChecked();
        break;
    case 2:
        b=ui->checkBox_4->isChecked();
        break;
    default:
        b=false;
        break;
    }
    return b;
}
