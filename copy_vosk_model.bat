@echo off
echo Copying Vosk model directory...

set SOURCE_DIR=vosk-model-small-fr-0.22
set TARGET_DIR=build\Desktop_Qt_6_9_0_MSVC2022_64bit-Debug\vosk-model-small-fr-0.22

if not exist %SOURCE_DIR% (
    echo Error: Source directory does not exist: %SOURCE_DIR%
    exit /b 1
)

if not exist build\Desktop_Qt_6_9_0_MSVC2022_64bit-Debug (
    echo Error: Build directory does not exist: build\Desktop_Qt_6_9_0_MSVC2022_64bit-Debug
    echo Please make sure to build the project first.
    exit /b 1
)

if not exist %TARGET_DIR% (
    echo Creating target directory: %TARGET_DIR%
    mkdir %TARGET_DIR%
)

echo Copying model files...
xcopy /E /I /Y "%SOURCE_DIR%" "%TARGET_DIR%"

if %ERRORLEVEL% neq 0 (
    echo Error copying files. Please check paths and permissions.
    exit /b 1
)

echo Vosk model directory copied successfully to: %TARGET_DIR%
echo You can now run the application. 