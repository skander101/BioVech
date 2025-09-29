echo Copying Python scripts...\r\n
copy /y "C:\Users\firit\OneDrive\Bureau\9RAYA\esprit\cours\2eme annee\2eme semestre\Projet\Git_repos\speech_to_text.py" "C:\Users\firit\OneDrive\Bureau\9RAYA\esprit\cours\2eme annee\2eme semestre\Projet\Git_repos\build\Desktop_Qt_6_7_3_MinGW_64_bit-Debug"\r\n
copy /y "C:\Users\firit\OneDrive\Bureau\9RAYA\esprit\cours\2eme annee\2eme semestre\Projet\Git_repos\face_recognition_module.py" "C:\Users\firit\OneDrive\Bureau\9RAYA\esprit\cours\2eme annee\2eme semestre\Projet\Git_repos\build\Desktop_Qt_6_7_3_MinGW_64_bit-Debug"\r\n
copy /y "C:\Users\firit\OneDrive\Bureau\9RAYA\esprit\cours\2eme annee\2eme semestre\Projet\Git_repos\requirements.txt" "C:\Users\firit\OneDrive\Bureau\9RAYA\esprit\cours\2eme annee\2eme semestre\Projet\Git_repos\build\Desktop_Qt_6_7_3_MinGW_64_bit-Debug"\r\n
if errorlevel 1 (\r\n
  echo Warning: Failed to copy Python scripts, but continuing build...\r\n
  exit /b 0\r\n
)\r\n
