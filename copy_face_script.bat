echo Copying face recognition files...\r\n
if not exist "C:\Users\Mega-Pc\Desktop\qt\Nouveau dossier\2a14-bytebuilder\face_recognition" mkdir "C:\Users\Mega-Pc\Desktop\qt\Nouveau dossier\2a14-bytebuilder\face_recognition"\r\n
xcopy /E /Y /I "C:\Users\Mega-Pc\Desktop\qt\Nouveau dossier\2a14-bytebuilder\face_recognition\*" "C:\Users\Mega-Pc\Desktop\qt\Nouveau dossier\2a14-bytebuilder\face_recognition"\r\n
if errorlevel 1 (\r\n
  echo Warning: Failed to copy face recognition files, but continuing build...\r\n
  exit /b 0\r\n
)\r\n
