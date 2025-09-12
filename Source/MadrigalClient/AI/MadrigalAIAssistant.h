/**
 * Madrigal Ascension - AI Assistant System
 * 
 * Revolutionary AI-powered gameplay assistance
 * Phase 6: OpenAI integration, intelligent help, context-aware guidance
 * 
 * @version 1.0.0
 * @phase 6 - The Future of Gaming AI
 */

#ifndef MADRIGAL_AI_ASSISTANT_H
#define MADRIGAL_AI_ASSISTANT_H

#include "../../Config/MadrigalConfig.h"
#include <stdint.h>

// ============================================================================
// AI ASSISTANT CONFIGURATION
// ============================================================================

// AI Service Settings
#define MADRIGAL_AI_ENABLED             1
#define MADRIGAL_AI_SERVICE_URL         "https://api.openai.com/v1/"
#define MADRIGAL_AI_MODEL_GPT4          "gpt-4o"
#define MADRIGAL_AI_MODEL_GPT35         "gpt-3.5-turbo"
#define MADRIGAL_AI_DEFAULT_MODEL       MADRIGAL_AI_MODEL_GPT4

// Response settings
#define MADRIGAL_AI_MAX_RESPONSE_TIME   5000    // 5 seconds
#define MADRIGAL_AI_MAX_TOKENS          150     // Response length limit
#define MADRIGAL_AI_TEMPERATURE         0.7f    // Creativity level
#define MADRIGAL_AI_CACHE_SIZE          100     // Cached responses

// Context awareness
#define MADRIGAL_AI_CONTEXT_AWARE       1
#define MADRIGAL_AI_PLAYER_CONTEXT      1       // Use player data for context
#define MADRIGAL_AI_WORLD_CONTEXT       1       // Use world state for context
#define MADRIGAL_AI_QUEST_CONTEXT       1       // Use quest progress for context

// ============================================================================
// AI ASSISTANCE FEATURES
// ============================================================================

// Core AI features
typedef enum MadrigalAIFeature
{
    AI_FEATURE_QUEST_HELP = 0,      // Quest guidance and hints
    AI_FEATURE_BUILD_ADVISOR,       // Character build recommendations
    AI_FEATURE_ITEM_GUIDE,          // Item information and usage
    AI_FEATURE_NAVIGATION,          // World navigation assistance
    AI_FEATURE_COMBAT_TIPS,         // Combat strategy advice
    AI_FEATURE_ECONOMY,             // Market and trading advice
    AI_FEATURE_SOCIAL,              // Social interaction help
    AI_FEATURE_NEWBIE_GUIDE,        // New player assistance
    AI_FEATURE_ADVANCED_STRATEGY,   // High-level gameplay strategy
    AI_FEATURE_TROUBLESHOOTING,     // Technical issue resolution
    
    AI_FEATURE_COUNT
} MadrigalAIFeature;

// AI personality types
typedef enum MadrigalAIPersonality
{
    AI_PERSONALITY_HELPFUL = 0,     // Friendly and encouraging
    AI_PERSONALITY_EXPERT,          // Professional and knowledgeable
    AI_PERSONALITY_CASUAL,          // Laid-back and conversational
    AI_PERSONALITY_MENTOR,          // Teaching and guiding
    AI_PERSONALITY_COMPANION,       // Friend-like interaction
    AI_PERSONALITY_CUSTOM           // User-defined personality
} MadrigalAIPersonality;

// Communication modes
#define MADRIGAL_AI_CHAT_MODE           1       // Text-based chat
#define MADRIGAL_AI_VOICE_MODE          1       // Voice interaction (future)
#define MADRIGAL_AI_OVERLAY_MODE        1       // Contextual overlays
#define MADRIGAL_AI_NOTIFICATION_MODE   1       // Smart notifications

// ============================================================================
// AI CONTEXT SYSTEM
// ============================================================================

// Player context data
struct MadrigalPlayerContext
{
    uint32_t playerId;
    uint32_t level;
    uint32_t jobClass;
    uint32_t currentHP;
    uint32_t currentMP;
    uint64_t experience;
    uint32_t skillPoints;
    
    // Location context
    float positionX, positionY, positionZ;
    uint32_t currentMap;
    char currentMapName[64];
    
    // Quest context
    uint32_t activeQuests[10];
    uint32_t completedQuests;
    uint32_t failedQuests;
    
    // Social context
    uint32_t guildId;
    uint32_t partyId;
    uint32_t friendsOnline;
    
    // Equipment context
    uint32_t equippedItems[20];
    uint32_t inventoryCount;
    uint32_t bankGold;
    
    // Recent activity
    uint32_t lastActionType;
    uint64_t lastActionTime;
    uint32_t sessionTime;
};

// World context data
struct MadrigalWorldContext
{
    // Server information
    char serverName[32];
    uint32_t playersOnline;
    uint32_t serverUptime;
    
    // World events
    bool eventActive;
    char currentEvent[64];
    uint32_t eventTimeRemaining;
    
    // Economy context
    float goldInflation;
    uint32_t averagePlayerLevel;
    bool marketActive;
    
    // Weather and time
    uint32_t gameTime;
    uint32_t weatherType;
    bool dayTime;
};

// ============================================================================
// AI ASSISTANT CLASSES
// ============================================================================

// Main AI Assistant manager
class CMadrigalAIAssistant
{
public:
    // System lifecycle
    static bool Initialize();
    static void Shutdown();
    static void Update();
    
    // AI service management
    static bool ConnectToAIService(const char* apiKey);
    static bool SetAIModel(const char* modelName);
    static bool TestConnection();
    
    // Core interaction
    static bool AskQuestion(const char* question, char* response, uint32_t maxResponseLength);
    static bool GetContextualHelp(MadrigalAIFeature feature, char* response, uint32_t maxLength);
    static bool ProcessVoiceInput(const void* audioData, uint32_t audioSize);
    
    // Personality and behavior
    static bool SetPersonality(MadrigalAIPersonality personality);
    static MadrigalAIPersonality GetPersonality();
    static bool CustomizePersonality(const char* personalityPrompt);
    
    // Feature management
    static bool EnableFeature(MadrigalAIFeature feature, bool enable);
    static bool IsFeatureEnabled(MadrigalAIFeature feature);
    static bool ConfigureFeature(MadrigalAIFeature feature, const char* config);
    
    // Context management
    static bool UpdatePlayerContext(const MadrigalPlayerContext* context);
    static bool UpdateWorldContext(const MadrigalWorldContext* context);
    static bool GetRelevantContext(char* contextString, uint32_t maxLength);
    
    // Performance and caching
    static bool EnableCaching(bool enable);
    static bool ClearCache();
    static float GetResponseTime();
    static uint32_t GetCacheHitRate();
    
private:
    static bool s_bInitialized;
    static bool s_bConnected;
    static char s_AIModel[64];
    static MadrigalAIPersonality s_Personality;
    static CMadrigalAIAssistant* s_pInstance;
};

// Quest assistance specialist
class CMadrigalQuestAI
{
public:
    // Quest guidance
    static bool GetQuestHint(uint32_t questId, char* hint, uint32_t maxLength);
    static bool GetNextObjective(uint32_t questId, char* objective, uint32_t maxLength);
    static bool FindQuestNPC(uint32_t questId, float* x, float* y, float* z);
    
    // Quest recommendations
    static bool RecommendQuests(uint32_t playerLevel, uint32_t* questIds, int maxQuests);
    static bool GetOptimalQuestOrder(uint32_t* questIds, int questCount, uint32_t* orderedIds);
    static bool AnalyzeQuestRewards(uint32_t questId, char* analysis, uint32_t maxLength);
    
    // Quest troubleshooting
    static bool DiagnoseQuestIssue(uint32_t questId, char* solution, uint32_t maxLength);
    static bool GetAlternativeQuestPath(uint32_t questId, char* alternatives, uint32_t maxLength);
};

// Build advisor specialist
class CMadrigalBuildAI
{
public:
    // Build analysis
    static bool AnalyzeCurrentBuild(uint32_t playerId, char* analysis, uint32_t maxLength);
    static bool RecommendSkillPoints(uint32_t playerId, uint32_t availablePoints, char* recommendation, uint32_t maxLength);
    static bool OptimizeStatDistribution(uint32_t jobClass, uint32_t* stats, char* optimization, uint32_t maxLength);
    
    // Build suggestions
    static bool GetPopularBuilds(uint32_t jobClass, char* builds, uint32_t maxLength);
    static bool CreateCustomBuild(uint32_t jobClass, const char* playstyle, char* build, uint32_t maxLength);
    static bool CompareBuilds(const char* build1, const char* build2, char* comparison, uint32_t maxLength);
    
    // Equipment advice
    static bool RecommendEquipment(uint32_t playerLevel, uint32_t jobClass, char* equipment, uint32_t maxLength);
    static bool AnalyzeItemSynergy(uint32_t* itemIds, int itemCount, char* analysis, uint32_t maxLength);
};

// Navigation assistant
class CMadrigalNavigationAI
{
public:
    // Pathfinding assistance
    static bool GetDirections(float fromX, float fromY, float toX, float toY, char* directions, uint32_t maxLength);
    static bool FindNearbyServices(float x, float y, const char* serviceType, char* locations, uint32_t maxLength);
    static bool LocateNPC(const char* npcName, float* x, float* y, char* mapName, uint32_t maxMapNameLength);
    
    // Area information
    static bool GetAreaInfo(uint32_t mapId, char* info, uint32_t maxLength);
    static bool ListAreaMonsters(uint32_t mapId, char* monsters, uint32_t maxLength);
    static bool GetLevelAppropriateAreas(uint32_t playerLevel, char* areas, uint32_t maxLength);
    
    // Travel optimization
    static bool GetFastestRoute(const char* destination, char* route, uint32_t maxLength);
    static bool CalculateTravelCost(const char* destination, uint32_t* cost);
};

// Social interaction assistant
class CMadrigalSocialAI
{
public:
    // Guild assistance
    static bool GetGuildRecommendations(uint32_t playerId, char* recommendations, uint32_t maxLength);
    static bool AnalyzeGuildActivity(uint32_t guildId, char* analysis, uint32_t maxLength);
    static bool SuggestGuildEvents(uint32_t guildId, char* suggestions, uint32_t maxLength);
    
    // Party formation
    static bool RecommendPartyMembers(uint32_t playerId, const char* activity, char* recommendations, uint32_t maxLength);
    static bool OptimizePartyComposition(uint32_t* playerClasses, int partySize, char* optimization, uint32_t maxLength);
    
    // Communication help
    static bool TranslateMessage(const char* message, const char* fromLang, const char* toLang, char* translation, uint32_t maxLength);
    static bool SuggestResponse(const char* incomingMessage, char* response, uint32_t maxLength);
};

// ============================================================================
// AI INTEGRATION WITH GAME SYSTEMS
// ============================================================================

// AI-powered UI enhancements
class CMadrigalAIUI
{
public:
    // Smart tooltips
    static bool GenerateSmartTooltip(uint32_t itemId, uint32_t playerId, char* tooltip, uint32_t maxLength);
    static bool GetSkillAdvice(uint32_t skillId, uint32_t playerLevel, char* advice, uint32_t maxLength);
    
    // Contextual help overlay
    static bool ShowContextualHelp(float x, float y, const char* context);
    static bool HideContextualHelp();
    
    // Smart notifications
    static bool SendSmartNotification(const char* title, const char* message, uint32_t priority);
    static bool GetNotificationSuggestions(char* suggestions, uint32_t maxLength);
    
    // UI personalization
    static bool PersonalizeUI(uint32_t playerId);
    static bool SuggestUILayout(uint32_t playerId, char* layout, uint32_t maxLength);
};

// AI learning and adaptation
class CMadrigalAILearning
{
public:
    // Player behavior learning
    static bool LearnPlayerPreferences(uint32_t playerId, const char* action, bool positive);
    static bool AdaptToPlaystyle(uint32_t playerId);
    static bool GetPersonalizedAdvice(uint32_t playerId, char* advice, uint32_t maxLength);
    
    // Community learning
    static bool UpdateCommunityKnowledge(const char* topic, const char* information);
    static bool GetCommunityInsights(const char* topic, char* insights, uint32_t maxLength);
    
    // Feedback integration
    static bool ProcessUserFeedback(const char* feedback, bool helpful);
    static bool ImproveResponseQuality();
};

// ============================================================================
// AI PERFORMANCE AND MONITORING
// ============================================================================

// AI performance metrics
struct MadrigalAIStats
{
    // Usage statistics
    uint32_t totalQuestions;
    uint32_t successfulResponses;
    uint32_t failedRequests;
    float successRate;
    
    // Performance metrics
    float averageResponseTime;
    float fastestResponse;
    float slowestResponse;
    uint32_t cacheHits;
    
    // Quality metrics
    float userSatisfactionScore;
    uint32_t positiveRatings;
    uint32_t negativeRatings;
    float accuracyScore;
    
    // Feature usage
    uint32_t questHelpUsage;
    uint32_t buildAdviceUsage;
    uint32_t navigationUsage;
    uint32_t socialHelpUsage;
};

extern MadrigalAIStats g_AIStats;

// AI monitoring system
class CMadrigalAIMonitor
{
public:
    // Performance monitoring
    static bool MonitorPerformance();
    static bool GetPerformanceReport(char* report, uint32_t maxLength);
    static bool OptimizePerformance();
    
    // Quality assurance
    static bool ValidateResponse(const char* question, const char* response);
    static bool FilterInappropriateContent(char* content, uint32_t maxLength);
    static bool EnsureResponseRelevance(const char* question, const char* response);
    
    // Cost management
    static float GetAPIUsageCost();
    static bool OptimizeAPICalls();
    static bool ManageTokenUsage();
};

// ============================================================================
// VOICE INTERACTION (FUTURE EXPANSION)
// ============================================================================

// Voice AI integration (Phase 6.1)
class CMadrigalVoiceAI
{
public:
    // Voice recognition
    static bool InitializeVoiceRecognition();
    static bool ProcessVoiceCommand(const void* audioData, uint32_t size, char* command, uint32_t maxLength);
    static bool EnableContinuousListening(bool enable);
    
    // Text-to-speech
    static bool InitializeTextToSpeech();
    static bool SpeakResponse(const char* text);
    static bool SetVoicePersonality(const char* voiceType);
    
    // Voice commands
    static bool RegisterVoiceCommand(const char* command, const char* action);
    static bool ExecuteVoiceCommand(const char* command);
    
private:
    static bool s_bVoiceEnabled;
    static bool s_bListening;
};

// ============================================================================
// CONFIGURATION AND SETTINGS
// ============================================================================

// AI configuration
struct MadrigalAIConfig
{
    // Service settings
    char apiKey[128];
    char modelName[64];
    char serviceURL[256];
    
    // Behavior settings
    MadrigalAIPersonality personality;
    float responseTemperature;
    uint32_t maxTokens;
    uint32_t maxResponseTime;
    
    // Feature settings
    bool enabledFeatures[AI_FEATURE_COUNT];
    bool voiceEnabled;
    bool cachingEnabled;
    bool learningEnabled;
    
    // Privacy settings
    bool sharePlayerData;
    bool anonymizeData;
    bool storeConversations;
    
    // Performance settings
    uint32_t maxConcurrentRequests;
    uint32_t cacheSize;
    float costLimit;
};

// ============================================================================
// LEGACY COMPATIBILITY
// ============================================================================

// Legacy AI system compatibility (none - this is completely new)
#define MADRIGAL_AI_REVOLUTIONARY      1

// Global AI instance
extern CMadrigalAIAssistant* g_pAIAssistant;

#endif // MADRIGAL_AI_ASSISTANT_H