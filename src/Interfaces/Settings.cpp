/***********************************************************************
 * Module:  Settings.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Implementation of the class Settings
 ***********************************************************************/

#include "settings.h"
#include "ui_settings.h"


////////////////////////////////////////////////////////////////////////
// Name:       Settings::Settings(QWidget *parent) : QWidget(parent), ui(new Ui::Settings)
// Purpose:    Implementation of Settings::Settings()
// Return:
////////////////////////////////////////////////////////////////////////

Settings::Settings(QWidget *parent) : QWidget(parent), ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool);
    readSettings();
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(click_close()));
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::~Settings()
// Purpose:    Implementation of Settings::~Settings()
// Return:
////////////////////////////////////////////////////////////////////////

Settings::~Settings()
{
    delete ui;
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::writeSettings()
// Purpose:    Implementation of Settings::writeSettings()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Settings::writeSettings()
{
    QSettings settings("Lorette Inc", "Anti-Plagia");
    settings.beginGroup("Anti-Plagia");
    settings.setValue("req_max", ui->spinBox->value());
    settings.setValue("pour_cent", ui->spinBox_2->value());
    settings.setValue("nb_mots", ui->spinBox_3->value());
    settings.setValue("police", ui->radioButton->isChecked());
    settings.setValue("taille", ui->radioButton_3->isChecked());
    settings.endGroup();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::readSettings()
// Purpose:    Implementation of Settings::readSettings()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Settings::readSettings()
{
    QSettings settings("Lorette Inc", "Anti-Plagia");
    settings.beginGroup("Anti-Plagia");
    ui->spinBox->setValue(settings.value("req_max").toInt());
    ui->spinBox_2->setValue(settings.value("pour_cent").toInt());
    ui->spinBox_3->setValue(settings.value("nb_mots").toInt());
    ui->radioButton->setChecked(settings.value("police").toBool());
    ui->radioButton_3->setChecked(settings.value("taille").toBool());
    settings.endGroup();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::click_close()
// Purpose:    Implementation of Settings::click_close()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Settings::click_close()
{
    writeSettings();
    close();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::getNbMots()
// Purpose:    Implementation of Settings::getNbMots()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Settings::getNbMots()
{
    return ui->spinBox_3->value();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::getParTaille()
// Purpose:    Implementation of Settings::getParTaille()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Settings::getParTaille()
{
    return ui->radioButton_3->isChecked();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::getParPolice()
// Purpose:    Implementation of Settings::getParPolice()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Settings::getParPolice()
{
    return ui->radioButton->isChecked();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::getPrCentATester()
// Purpose:    Implementation of Settings::getPrCentATester()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Settings::getPrCentATester()
{
    return ui->spinBox_2->value();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::nbMaxRequete()
// Purpose:    Implementation of Settings::nbMaxRequete()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Settings::nbMaxRequete()
{
    return ui->spinBox->value();
}

////////////////////////////////////////////////////////////////////////
// Name:       Settings::closeEvent(QCloseEvent *event)
// Purpose:    Implementation of Settings::closeEvent()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Settings::closeEvent(QCloseEvent *event)
{
    writeSettings();
    close();
}
