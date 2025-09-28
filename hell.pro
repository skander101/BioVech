QT       += core gui widgets sql printsupport multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    credentials.cpp \
    employe.cpp \
    main.cpp \
    autohidedockwidget.cpp \
    personnel.cpp \
    piechartwidget.cpp

HEADERS += \
    autohidedockwidget.h \
    connection.h \
    credentials.h \
    employe.h \
    personnel.h \
    piechartwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    static.qrc

FORMS += \
    credentials.ui \
    personnel.ui

# Copy Python scripts to the build directory
python.files = speech_to_text.py face_recognition_module.py requirements.txt
python.path = $$OUT_PWD  # Output directory (build directory)
INSTALLS += python

# Use a more direct approach for copying the Python scripts during build
win32 {
    PYTHON_SCRIPT = $$shell_path($$PWD/speech_to_text.py)
    FACE_SCRIPT = $$shell_path($$PWD/face_recognition_module.py)
    REQUIREMENTS = $$shell_path($$PWD/requirements.txt)
    OUTPUT_DIR = $$shell_path($$OUT_PWD)
    
    # Create a script.bat file to be executed for copying
    SCRIPT_FILE = $$OUT_PWD/copy_script.bat
    SCRIPT_CONTENT = "echo Copying Python scripts...\r\n"
    SCRIPT_CONTENT += "copy /y \"$$PYTHON_SCRIPT\" \"$$OUTPUT_DIR\"\r\n"
    SCRIPT_CONTENT += "copy /y \"$$FACE_SCRIPT\" \"$$OUTPUT_DIR\"\r\n"
    SCRIPT_CONTENT += "copy /y \"$$REQUIREMENTS\" \"$$OUTPUT_DIR\"\r\n"
    SCRIPT_CONTENT += "if errorlevel 1 (\r\n"
    SCRIPT_CONTENT += "  echo Warning: Failed to copy Python scripts, but continuing build...\r\n"
    SCRIPT_CONTENT += "  exit /b 0\r\n"
    SCRIPT_CONTENT += ")\r\n"
    
    write_file($$SCRIPT_FILE, SCRIPT_CONTENT)
    
    # Execute the batch file and continue even if it fails
    QMAKE_POST_LINK += cmd /c $$shell_path($$SCRIPT_FILE) || exit /b 0 $$escape_expand(\\n\\t)
    
    # Add messages about required files
    message("Note: The Vosk model directory should be copied manually if needed.")
    message("Copy from: $$PWD/vosk-model-small-fr-0.22")
    message("To: $$OUT_PWD/vosk-model-small-fr-0.22")
    message("Note: Make sure to install the required Python packages:")
    message("Run: pip install -r requirements.txt")
} else {
    # For non-Windows platforms, use a simpler approach
    vosk_model.files = vosk-model-small-fr-0.22/*
    vosk_model.path = $$OUT_PWD/vosk-model-small-fr-0.22
    INSTALLS += vosk_model
    
    # Also for direct runs
    QMAKE_POST_LINK += $$escape_expand(\\n\\t) mkdir -p $$shell_quote($$OUT_PWD/vosk-model-small-fr-0.22) $$escape_expand(\\n\\t)
    QMAKE_POST_LINK += $$QMAKE_COPY $$shell_quote($$PWD/speech_to_text.py) $$shell_quote($$OUT_PWD)
    QMAKE_POST_LINK += $$QMAKE_COPY $$shell_quote($$PWD/face_recognition_module.py) $$shell_quote($$OUT_PWD)
    QMAKE_POST_LINK += $$QMAKE_COPY $$shell_quote($$PWD/requirements.txt) $$shell_quote($$OUT_PWD)
}
