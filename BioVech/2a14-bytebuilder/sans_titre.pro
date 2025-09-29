#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT += printsupport
QT += charts
QT += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Micro_layout.cpp \
    Microorganisme.cpp \
    PredictionEvolution.cpp \
    autohidedockwidget.cpp \
    connection.cpp \
    main.cpp

HEADERS += \
    Micro_layout.h \
    Microorganisme.h \
    PredictionEvolution.h \
    autohidedockwidget.h \
    connection.h

FORMS += \
    Micro_layout.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Static.qrc

DISTFILES += \
    Static/1.png \
    Static/2.png \
    Static/3.png \
    Static/4.png \
    Static/5.png \
    Static/6.png \
    Static/7.png \
    Static/8.png \
    Static/IOS_Google_icon.png \
    Static/dashboard.png \
    Static/github logo.png \
    Static/logo_small.png



