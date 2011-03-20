/***********************************************************************
 * Module:  Document.cpp
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:33:13
 * Purpose: Implementation of the class Document
 ***********************************************************************/


#include "Document.h"


////////////////////////////////////////////////////////////////////////
// Name:       Document::Document()
// Purpose:    Implementation of Document::Document()
// Return:
////////////////////////////////////////////////////////////////////////

Document::Document(Ihm* interface) : QObject()
{
    m_moteurRecherche << new Google();
    m_moteurRecherche << new Yahoo();
    m_moteurRecherche << new Bing();
    m_ihm = interface;
    m_file = NULL;

    // Quand la requete est terminer, execute traiterReponse
    QObject::connect(m_moteurRecherche[0], SIGNAL(requetFini(int)), this, SLOT(traiterReponse(int)));
    QObject::connect(m_moteurRecherche[1], SIGNAL(requetFini(int)), this, SLOT(traiterReponse(int)));
    QObject::connect(m_moteurRecherche[2], SIGNAL(requetFini(int)), this, SLOT(traiterReponse(int)));
    // Quand le traitement est fini
    QObject::connect(this, SIGNAL(traitementFini()), m_ihm, SLOT(result()));
    // Si il y a une erreur lors de la requete
    QObject::connect(m_moteurRecherche[0], SIGNAL(erreurRequet(bool,QString)), m_ihm, SLOT(result(bool,QString)));
    QObject::connect(m_moteurRecherche[1], SIGNAL(erreurRequet(bool,QString)), m_ihm, SLOT(result(bool,QString)));
    QObject::connect(m_moteurRecherche[2], SIGNAL(erreurRequet(bool,QString)), m_ihm, SLOT(result(bool,QString)));
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::~Document()
// Purpose:    Implementation of Document::~Document()
// Return:
////////////////////////////////////////////////////////////////////////

Document::~Document()
{
       delete m_moteurRecherche[0];
       delete m_moteurRecherche[1];
       delete m_moteurRecherche[2];
       if(m_file != NULL) delete m_file;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getText()
// Purpose:    Implementation of Document::getText()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getText()
{
   return m_text;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::setText(QString text)
// Purpose:    Implementation of Document::setText()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::setText(QString text)
{
   m_text = text;
}


////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterDocument()
// Purpose:    Implementation of Document::traiterDocument()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterDocument()
{
    // Récupere les donné de l'ihm
    initialisation();
    // traite l'envoi la 1er requete
    if(m_ihm->isSelect(0))
        traiterEnvoie(0);
    if(m_ihm->isSelect(1))
        traiterEnvoie(1);
    if(m_ihm->isSelect(2))
        traiterEnvoie(2);
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterEnvoie()
// Purpose:    Implementation of Document::traiterEnvoie()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterEnvoie(int idMoteurRecherche)
{
    m_requet++;
    m_indiceCible[idMoteurRecherche]++;
    if(m_requet == m_nbRequet) // Toute les requete on été traiter
        emit traitementFini();//signal de fin
    else if(m_indiceCible[idMoteurRecherche] == m_textCible.size())
        ;// tout les requettes de ce moteur de recherche on été effectuer
    else{
        if(m_ihm->focusTab() != 1)
            emit progress(5+(int)((float)m_requet/(float)m_nbRequet*90),"Envoi des requetes... "+QString::number(m_requet)+"/"+QString::number(m_nbRequet));
        m_moteurRecherche[idMoteurRecherche]->setText(m_textCible[m_indiceCible[idMoteurRecherche]].getText());
        // Envoi la requette
        m_moteurRecherche[idMoteurRecherche]->sendRequest();
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::traiterReponse(bool error,QString errorString)
// Purpose:    Implementation of Document::traiterReponse()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::traiterReponse(int idMoteurRecherche)
{
        // Détermine si le texte est plagier
        bool b=m_moteurRecherche[idMoteurRecherche]->traiterDOM();
        // Stock le résulta
        m_textCible[m_indiceCible[idMoteurRecherche]].setResult(b,m_moteurRecherche[idMoteurRecherche]->getUrl(),idMoteurRecherche);
        // Passe a la requete suivante
        traiterEnvoie(idMoteurRecherche);
}


////////////////////////////////////////////////////////////////////////
// Name:       Document::initialisation()
// Purpose:    Implementation of Document::initialisation()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::initialisation()
{
    m_textCible.clear();
    m_text="";
    m_requet=0;
    m_indiceCible[0]=-1;
    m_indiceCible[1]=-1;
    m_indiceCible[2]=-1;

    int focus=m_ihm->focusTab();

    if(focus == 1){//Par texte
        m_text=m_ihm->getText();
        m_textCible << TextCible(m_text.trimmed());
    }
    else{
        emit progress(0,"Selection des texts cible...");
        if(focus == 2) {// Par document
            m_text=m_ihm->getDocument();
            determinTextCible();
        }
        else  // Par fichier
        {   /*
            extractTextFile();
            triTextFile();
            m_text=m_docx->getText();
            determinDocxCible();
            */
            m_text=m_file->getText();
            determinTextCibleFile();
        }
    }

    m_nbRequet=0;
    m_nbRequet+=(m_ihm->isSelect(0))? 1 : 0;
    m_nbRequet+=(m_ihm->isSelect(1))? 1 : 0;
    m_nbRequet+=(m_ihm->isSelect(2))? 1 : 0;
    m_requet-=m_nbRequet;
    m_nbRequet*=m_textCible.size();
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::determinTextCibleFile()
// Purpose:    Implementation of Document::determinTextCibleFile()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::determinTextCibleFile()
{
    QStringList cible = m_file->getCible();
    for(int i=0;i < cible.size();i++)
        m_textCible << TextCible((cible[i]).trimmed());
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::determinTextCible()
// Purpose:    Implementation of Document::determinTextCible()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::determinTextCible()
{
        QStringList list = m_text.split(".");
        QStringList listFinal;
        QStringList list2;
        int n;
        QString s;

        for(int i=0;i<list.size();i++){
            list2=(list[i]).split(" ");
            n=list2.size()/10;
            for(int j=0;j < n ;j++){
                s="";
                for(int h=0;h<10;h++)
                    s += list2[j*10+h]+" ";
                listFinal << s;

            }
            s="";
            for(int h=(10*n);h<list2.size();h++)
                s+=list2[h]+" ";
            listFinal << s;
            list2.clear();
        }

        for(int i=0;i < listFinal.size();i++)
            m_textCible << TextCible((listFinal[i]).trimmed());

}

////////////////////////////////////////////////////////////////////////
// Name:       Document::textIsPlagier()
// Purpose:    Implementation of Document::textIsPlagier()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Document::textIsPlagier()
{
    return m_textCible[0].isPlagier();
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getUrlTextPlagier()
// Purpose:    Implementation of Document::getUrlTextPlagier()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getUrlTextPlagier()
{
    return m_textCible[0].getUrl();
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getTextEnrichi()
// Purpose:    Implementation of Document::getTextEnrichi()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getDocumentEnrichi(){
    QString doc=m_text;
    emit progress(95,"Traitement des résultats... ");
    for(int i=0;i<m_textCible.size();i++)
        if(m_textCible[i].isPlagier())
            doc.replace(m_textCible[i].getText(),"<a style=\"text-decoration:none;background:yellow;color:black;\" href=\""+m_textCible[i].getUrl()+"\" >"+m_textCible[i].getText()+"</a>");
    return doc;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::setFile(QString file)
// Purpose:    Implementation of Document::setFile()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Document::setFile(QString file)
{
    if(m_file != NULL) delete m_file;

    QString extention(file);
    int pos=0;

    while(pos != -1){
        pos=extention.indexOf(".",0,Qt::CaseInsensitive);
        if(pos != -1 ) extention=extention.right(extention.size()-pos-1);
    }

    if(extention == "docx")
        m_file = new TextDocx(file);

    if(!m_file->fileIsValid())
    {
        delete m_file;
        m_file = NULL;
        return false;
    }

    return true;
}
