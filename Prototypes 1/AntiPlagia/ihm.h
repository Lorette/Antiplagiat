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
#include "Document.h"

namespace Ui {
    class Ihm;
}
class Document;

class Ihm : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ihm(QWidget *parent = 0);
    ~Ihm();
    QString getText();
public slots:
    void ouvrirDialogue();

private:
    Ui::Ihm *ui;
    QLineEdit *m_QLineEdit;
    QPushButton *m_boutonDialogue;
    Document *m_document;
};

#endif /* IHM_H */
