@echo off
echo Fixing AutoHideDockWidget files...

echo Compiling autohidedockwidget.cpp...
set PATH=%PATH%;C:\Qt\6.9.0\msvc2022_64\bin
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cl /c /I "C:\Qt\6.9.0\msvc2022_64\include" /EHsc autohidedockwidget.cpp

echo Copying files to build directory...
copy autohidedockwidget.h build\Desktop_Qt_6_9_0_MSVC2022_64bit-Debug /Y
copy autohidedockwidget.cpp build\Desktop_Qt_6_9_0_MSVC2022_64bit-Debug /Y
copy autohidedockwidget.obj build\Desktop_Qt_6_9_0_MSVC2022_64bit-Debug /Y

echo Done! 