QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connection.h \
    mainwindow.h

FORMS += \
    face_embedding.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Python integration
win32 {
    PYTHON_PATH = C:/Python310
    INCLUDEPATH += $${PYTHON_PATH}/include
    LIBS += -L$${PYTHON_PATH}/libs -lpython310
}

# Add TensorFlow and DeepFace dependencies
# For a complete PyQt project, these dependencies are handled by Python
