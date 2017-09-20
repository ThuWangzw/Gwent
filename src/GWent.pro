#-------------------------------------------------
#
# Project created by QtCreator 2017-09-07T14:32:09
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GWent
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

CONFIG += resources_big
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cardinfo.cpp \
    cardimage.cpp \
    card.cpp \
    herocard.cpp \
    abilitycard.cpp \
    logicmatching.cpp \
    interactionmatching.cpp \
    abstractlogic.cpp \
    abstractinteraction.cpp \
    showmainmenu.cpp \
    abstractshow.cpp \
    logicchoosecardgroup.cpp \
    interactionchoosecardgroup.cpp \
    showchoosecardgroup.cpp \
    logicdispatchcards.cpp \
    interactiondispatchcards.cpp \
    showdispatchcards.cpp \
    battlefield.cpp \
    logicmaingame.cpp \
    showmaingame.cpp \
    interactionmaingame.cpp \
    logicbetweengame.cpp \
    showbetweengame.cpp \
    interactionbetweengame.cpp \
    showtcpconnect.cpp \
    logictcpconnect.cpp \
    interactiontcpconnect.cpp \
    interactionmainmenu.cpp \
    showgameend.cpp \
    interactiongameend.cpp

HEADERS += \
        mainwindow.h \
    cardinfo.h \
    cardimage.h \
    card.h \
    herocard.h \
    abilitycard.h \
    logicmatching.h \
    interactionmatching.h \
    abstractlogic.h \
    abstractinteraction.h \
    showmainmenu.h \
    abstractshow.h \
    logicchoosecardgroup.h \
    interactionchoosecardgroup.h \
    showchoosecardgroup.h \
    logicdispatchcards.h \
    interactiondispatchcards.h \
    showdispatchcards.h \
    battlefield.h \
    logicmaingame.h \
    showmaingame.h \
    interactionmaingame.h \
    logicbetweengame.h \
    showbetweengame.h \
    interactionbetweengame.h \
    showtcpconnect.h \
    logictcpconnect.h \
    interactiontcpconnect.h \
    interactionmainmenu.h \
    showgameend.h \
    interactiongameend.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resource_image.qrc \
    resource_json.qrc
