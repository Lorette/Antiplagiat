/***********************************************************************
 * Module:  ListTextCible.h
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Declaration of the class ListTextCible
 ***********************************************************************/

#ifndef LISTTEXTCICBLE_H
#define LISTTEXTCICBLE_H

/*!
 * \file ListTextCicble.h
 * \brief Liste des Textes Cibles.
 * \author RONGIARD Fabien
 *         DUREUIL Brice
 *         CRESSON Thomas
 *         NAJAR Soufiene
 *         FATNI Elkhader
 * \version 1.0
 * \date 26 mars 2011
 */

#include <QList>
#include "textCible.h"
#include <QString>


class TextCible;

/*! \class ListTextCicble
  * \brief Classe ListTextCicble :
  *
  *  Classe qui gere la liste de tous les TextCible.
  */

class ListTextCicble : public QList<TextCible>
{
public:
    /*!
     *  \brief Constructeur.
     *
     *  Constructeur de la classe ListTextCicble.
     */
    ListTextCicble();
    /*!
     *  \brief Destructeur.
     *
     *  Destructeur de la classe ListTextCicble.
     */
    ~ListTextCicble();

};

#endif /* LISTTEXTCICBLE_H */
