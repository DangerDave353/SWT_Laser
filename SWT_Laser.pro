#-------------------------------------------------
#
# Project created by QtCreator 2015-07-02T19:12:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SWT_Laser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    state.cpp \
    control.cpp \
    statebereit.cpp \
    statelaseran.cpp \
    statelaseraus.cpp \
    statemove.cpp

HEADERS  += mainwindow.h \
    state.h \
    control.h \
    statebereit.h \
    statelaseran.h \
    statelaseraus.h \
    statemove.h

FORMS    += mainwindow.ui
