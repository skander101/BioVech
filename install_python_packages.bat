@echo off
echo ====================================================================
echo    Installing required Python packages for voice recognition...
echo    This script will request administrator privileges if needed
echo ====================================================================

:: Check for admin privileges
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo Requesting administrator privileges...
    powershell -Command "Start-Process '%~dpnx0' -Verb RunAs"
    exit /b
)

:: Check if Python is installed
python --version > nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo Python not found. Please install Python from https://www.python.org/downloads/
    echo Make sure to check "Add Python to PATH" during installation.
    pause
    exit /b 1
)

echo Python found. Installing required packages...

:: Try to install PyAudio
echo Installing PyAudio...
python -m pip install --upgrade pip
python -m pip install pyaudio

if %ERRORLEVEL% neq 0 (
    echo.
    echo PyAudio installation failed. Trying alternative method...
    echo.
    
    :: Get Python version to determine wheel file
    for /f "tokens=2" %%V in ('python -c "import sys; print(sys.version.split()[0])"') do set PYTHON_VERSION=%%V
    for /f "tokens=1,2 delims=." %%A in ("%PYTHON_VERSION%") do set PYTHON_MAJOR_MINOR=%%A%%B
    
    echo Python version: %PYTHON_VERSION% (Major.Minor: %PYTHON_MAJOR_MINOR%)
    
    :: Download and install appropriate wheel file
    echo Downloading appropriate PyAudio wheel...
    
    :: Detect architecture
    if defined PROCESSOR_ARCHITECTURE (
        if "%PROCESSOR_ARCHITECTURE%"=="AMD64" (
            set ARCH=amd64
        ) else (
            set ARCH=win32
        )
    ) else (
        set ARCH=win32
    )
    
    echo Architecture: %ARCH%
    
    :: Create a temporary directory
    set TEMP_DIR=%TEMP%\pyaudio_install
    mkdir %TEMP_DIR% 2>nul
    
    :: Download wheel file
    powershell -Command "& {[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest -Uri \"https://download.lfd.uci.edu/pythonlibs/archived/PyAudio-0.2.11-cp%PYTHON_MAJOR_MINOR%-cp%PYTHON_MAJOR_MINOR%%PYTHON_MAJOR_MINOR%-win_%ARCH%.whl\" -OutFile \"%TEMP_DIR%\pyaudio.whl\"}"
    
    if %ERRORLEVEL% neq 0 (
        echo Failed to download wheel file. Please download manually from:
        echo https://www.lfd.uci.edu/~gohlke/pythonlibs/#pyaudio
        pause
        exit /b 1
    )
    
    :: Install the wheel
    echo Installing PyAudio from wheel...
    python -m pip install %TEMP_DIR%\pyaudio.whl
    
    if %ERRORLEVEL% neq 0 (
        echo.
        echo PyAudio installation failed even with wheel file.
        echo.
        echo If you're on Windows, you may need to install the PyAudio wheel manually.
        echo.
        echo 1. First, find your Python version:
        python --version
        echo.
        echo 2. Download the appropriate wheel file for your Python version from:
        echo    https://www.lfd.uci.edu/~gohlke/pythonlibs/#pyaudio
        echo.
        echo 3. Install the downloaded wheel file using:
        echo    python -m pip install C:\path\to\downloaded\PyAudio-file.whl
        echo.
        pause
        exit /b 1
    ) else (
        echo PyAudio successfully installed from wheel file!
        rmdir /s /q %TEMP_DIR%
    )
)

:: Install Vosk for speech recognition
echo.
echo Installing Vosk for speech recognition...
python -m pip install vosk

if %ERRORLEVEL% neq 0 (
    echo.
    echo Vosk installation failed.
    echo.
    echo Please try to install it manually with:
    echo python -m pip install vosk
    echo.
    pause
    exit /b 1
)

echo.
echo All required packages installed successfully!
echo.
echo You can now run the application and use voice recognition.
echo.
echo NOTE: You also need the voice model files (vosk-model-small-fr-0.22 directory)
echo in your application directory. If you don't have them, please download from:
echo https://alphacephei.com/vosk/models
echo.
pause 