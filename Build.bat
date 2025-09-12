@echo off
REM Madrigal Ascension - Modern Build Script
REM Replaces legacy Visual Studio build process with CMake
REM 
REM Version: 1.0.0

echo.
echo ========================================
echo Madrigal Ascension Build System v1.0.0
echo ========================================
echo.

REM Set build configuration
set BUILD_TYPE=Release
set GENERATOR="Visual Studio 16 2019"
set PLATFORM=x64
set BUILD_DIR=build
set INSTALL_DIR=install

REM Parse command line arguments
:parse_args
if "%1"=="" goto start_build
if /i "%1"=="debug" set BUILD_TYPE=Debug
if /i "%1"=="release" set BUILD_TYPE=Release
if /i "%1"=="clean" goto clean_build
if /i "%1"=="help" goto show_help
if /i "%1"=="--help" goto show_help
if /i "%1"=="-h" goto show_help
shift
goto parse_args

:start_build
echo Build Configuration:
echo   Type: %BUILD_TYPE%
echo   Generator: %GENERATOR%
echo   Platform: %PLATFORM%
echo   Build Directory: %BUILD_DIR%
echo   Install Directory: %INSTALL_DIR%
echo.

REM Create build directory
if not exist %BUILD_DIR% (
    echo Creating build directory...
    mkdir %BUILD_DIR%
)

REM Navigate to build directory
cd %BUILD_DIR%

REM Configure project with CMake
echo Configuring Madrigal Ascension with CMake...
cmake .. ^
    -G %GENERATOR% ^
    -A %PLATFORM% ^
    -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ^
    -DCMAKE_INSTALL_PREFIX=../%INSTALL_DIR% ^
    -DMADRIGAL_BUILD_CLIENT=ON ^
    -DMADRIGAL_BUILD_WORLD_SERVER=ON ^
    -DMADRIGAL_BUILD_LOGIN_SERVER=ON ^
    -DMADRIGAL_BUILD_DATABASE_SERVER=ON ^
    -DMADRIGAL_ENABLE_MULTITHREADING=ON ^
    -DMADRIGAL_ENABLE_MODERN_GRAPHICS=ON ^
    -DMADRIGAL_ENABLE_ANTI_CHEAT=ON ^
    -DMADRIGAL_ENABLE_AI_ASSISTANT=OFF

if errorlevel 1 (
    echo.
    echo ERROR: CMake configuration failed!
    echo Please check that CMake is installed and Visual Studio is available.
    pause
    exit /b 1
)

echo.
echo Configuration successful!
echo.

REM Build the project
echo Building Madrigal Ascension...
cmake --build . --config %BUILD_TYPE% --parallel

if errorlevel 1 (
    echo.
    echo ERROR: Build failed!
    echo Please check the build output for errors.
    pause
    exit /b 1
)

echo.
echo ========================================
echo Build completed successfully!
echo ========================================
echo.

REM Show output location
echo Built files are available in:
echo   Client: %BUILD_DIR%\bin\%BUILD_TYPE%\MadrigalAscension.exe
echo   World Server: %BUILD_DIR%\bin\%BUILD_TYPE%\MadrigalWorldServer.exe
echo   Login Server: %BUILD_DIR%\bin\%BUILD_TYPE%\MadrigalLoginServer.exe
echo   Database Server: %BUILD_DIR%\bin\%BUILD_TYPE%\MadrigalDatabaseServer.exe
echo.

REM Optional installation
set /p install_choice=Install to %INSTALL_DIR% directory? (y/n): 
if /i "%install_choice%"=="y" (
    echo Installing Madrigal Ascension...
    cmake --install . --config %BUILD_TYPE%
    
    if errorlevel 1 (
        echo WARNING: Installation failed!
    ) else (
        echo Installation completed successfully!
        echo Files installed to: %INSTALL_DIR%
    )
)

echo.
echo Build process complete!
pause
goto :eof

:clean_build
echo Cleaning build directory...
if exist %BUILD_DIR% (
    rmdir /s /q %BUILD_DIR%
    echo Build directory cleaned.
) else (
    echo Build directory does not exist.
)

if exist %INSTALL_DIR% (
    set /p clean_install=Also clean install directory? (y/n): 
    if /i "%clean_install%"=="y" (
        rmdir /s /q %INSTALL_DIR%
        echo Install directory cleaned.
    )
)

echo Clean operation completed.
pause
goto :eof

:show_help
echo.
echo Madrigal Ascension Build Script Help
echo ====================================
echo.
echo Usage: Build.bat [options]
echo.
echo Options:
echo   debug     Build in Debug configuration
echo   release   Build in Release configuration (default)
echo   clean     Clean all build files
echo   help      Show this help message
echo.
echo Examples:
echo   Build.bat              - Build in Release mode
echo   Build.bat debug        - Build in Debug mode  
echo   Build.bat clean        - Clean build files
echo.
echo Requirements:
echo   - CMake 3.20 or newer
echo   - Visual Studio 2019 or newer
echo   - Windows 10 or newer
echo.
echo For more information, visit:
echo https://github.com/GitMischaHub/MSFlyff/wiki/Building
echo.
pause
goto :eof