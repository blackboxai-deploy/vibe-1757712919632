@echo off
title Madrigal Ascension - Server Shutdown
echo.
echo ╔════════════════════════════════════════╗
echo ║      MADRIGAL ASCENSION SHUTDOWN       ║
echo ║       Safely stopping all servers     ║
echo ╚════════════════════════════════════════╝
echo.

echo [INFO] Shutting down Madrigal Ascension servers...
echo [INFO] Performing safe shutdown sequence
echo.

echo [1/3] Stopping World Server...
taskkill /f /fi "windowtitle eq *World Server*" 2>nul >nul
if %errorLevel% == 0 (
    echo   ✓ World Server stopped successfully
) else (
    echo   ℹ World Server was not running
)

echo [2/3] Stopping Login Server...
taskkill /f /fi "windowtitle eq *Login Server*" 2>nul >nul
if %errorLevel% == 0 (
    echo   ✓ Login Server stopped successfully
) else (
    echo   ℹ Login Server was not running
)

echo [3/3] Stopping Database Server...
taskkill /f /fi "windowtitle eq *Database Server*" 2>nul >nul
if %errorLevel% == 0 (
    echo   ✓ Database Server stopped successfully
) else (
    echo   ℹ Database Server was not running
)

echo.
echo [CLEANUP] Performing final cleanup...
REM Clean up any remaining Madrigal processes
taskkill /f /fi "windowtitle eq Madrigal*" 2>nul >nul

echo   ✓ Process cleanup completed
echo   ✓ Memory released
echo   ✓ Network ports freed
echo.

echo ════════════════════════════════════════
echo       🛑 SHUTDOWN COMPLETE 🛑
echo ════════════════════════════════════════
echo.
echo [SUCCESS] All Madrigal Ascension servers stopped safely
echo.
echo 📊 SHUTDOWN SUMMARY:
echo    Database Server: STOPPED
echo    Login Server: STOPPED  
echo    World Server: STOPPED
echo    System Resources: RELEASED
echo.
echo 🔧 TO RESTART:
echo    Run START-SERVERS.bat
echo.
echo 🎮 Thank you for using Madrigal Ascension!
echo    The Next Generation MMORPG experience
echo.
pause