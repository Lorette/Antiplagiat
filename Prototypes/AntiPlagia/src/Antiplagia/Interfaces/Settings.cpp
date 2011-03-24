#include "Settings.h"
#include "ui_settings.h"


Settings::Settings(QWidget *parent) : QWidget(parent), ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool);
    readSettings();
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(click_close()));
}

Settings::~Settings()
{
    delete ui;
}


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

void Settings::click_close()
{
    writeSettings();
    close();
}

int Settings::getNbMots()
{
    return ui->spinBox_3->value();
}

bool Settings::getParTaille()
{
    return ui->radioButton_3->isChecked();
}

bool Settings::getParPolice()
{
    return ui->radioButton->isChecked();
}

int Settings::getPrCentATester()
{
    return ui->spinBox_2->value();
}

int Settings::nbMaxRequete()
{
    return ui->spinBox->value();
}

void Settings::closeEvent(QCloseEvent *event)
{
    writeSettings();
    close();
}
