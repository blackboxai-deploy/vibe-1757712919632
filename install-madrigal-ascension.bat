@echo off
REM Madrigal Ascension - Windows Installation Script
REM Complete setup for the Next Generation MMORPG Server
REM 
REM Version: 1.0.0

setlocal enabledelayedexpansion

echo.
echo ========================================
echo MADRIGAL ASCENSION - INSTALLATION WIZARD
echo The Next Generation MMORPG Server Setup
echo ========================================
echo.

REM Set installation paths
set INSTALL_DIR=C:\MadrigalAscension
set DATA_DIR=%INSTALL_DIR%\Data
set LOG_DIR=%INSTALL_DIR%\Logs
set CONFIG_DIR=%INSTALL_DIR%\Config
set BACKUP_DIR=%INSTALL_DIR%\Backups

REM Check for administrator privileges
net session >nul 2>&1
if %errorLevel% == 0 (
    echo [INFO] Administrator privileges confirmed
) else (
    echo [ERROR] This script requires administrator privileges
    echo [INFO] Please run as Administrator
    pause
    exit /b 1
)

REM Create installation directories
echo [STEP] Creating installation directories...
if not exist "%INSTALL_DIR%" mkdir "%INSTALL_DIR%"
if not exist "%DATA_DIR%" mkdir "%DATA_DIR%"
if not exist "%LOG_DIR%" mkdir "%LOG_DIR%"
if not exist "%CONFIG_DIR%" mkdir "%CONFIG_DIR%"
if not exist "%BACKUP_DIR%" mkdir "%BACKUP_DIR%"
echo [SUCCESS] Directories created successfully

REM Check for required software
echo.
echo [STEP] Checking system requirements...

REM Check for CMake
cmake --version >nul 2>&1
if %errorLevel% == 0 (
    echo [SUCCESS] CMake found
) else (
    echo [WARNING] CMake not found
    echo [INFO] Please install CMake from https://cmake.org/download/
    echo [INFO] Make sure to add CMake to PATH
    pause
)

REM Check for Visual Studio Build Tools
where cl.exe >nul 2>&1
if %errorLevel% == 0 (
    echo [SUCCESS] Visual Studio Build Tools found
) else (
    echo [WARNING] Visual Studio Build Tools not found
    echo [INFO] Please install Visual Studio 2019 or newer
    echo [INFO] Or install Visual Studio Build Tools
    pause
)

REM Check for Git
git --version >nul 2>&1
if %errorLevel% == 0 (
    echo [SUCCESS] Git found
) else (
    echo [WARNING] Git not found
    echo [INFO] Please install Git from https://git-scm.com/
    pause
)

echo.
echo [STEP] Building Madrigal Ascension...
cd /d "%INSTALL_DIR%"

REM Create build directory
if not exist "build" mkdir "build"
cd build

REM Configure with CMake
echo [INFO] Configuring project...
cmake .. ^
    -G "Visual Studio 16 2019" ^
    -A x64 ^
    -DCMAKE_BUILD_TYPE=Release ^
    -DMADRIGAL_BUILD_CLIENT=ON ^
    -DMADRIGAL_BUILD_WORLD_SERVER=ON ^
    -DMADRIGAL_BUILD_LOGIN_SERVER=ON ^
    -DMADRIGAL_BUILD_DATABASE_SERVER=ON ^
    -DMADRIGAL_ENABLE_MULTITHREADING=ON ^
    -DMADRIGAL_ENABLE_MODERN_GRAPHICS=ON ^
    -DMADRIGAL_ENABLE_ANTI_CHEAT=ON ^
    -DCMAKE_INSTALL_PREFIX="%INSTALL_DIR%"

if %errorLevel% neq 0 (
    echo [ERROR] CMake configuration failed
    pause
    exit /b 1
)

REM Build the project
echo [INFO] Building project (this may take several minutes)...
cmake --build . --config Release --parallel

if %errorLevel% neq 0 (
    echo [ERROR] Build failed
    pause
    exit /b 1
)

REM Install the project
echo [INFO] Installing project...
cmake --install . --config Release

echo [SUCCESS] Build completed successfully

REM Create server configuration
echo.
echo [STEP] Creating server configuration...

echo # Madrigal Ascension Server Configuration > "%CONFIG_DIR%\server.conf"
echo # The Next Generation MMORPG Server >> "%CONFIG_DIR%\server.conf"
echo. >> "%CONFIG_DIR%\server.conf"
echo [ServerInfo] >> "%CONFIG_DIR%\server.conf"
echo ServerName=Madrigal Ascension Server >> "%CONFIG_DIR%\server.conf"
echo ServerDescription=The Next Generation MMORPG Server >> "%CONFIG_DIR%\server.conf"
echo Version=1.0.0 >> "%CONFIG_DIR%\server.conf"
echo. >> "%CONFIG_DIR%\server.conf"
echo [Network] >> "%CONFIG_DIR%\server.conf"
echo WorldServerPort=15500 >> "%CONFIG_DIR%\server.conf"
echo LoginServerPort=15400 >> "%CONFIG_DIR%\server.conf"
echo DatabaseServerPort=15300 >> "%CONFIG_DIR%\server.conf"
echo MaxConnections=1000 >> "%CONFIG_DIR%\server.conf"
echo EnableCompression=1 >> "%CONFIG_DIR%\server.conf"
echo EnableEncryption=1 >> "%CONFIG_DIR%\server.conf"
echo. >> "%CONFIG_DIR%\server.conf"
echo [Performance] >> "%CONFIG_DIR%\server.conf"
echo EnableMultiThreading=1 >> "%CONFIG_DIR%\server.conf"
echo MaxWorkerThreads=8 >> "%CONFIG_DIR%\server.conf"
echo EnableMemoryPooling=1 >> "%CONFIG_DIR%\server.conf"
echo EnableAntiLag=1 >> "%CONFIG_DIR%\server.conf"
echo. >> "%CONFIG_DIR%\server.conf"
echo [Security] >> "%CONFIG_DIR%\server.conf"
echo EnableAntiCheat=1 >> "%CONFIG_DIR%\server.conf"
echo SecurityLevel=2 >> "%CONFIG_DIR%\server.conf"
echo EnableBehavioralAnalysis=1 >> "%CONFIG_DIR%\server.conf"
echo. >> "%CONFIG_DIR%\server.conf"
echo [Features] >> "%CONFIG_DIR%\server.conf"
echo EnableModernUI=1 >> "%CONFIG_DIR%\server.conf"
echo EnableAIAssistant=0 >> "%CONFIG_DIR%\server.conf"
echo EnableAutoPickup=1 >> "%CONFIG_DIR%\server.conf"
echo EnableSmartInventory=1 >> "%CONFIG_DIR%\server.conf"

REM Create AI configuration
echo { > "%CONFIG_DIR%\ai-config.json"
echo   "enabled": false, >> "%CONFIG_DIR%\ai-config.json"
echo   "apiKey": "your-openai-api-key-here", >> "%CONFIG_DIR%\ai-config.json"
echo   "model": "gpt-4o", >> "%CONFIG_DIR%\ai-config.json"
echo   "maxTokens": 150, >> "%CONFIG_DIR%\ai-config.json"
echo   "timeout": 5000, >> "%CONFIG_DIR%\ai-config.json"
echo   "features": { >> "%CONFIG_DIR%\ai-config.json"
echo     "questHelp": true, >> "%CONFIG_DIR%\ai-config.json"
echo     "buildAdvice": true, >> "%CONFIG_DIR%\ai-config.json"
echo     "navigation": true, >> "%CONFIG_DIR%\ai-config.json"
echo     "socialAssistance": true >> "%CONFIG_DIR%\ai-config.json"
echo   } >> "%CONFIG_DIR%\ai-config.json"
echo } >> "%CONFIG_DIR%\ai-config.json"

echo [SUCCESS] Configuration files created

REM Create management scripts
echo.
echo [STEP] Creating management scripts...

REM Start servers script
echo @echo off > "%INSTALL_DIR%\start-servers.bat"
echo echo Starting Madrigal Ascension servers... >> "%INSTALL_DIR%\start-servers.bat"
echo start "Database Server" /min "%INSTALL_DIR%\bin\MadrigalDatabaseServer.exe" >> "%INSTALL_DIR%\start-servers.bat"
echo timeout /t 5 /nobreak ^>nul >> "%INSTALL_DIR%\start-servers.bat"
echo start "Login Server" /min "%INSTALL_DIR%\bin\MadrigalLoginServer.exe" >> "%INSTALL_DIR%\start-servers.bat"
echo timeout /t 3 /nobreak ^>nul >> "%INSTALL_DIR%\start-servers.bat"
echo start "World Server" /min "%INSTALL_DIR%\bin\MadrigalWorldServer.exe" >> "%INSTALL_DIR%\start-servers.bat"
echo echo [SUCCESS] All servers started >> "%INSTALL_DIR%\start-servers.bat"
echo echo Check Task Manager for running processes >> "%INSTALL_DIR%\start-servers.bat"
echo pause >> "%INSTALL_DIR%\start-servers.bat"

REM Stop servers script
echo @echo off > "%INSTALL_DIR%\stop-servers.bat"
echo echo Stopping Madrigal Ascension servers... >> "%INSTALL_DIR%\stop-servers.bat"
echo taskkill /f /im MadrigalWorldServer.exe 2^>nul >> "%INSTALL_DIR%\stop-servers.bat"
echo taskkill /f /im MadrigalLoginServer.exe 2^>nul >> "%INSTALL_DIR%\stop-servers.bat"  
echo taskkill /f /im MadrigalDatabaseServer.exe 2^>nul >> "%INSTALL_DIR%\stop-servers.bat"
echo echo [SUCCESS] All servers stopped >> "%INSTALL_DIR%\stop-servers.bat"
echo pause >> "%INSTALL_DIR%\stop-servers.bat"

REM Status script
echo @echo off > "%INSTALL_DIR%\server-status.bat"
echo echo === Madrigal Ascension Server Status === >> "%INSTALL_DIR%\server-status.bat"
echo echo. >> "%INSTALL_DIR%\server-status.bat"
echo tasklist /fi "imagename eq MadrigalDatabaseServer.exe" 2^>nul ^| find /i "MadrigalDatabaseServer.exe" ^>nul ^&^& echo [RUNNING] Database Server ^|^| echo [STOPPED] Database Server >> "%INSTALL_DIR%\server-status.bat"
echo tasklist /fi "imagename eq MadrigalLoginServer.exe" 2^>nul ^| find /i "MadrigalLoginServer.exe" ^>nul ^&^& echo [RUNNING] Login Server ^|^| echo [STOPPED] Login Server >> "%INSTALL_DIR%\server-status.bat"
echo tasklist /fi "imagename eq MadrigalWorldServer.exe" 2^>nul ^| find /i "MadrigalWorldServer.exe" ^>nul ^&^& echo [RUNNING] World Server ^|^| echo [STOPPED] World Server >> "%INSTALL_DIR%\server-status.bat"
echo echo. >> "%INSTALL_DIR%\server-status.bat"
echo pause >> "%INSTALL_DIR%\server-status.bat"

REM Restart script
echo @echo off > "%INSTALL_DIR%\restart-servers.bat"
echo echo Restarting Madrigal Ascension servers... >> "%INSTALL_DIR%\restart-servers.bat"
echo call "%INSTALL_DIR%\stop-servers.bat" >> "%INSTALL_DIR%\restart-servers.bat"
echo timeout /t 3 /nobreak ^>nul >> "%INSTALL_DIR%\restart-servers.bat"
echo call "%INSTALL_DIR%\start-servers.bat" >> "%INSTALL_DIR%\restart-servers.bat"

echo [SUCCESS] Management scripts created

REM Configure Windows Firewall
echo.
echo [STEP] Configuring Windows Firewall...
netsh advfirewall firewall add rule name="Madrigal Ascension - Login Server" dir=in action=allow protocol=TCP localport=15400 >nul 2>&1
netsh advfirewall firewall add rule name="Madrigal Ascension - World Server" dir=in action=allow protocol=TCP localport=15500 >nul 2>&1
echo [SUCCESS] Firewall rules added

REM Create desktop shortcut
echo.
echo [STEP] Creating shortcuts...
echo [InternetShortcut] > "%USERPROFILE%\Desktop\Madrigal Ascension Server.url"
echo URL=file:///%INSTALL_DIR:\=/%/ >> "%USERPROFILE%\Desktop\Madrigal Ascension Server.url"

REM Installation complete
echo.
echo ========================================
echo   MADRIGAL ASCENSION INSTALLATION COMPLETE!
echo   The Next Generation MMORPG Server
echo ========================================
echo.
echo [SUCCESS] Installation completed successfully!
echo.
echo INSTALLATION DETAILS:
echo   Installation Directory: %INSTALL_DIR%
echo   Configuration Directory: %CONFIG_DIR%
echo   Data Directory: %DATA_DIR%
echo   Log Directory: %LOG_DIR%
echo.
echo SERVER MANAGEMENT:
echo   Start servers: %INSTALL_DIR%\start-servers.bat
echo   Stop servers: %INSTALL_DIR%\stop-servers.bat  
echo   Check status: %INSTALL_DIR%\server-status.bat
echo   Restart servers: %INSTALL_DIR%\restart-servers.bat
echo.
echo CONFIGURATION FILES:
echo   Server config: %CONFIG_DIR%\server.conf
echo   AI config: %CONFIG_DIR%\ai-config.json
echo.
echo NETWORK PORTS:
echo   Login Server: 15400
echo   World Server: 15500
echo   Database Server: 15300 (internal)
echo.
echo NEXT STEPS:
echo   1. Configure your server settings in %CONFIG_DIR%\server.conf
echo   2. Start the servers: %INSTALL_DIR%\start-servers.bat
echo   3. Check server status: %INSTALL_DIR%\server-status.bat
echo   4. Connect your client to: localhost:15400
echo.
echo Welcome to Madrigal Ascension - The Future of MMORPG Gaming!
echo.
pause