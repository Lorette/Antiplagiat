/***********************************************************************
 * Module:  TextCible.cpp
 * Author:  RONGIARD Fabien
 *          DUREUIL Brice
 *          CRESSON Thomas
 *          NAJAR Soufiene
 *          FATNI Elkhader
 * Modified: vendredi 26 mars 2011 16:46:28
 * Purpose: Implementation of the class TextCible
 ***********************************************************************/

#include "textCible.h"

////////////////////////////////////////////////////////////////////////
// Name:       TextCible::TextCible()
// Purpose:    Implementation of TextCible::TextCible()
// Return:
////////////////////////////////////////////////////////////////////////

TextCible::TextCible(QString text)
{
    m_text=text;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextCible::~TextCible()
// Purpose:    Implementation of TextCible::~TextCible()
// Return:
////////////////////////////////////////////////////////////////////////

TextCible::~TextCible()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       TextCible::setResult(bool plagier,int idMoteurRecherche,QString url)
// Purpose:    Implementation of TextCible::setResult()
// Return:     void
////////////////////////////////////////////////////////////////////////

void TextCible::setResult(bool plagier,QString url,int idMoteurRecherche)
{
    m_plagier << plagier;
    m_IdMoteurRecherche << idMoteurRecherche;
    m_url << url;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextCible::getText()
// Purpose:    Implementation of TextCible::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString TextCible::getText()
{
   return m_text;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextCible::isPlagia()
// Purpose:    Implementation of TextCible::isPlagia()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool TextCible::isPlagier()
{
    bool b=false;
    for(int i=0;i < m_plagier.size();i++)
        b=b|m_plagier[i];
    return b;
}

////////////////////////////////////////////////////////////////////////
// Name:       TextCible::getUrl()
// Purpose:    Implementation of TextCible::getUrl()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString TextCible::getUrl()
{
    QString url("");
    int id=100;
    for(int i=0;i < m_url.size();i++){
        if ( m_plagier[i] && m_IdMoteurRecherche[i] < id ){
            url=m_url[i];
            id=m_IdMoteurRecherche[i];
        }
    }
    return url;
}

