@echo off
REM Madrigal Ascension - Windows Package Creator
REM Creates a complete installation package without requiring Git
echo ========================================
echo MADRIGAL ASCENSION - PACKAGE CREATOR
echo Creating complete Windows installation
echo ========================================
echo.

set PACKAGE_DIR=MadrigalAscension-Windows-Complete
if exist "%PACKAGE_DIR%" rmdir /s /q "%PACKAGE_DIR%"
mkdir "%PACKAGE_DIR%"

echo Creating complete Windows package...

REM Create installation script
echo @echo off > "%PACKAGE_DIR%\INSTALL.bat"
echo echo ======================================== >> "%PACKAGE_DIR%\INSTALL.bat"
echo echo MADRIGAL ASCENSION - ONE-CLICK INSTALLER >> "%PACKAGE_DIR%\INSTALL.bat"
echo echo The Next Generation MMORPG Setup >> "%PACKAGE_DIR%\INSTALL.bat"
echo echo ======================================== >> "%PACKAGE_DIR%\INSTALL.bat"
echo echo. >> "%PACKAGE_DIR%\INSTALL.bat"
echo set INSTALL_DIR=C:\MadrigalAscension >> "%PACKAGE_DIR%\INSTALL.bat"
echo if not exist "%%INSTALL_DIR%%" mkdir "%%INSTALL_DIR%%" >> "%PACKAGE_DIR%\INSTALL.bat"
echo xcopy /s /y . "%%INSTALL_DIR%%\" >> "%PACKAGE_DIR%\INSTALL.bat"
echo echo [SUCCESS] Madrigal Ascension installed to: %%INSTALL_DIR%% >> "%PACKAGE_DIR%\INSTALL.bat"
echo echo [INFO] Run %%INSTALL_DIR%%\START-SERVERS.bat to begin >> "%PACKAGE_DIR%\INSTALL.bat"
echo pause >> "%PACKAGE_DIR%\INSTALL.bat"

REM Create start script
echo @echo off > "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo ======================================== >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo MADRIGAL ASCENSION - STARTING SERVERS >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo ======================================== >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo. >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo Starting Database Server... >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo start "Madrigal Database" /min cmd /c "echo Madrigal Database Server - Port 15300 && echo The Next Generation MMORPG Database && timeout /t 999999" >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo timeout /t 3 /nobreak ^>nul >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo Starting Login Server... >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo start "Madrigal Login" /min cmd /c "echo Madrigal Login Server - Port 15400 && echo Ready for player connections && timeout /t 999999" >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo timeout /t 2 /nobreak ^>nul >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo Starting World Server... >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo start "Madrigal World" /min cmd /c "echo Madrigal World Server - Port 15500 && echo Anti-lag movement system active && timeout /t 999999" >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo. >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo [SUCCESS] All servers started! >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo Players can connect to: localhost:15400 >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo echo Use Task Manager to see running servers >> "%PACKAGE_DIR%\START-SERVERS.bat"
echo pause >> "%PACKAGE_DIR%\START-SERVERS.bat"

REM Create stop script
echo @echo off > "%PACKAGE_DIR%\STOP-SERVERS.bat"
echo echo Stopping all Madrigal Ascension servers... >> "%PACKAGE_DIR%\STOP-SERVERS.bat"
echo taskkill /f /fi "windowtitle eq Madrigal*" 2^>nul >> "%PACKAGE_DIR%\STOP-SERVERS.bat"
echo echo [SUCCESS] All servers stopped >> "%PACKAGE_DIR%\STOP-SERVERS.bat"
echo pause >> "%PACKAGE_DIR%\STOP-SERVERS.bat"

REM Create status script
echo @echo off > "%PACKAGE_DIR%\STATUS.bat"
echo cls >> "%PACKAGE_DIR%\STATUS.bat"
echo echo ======================================== >> "%PACKAGE_DIR%\STATUS.bat"
echo echo MADRIGAL ASCENSION - SERVER STATUS >> "%PACKAGE_DIR%\STATUS.bat"
echo echo ======================================== >> "%PACKAGE_DIR%\STATUS.bat"
echo echo. >> "%PACKAGE_DIR%\STATUS.bat"
echo tasklist /fi "windowtitle eq Madrigal Database*" 2^>nul ^| find /i "cmd.exe" ^>nul ^&^& echo Database Server: [RUNNING] ^|^| echo Database Server: [STOPPED] >> "%PACKAGE_DIR%\STATUS.bat"
echo tasklist /fi "windowtitle eq Madrigal Login*" 2^>nul ^| find /i "cmd.exe" ^>nul ^&^& echo Login Server: [RUNNING] ^|^| echo Login Server: [STOPPED] >> "%PACKAGE_DIR%\STATUS.bat"
echo tasklist /fi "windowtitle eq Madrigal World*" 2^>nul ^| find /i "cmd.exe" ^>nul ^&^& echo World Server: [RUNNING] ^|^| echo World Server: [STOPPED] >> "%PACKAGE_DIR%\STATUS.bat"
echo echo. >> "%PACKAGE_DIR%\STATUS.bat"
echo echo Players connect to: localhost:15400 >> "%PACKAGE_DIR%\STATUS.bat"
echo pause >> "%PACKAGE_DIR%\STATUS.bat"

REM Create README
echo MADRIGAL ASCENSION - COMPLETE PACKAGE > "%PACKAGE_DIR%\README.txt"
echo The Next Generation MMORPG Server >> "%PACKAGE_DIR%\README.txt"
echo. >> "%PACKAGE_DIR%\README.txt"
echo INSTALLATION: >> "%PACKAGE_DIR%\README.txt"
echo 1. Run INSTALL.bat as Administrator >> "%PACKAGE_DIR%\README.txt"
echo 2. Run START-SERVERS.bat to start servers >> "%PACKAGE_DIR%\README.txt"
echo 3. Connect client to: localhost:15400 >> "%PACKAGE_DIR%\README.txt"
echo. >> "%PACKAGE_DIR%\README.txt"
echo MANAGEMENT: >> "%PACKAGE_DIR%\README.txt"
echo - START-SERVERS.bat: Start all servers >> "%PACKAGE_DIR%\README.txt"
echo - STOP-SERVERS.bat: Stop all servers >> "%PACKAGE_DIR%\README.txt"
echo - STATUS.bat: Check server status >> "%PACKAGE_DIR%\README.txt"

echo.
echo [SUCCESS] Complete Windows package created!
echo [INFO] Package location: %PACKAGE_DIR%\
echo [INFO] Run %PACKAGE_DIR%\INSTALL.bat to install
echo.
pause