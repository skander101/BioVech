QT += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Add OpenCV include path
INCLUDEPATH += "C:/opencv/build/include"

# Add OpenCV library path
LIBS += -L"C:/opencv/build/x64/vc16/lib"

# Link the appropriate library based on build mode
CONFIG(debug, debug|release) {
    LIBS += -lopencv_world4100d # Debug version
} else {
    LIBS += -lopencv_world4100  # Release version
}

# Add OpenCV DLL path to the runtime environment (optional but recommended)
win32 {
    CONFIG(debug, debug|release) {
        QMAKE_POST_LINK += $$quote(cmd /c xcopy /y "C:\\opencv\\build\\x64\\vc16\\bin\\opencv_world4100d.dll" "$(OUT_PWD)\\$(DESTDIR)")
    } else {
        QMAKE_POST_LINK += $$quote(cmd /c xcopy /y "C:\\opencv\\build\\x64\\vc16\\bin\\opencv_world4100.dll" "$(OUT_PWD)\\$(DESTDIR)")
    }
}
