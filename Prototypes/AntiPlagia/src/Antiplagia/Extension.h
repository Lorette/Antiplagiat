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
    virtual QStringList getCible();

};

#endif // EXTENSION_H
