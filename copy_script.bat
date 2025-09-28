@echo off
echo Copying Python scripts...

copy /y "%~dp0..\..\speech_to_text.py" "%~dp0"
copy /y "%~dp0..\..\face_recognition_module.py" "%~dp0"
copy /y "%~dp0..\..\requirements.txt" "%~dp0"

echo Done copying files. 