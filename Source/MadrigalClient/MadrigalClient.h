/**
 * Madrigal Ascension - Next Generation MMORPG Client
 * 
 * Main client header file (formerly Neuz.h)
 * Modernized for 2025 with enhanced performance and AI integration
 * 
 * @author Madrigal Ascension Development Team
 * @version 1.0.0
 * @date 2025
 */

#ifndef MADRIGAL_CLIENT_H
#define MADRIGAL_CLIENT_H

// Version information
#define MADRIGAL_VERSION_MAJOR    1
#define MADRIGAL_VERSION_MINOR    0  
#define MADRIGAL_VERSION_PATCH    0
#define MADRIGAL_VERSION_BUILD    1000

#define MADRIGAL_VERSION_STRING   "1.0.0.1000"
#define MADRIGAL_CLIENT_NAME      "Madrigal Ascension Client"
#define MADRIGAL_WINDOW_TITLE     "Madrigal Ascension - The Next Generation MMORPG"

// Legacy compatibility defines (to be phased out)
#define NEUZ_VERSION             MADRIGAL_VERSION_STRING
#define __VER                    MADRIGAL_VERSION_BUILD

// Modern C++ standards
#pragma once
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <atomic>

// Platform-specific includes
#ifdef _WIN32
    #include <windows.h>
    #include <d3d11.h>  // Modern DirectX
    #include <dxgi.h>
#endif

// Core engine includes
#include "Core/MadrigalEngine.h"
#include "Network/MadrigalNetwork.h"
#include "Renderer/MadrigalRenderer.h"
#include "UI/MadrigalUI.h"
#include "Audio/MadrigalAudio.h"
#include "Input/MadrigalInput.h"
#include "Security/MadrigalSecurity.h"

// Forward declarations
class CMadrigalApp;
class CGameWorld;
class CPlayerCharacter;
class CNetworkManager;
class CRendererManager;
class CUIManager;
class CAIAssistant;

// Forward declarations
class CGameWorld;
class CNetworkManager; 
class CRendererManager;
class CUIManager;
class CAIAssistant;

/**
 * Main application class for Madrigal Ascension client
 * Replaces the legacy CNeuzApp class with modern architecture
 */
class CMadrigalApp
{
public:
    CMadrigalApp();
    virtual ~CMadrigalApp();

    // Application lifecycle
    bool Initialize();
    void Shutdown();
    int Run();

    // Modern features
    bool InitializeModernRenderer();
    bool InitializeAIAssistant();
    bool InitializeSecuritySystem();
    
    // Performance optimizations
    void EnableMultiThreading();
    void OptimizeMemoryUsage();
    void PreloadCriticalAssets();

    // Legacy compatibility (temporary)
    static CMadrigalApp* GetInstance() { return s_pInstance; }

private:
    // Static instance for legacy compatibility
    static CMadrigalApp* s_pInstance;
    
    // Application state
    bool m_bRunning;
    bool m_bInitialized;
    
    // Internal methods
    void UpdateSystems(float deltaTime);
    void RenderFrame();
    void ProcessMessages();
    void HandleInput();
    
    // Modern optimization features
    void UpdateAsyncSystems();
    void ManageMemoryPools();
    void MonitorPerformance();
};

// Global functions for legacy compatibility
extern CMadrigalApp* g_pMadrigalApp;

// Modern utility functions
namespace MadrigalUtils
{
    const char* GetVersionString();
    bool IsModernFeatureEnabled(const char* featureName);
    void LogSystemMessage(const char* message);
    void EnablePerformanceMode(bool bEnable);
}

// Legacy defines for backward compatibility (will be removed in v2.0)
#define g_pNeuzApp          g_pMadrigalApp
#define CNeuzApp            CMadrigalApp
#define NEUZ_WINDOW_TITLE   MADRIGAL_WINDOW_TITLE

#endif // MADRIGAL_CLIENT_H