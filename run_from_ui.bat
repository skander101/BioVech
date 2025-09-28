@echo off
echo ===== RUNNING APPLICATION FROM UI FILES =====
echo This script will rebuild the app with direct UI files

REM Run the clean script first
call clean_rebuild.bat

REM Run qmake with the -r flag to recursive rebuild
echo.
echo Running qmake...
qmake -r

REM Force touch the UI files to update their timestamps
echo.
echo Updating UI files...
copy /b credentials.ui +,,
copy /b personnel.ui +,,

REM Build the application
echo.
echo Building application...
mingw32-make

REM Run the application if build was successful
if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Running application...
    echo.
    start debug\hell.exe
) else (
    echo.
    echo Build failed. Please check the error messages above.
    echo.
)

pause 