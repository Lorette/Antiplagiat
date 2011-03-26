/***********************************************************************
 * Module:  ListTextCible.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:44:15
 * Purpose: Declaration of the class ListTextCible
 ***********************************************************************/

#ifndef LISTTEXTCICBLE_H
#define LISTTEXTCICBLE_H

#include <QList>
#include "TextCible.h"
#include <QString>


class TextCible;

class ListTextCicble : public QList<TextCible>
{
public:
    ListTextCicble();
    ~ListTextCicble();

};

#endif /* LISTTEXTCICBLE_H */
