/***********************************************************************
 * Module:  Ihm.h
 * Author:  fabien
 * Modified: vendredi 11 février 2011 16:46:28
 * Purpose: Declaration of the class Ihm
 ***********************************************************************/

#ifndef IHM_H
#define IHM_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include "Document.h"
#include "IhmPopup.h"
#include "Settings.h"

namespace Ui {
    class Ihm;
}
class Document;
class IhmPopup;
class Settings;

class Ihm : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ihm(QWidget *parent = 0);
    ~Ihm();
    QFile *m_file;
    QString getText();
    QString getNameFile();
    QString getDocument();
    QString getDir();
    int focusTab();
    void enabelDisabel(bool b);
    bool erreurChamp();
    bool isSelect(int idMoteurRecherche);
    int getNbMots();
    bool getParTaille();
    bool getParPolice();
    int getPrCentATester();
    int nbMaxRequete();

public slots:
    void traitement();
    void aPropos();
    void preference();
    void documentation();
    void selectFile();
    void selectDir();
    void result(bool error = false , QString errorString = QString());
    void annulerTraitement();

private:
    Ui::Ihm *ui;
    Document *m_document;
    IhmPopup *m_popup;
    Settings *m_settings;

};

#endif /* IHM_H */
