/**
 * Madrigal Ascension - Core Definitions
 * 
 * Central definitions file replacing legacy defines
 * Updated for modern Madrigal Ascension features
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_DEFINES_H
#define MADRIGAL_DEFINES_H

// ============================================================================
// APPLICATION INFORMATION
// ============================================================================

#define MADRIGAL_APP_NAME           "Madrigal Ascension"
#define MADRIGAL_APP_VERSION        "1.0.0"
#define MADRIGAL_APP_BUILD          1000
#define MADRIGAL_COMPANY_NAME       "Madrigal Ascension Studio"
#define MADRIGAL_COPYRIGHT          "© 2025 Madrigal Ascension Studio. All rights reserved."

// Window and UI
#define MADRIGAL_WINDOW_CLASS       "MadrigalAscensionWnd"
#define MADRIGAL_WINDOW_TITLE       "Madrigal Ascension - The Next Generation MMORPG"
#define MADRIGAL_ICON_RESOURCE      "madrigal_icon.ico"

// ============================================================================
// LEGACY COMPATIBILITY MAPPINGS
// ============================================================================

// Legacy defines that map to new Madrigal equivalents
#define NEUZ_APP_NAME               MADRIGAL_APP_NAME
#define NEUZ_VERSION                MADRIGAL_APP_VERSION
#define FLYFF_WINDOW_TITLE          MADRIGAL_WINDOW_TITLE
#define CLIENT_NAME                 MADRIGAL_APP_NAME

// ============================================================================
// NETWORK DEFINITIONS
// ============================================================================

// Server communication
#define MADRIGAL_DEFAULT_PORT       23000
#define MADRIGAL_LOGIN_PORT         15400
#define MADRIGAL_WORLD_PORT         15500

// Protocol versions
#define MADRIGAL_PROTOCOL_VERSION   19000   // Based on Flyff V19, modernized
#define MADRIGAL_CLIENT_VERSION     10000   // New Madrigal versioning

// Legacy protocol compatibility
#define FLYFF_PROTOCOL_VER          MADRIGAL_PROTOCOL_VERSION
#define CLIENT_VER                  MADRIGAL_CLIENT_VERSION

// ============================================================================
// GAME WORLD DEFINITIONS
// ============================================================================

// World settings
#define MADRIGAL_MAX_PLAYERS        1000
#define MADRIGAL_MAX_LEVEL          120
#define MADRIGAL_MAX_GUILDS         100
#define MADRIGAL_MAX_INVENTORY      100

// Character classes (modernized from legacy)
#define MADRIGAL_CLASS_VAGRANT      0
#define MADRIGAL_CLASS_MERCENARY    1
#define MADRIGAL_CLASS_ACROBAT      2
#define MADRIGAL_CLASS_ASSIST       3
#define MADRIGAL_CLASS_MAGICIAN     4
#define MADRIGAL_CLASS_KNIGHT       5
#define MADRIGAL_CLASS_BLADE        6
#define MADRIGAL_CLASS_JESTER       7
#define MADRIGAL_CLASS_RANGER       8
#define MADRIGAL_CLASS_RINGMASTER   9
#define MADRIGAL_CLASS_BILLPOSTER   10
#define MADRIGAL_CLASS_PSYCHIKEEPER 11
#define MADRIGAL_CLASS_ELEMENTOR    12

// Legacy job compatibility
#define JOB_VAGRANT                 MADRIGAL_CLASS_VAGRANT
#define JOB_MERCENARY               MADRIGAL_CLASS_MERCENARY
#define JOB_ACROBAT                 MADRIGAL_CLASS_ACROBAT
#define JOB_ASSIST                  MADRIGAL_CLASS_ASSIST
#define JOB_MAGICIAN                MADRIGAL_CLASS_MAGICIAN

// ============================================================================
// UI AND INTERFACE DEFINITIONS
// ============================================================================

// Modern UI features
#define MADRIGAL_ENABLE_THEMES          1
#define MADRIGAL_THEME_DARK             0
#define MADRIGAL_THEME_LIGHT            1
#define MADRIGAL_THEME_CLASSIC          2

// Interface improvements
#define MADRIGAL_AUTO_PICKUP            1
#define MADRIGAL_SMART_INVENTORY        1
#define MADRIGAL_ADVANCED_CHAT          1
#define MADRIGAL_AI_ASSISTANT_UI        1

// ============================================================================
// PERFORMANCE AND OPTIMIZATION
// ============================================================================

// Rendering settings
#define MADRIGAL_MAX_FPS                120
#define MADRIGAL_MIN_FPS                30
#define MADRIGAL_VSYNC_DEFAULT          1

// Memory optimization
#define MADRIGAL_TEXTURE_POOL_SIZE      (256 * 1024 * 1024) // 256MB
#define MADRIGAL_SOUND_POOL_SIZE        (64 * 1024 * 1024)  // 64MB
#define MADRIGAL_MODEL_POOL_SIZE        (128 * 1024 * 1024) // 128MB

// Network optimization
#define MADRIGAL_PACKET_COMPRESSION     1
#define MADRIGAL_NETWORK_PREDICTION     1
#define MADRIGAL_SMOOTH_MOVEMENT        1

// ============================================================================
// SECURITY DEFINITIONS
// ============================================================================

// Anti-cheat settings
#define MADRIGAL_ANTICHEAT_ENABLED      1
#define MADRIGAL_MEMORY_PROTECTION      1
#define MADRIGAL_PACKET_ENCRYPTION      1

// Security levels
#define MADRIGAL_SECURITY_LOW           0
#define MADRIGAL_SECURITY_MEDIUM        1
#define MADRIGAL_SECURITY_HIGH          2
#define MADRIGAL_SECURITY_MAXIMUM       3

#define MADRIGAL_DEFAULT_SECURITY       MADRIGAL_SECURITY_HIGH

// ============================================================================
// AI ASSISTANT DEFINITIONS (Phase 6)
// ============================================================================

// AI features (disabled until Phase 6)
#define MADRIGAL_AI_ENABLED             0
#define MADRIGAL_AI_CHAT_ENABLED        0
#define MADRIGAL_AI_QUEST_HELP          0
#define MADRIGAL_AI_BUILD_ADVISOR       0

// AI configuration
#define MADRIGAL_AI_MAX_HISTORY         50
#define MADRIGAL_AI_RESPONSE_TIMEOUT    5000 // ms
#define MADRIGAL_AI_CACHE_SIZE          100

// ============================================================================
// DEBUG AND DEVELOPMENT
// ============================================================================

#ifdef _DEBUG
    #define MADRIGAL_DEBUG              1
    #define MADRIGAL_CONSOLE_ENABLED    1
    #define MADRIGAL_LOGGING_ENABLED    1
#else
    #define MADRIGAL_DEBUG              0
    #define MADRIGAL_CONSOLE_ENABLED    0
    #define MADRIGAL_LOGGING_ENABLED    0
#endif

// Development tools
#define MADRIGAL_METRICS_ENABLED        1
#define MADRIGAL_PROFILING_ENABLED      MADRIGAL_DEBUG
#define MADRIGAL_CRASH_REPORTING        1

// ============================================================================
// PLATFORM-SPECIFIC DEFINITIONS
// ============================================================================

#ifdef _WIN32
    #define MADRIGAL_PLATFORM           "Windows"
    #define MADRIGAL_USE_DIRECTX        1
#elif defined(__linux__)
    #define MADRIGAL_PLATFORM           "Linux"  
    #define MADRIGAL_USE_OPENGL         1
#elif defined(__APPLE__)
    #define MADRIGAL_PLATFORM           "macOS"
    #define MADRIGAL_USE_METAL          1
#else
    #define MADRIGAL_PLATFORM           "Unknown"
#endif

// ============================================================================
// QUALITY OF LIFE IMPROVEMENTS
// ============================================================================

// Modern convenience features
#define MADRIGAL_QOL_AUTO_LOOT          1
#define MADRIGAL_QOL_QUICK_SKILLS       1
#define MADRIGAL_QOL_SMART_CAMERA       1
#define MADRIGAL_QOL_ENHANCED_MINI_MAP  1
#define MADRIGAL_QOL_PARTY_FINDER       1
#define MADRIGAL_QOL_GUILD_TOOLS        1

// Accessibility features
#define MADRIGAL_ACCESSIBILITY          1
#define MADRIGAL_COLORBLIND_SUPPORT     1
#define MADRIGAL_SCREEN_READER_SUPPORT  1
#define MADRIGAL_HIGH_CONTRAST_MODE     1

#endif // MADRIGAL_DEFINES_H