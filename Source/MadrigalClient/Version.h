/**
 * Madrigal Ascension - Version Information
 * 
 * Centralized version management replacing legacy version files
 * Auto-generated version information for consistent branding
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_VERSION_H
#define MADRIGAL_VERSION_H

// ============================================================================
// VERSION NUMBERS
// ============================================================================

#define MADRIGAL_VERSION_MAJOR          1
#define MADRIGAL_VERSION_MINOR          0
#define MADRIGAL_VERSION_PATCH          0
#define MADRIGAL_VERSION_BUILD          1000

// ============================================================================
// VERSION STRINGS
// ============================================================================

#define MADRIGAL_VERSION_STRING         "1.0.0"
#define MADRIGAL_VERSION_FULL           "1.0.0.1000"
#define MADRIGAL_VERSION_DISPLAY        "Madrigal Ascension v1.0.0"

// ============================================================================
// PRODUCT INFORMATION
// ============================================================================

#define MADRIGAL_PRODUCT_NAME           "Madrigal Ascension"
#define MADRIGAL_PRODUCT_DESCRIPTION    "The Next Generation MMORPG"
#define MADRIGAL_COMPANY_NAME           "Madrigal Ascension Studio"
#define MADRIGAL_COPYRIGHT              "© 2025 Madrigal Ascension Studio. All rights reserved."

// ============================================================================
// BUILD INFORMATION
// ============================================================================

#define MADRIGAL_BUILD_DATE             __DATE__
#define MADRIGAL_BUILD_TIME             __TIME__
#define MADRIGAL_BUILD_TIMESTAMP        __DATE__ " " __TIME__

#ifdef _DEBUG
    #define MADRIGAL_BUILD_CONFIG       "Debug"
#else
    #define MADRIGAL_BUILD_CONFIG       "Release"
#endif

#ifdef _WIN64
    #define MADRIGAL_BUILD_PLATFORM     "Windows x64"
#elif defined(_WIN32)
    #define MADRIGAL_BUILD_PLATFORM     "Windows x86"
#elif defined(__linux__)
    #define MADRIGAL_BUILD_PLATFORM     "Linux"
#elif defined(__APPLE__)
    #define MADRIGAL_BUILD_PLATFORM     "macOS"
#else
    #define MADRIGAL_BUILD_PLATFORM     "Unknown"
#endif

// ============================================================================
// LEGACY COMPATIBILITY
// ============================================================================

// Map legacy version defines to new Madrigal versions
#define __VER                           MADRIGAL_VERSION_BUILD
#define NEUZ_VER                        MADRIGAL_VERSION_STRING
#define CLIENT_VER                      MADRIGAL_VERSION_BUILD
#define FLYFF_VERSION                   MADRIGAL_VERSION_STRING

// Legacy product names
#define NEUZ_PRODUCT_NAME               MADRIGAL_PRODUCT_NAME
#define FLYFF_PRODUCT_NAME              MADRIGAL_PRODUCT_NAME

// ============================================================================
// PROTOCOL VERSIONS
// ============================================================================

// Network protocol versions
#define MADRIGAL_PROTOCOL_VERSION       19000   // Based on Flyff V19
#define MADRIGAL_LOGIN_PROTOCOL         19001
#define MADRIGAL_WORLD_PROTOCOL         19002

// Legacy protocol compatibility
#define PROTOCOL_VER                    MADRIGAL_PROTOCOL_VERSION
#define LOGIN_PROTOCOL_VER              MADRIGAL_LOGIN_PROTOCOL
#define WORLD_PROTOCOL_VER              MADRIGAL_WORLD_PROTOCOL

// ============================================================================
// FEATURE VERSIONS
// ============================================================================

// Feature version tracking for compatibility
#define MADRIGAL_RENDERER_VERSION       1       // Modern renderer
#define MADRIGAL_NETWORK_VERSION        1       // Optimized networking
#define MADRIGAL_SECURITY_VERSION       1       // Enhanced security
#define MADRIGAL_AI_VERSION             0       // AI assistant (Phase 6)

// ============================================================================
// COMPILE-TIME VERSION MACROS
// ============================================================================

// Version comparison macros
#define MADRIGAL_VERSION_AT_LEAST(major, minor, patch) \
    ((MADRIGAL_VERSION_MAJOR > (major)) || \
     (MADRIGAL_VERSION_MAJOR == (major) && MADRIGAL_VERSION_MINOR > (minor)) || \
     (MADRIGAL_VERSION_MAJOR == (major) && MADRIGAL_VERSION_MINOR == (minor) && MADRIGAL_VERSION_PATCH >= (patch)))

#define MADRIGAL_VERSION_LESS_THAN(major, minor, patch) \
    !MADRIGAL_VERSION_AT_LEAST(major, minor, patch)

// Build number to version conversion
#define MADRIGAL_MAKE_VERSION(major, minor, patch) \
    (((major) << 24) | ((minor) << 16) | ((patch) << 8))

#define MADRIGAL_CURRENT_VERSION \
    MADRIGAL_MAKE_VERSION(MADRIGAL_VERSION_MAJOR, MADRIGAL_VERSION_MINOR, MADRIGAL_VERSION_PATCH)

// ============================================================================
// VERSION UTILITY FUNCTIONS
// ============================================================================

#ifdef __cplusplus
namespace MadrigalVersion
{
    // Version string functions
    inline const char* GetVersionString() { return MADRIGAL_VERSION_STRING; }
    inline const char* GetFullVersionString() { return MADRIGAL_VERSION_FULL; }
    inline const char* GetDisplayString() { return MADRIGAL_VERSION_DISPLAY; }
    
    // Product information
    inline const char* GetProductName() { return MADRIGAL_PRODUCT_NAME; }
    inline const char* GetProductDescription() { return MADRIGAL_PRODUCT_DESCRIPTION; }
    inline const char* GetCompanyName() { return MADRIGAL_COMPANY_NAME; }
    inline const char* GetCopyright() { return MADRIGAL_COPYRIGHT; }
    
    // Build information
    inline const char* GetBuildDate() { return MADRIGAL_BUILD_DATE; }
    inline const char* GetBuildTime() { return MADRIGAL_BUILD_TIME; }
    inline const char* GetBuildTimestamp() { return MADRIGAL_BUILD_TIMESTAMP; }
    inline const char* GetBuildConfig() { return MADRIGAL_BUILD_CONFIG; }
    inline const char* GetBuildPlatform() { return MADRIGAL_BUILD_PLATFORM; }
    
    // Version numbers
    inline int GetMajorVersion() { return MADRIGAL_VERSION_MAJOR; }
    inline int GetMinorVersion() { return MADRIGAL_VERSION_MINOR; }
    inline int GetPatchVersion() { return MADRIGAL_VERSION_PATCH; }
    inline int GetBuildNumber() { return MADRIGAL_VERSION_BUILD; }
    
    // Version comparison
    inline bool IsVersionAtLeast(int major, int minor, int patch) {
        return MADRIGAL_VERSION_AT_LEAST(major, minor, patch);
    }
    
    inline bool IsVersionLessThan(int major, int minor, int patch) {
        return MADRIGAL_VERSION_LESS_THAN(major, minor, patch);
    }
}
#endif // __cplusplus

// ============================================================================
// DEVELOPMENT PHASE TRACKING
// ============================================================================

// Current development phase
#define MADRIGAL_PHASE_1_REBRANDING             1   // ✓ Current
#define MADRIGAL_PHASE_2_PERFORMANCE            0   // Planned
#define MADRIGAL_PHASE_3_NETWORK                0   // Planned
#define MADRIGAL_PHASE_4_UI                     0   // Planned
#define MADRIGAL_PHASE_5_SECURITY               0   // Planned
#define MADRIGAL_PHASE_6_AI                     0   // Planned

// Phase completion tracking
#define MADRIGAL_CURRENT_PHASE                  1
#define MADRIGAL_PHASE_NAME                     "Rebranding & Foundation"
#define MADRIGAL_NEXT_PHASE                     "Performance Optimizations"

// ============================================================================
// CHANGELOG INTEGRATION
// ============================================================================

#define MADRIGAL_CHANGELOG_VERSION              "1.0.0"
#define MADRIGAL_CHANGELOG_DATE                 "2025-01-XX"
#define MADRIGAL_CHANGELOG_SUMMARY              "Initial Madrigal Ascension release with complete rebranding from FlyForFruit"

#endif // MADRIGAL_VERSION_H