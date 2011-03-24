/***********************************************************************
 * Module:  main.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Implementation of the class Main
 ***********************************************************************/

#include <QtGui/QApplication>
#include "ihm.h"
#include <QPlastiqueStyle>

////////////////////////////////////////////////////////////////////////
// Name:       int main(int argc, char *argv[])
// Purpose:    Implementation of main()
// Return:     int
////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ihm w;
    a.setStyle(new QPlastiqueStyle);
    w.show();

    return a.exec();
}
