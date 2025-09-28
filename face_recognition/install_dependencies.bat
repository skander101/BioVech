@echo off
echo Installing face recognition dependencies...

:: Check if Python is installed
python --version > nul 2>&1
if %errorlevel% neq 0 (
    echo Python is not installed or not in PATH.
    echo Please install Python from https://www.python.org/downloads/
    pause
    exit /b 1
)

:: Install pip if not already installed
python -m ensurepip --upgrade

:: Install requirements
echo Installing required packages...
python -m pip install -r "%~dp0\requirements.txt"

:: Create models directory
if not exist "%~dp0\models" mkdir "%~dp0\models"

:: Create Python extraction script using built-in libraries
echo import sys, bz2, os > "%~dp0\extract.py"
echo def extract_bz2(input_file, output_file): >> "%~dp0\extract.py"
echo     print(f"Extracting {os.path.basename(input_file)} to {os.path.basename(output_file)}...") >> "%~dp0\extract.py"
echo     with bz2.open(input_file, "rb") as f_in, open(output_file, "wb") as f_out: >> "%~dp0\extract.py"
echo         f_out.write(f_in.read()) >> "%~dp0\extract.py"
echo     print(f"Extraction complete for {os.path.basename(output_file)}") >> "%~dp0\extract.py"
echo if __name__ == "__main__": >> "%~dp0\extract.py"
echo     if len(sys.argv) != 3: >> "%~dp0\extract.py"
echo         print("Usage: python extract.py input_file.bz2 output_file") >> "%~dp0\extract.py"
echo         sys.exit(1) >> "%~dp0\extract.py"
echo     extract_bz2(sys.argv[1], sys.argv[2]) >> "%~dp0\extract.py"

:: Download and extract shape predictor model
if not exist "%~dp0\models\shape_predictor_68_face_landmarks.dat" (
    echo Downloading shape predictor model...
    powershell -Command "& {Invoke-WebRequest -Uri 'http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2' -OutFile '%~dp0\models\shape_predictor_68_face_landmarks.dat.bz2'}"
    
    echo Extracting shape predictor model...
    python "%~dp0\extract.py" "%~dp0\models\shape_predictor_68_face_landmarks.dat.bz2" "%~dp0\models\shape_predictor_68_face_landmarks.dat"
)

:: Download and extract face recognition model
if not exist "%~dp0\models\dlib_face_recognition_resnet_model_v1.dat" (
    echo Downloading face recognition model...
    powershell -Command "& {Invoke-WebRequest -Uri 'http://dlib.net/files/dlib_face_recognition_resnet_model_v1.dat.bz2' -OutFile '%~dp0\models\dlib_face_recognition_resnet_model_v1.dat.bz2'}"
    
    echo Extracting face recognition model...
    python "%~dp0\extract.py" "%~dp0\models\dlib_face_recognition_resnet_model_v1.dat.bz2" "%~dp0\models\dlib_face_recognition_resnet_model_v1.dat"
)

:: Download and extract face detector model
if not exist "%~dp0\models\mmod_human_face_detector.dat" (
    echo Downloading face detector model...
    powershell -Command "& {Invoke-WebRequest -Uri 'http://dlib.net/files/mmod_human_face_detector.dat.bz2' -OutFile '%~dp0\models\mmod_human_face_detector.dat.bz2'}"
    
    echo Extracting face detector model...
    python "%~dp0\extract.py" "%~dp0\models\mmod_human_face_detector.dat.bz2" "%~dp0\models\mmod_human_face_detector.dat"
)

:: Clean up temporary files
if exist "%~dp0\extract.py" del "%~dp0\extract.py"
if exist "%~dp0\models\*.bz2" del "%~dp0\models\*.bz2"

echo Installation complete!
echo You can now run the face recognition module.
pause 