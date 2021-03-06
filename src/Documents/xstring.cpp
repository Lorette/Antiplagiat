/***********************************************************************
 * Module:  xstring.cpp
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Implementation of the class XString
 ***********************************************************************/

#include "xstring.h"

////////////////////////////////////////////////////////////////////////
// Name:       XString::XString()
// Purpose:    Implementation of XString::XString()
// Return:
////////////////////////////////////////////////////////////////////////

XString::XString()
{

}

////////////////////////////////////////////////////////////////////////
// Name:       XString::~XString()
// Purpose:    Implementation of XString::~XString()
// Return:
////////////////////////////////////////////////////////////////////////

XString::~XString()
{

}

////////////////////////////////////////////////////////////////////////
// Name:       XString::~XString(QString string, QString police = "None", QString size = "")
// Purpose:    Implementation of XString::~XString()
// Return:
////////////////////////////////////////////////////////////////////////

XString::XString(QString string, QString police, QString size) : m_text(string), m_police(police),m_size(size)
{
}

////////////////////////////////////////////////////////////////////////
// Name:       XString::toString()
// Purpose:    Implementation of XString::toString()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString XString::toString()
{
    return m_text;
}

////////////////////////////////////////////////////////////////////////
// Name:       XString::get_m_police()
// Purpose:    Implementation of XString::get_m_police()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString XString::get_m_police()
{
    return m_police;
}

////////////////////////////////////////////////////////////////////////
// Name:       XString::get_m_size()
// Purpose:    Implementation of XString::get_m_size()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString XString::get_m_size()
{
    return m_size;
}

////////////////////////////////////////////////////////////////////////
// Name:       XString::count_words()
// Purpose:    Implementation of XString::count_words()
// Return:     int
////////////////////////////////////////////////////////////////////////

int XString::count_words()
{
    QStringList list = m_text.split(" ");
    return list.count();
}

////////////////////////////////////////////////////////////////////////
// Name:       XString::setText(QString text)
// Purpose:    Implementation of XString::setText()
// Return:     int
////////////////////////////////////////////////////////////////////////

void XString::setText(QString text)
{
    m_text = text;
}
