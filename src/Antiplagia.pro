######################################################################
# Automatically generated by qmake (2.01a) Wed Mar 23 12:50:49 2011
######################################################################

QT += core gui network xml webkit

TEMPLATE = app
TARGET = Antiplagia
DESTDIR = ../workdir/bin

DEPENDPATH += . \
              Documents \
              Fichiers \
              Formulaires \
              Headers \
              Interfaces \
              MoteurRecherches \
              Ressources

INCLUDEPATH += . Headers

# Input
HEADERS += Headers/bing.h \
           Headers/document.h \
           Headers/extension.h \
           Headers/google.h \
           Headers/ihm.h \
           Headers/ihmPopup.h \
           Headers/listTextCible.h \
           Headers/moteurRecherche.h \
           Headers/textCible.h \
           Headers/textdocx.h \
           Headers/textodt.h \
           Headers/textPdf.h \
           Headers/xstring.h \
           Headers/yahoo.h \
           Headers/settings.h


FORMS += Formulaires/ihm.ui \
         Formulaires/progress.ui \
         Formulaires/resultat.ui \
         Formulaires/settings.ui


SOURCES += main.cpp \
           Documents/document.cpp \
           Documents/listTextCible.cpp \
           Documents/textCible.cpp \
           Documents/xstring.cpp \
           Fichiers/extension.cpp \
           Fichiers/textdocx.cpp \
           Fichiers/textodt.cpp \
           Fichiers/textPdf.cpp \
           Interfaces/ihm.cpp \
           Interfaces/ihmPopup.cpp \
           MoteurRecherches/bing.cpp \
           MoteurRecherches/google.cpp \
           MoteurRecherches/moteurRecherche.cpp \
           MoteurRecherches/yahoo.cpp \
           Interfaces/settings.cpp


RESOURCES += Ressources/antiplagia.qrc

win32:RC_FILE += Ressources/ico.rc

TRANSLATIONS = Traduction/antiplagia_en.ts \
               Traduction/antiplagia_es.ts \
               Traduction/antiplagia_it.ts \
               Traduction/antiplagia_de.ts \
               Traduction/antiplagia_ar.ts \
               Traduction/antiplagia_fr.ts
