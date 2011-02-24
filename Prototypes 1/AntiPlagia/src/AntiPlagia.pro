#-------------------------------------------------
#
# Project created by QtCreator 2011-02-15T18:17:51
#
#-------------------------------------------------

QT += core gui
QT += network
QT += webkit

TARGET = AntiPlagia
TEMPLATE = app


SOURCES += main.cpp\
        Ihm.cpp \
    MoteurRecherche.cpp \
    Google.cpp \
    Document.cpp \
    TextCible.cpp \
    ListTextCicble.cpp \
    IhmPopup.cpp

HEADERS += Ihm.h \
    MoteurRecherche.h \
    Google.h \
    Document.h \
    TextCible.h \
    ListTextCicble.h \
    IhmPopup.h

FORMS += ihm.ui
