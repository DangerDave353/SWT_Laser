#-------------------------------------------------
#
# Project created by QtCreator 2015-06-18T12:03:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SWT_Projekt_Laser
TEMPLATE = app


SOURCES += main.cpp\
        main.cpp \
    state.cpp \
    statebereit.cpp \
    statelaseran.cpp \
    statelaseraus.cpp \
    statemove.cpp \
    control.cpp

HEADERS  += main.h \
    state.h \
    statebereit.h \
    statelaseran.h \
    statelaseraus.h \
    statemove.h \
    control.h

FORMS    += main.ui
