/**
 * Madrigal Ascension - Modern UI System
 * 
 * Next-generation user interface replacing legacy Flyff UI
 * Phase 4: Responsive design, themes, quality of life features
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_MODERN_UI_H
#define MADRIGAL_MODERN_UI_H

#include "../../Config/MadrigalConfig.h"
#include <stdint.h>

// ============================================================================
// MODERN UI CONFIGURATION
// ============================================================================

// Theme system
#define MADRIGAL_THEME_SYSTEM           1
#define MADRIGAL_DEFAULT_THEME          "Dark"
#define MADRIGAL_CUSTOM_THEMES          1

// Available themes
typedef enum MadrigalTheme
{
    THEME_DARK = 0,
    THEME_LIGHT = 1,
    THEME_CLASSIC = 2,
    THEME_NEON = 3,
    THEME_MINIMAL = 4,
    THEME_CUSTOM = 99
} MadrigalTheme;

// Responsive UI
#define MADRIGAL_RESPONSIVE_UI          1
#define MADRIGAL_SCALABLE_INTERFACE     1
#define MADRIGAL_ADAPTIVE_LAYOUT        1

// Screen resolution support
#define MADRIGAL_MIN_RESOLUTION_X       1024
#define MADRIGAL_MIN_RESOLUTION_Y       768
#define MADRIGAL_MAX_RESOLUTION_X       7680    // 8K support
#define MADRIGAL_MAX_RESOLUTION_Y       4320

// UI scaling factors
#define MADRIGAL_UI_SCALE_SMALL         0.8f
#define MADRIGAL_UI_SCALE_NORMAL        1.0f
#define MADRIGAL_UI_SCALE_LARGE         1.25f
#define MADRIGAL_UI_SCALE_HUGE          1.5f

// ============================================================================
// QUALITY OF LIFE FEATURES
// ============================================================================

// Auto-pickup system
#define MADRIGAL_AUTO_PICKUP            1
#define MADRIGAL_SMART_PICKUP           1       // Filter items intelligently
#define MADRIGAL_PICKUP_RADIUS          50.0f   // Pickup radius in units
#define MADRIGAL_PICKUP_BLACKLIST       1       // Blacklist unwanted items

// Smart inventory management
#define MADRIGAL_SMART_INVENTORY        1
#define MADRIGAL_AUTO_SORT              1       // Automatic item sorting
#define MADRIGAL_STACK_OPTIMIZATION     1       // Optimize item stacking
#define MADRIGAL_INVENTORY_SEARCH       1       // Search functionality
#define MADRIGAL_QUICK_ACTIONS          1       // Right-click quick actions

// Enhanced chat system
#define MADRIGAL_ADVANCED_CHAT          1
#define MADRIGAL_CHAT_TABS              1       // Multiple chat tabs
#define MADRIGAL_CHAT_FILTERS           1       // Message filtering
#define MADRIGAL_CHAT_HISTORY           1       // Chat history saving
#define MADRIGAL_EMOJI_SUPPORT          1       // Emoji and reactions

// ============================================================================
// GUILD AND SOCIAL IMPROVEMENTS
// ============================================================================

// Advanced guild tools
#define MADRIGAL_GUILD_TOOLS            1
#define MADRIGAL_GUILD_CALENDAR         1       // Event calendar
#define MADRIGAL_GUILD_BANK_V2          1       // Enhanced guild bank
#define MADRIGAL_GUILD_ACHIEVEMENTS     1       // Guild achievements
#define MADRIGAL_GUILD_ANALYTICS        1       // Member activity tracking

// Party finder system
#define MADRIGAL_PARTY_FINDER           1
#define MADRIGAL_AUTO_MATCHMAKING       1       // Automatic party matching
#define MADRIGAL_ROLE_SELECTION         1       // Tank/DPS/Healer roles
#define MADRIGAL_CROSS_SERVER_PARTIES   1       // Cross-server partying

// Social features
#define MADRIGAL_FRIENDS_LIST_V2        1       // Enhanced friends list
#define MADRIGAL_PLAYER_PROFILES        1       // Detailed player profiles
#define MADRIGAL_ACHIEVEMENT_SHOWCASE   1       // Show off achievements
#define MADRIGAL_SOCIAL_MEDIA_INTEGRATION 1     // Share achievements

// ============================================================================
// ACCESSIBILITY FEATURES
// ============================================================================

// Visual accessibility
#define MADRIGAL_COLORBLIND_SUPPORT     1
#define MADRIGAL_HIGH_CONTRAST_MODE     1
#define MADRIGAL_LARGE_TEXT_MODE        1
#define MADRIGAL_FONT_SCALING           1

// Audio accessibility
#define MADRIGAL_AUDIO_CUES             1       // Audio feedback for UI
#define MADRIGAL_SCREEN_READER_SUPPORT  1       // Screen reader compatibility
#define MADRIGAL_VOICE_COMMANDS         1       // Basic voice control

// Input accessibility
#define MADRIGAL_ONE_HANDED_MODE        1       // One-handed operation
#define MADRIGAL_CUSTOMIZABLE_HOTKEYS   1       // Flexible key binding
#define MADRIGAL_GAMEPAD_SUPPORT        1       // Controller support

// ============================================================================
// UI COMPONENTS AND WINDOWS
// ============================================================================

// Main UI windows (modernized names)
typedef enum MadrigalUIWindow
{
    // Core windows
    UI_MAIN_HUD = 0,
    UI_CHARACTER_STATUS,
    UI_INVENTORY,
    UI_SKILLS,
    UI_QUESTS,
    
    // Social windows
    UI_CHAT,
    UI_FRIENDS_LIST,
    UI_GUILD_PANEL,
    UI_PARTY_PANEL,
    
    // Game systems
    UI_MAP,
    UI_MINIMAP,
    UI_SHOP,
    UI_TRADE,
    UI_BANK,
    
    // Modern additions
    UI_ACHIEVEMENT_PANEL,
    UI_SETTINGS,
    UI_PERFORMANCE_MONITOR,
    UI_AI_ASSISTANT,        // Phase 6
    
    UI_WINDOW_COUNT
} MadrigalUIWindow;

// ============================================================================
// MODERN UI CLASSES
// ============================================================================

// Main UI manager
class CMadrigalUIManager
{
public:
    // System lifecycle
    static bool Initialize();
    static void Shutdown();
    static void Update();
    static void Render();
    
    // Theme management
    static bool SetTheme(MadrigalTheme theme);
    static MadrigalTheme GetCurrentTheme();
    static bool LoadCustomTheme(const char* themePath);
    
    // Window management
    static bool ShowWindow(MadrigalUIWindow window, bool show = true);
    static bool IsWindowVisible(MadrigalUIWindow window);
    static bool ToggleWindow(MadrigalUIWindow window);
    
    // Layout management
    static bool SetUIScale(float scale);
    static float GetUIScale();
    static bool AdaptToResolution(int width, int height);
    
    // Accessibility
    static bool EnableColorblindMode(bool enable);
    static bool EnableHighContrastMode(bool enable);
    static bool SetFontScale(float scale);
    
private:
    static bool s_bInitialized;
    static CMadrigalUIManager* s_pInstance;
    static MadrigalTheme s_CurrentTheme;
    static float s_UIScale;
};

// Theme configuration
struct MadrigalThemeConfig
{
    // Color scheme
    uint32_t backgroundColor;
    uint32_t primaryColor;
    uint32_t secondaryColor;
    uint32_t accentColor;
    uint32_t textColor;
    uint32_t borderColor;
    
    // Window styling
    float windowOpacity;
    float borderRadius;
    int shadowIntensity;
    
    // Animation settings
    float animationSpeed;
    bool enableTransitions;
    bool enableEffects;
    
    // Font settings
    char fontFamily[64];
    int fontSize;
    bool fontBold;
    bool fontAntiAliasing;
};

// Quality of life manager
class CMadrigalQoLManager
{
public:
    // Auto-pickup system
    static bool EnableAutoPickup(bool enable);
    static bool SetPickupRadius(float radius);
    static bool AddToPickupBlacklist(uint32_t itemId);
    static bool RemoveFromPickupBlacklist(uint32_t itemId);
    
    // Smart inventory
    static bool EnableAutoSort(bool enable);
    static bool SortInventory();
    static bool OptimizeItemStacks();
    static int SearchInventory(const char* itemName);
    
    // Quick actions
    static bool RegisterQuickAction(int slot, const char* action);
    static bool ExecuteQuickAction(int slot);
    
    // Chat enhancements
    static bool EnableChatTabs(bool enable);
    static bool AddChatFilter(const char* filter);
    static bool SaveChatHistory(bool enable);
    
private:
    static bool s_bAutoPickupEnabled;
    static float s_PickupRadius;
    static bool s_bAutoSortEnabled;
};

// Guild tools manager
class CMadrigalGuildTools
{
public:
    // Guild calendar
    static bool CreateEvent(const char* eventName, uint64_t timestamp);
    static bool JoinEvent(uint32_t eventId);
    static bool GetUpcomingEvents(void* eventList, int maxEvents);
    
    // Guild bank v2
    static bool DepositItem(uint32_t itemId, int quantity);
    static bool WithdrawItem(uint32_t itemId, int quantity);
    static bool GetBankContents(void* itemList, int maxItems);
    
    // Guild achievements
    static bool GetGuildAchievements(void* achievementList, int maxAchievements);
    static bool GetAchievementProgress(uint32_t achievementId);
    
    // Member management
    static bool GetMemberActivity(uint32_t memberId);
    static bool SetMemberRole(uint32_t memberId, int role);
    static bool GetOnlineMembers(void* memberList, int maxMembers);
};

// Party finder system
class CMadrigalPartyFinder
{
public:
    // Party search
    static bool SearchForParty(const char* activity, int preferredRole);
    static bool CreatePartyListing(const char* description, int maxMembers);
    static bool JoinParty(uint32_t partyId);
    
    // Role system
    enum PartyRole
    {
        ROLE_ANY = 0,
        ROLE_TANK = 1,
        ROLE_DPS = 2,
        ROLE_HEALER = 3,
        ROLE_SUPPORT = 4
    };
    
    static bool SetPreferredRole(PartyRole role);
    static PartyRole GetPreferredRole();
    
    // Matchmaking
    static bool EnableAutoMatchmaking(bool enable);
    static bool FindOptimalParty();
};

// ============================================================================
// ENHANCED HUD ELEMENTS
// ============================================================================

// Modern status bars
class CMadrigalStatusBars
{
public:
    // Health/Mana bars with gradients and animations
    static void RenderHealthBar(float health, float maxHealth, int x, int y, int width, int height);
    static void RenderManaBar(float mana, float maxMana, int x, int y, int width, int height);
    static void RenderExperienceBar(uint64_t exp, uint64_t maxExp, int x, int y, int width, int height);
    
    // Enhanced minimap
    static void RenderMinimap(int x, int y, int size);
    static void AddMinimapMarker(float x, float y, int iconType, const char* label);
    static void SetMinimapZoom(float zoom);
    
    // Skill cooldown indicators
    static void RenderSkillCooldown(int skillSlot, float cooldownRemaining, float totalCooldown);
    static void EnableCooldownAnimations(bool enable);
};

// ============================================================================
// PERFORMANCE OPTIMIZATIONS
// ============================================================================

// UI rendering optimization
#define MADRIGAL_UI_CACHING             1       // Cache UI elements
#define MADRIGAL_UI_BATCHING            1       // Batch draw calls
#define MADRIGAL_UI_CULLING             1       // Cull off-screen elements
#define MADRIGAL_UI_LOD                 1       // Level of detail for UI

// Animation system
#define MADRIGAL_UI_ANIMATIONS          1
#define MADRIGAL_SMOOTH_TRANSITIONS     1
#define MADRIGAL_EASING_FUNCTIONS       1
#define MADRIGAL_PARTICLE_EFFECTS       1       // UI particle effects

// ============================================================================
// LEGACY COMPATIBILITY
// ============================================================================

// Legacy UI window mappings
#define WND_NEUZ_STATUS                 UI_CHARACTER_STATUS
#define WND_NEUZ_INVENTORY              UI_INVENTORY
#define WND_NEUZ_SKILL                  UI_SKILLS
#define WND_NEUZ_CHAT                   UI_CHAT

// Legacy class aliases
typedef CMadrigalUIManager CUIManager;
#define g_pUIManager CMadrigalUIManager

#endif // MADRIGAL_MODERN_UI_H