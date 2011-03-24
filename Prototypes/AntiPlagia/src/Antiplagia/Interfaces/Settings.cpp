#include "Settings.h"
#include "ui_settings.h"
#include <QPlastiqueStyle>
Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Tool);
}

Settings::~Settings()
{
    delete ui;
}
