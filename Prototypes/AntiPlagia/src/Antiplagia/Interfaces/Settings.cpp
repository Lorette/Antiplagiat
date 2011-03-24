#include "Settings.h"
#include "ui_settings.h"

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
