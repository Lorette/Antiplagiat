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

namespace Ui {
    class Ihm;
}
class Document;
class IhmPopup;

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
    int focusTab();
    void enabelDisabel(bool b);
    bool erreurChamp();
    bool isSelect(int idMoteurRecherche);

public slots:
    void traitement();
    void aPropos();
    void preference();
    void documentation();
    void selectFile();
    void result(bool error = false , QString errorString = QString());

private:
    Ui::Ihm *ui;
    Document *m_document;
    IhmPopup *m_popup;

};

#endif /* IHM_H */
