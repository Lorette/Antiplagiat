/***********************************************************************
 * Module:  Extension.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Declaration of the class Extension
 ***********************************************************************/

#ifndef EXTENSION_H
#define EXTENSION_H

#include <QString>
#include <QStringList>

class Extension
{

public:
    Extension();
    ~Extension();
    virtual bool fileIsValid();
    virtual QString getText();
    virtual QStringList getCible(int max_word, bool tri_police, bool tri_size);

};

#endif // EXTENSION_H
