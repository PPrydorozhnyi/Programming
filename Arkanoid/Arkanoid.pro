#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T18:23:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arkanoid
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        gamewidget.cpp \
    game.cpp \
    fallingball.cpp \
    mainwidget.cpp \
    activewindow.cpp \
    results.cpp \
    menu.cpp \
    playing.cpp \
    logger.cpp \
    readlog.cpp \
    buttonwidget.cpp \
    labelwidget.cpp \
    loglabel.cpp

HEADERS  += gamewidget.h \
    game.h \
    fallingball.h \
    mainwidget.h \
    results.h \
    menu.h \
    activewindow.h \
    playing.h \
    logger.h \
    readlog.h \
    buttonwidget.h \
    labelwidget.h \
    loglabel.h

FORMS    += gamewidget.ui \
    mainwidget.ui \
    activewindow.ui

RESOURCES += \
    myres.qrc
