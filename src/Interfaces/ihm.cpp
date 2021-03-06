/***********************************************************************
 * Module:  Ihm.cpp
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
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
    m_settings = new Settings(this);

    m_popup = NULL;

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(traitement()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(traitement()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(traitement()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(traitement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    QObject::connect(ui->action_propos, SIGNAL(triggered()), this, SLOT(aPropos()));
    QObject::connect(ui->actionDocumentation,SIGNAL(triggered()),this,SLOT(documentation()));
    QObject::connect(ui->actionPr_f_rences,SIGNAL(triggered()),this,SLOT(preference()));
    QObject::connect(ui->toolButton_2,SIGNAL(clicked()),this,SLOT(selectFile()));
    QObject::connect(ui->toolButton_3,SIGNAL(clicked()),this,SLOT(selectDir()));

    QObject::connect(ui->actionFran_ais,SIGNAL(triggered()),this,SLOT(traductionFr()));
    QObject::connect(ui->actionEnglish,SIGNAL(triggered()),this,SLOT(traductionEn()));
    QObject::connect(ui->actionDeutsch,SIGNAL(triggered()),this,SLOT(traductionDe()));
    QObject::connect(ui->actionEspa_ol,SIGNAL(triggered()),this,SLOT(traductionEs()));
    QObject::connect(ui->actionItaliano,SIGNAL(triggered()),this,SLOT(traductionIt()));
    QObject::connect(ui->action,SIGNAL(triggered()),this,SLOT(traductionAr()));
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
    delete m_settings;

    if (m_popup != NULL)
        delete m_popup;
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
    if (m_popup != NULL ){
         QObject::disconnect(m_popup,SIGNAL(exportHtml(QString)),m_document,SLOT(exportHtml(QString)));
        delete m_popup;
        m_popup = NULL;
    }
    if(!erreurChamp()){ // Si les champ son bien entrer
        if(focusTab() != 1 ){
            m_popup = new IhmPopup();
            QObject::connect(m_document,SIGNAL(progress(int,QString)),m_popup,SLOT(progressDL(int,QString)));
            QObject::connect(m_popup,SIGNAL(annuler()),m_document,SLOT(annulerTraitement()));
            QObject::connect(m_popup,SIGNAL(annuler()),this,SLOT(annulerTraitement()));
            m_popup->startDL();
        }
        if(focusTab() != 4)
            m_document->traiterDocument();
        else
            m_document->traiterDossier();
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
// Name:       Ihm::getDir()
// Purpose:    Implementation of Ihm::getDir()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Ihm::getDir(){
    return ui->lineEdit_5->text();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::result(bool plagier, QString url)
// Purpose:    Implementation of Ihm::result()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::result(bool error, QString errorString)
{
    if (error)
        QMessageBox::critical(this, QObject::tr("Erreur"), errorString);
    else{
        int n=focusTab();
        if(n == 1){ // Par text
            if(m_document->textIsPlagier()) // text plagier
                ui->label->setText("<h3>"+QObject::tr("Ce texte a �t� plagi�")+"</h3>\n"+QObject::tr("Source: ")+"<a href=\""+m_document->getUrlTextPlagier()+"\"> "+m_document->getUrlTextPlagier()+" </a>");
            else
                ui->label->setText("<h3>"+QObject::tr("Ce texte n'a pas �t� plagi�")+"</h3>");
        }
        else{// Par document
            QObject::disconnect(m_document,SIGNAL(progress(int,QString)),m_popup,SLOT(progressDL(int,QString)));
            QObject::disconnect(m_popup,SIGNAL(annuler()),m_document,SLOT(annulerTraitement()));
            QObject::disconnect(m_popup,SIGNAL(annuler()),this,SLOT(annulerTraitement()));
            delete m_popup;
            m_popup = NULL;
            if(n == 4)
                QMessageBox::information(this, QObject::tr("Traitement Fini"), QObject::tr("Tous les fichiers on �t� trait�"));
            else{
                m_popup = new IhmPopup();
                QObject::connect(m_popup,SIGNAL(exportHtml(QString)),m_document,SLOT(exportHtml(QString)));
                m_popup->result(m_document->getDocumentEnrichi(1),m_document->getDocumentEnrichi(2),m_document->getListSource(),m_document->getNbSource(),m_document->getPrCentPlagier());
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
    QString propos = "<strong>"+QObject::tr("Projet Anti-Plagiat")+"</strong>:<br/><br/><u><i>"+QObject::tr("R�alis� par")+"</i></u>:<ul><li>Fabien RONGIARD</li><li>Brice DUREUIL</li><li>Elkader FATNI</li><li>Soufi&egrave;ne NAJAR</li><li>Thomas CRESSON</li></ul><br/><u><i>"+QObject::tr("Langage de programmation utilis�")+"</u></i>:<ul><li>"+QObject::tr("Langage C++")+"</li></ul><br/><u><i>"+QObject::tr("Framework utilis�e")+"</u></i>:<ul><li>Qt 4.7</li></ul><br/><br/>"+QObject::tr("Pour de plus amples informations visitez notre")+" <a href=\"http://lorette.fr.nf\">"+QObject::tr("site web")+"</a>.";
    QLabel *text = new QLabel(propos);
    text->setOpenExternalLinks(true);
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
    m_settings->show();
}


////////////////////////////////////////////////////////////////////////
// Name:       Ihm::documentation()
// Purpose:    Implementation of Ihm::documentation()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::documentation()
{
    QWebView *pageWeb = new QWebView();
    pageWeb->load(QUrl("file://localhost/"+QDir().absolutePath()+"/doc/Anti-Plagiat.html"));
    pageWeb->show();

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
    else
        n=4;

    return n;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::selectFile()
// Purpose:    Implementation of Ihm::selectFile()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::selectFile()
{
    QString file = QFileDialog::getOpenFileName(this, QObject::tr("Ouvrir un fichier"), QString(), QObject::tr("Fichier")+" (*.pdf *.docx *.odt)");

    if(file != "")
    {
        if(m_document->setFile(file))
            ui->lineEdit_4->setText(file);
        else
            ui->lineEdit_4->setText("");
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::selectDir()
// Purpose:    Implementation of Ihm::selectDir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::selectDir()
{
    QString dir = QFileDialog::getExistingDirectory(this);

    ui->lineEdit_5->setText(dir);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::enabelDisabel()
// Purpose:    Implementation of Ihm::enabelDisabel()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::enabelDisabel(bool b)
{
    ui->tabWidget->setEnabled(b);
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
        result(true,QObject::tr("Vous devez saisir un texte � tester"));
        b=true;
    }
    else if (n == 2 && ui->textEdit_2->toPlainText() == ""){
        result(true,QObject::tr("Vous devez saisir le texte du document � tester"));
        b=true;
    }
    else if (n == 3 && ui->lineEdit_4->text() == "" ){
        result(true,QObject::tr("Vous devez selection� un fichier"));
        b=true;
    }
    else if (n == 4 && ui->lineEdit_5->text() == "" ){
        result(true,QObject::tr("Vous devez selection� un dossier"));
        b=true;
    }

    else if(n == 1 && !ui->checkBox_4->isChecked() && !ui->checkBox_5->isChecked() && !ui->checkBox_6->isChecked()){
        result(true,QObject::tr("Aucun moteur de recheche s�lection�"));
        b=true;
    }

    else if(n == 2 && !ui->checkBox_7->isChecked() && !ui->checkBox_8->isChecked() && !ui->checkBox_9->isChecked()){
        result(true,QObject::tr("Aucun moteur de recheche s�lection�"));
        b=true;
    }

    else if(n == 3 && !ui->checkBox_10->isChecked() && !ui->checkBox_11->isChecked() && !ui->checkBox_12->isChecked()){
        result(true,QObject::tr("Aucun moteur de recheche s�lection�"));
        b=true;
    }
    else if(n == 4 && !ui->checkBox_13->isChecked() && !ui->checkBox_14->isChecked() && !ui->checkBox_15->isChecked()){
        result(true,QObject::tr("Aucun moteur de recheche s�lection�"));
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
    bool b=false;
    switch(focusTab()){
    case 1:
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
        break;
    case 2:
        switch(idMoteurRecherche){
        case 0:
            b=ui->checkBox_7->isChecked();
            break;
        case 1:
            b=ui->checkBox_9->isChecked();
            break;
        case 2:
            b=ui->checkBox_8->isChecked();
            break;
        default:
            b=false;
            break;
        }
        break;
    case 3:
        switch(idMoteurRecherche){
        case 0:
            b=ui->checkBox_10->isChecked();
            break;
        case 1:
            b=ui->checkBox_12->isChecked();
            break;
        case 2:
            b=ui->checkBox_11->isChecked();
            break;
        default:
            b=false;
            break;
        }
        break;
    case 4:
        switch(idMoteurRecherche){
        case 0:
            b=ui->checkBox_13->isChecked();
            break;
        case 1:
            b=ui->checkBox_15->isChecked();
            break;
        case 2:
            b=ui->checkBox_14->isChecked();
            break;
        default:
            b=false;
            break;
        }
        break;
    }
    return b;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::annulerTraitement()
// Purpose:    Implementation of Ihm::annulerTraitement()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::annulerTraitement()
{
    if(m_popup != NULL ){
        QObject::disconnect(m_document,SIGNAL(progress(int,QString)),m_popup,SLOT(progressDL(int,QString)));
        QObject::disconnect(m_popup,SIGNAL(annuler()),m_document,SLOT(annulerTraitement()));
        QObject::disconnect(m_popup,SIGNAL(annuler()),this,SLOT(annulerTraitement()));
        delete m_popup;
        m_popup = NULL;
    }
    enabelDisabel(true);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::getNbMots()
// Purpose:    Implementation of Ihm::getNbMots()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Ihm::getNbMots()
{
    return m_settings->getNbMots();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::getParTaille()
// Purpose:    Implementation of Ihm::getParTaille()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Ihm::getParTaille()
{
    return m_settings->getParTaille();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::getParPolice()
// Purpose:    Implementation of Ihm::getParPolice()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Ihm::getParPolice()
{
    return m_settings->getParPolice();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::getPrCentATester()
// Purpose:    Implementation of Ihm::getPrCentATester()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Ihm::getPrCentATester()
{
    return m_settings->getPrCentATester();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::nbMaxRequete()
// Purpose:    Implementation of Ihm::nbMaxRequete()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Ihm::nbMaxRequete()
{
    return m_settings->nbMaxRequete();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::traductionFr()
// Purpose:    Implementation of Ihm::traductionFr()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::traductionFr()
{
    QTranslator* translator = new QTranslator();
    translator->load("Traduction/antiplagia_fr");
    qApp->installTranslator(translator);
    ui->actionFran_ais->setChecked(true);;
    ui->actionEnglish->setChecked(false);
    ui->actionDeutsch->setChecked(false);
    ui->actionEspa_ol->setChecked(false);
    ui->actionItaliano->setChecked(false);
    ui->action->setChecked(false);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::traductionEn()
// Purpose:    Implementation of Ihm::traductionEn()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::traductionEn()
{
    QTranslator* translator = new QTranslator();
    translator->load("Traduction/antiplagia_en");
    qApp->installTranslator(translator);
    ui->actionFran_ais->setChecked(false);
    ui->actionEnglish->setChecked(true);
    ui->actionDeutsch->setChecked(false);
    ui->actionEspa_ol->setChecked(false);
    ui->actionItaliano->setChecked(false);
    ui->action->setChecked(false);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::traductionDe()
// Purpose:    Implementation of Ihm::traductionDe()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::traductionDe()
{
    QTranslator* translator = new QTranslator();
    translator->load("Traduction/antiplagia_de");
    qApp->installTranslator(translator);
    ui->actionFran_ais->setChecked(false);
    ui->actionEnglish->setChecked(false);
    ui->actionDeutsch->setChecked(true);
    ui->actionEspa_ol->setChecked(false);
    ui->actionItaliano->setChecked(false);
    ui->action->setChecked(false);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::traductionEs()
// Purpose:    Implementation of Ihm::traductionEs()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::traductionEs()
{
    QTranslator* translator = new QTranslator();
    translator->load("Traduction/antiplagia_es");
    qApp->installTranslator(translator);
    ui->actionFran_ais->setChecked(false);
    ui->actionEnglish->setChecked(false);
    ui->actionDeutsch->setChecked(false);
    ui->actionEspa_ol->setChecked(true);
    ui->actionItaliano->setChecked(false);
    ui->action->setChecked(false);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::traductionIt()
// Purpose:    Implementation of Ihm::traductionIt()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::traductionIt()
{
    QTranslator* translator  = new QTranslator();
    translator->load("Traduction/antiplagia_it");
    qApp->installTranslator(translator);
    ui->actionFran_ais->setChecked(false);
    ui->actionEnglish->setChecked(false);
    ui->actionDeutsch->setChecked(false);
    ui->actionEspa_ol->setChecked(false);
    ui->actionItaliano->setChecked(true);
    ui->action->setChecked(false);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::traductionAr()
// Purpose:    Implementation of Ihm::traductionAr()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::traductionAr()
{
    QTranslator* translator = new QTranslator();
    translator->load("Traduction/antiplagia_ar");
    qApp->installTranslator(translator);
    ui->actionFran_ais->setChecked(false);
    ui->actionEnglish->setChecked(false);
    ui->actionDeutsch->setChecked(false);
    ui->actionEspa_ol->setChecked(false);
    ui->actionItaliano->setChecked(false);
    ui->action->setChecked(true);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ihm::changeEvent(QEvent *event)
// Purpose:    Implementation of Ihm::changeEvent()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ihm::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    else
         QWidget::changeEvent(event);
}
