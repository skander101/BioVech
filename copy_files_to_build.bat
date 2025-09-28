@echo off
echo Copying files to build directory...

:: Define source and destination paths
set SRC_DIR=%~dp0
set PYTHON_SCRIPT=%SRC_DIR%speech_to_text.py
set VOSK_MODEL=%SRC_DIR%vosk-model-small-fr-0.22
set BUILD_DIR=%SRC_DIR%build\Desktop_Qt_6_9_0_MSVC2022_64bit-Debug
set DEST_MODEL=%BUILD_DIR%\vosk-model-small-fr-0.22

echo Source directory: %SRC_DIR%
echo Build directory: %BUILD_DIR%

:: Check if source files exist
if not exist "%PYTHON_SCRIPT%" (
    echo Error: Python script not found at %PYTHON_SCRIPT%
    exit /b 1
)

if not exist "%VOSK_MODEL%" (
    echo Error: Vosk model directory not found at %VOSK_MODEL%
    exit /b 1
)

:: Create destination directories if needed
if not exist "%BUILD_DIR%" (
    echo Error: Build directory does not exist. Please build the project first.
    exit /b 1
)

:: Copy the Python script
echo Copying Python script...
copy /y "%PYTHON_SCRIPT%" "%BUILD_DIR%"
if %ERRORLEVEL% neq 0 (
    echo Error copying Python script.
    exit /b 1
)

:: Create and copy the Vosk model directory
echo Creating vosk model directory...
if not exist "%DEST_MODEL%" mkdir "%DEST_MODEL%"

echo Copying vosk model files...
xcopy /E /I /Y "%VOSK_MODEL%" "%DEST_MODEL%"
if %ERRORLEVEL% neq 0 (
    echo Error copying vosk model files.
    exit /b 1
)

echo.
echo All files copied successfully!
echo Python script: %BUILD_DIR%\speech_to_text.py
echo Vosk model: %DEST_MODEL%
echo.
echo You can now run the application.
pause 