QT       += core network gui printsupport sql widgets qml quickwidgets charts location quickcontrols2 serialport \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dialogue.cpp \
    Evenement.cpp \
    autohidedockwidget.cpp \
    codearea.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    openlocationcode.cpp \
    routingservice.cpp

HEADERS += \
    Dialogue.h \
    Evenement.h \
    autohidedockwidget.h \
    codearea.h \
    connection.h \
    mainwindow.h \
    openlocationcode.h \
    routingservice.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
