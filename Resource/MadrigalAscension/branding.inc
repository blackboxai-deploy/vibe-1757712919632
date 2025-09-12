/**
 * Madrigal Ascension - Branding Resource File
 * 
 * Central branding configuration replacing legacy Flyff branding
 * Contains all text strings, titles, and UI elements for consistent branding
 * 
 * @version 1.0.0
 */

// ============================================================================
// APPLICATION BRANDING
// ============================================================================

// Main application titles
#define IDS_APP_TITLE                   "Madrigal Ascension"
#define IDS_APP_SUBTITLE                "The Next Generation MMORPG"
#define IDS_APP_VERSION                 "Version 1.0.0"
#define IDS_APP_COPYRIGHT               "© 2025 Madrigal Ascension Studio"

// Window titles
#define IDS_MAIN_WINDOW                 "Madrigal Ascension - The Next Generation MMORPG"
#define IDS_LOGIN_WINDOW                "Madrigal Ascension - Login"
#define IDS_CHARACTER_WINDOW            "Madrigal Ascension - Character Selection"
#define IDS_LOADING_WINDOW              "Madrigal Ascension - Loading..."

// ============================================================================
// SPLASH SCREEN AND STARTUP
// ============================================================================

// Splash screen messages
#define IDS_SPLASH_LOADING              "Loading Madrigal Ascension..."
#define IDS_SPLASH_INITIALIZING         "Initializing game systems..."
#define IDS_SPLASH_CONNECTING           "Connecting to Madrigal world..."
#define IDS_SPLASH_WELCOME              "Welcome to Madrigal Ascension!"

// Loading messages
#define IDS_LOADING_RESOURCES           "Loading game resources..."
#define IDS_LOADING_TEXTURES            "Optimizing textures..."
#define IDS_LOADING_MODELS              "Loading 3D models..."
#define IDS_LOADING_SOUNDS              "Preparing audio system..."
#define IDS_LOADING_WORLD               "Entering the world of Madrigal..."

// ============================================================================
// USER INTERFACE BRANDING
// ============================================================================

// Menu items
#define IDS_MENU_FILE                   "&File"
#define IDS_MENU_OPTIONS                "&Options"
#define IDS_MENU_HELP                   "&Help"
#define IDS_MENU_ABOUT                  "&About Madrigal Ascension"

// Button labels
#define IDS_BUTTON_LOGIN                "Login"
#define IDS_BUTTON_CREATE_ACCOUNT       "Create Account"
#define IDS_BUTTON_OPTIONS              "Options"
#define IDS_BUTTON_EXIT                 "Exit Game"
#define IDS_BUTTON_START_GAME           "Start Adventure"
#define IDS_BUTTON_CHARACTER_CREATE     "Create Character"

// ============================================================================
// GAME WORLD BRANDING
// ============================================================================

// World and server names
#define IDS_WORLD_NAME                  "Madrigal"
#define IDS_SERVER_ASCENSION            "Ascension Server"
#define IDS_SERVER_ETERNAL              "Eternal Server"
#define IDS_SERVER_PHOENIX              "Phoenix Server"

// Welcome messages
#define IDS_WELCOME_MESSAGE             "Welcome to the world of Madrigal Ascension!"
#define IDS_WELCOME_NEW_PLAYER          "Begin your legendary journey in Madrigal!"
#define IDS_WELCOME_RETURNING           "Welcome back, adventurer!"

// ============================================================================
// CHARACTER CLASSES (MODERNIZED NAMES)
// ============================================================================

// Class names with modern styling
#define IDS_CLASS_VAGRANT               "Wanderer"
#define IDS_CLASS_MERCENARY             "Warrior"
#define IDS_CLASS_ACROBAT               "Scout"
#define IDS_CLASS_ASSIST                "Healer"
#define IDS_CLASS_MAGICIAN              "Mage"
#define IDS_CLASS_KNIGHT                "Guardian"
#define IDS_CLASS_BLADE                 "Blademaster"
#define IDS_CLASS_JESTER                "Trickster"
#define IDS_CLASS_RANGER                "Archer"
#define IDS_CLASS_RINGMASTER            "Sage"
#define IDS_CLASS_BILLPOSTER            "Champion"
#define IDS_CLASS_PSYCHIKEEPER          "Psykeeper"
#define IDS_CLASS_ELEMENTOR             "Elementalist"

// Class descriptions
#define IDS_CLASS_DESC_VAGRANT          "Begin your journey as a versatile Wanderer"
#define IDS_CLASS_DESC_MERCENARY        "Master of close combat and heavy weapons"
#define IDS_CLASS_DESC_ACROBAT          "Agile fighter skilled in speed and precision"

// ============================================================================
// ERROR MESSAGES AND NOTIFICATIONS
// ============================================================================

// Connection errors
#define IDS_ERROR_CONNECTION            "Unable to connect to Madrigal Ascension servers"
#define IDS_ERROR_LOGIN_FAILED          "Login failed. Please check your credentials."
#define IDS_ERROR_SERVER_FULL           "Server is currently full. Please try again later."
#define IDS_ERROR_MAINTENANCE           "Servers are under maintenance. Please try again later."

// Game errors
#define IDS_ERROR_CHARACTER_LOAD        "Unable to load character data"
#define IDS_ERROR_WORLD_LOAD            "Failed to load game world"
#define IDS_ERROR_NETWORK_TIMEOUT       "Network timeout. Reconnecting..."

// Success messages
#define IDS_SUCCESS_LOGIN               "Successfully logged in to Madrigal Ascension"
#define IDS_SUCCESS_CHARACTER_CREATE    "Character created successfully!"
#define IDS_SUCCESS_LEVEL_UP            "Congratulations! You have gained a level!"

// ============================================================================
// SYSTEM MESSAGES
// ============================================================================

// Performance notifications
#define IDS_SYSTEM_OPTIMIZING           "Optimizing performance for Madrigal Ascension..."
#define IDS_SYSTEM_MEMORY_CLEANED       "Memory optimization complete"
#define IDS_SYSTEM_GRAPHICS_UPDATED     "Graphics settings updated"

// Security messages
#define IDS_SECURITY_PROTECTED          "Game protection active"
#define IDS_SECURITY_WARNING            "Suspicious activity detected"

// AI Assistant messages (Phase 6)
#define IDS_AI_GREETING                 "Hello! I'm your Madrigal AI Assistant. How can I help?"
#define IDS_AI_QUEST_HELP               "Need help with quests? Ask me anything!"
#define IDS_AI_BUILD_ADVICE             "Want advice on your character build?"

// ============================================================================
// LEGACY COMPATIBILITY MAPPINGS
// ============================================================================

// Legacy Flyff/Neuz string mappings (to be removed in v2.0)
#define IDS_NEUZ_TITLE                  IDS_APP_TITLE
#define IDS_FLYFF_TITLE                 IDS_APP_TITLE
#define IDS_FLYFF_MAIN                  IDS_MAIN_WINDOW

// Legacy class names
#define IDS_JOB_VAGRANT                 IDS_CLASS_VAGRANT
#define IDS_JOB_MERCENARY               IDS_CLASS_MERCENARY
#define IDS_JOB_ACROBAT                 IDS_CLASS_ACROBAT

// ============================================================================
// CONFIGURATION MESSAGES
// ============================================================================

// Build configuration
#ifdef _DEBUG
    #define IDS_BUILD_CONFIG            "Madrigal Ascension - Development Build"
#else
    #define IDS_BUILD_CONFIG            "Madrigal Ascension - Release Build"
#endif

// Platform information
#ifdef _WIN32
    #define IDS_PLATFORM                "Windows"
#elif defined(__linux__)
    #define IDS_PLATFORM                "Linux"
#elif defined(__APPLE__)
    #define IDS_PLATFORM                "macOS"
#endif

// ============================================================================
// QUALITY OF LIFE FEATURES BRANDING
// ============================================================================

// Modern feature names
#define IDS_FEATURE_AUTO_PICKUP         "Smart Loot Collection"
#define IDS_FEATURE_AI_ASSISTANT        "AI Adventure Guide"
#define IDS_FEATURE_PERFORMANCE_MODE    "Enhanced Performance Mode"
#define IDS_FEATURE_ANTI_CHEAT          "Fair Play Protection"

// Feature descriptions
#define IDS_DESC_AUTO_PICKUP            "Automatically collect nearby items"
#define IDS_DESC_AI_ASSISTANT           "Get intelligent help with your adventure"
#define IDS_DESC_PERFORMANCE_MODE       "Optimized settings for best performance"

// ============================================================================
// WEBSITE AND SOCIAL LINKS
// ============================================================================

#define IDS_WEBSITE_URL                 "https://madrigalascension.com"
#define IDS_DISCORD_URL                 "https://discord.gg/madrigal"
#define IDS_TWITTER_URL                 "https://twitter.com/madrigalgame"
#define IDS_SUPPORT_URL                 "https://support.madrigalascension.com"

// Link descriptions
#define IDS_WEBSITE_DESC                "Visit our official website"
#define IDS_DISCORD_DESC                "Join our Discord community"
#define IDS_SUPPORT_DESC                "Get help and support"