#include <QApplication>
#include <QtGui>
#include "ui_Maquete.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow *fenetre = new QMainWindow;
    Ui::AntiPlagia ui;
    ui.setupUi(fenetre);

    fenetre->show();

    return app.exec();
}