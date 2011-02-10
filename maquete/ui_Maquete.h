/********************************************************************************
** Form generated from reading UI file 'Maquete.ui'
**
** Created: Thu 10. Feb 01:16:24 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAQUETE_H
#define UI_MAQUETE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AntiPlagia
{
public:
    QAction *actionQuiter;
    QAction *actionPr_f_rence;
    QAction *actionDocumentation;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *Texte;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QWidget *Document;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QTextEdit *textEdit;
    QWidget *fichier;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuOption;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AntiPlagia)
    {
        if (AntiPlagia->objectName().isEmpty())
            AntiPlagia->setObjectName(QString::fromUtf8("AntiPlagia"));
        AntiPlagia->resize(672, 398);
        actionQuiter = new QAction(AntiPlagia);
        actionQuiter->setObjectName(QString::fromUtf8("actionQuiter"));
        actionPr_f_rence = new QAction(AntiPlagia);
        actionPr_f_rence->setObjectName(QString::fromUtf8("actionPr_f_rence"));
        actionDocumentation = new QAction(AntiPlagia);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        centralwidget = new QWidget(AntiPlagia);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setChecked(true);

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setEnabled(true);
        checkBox_3->setChecked(true);

        verticalLayout->addWidget(checkBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 0, 1, 2, 1);

        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Texte = new QWidget();
        Texte->setObjectName(QString::fromUtf8("Texte"));
        verticalLayout_2 = new QVBoxLayout(Texte);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Texte);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Texte);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(Texte, QString());
        Document = new QWidget();
        Document->setObjectName(QString::fromUtf8("Document"));
        verticalLayout_5 = new QVBoxLayout(Document);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(Document);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        textEdit = new QTextEdit(Document);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);

        tabWidget->addTab(Document, QString());
        fichier = new QWidget();
        fichier->setObjectName(QString::fromUtf8("fichier"));
        gridLayout_3 = new QGridLayout(fichier);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(fichier);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(fichier);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 1, 0, 1, 1);

        toolButton = new QToolButton(fichier);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        gridLayout_3->addWidget(toolButton, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 0, 1, 1);

        tabWidget->addTab(fichier, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        AntiPlagia->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AntiPlagia);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 672, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuOption = new QMenu(menubar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        AntiPlagia->setMenuBar(menubar);
        statusbar = new QStatusBar(AntiPlagia);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AntiPlagia->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuOption->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionQuiter);
        menuOption->addAction(actionPr_f_rence);
        menuAide->addAction(actionDocumentation);

        retranslateUi(AntiPlagia);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AntiPlagia);
    } // setupUi

    void retranslateUi(QMainWindow *AntiPlagia)
    {
        AntiPlagia->setWindowTitle(QApplication::translate("AntiPlagia", "Anti-plagia", 0, QApplication::UnicodeUTF8));
        actionQuiter->setText(QApplication::translate("AntiPlagia", "Quitter", 0, QApplication::UnicodeUTF8));
        actionPr_f_rence->setText(QApplication::translate("AntiPlagia", "Pr\303\251f\303\251rences", 0, QApplication::UnicodeUTF8));
        actionDocumentation->setText(QApplication::translate("AntiPlagia", "Documentation", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AntiPlagia", "Moteur de recherche", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("AntiPlagia", "Google", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("AntiPlagia", "Yahou", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("AntiPlagia", "Bing", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AntiPlagia", "Entrer le texte \303\240 v\303\251rifier :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Texte), QApplication::translate("AntiPlagia", "Le Texte", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AntiPlagia", "Entrer le texte du document :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Document), QApplication::translate("AntiPlagia", "Le document", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        fichier->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("AntiPlagia", "Selectionrt un fichier .doc ou .pdf :", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("AntiPlagia", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(fichier), QApplication::translate("AntiPlagia", "Le fichier", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AntiPlagia", "Choisissez un mode de saisie :", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("AntiPlagia", "Fichier", 0, QApplication::UnicodeUTF8));
        menuOption->setTitle(QApplication::translate("AntiPlagia", "Option", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("AntiPlagia", "Aide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AntiPlagia: public Ui_AntiPlagia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAQUETE_H
