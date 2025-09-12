/**
 * Madrigal Ascension - Configuration Header
 * 
 * Central configuration file for all Madrigal Ascension systems
 * Replaces legacy configuration scattered across multiple files
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_CONFIG_H
#define MADRIGAL_CONFIG_H

// ============================================================================
// VERSION INFORMATION
// ============================================================================
#define MADRIGAL_VERSION_MAJOR          1
#define MADRIGAL_VERSION_MINOR          0
#define MADRIGAL_VERSION_PATCH          0
#define MADRIGAL_VERSION_BUILD          1000

#define MADRIGAL_VERSION_STRING         "1.0.0"
#define MADRIGAL_CLIENT_NAME            "Madrigal Ascension"
#define MADRIGAL_SERVER_NAME            "Madrigal Ascension Server"

// ============================================================================
// PERFORMANCE OPTIMIZATION SETTINGS
// ============================================================================

// Multi-threading configuration
#define MADRIGAL_ENABLE_MULTITHREADING  1
#define MADRIGAL_RENDER_THREAD_ENABLED  1
#define MADRIGAL_NETWORK_THREAD_ENABLED 1
#define MADRIGAL_AUDIO_THREAD_ENABLED   1

// Memory optimization
#define MADRIGAL_ENABLE_MEMORY_POOLING  1
#define MADRIGAL_MAX_MEMORY_POOL_SIZE   (512 * 1024 * 1024) // 512MB
#define MADRIGAL_ENABLE_ASSET_STREAMING 1

// Rendering optimizations  
#define MADRIGAL_USE_DIRECTX11          1
#define MADRIGAL_ENABLE_LOD_SYSTEM      1
#define MADRIGAL_MAX_FPS                120
#define MADRIGAL_VSYNC_ENABLED          1

// ============================================================================
// NETWORK OPTIMIZATION SETTINGS
// ============================================================================

// Protocol settings
#define MADRIGAL_USE_TCP_UDP_HYBRID     1
#define MADRIGAL_ENABLE_PACKET_COMPRESSION 1
#define MADRIGAL_MAX_PACKET_SIZE        8192
#define MADRIGAL_CONNECTION_TIMEOUT     30000   // 30 seconds

// Anti-lag features
#define MADRIGAL_ENABLE_PREDICTION      1
#define MADRIGAL_ENABLE_INTERPOLATION   1
#define MADRIGAL_MAX_PREDICTION_TIME    100     // ms

// ============================================================================
// SECURITY SETTINGS
// ============================================================================

// Anti-cheat system
#define MADRIGAL_ENABLE_ANTICHEAT       1
#define MADRIGAL_ENABLE_MEMORY_PROTECTION 1
#define MADRIGAL_ENABLE_BEHAVIORAL_ANALYSIS 1

// Encryption
#define MADRIGAL_USE_MODERN_ENCRYPTION  1
#define MADRIGAL_ENCRYPTION_KEY_SIZE    256     // AES-256

// ============================================================================
// AI ASSISTANT SETTINGS (Phase 6)
// ============================================================================

// AI integration (disabled until Phase 6)
#define MADRIGAL_ENABLE_AI_ASSISTANT    0
#define MADRIGAL_AI_RESPONSE_TIMEOUT    5000    // 5 seconds
#define MADRIGAL_AI_CACHE_SIZE          100     // responses

// ============================================================================
// LEGACY COMPATIBILITY SETTINGS
// ============================================================================

// Backward compatibility (to be removed in v2.0)
#define MADRIGAL_LEGACY_MODE_ENABLED    1
#define MADRIGAL_SUPPORT_OLD_SAVES      1

// Legacy defines mapping
#ifdef MADRIGAL_LEGACY_MODE_ENABLED
    #define __VER                       MADRIGAL_VERSION_BUILD
    #define NEUZ_VER                    MADRIGAL_VERSION_STRING
    #define CLIENT_VER                  MADRIGAL_VERSION_BUILD
#endif

// ============================================================================
// PLATFORM-SPECIFIC SETTINGS
// ============================================================================

#ifdef _WIN32
    #define MADRIGAL_PLATFORM_WINDOWS   1
    #define MADRIGAL_USE_DIRECTX        1
#elif defined(__linux__)
    #define MADRIGAL_PLATFORM_LINUX     1
    #define MADRIGAL_USE_OPENGL         1
#elif defined(__APPLE__)
    #define MADRIGAL_PLATFORM_MACOS     1
    #define MADRIGAL_USE_METAL          1
#endif

// ============================================================================
// DEBUG AND DEVELOPMENT SETTINGS
// ============================================================================

#ifdef _DEBUG
    #define MADRIGAL_DEBUG_MODE         1
    #define MADRIGAL_ENABLE_LOGGING     1
    #define MADRIGAL_ENABLE_PROFILING   1
#else
    #define MADRIGAL_DEBUG_MODE         0
    #define MADRIGAL_ENABLE_LOGGING     0
    #define MADRIGAL_ENABLE_PROFILING   0
#endif

// Development tools
#define MADRIGAL_ENABLE_CONSOLE        MADRIGAL_DEBUG_MODE
#define MADRIGAL_ENABLE_METRICS        1

// ============================================================================
// GAME-SPECIFIC SETTINGS
// ============================================================================

// World and gameplay
#define MADRIGAL_MAX_PLAYERS           1000
#define MADRIGAL_MAX_GUILDS            100
#define MADRIGAL_MAX_LEVEL             120
#define MADRIGAL_BASE_EXP_RATE         1.0f

// UI and interface
#define MADRIGAL_ENABLE_MODERN_UI      1
#define MADRIGAL_ENABLE_THEMES         1
#define MADRIGAL_DEFAULT_THEME         "Dark"

// Quality of life features
#define MADRIGAL_ENABLE_AUTO_PICKUP    1
#define MADRIGAL_ENABLE_SMART_INVENTORY 1
#define MADRIGAL_ENABLE_ADVANCED_GUILD_TOOLS 1

#endif // MADRIGAL_CONFIG_H