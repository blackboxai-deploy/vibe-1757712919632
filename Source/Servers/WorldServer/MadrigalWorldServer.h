/**
 * Madrigal Ascension - World Server
 * 
 * Modernized world server replacing legacy WORLDSERVER
 * Enhanced with performance optimizations and modern features
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_WORLD_SERVER_H
#define MADRIGAL_WORLD_SERVER_H

#include "../../Config/MadrigalConfig.h"
#include "../../Resource/MadrigalAscension/defines.h"

#include <memory>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <atomic>

// Forward declarations
class CMadrigalPlayer;
class CMadrigalGuild;
class CMadrigalWorld;
class CNetworkManager;
class CDatabaseManager;
class CSecurityManager;

/**
 * Main World Server class for Madrigal Ascension
 * Handles all game world logic, player management, and gameplay systems
 */
class CMadrigalWorldServer
{
public:
    CMadrigalWorldServer();
    virtual ~CMadrigalWorldServer();

    // Server lifecycle
    bool Initialize();
    void Shutdown();
    bool Start(int port = MADRIGAL_WORLD_PORT);
    void Stop();
    
    // Main server loop
    void Run();

    // Modern features
    bool EnableAntiCheat();
    bool EnablePerformanceOptimization();
    bool EnableAIAssistantIntegration(); // Phase 6

    // Player management
    bool AddPlayer(std::shared_ptr<CMadrigalPlayer> player);
    bool RemovePlayer(uint32_t playerId);
    std::shared_ptr<CMadrigalPlayer> GetPlayer(uint32_t playerId);
    size_t GetPlayerCount() const;

    // Guild management
    bool CreateGuild(const std::string& guildName, uint32_t leaderId);
    bool DisbandGuild(uint32_t guildId);
    std::shared_ptr<CMadrigalGuild> GetGuild(uint32_t guildId);

    // World management
    void UpdateWorld(float deltaTime);
    void ProcessPlayerActions();
    void HandleNetworkMessages();
    
    // Performance optimization features
    void OptimizeMemoryUsage();
    void UpdateAsyncSystems();
    void MonitorPerformance();

    // Security features
    void ValidatePlayerActions();
    void DetectSuspiciousActivity();
    void LogSecurityEvents();

    // Legacy compatibility
    static CMadrigalWorldServer* GetInstance() { return s_pInstance; }

private:
    // Core systems
    std::unique_ptr<CNetworkManager> m_pNetwork;
    std::unique_ptr<CDatabaseManager> m_pDatabase;
    std::unique_ptr<CSecurityManager> m_pSecurity;
    std::unique_ptr<CMadrigalWorld> m_pGameWorld;

    // Player management
    std::unordered_map<uint32_t, std::shared_ptr<CMadrigalPlayer>> m_Players;
    std::mutex m_PlayersMutex;

    // Guild management  
    std::unordered_map<uint32_t, std::shared_ptr<CMadrigalGuild>> m_Guilds;
    std::mutex m_GuildsMutex;

    // Server state
    std::atomic<bool> m_bRunning;
    std::atomic<bool> m_bInitialized;
    std::atomic<size_t> m_PlayerCount;

    // Threading
    std::thread m_NetworkThread;
    std::thread m_DatabaseThread;
    std::thread m_GameLogicThread;
    
    // Performance monitoring
    float m_LastUpdateTime;
    uint32_t m_FrameCount;
    float m_AverageFrameTime;

    // Static instance for legacy compatibility
    static CMadrigalWorldServer* s_pInstance;

    // Internal methods
    void InitializeNetworking();
    void InitializeDatabase();
    void InitializeSecurity();
    void InitializeGameWorld();
    
    void NetworkThreadProc();
    void DatabaseThreadProc();
    void GameLogicThreadProc();
    
    void ProcessIncomingConnections();
    void ProcessPlayerUpdates();
    void ProcessGuildActions();
    void ProcessWorldEvents();
    
    void HandlePlayerLogin(uint32_t playerId);
    void HandlePlayerLogout(uint32_t playerId);
    void HandlePlayerMovement(uint32_t playerId, float x, float y, float z);
    void HandlePlayerAction(uint32_t playerId, uint32_t actionId);
    
    void BroadcastToPlayers(const void* data, size_t size);
    void BroadcastToArea(float x, float y, float radius, const void* data, size_t size);
    
    void SavePlayerData();
    void SaveGuildData();
    void SaveWorldState();
};

/**
 * Player representation in the world server
 */
class CMadrigalPlayer
{
public:
    CMadrigalPlayer(uint32_t id);
    virtual ~CMadrigalPlayer();

    // Player properties
    uint32_t GetId() const { return m_Id; }
    const std::string& GetName() const { return m_Name; }
    uint32_t GetLevel() const { return m_Level; }
    uint32_t GetClass() const { return m_Class; }
    
    // Position and movement
    void SetPosition(float x, float y, float z);
    void GetPosition(float& x, float& y, float& z) const;
    bool ValidatePosition(float x, float y, float z);
    
    // Combat and stats
    uint32_t GetHP() const { return m_HP; }
    uint32_t GetMP() const { return m_MP; }
    uint32_t GetExp() const { return m_Experience; }
    
    void SetHP(uint32_t hp) { m_HP = hp; }
    void SetMP(uint32_t mp) { m_MP = mp; }
    void AddExp(uint32_t exp);
    
    // Guild membership
    uint32_t GetGuildId() const { return m_GuildId; }
    void SetGuildId(uint32_t guildId) { m_GuildId = guildId; }
    
    // Network and state
    bool IsOnline() const { return m_bOnline; }
    void SetOnline(bool online) { m_bOnline = online; }
    
    // Modern features
    void EnableAntiCheat() { m_bAntiCheatEnabled = true; }
    bool IsAntiCheatEnabled() const { return m_bAntiCheatEnabled; }
    
    // Data persistence
    bool LoadFromDatabase();
    bool SaveToDatabase();

private:
    uint32_t m_Id;
    std::string m_Name;
    uint32_t m_Level;
    uint32_t m_Class;
    
    // Position
    float m_X, m_Y, m_Z;
    float m_LastValidX, m_LastValidY, m_LastValidZ;
    
    // Stats
    uint32_t m_HP;
    uint32_t m_MP;
    uint32_t m_MaxHP;
    uint32_t m_MaxMP;
    uint32_t m_Experience;
    
    // Guild
    uint32_t m_GuildId;
    
    // State
    bool m_bOnline;
    bool m_bAntiCheatEnabled;
    
    // Timing for anti-cheat
    std::chrono::high_resolution_clock::time_point m_LastMoveTime;
    std::chrono::high_resolution_clock::time_point m_LastActionTime;
};

/**
 * Guild representation in the world server
 */
class CMadrigalGuild
{
public:
    CMadrigalGuild(uint32_t id, const std::string& name, uint32_t leaderId);
    virtual ~CMadrigalGuild();

    // Basic properties
    uint32_t GetId() const { return m_Id; }
    const std::string& GetName() const { return m_Name; }
    uint32_t GetLeaderId() const { return m_LeaderId; }
    
    // Member management
    bool AddMember(uint32_t playerId);
    bool RemoveMember(uint32_t playerId);
    bool IsMember(uint32_t playerId) const;
    size_t GetMemberCount() const;
    
    // Guild features
    uint32_t GetLevel() const { return m_Level; }
    uint32_t GetExperience() const { return m_Experience; }
    void AddExperience(uint32_t exp);
    
    // Data persistence
    bool LoadFromDatabase();
    bool SaveToDatabase();

private:
    uint32_t m_Id;
    std::string m_Name;
    uint32_t m_LeaderId;
    
    std::vector<uint32_t> m_Members;
    std::mutex m_MembersMutex;
    
    uint32_t m_Level;
    uint32_t m_Experience;
    std::chrono::system_clock::time_point m_CreationTime;
};

// Utility functions
namespace MadrigalWorldUtils
{
    bool ValidateMovementSpeed(float distance, float timeElapsed);
    bool ValidatePlayerAction(uint32_t playerId, uint32_t actionId);
    float CalculateDistance(float x1, float y1, float x2, float y2);
    bool IsInValidArea(float x, float y, float z);
}

// Legacy compatibility macros
#define g_pWorldServer      CMadrigalWorldServer::GetInstance()
#define CWorldServer        CMadrigalWorldServer
#define CPlayer             CMadrigalPlayer
#define CGuild              CMadrigalGuild

#endif // MADRIGAL_WORLD_SERVER_H