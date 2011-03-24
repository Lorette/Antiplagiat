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
    QObject::connect(m_moteurRecherche[0], SIGNAL(erreurRequet(bool,QString)), m_ihm, SLOT(annulerTraitement()));
    QObject::connect(m_moteurRecherche[1], SIGNAL(erreurRequet(bool,QString)), m_ihm, SLOT(annulerTraitement()));
    QObject::connect(m_moteurRecherche[2], SIGNAL(erreurRequet(bool,QString)), m_ihm, SLOT(annulerTraitement()));
    QObject::connect(m_moteurRecherche[0], SIGNAL(erreurRequet(bool,QString)), this, SLOT(annulerTraitement()));
    QObject::connect(m_moteurRecherche[1], SIGNAL(erreurRequet(bool,QString)), this, SLOT(annulerTraitement()));
    QObject::connect(m_moteurRecherche[2], SIGNAL(erreurRequet(bool,QString)), this, SLOT(annulerTraitement()));
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
    if(!m_annuler){
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
    m_annuler=false;

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
        {
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
// Name:       Document::getTextEnrichi(int mode)
// Purpose:    Implementation of Document::getTextEnrichi()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getDocumentEnrichi(int mode){
    QString doc=m_text;
    if(mode == 1){
        emit progress(95,"Traitement des résultats... ");
        for(int i=0;i<m_textCible.size();i++)
            if(m_textCible[i].isPlagier())
                doc.replace(m_textCible[i].getText(),"<a style=\"text-decoration:none;background:yellow;color:black;\" href=\""+m_textCible[i].getUrl()+"\" >"+m_textCible[i].getText()+"</a>");
    }
    else if (mode == 2){
        QList<MemeSource> list;
        QList<int> indiceTraiter;
        int indiceColor=0;
        QString color[20]= {"yellow","YellowGreen","Wheat","Turquoise","SpringGreen","DeepPink","Silver","MistyRose","MediumPurple","DarkKhaki","GoldenRod","Tan","DarkSalmon","Coral","BlueViolet","Aqua","Plum","MediumBlue","DarkOrchid","Aquamarine"};
        for(int i=0; i < m_textCible.size() ; i++ ){
            if( !indiceTraiter.contains(i) && m_textCible[i].isPlagier()){
                list = getMemeSource(m_textCible[i].getUrl());
                for(int j=0;j<list.size();j++){
                    indiceTraiter << list[j].position;
                    doc.replace(list[j].text,"<a style=\"text-decoration:none;background:"+color[indiceColor%20]+";color:black;\" href=\""+m_textCible[i].getUrl()+"\" >"+list[j].text+"</a>");
                }
                indiceColor++;
            }
            list.clear();
        }
    }
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

    if(file.endsWith(".docx",Qt::CaseInsensitive))
        m_file = new TextDocx(file);
    if(file.endsWith(".pdf",Qt::CaseInsensitive))
        m_file = new TextPdf(file);
    if(file.endsWith(".odt",Qt::CaseInsensitive))
        m_file = new TextOdt(file);

    if(!m_file->fileIsValid())
    {
        delete m_file;
        m_file = NULL;
        return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::annulerTraitement()
// Purpose:    Implementation of Document::annulerTraitement()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::annulerTraitement()
{
    m_annuler=true;
}


////////////////////////////////////////////////////////////////////////
// Name:       Document::getMemeSource(QString source)
// Purpose:    Implementation of Document::getMemeSource()
// Return:     QList<MemeSource>
////////////////////////////////////////////////////////////////////////

QList<MemeSource> Document::getMemeSource(QString source)
{
    QList<MemeSource> list;
    for(int i=0;i<m_textCible.size();i++){
        if( ( source == m_textCible[i].getUrl() ) && m_textCible[i].isPlagier() ){
            MemeSource s;
            s.position=i;
            s.text=m_textCible[i].getText();
            list << s;
        }
    }

    return list;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getNbSource()
// Purpose:    Implementation of Document::getNbSource()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Document::getNbSource()
{
    int nb = 0;
    QStringList list;
    for(int i=0;i<m_textCible.size();i++)
        if( !list.contains(m_textCible[i].getUrl()) && m_textCible[i].isPlagier() ){
            nb++;
            list << m_textCible[i].getUrl();
        }
    return nb;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::getPrCentPlagier()
// Purpose:    Implementation of Document::getPrCentPlagier()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Document::getPrCentPlagier()
{
    int nbPlagier=0;
    for(int i=0;i<m_textCible.size();i++)
        if(m_textCible[i].isPlagier())
            nbPlagier++;

    return (int)((float)nbPlagier/(float)m_textCible.size()*100);
}


////////////////////////////////////////////////////////////////////////
// Name:       Document::getListSource()
// Purpose:    Implementation of Document::getListSource()
// Return:     QString
////////////////////////////////////////////////////////////////////////

QString Document::getListSource()
{
    QStringList list;
    QString listSource;
    for(int i=0;i<m_textCible.size();i++)
        if( !list.contains(m_textCible[i].getUrl()) && m_textCible[i].isPlagier() ){
            list << m_textCible[i].getUrl();
        }
    for(int i=0;i<list.size();i++)
        listSource+="<a href=\">"+list[i]+"\" >"+list[i]+"</a><br/>";

    return listSource;
}

////////////////////////////////////////////////////////////////////////
// Name:       Document::exportHtml(QString file)
// Purpose:    Implementation of Document::exportHtml()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Document::exportHtml(QString file)
{
    QString html="<html><head><style type=\"text/css\"> div#contenu { margin-left:15%;margin-right:15%;border-style:solid;border-width:2px;height:100%;padding:10px;}";
    html+=" div#info { border-bottom-style:solid;border-bottom-width:1px;} div#text {border-bottom-style:solid;border-bottom-width:1px;padding:10px;}";
    html+=" div#source {padding:10px;} table { width:100%;text-align:center;} .boutton { background-color:#E5E5E5;border:1px solid;border-color: black;padding: 2px;color:black;margin:5px;}";
    html+=" .boutton:hover { background-color:#C4C4C4;}</style></head>";

    html+="<body><div id=\"contenu\" ><div id=\"info\" ><table><tr><td><strong>Text plagier à "+QString::number(getPrCentPlagier())+"%</strong></td><td><p class=\"boutton\">Changer Mode Couleur</p></td><td><strong>Nombres de sources: "+QString::number(getNbSource())+"</strong></td></tr></table></div><div id=\"text\">";

    html+=getDocumentEnrichi(1);
    html+="</div><div id=\"source\">";
    html+=getListSource();
    html+="</div></div></body></html>";

    html.replace("\n","<br/>");

    QFile f(file);
    if (f.open(QFile::WriteOnly)) {
        QTextStream out(&f);
        out << html;
    }

}
