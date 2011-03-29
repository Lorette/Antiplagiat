/***********************************************************************
 * Module:  main.cpp
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Implementation of the class Main
 ***********************************************************************/

#include <QtGui/QApplication>
#include "ihm.h"
#include <QPlastiqueStyle>
#include <QTranslator>

////////////////////////////////////////////////////////////////////////
// Name:       int main(int argc, char *argv[])
// Purpose:    Implementation of main()
// Return:     int
////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("Traduction/antiplagia_fr");
    a.installTranslator(&translator);
    Ihm w;
    a.setStyle(new QPlastiqueStyle);
    w.show();

    return a.exec();
}
