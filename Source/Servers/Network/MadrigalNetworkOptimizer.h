/**
 * Madrigal Ascension - Network Optimization System
 * 
 * Advanced networking eliminating traditional Flyff connection issues
 * Phase 3: TCP/UDP hybrid, compression, modern protocols
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_NETWORK_OPTIMIZER_H
#define MADRIGAL_NETWORK_OPTIMIZER_H

#include "../../Config/MadrigalConfig.h"
#include <stdint.h>

// ============================================================================
// NETWORK PROTOCOL OPTIMIZATION
// ============================================================================

// Hybrid protocol configuration
#define MADRIGAL_USE_TCP_UDP_HYBRID     1
#define MADRIGAL_TCP_RELIABLE_DATA      1    // Character data, inventory, etc.
#define MADRIGAL_UDP_REALTIME_DATA      1    // Movement, combat, etc.

// Packet optimization
#define MADRIGAL_PACKET_COMPRESSION     1
#define MADRIGAL_DELTA_COMPRESSION      1    // Send only changes
#define MADRIGAL_PACKET_BATCHING        1    // Batch small packets
#define MADRIGAL_ADAPTIVE_COMPRESSION   1    // Smart compression based on data

// Protocol versions
#define MADRIGAL_NETWORK_PROTOCOL_V2    20000
#define MADRIGAL_PACKET_MAGIC           0x4D41  // "MA" for Madrigal Ascension

// ============================================================================
// CONNECTION MANAGEMENT
// ============================================================================

// Connection settings
#define MADRIGAL_MAX_CONNECTIONS        1000
#define MADRIGAL_CONNECTION_TIMEOUT     30000   // 30 seconds
#define MADRIGAL_HEARTBEAT_INTERVAL     15000   // 15 seconds
#define MADRIGAL_RECONNECT_ATTEMPTS     3

// Quality of Service (QoS)
#define MADRIGAL_ENABLE_QOS             1
#define MADRIGAL_PRIORITY_PACKETS       1    // Prioritize important packets
#define MADRIGAL_BANDWIDTH_MANAGEMENT   1
#define MADRIGAL_CONGESTION_CONTROL     1

// ============================================================================
// ANTI-LAG NETWORKING
// ============================================================================

// Prediction and interpolation
#define MADRIGAL_CLIENT_PREDICTION      1
#define MADRIGAL_SERVER_RECONCILIATION  1
#define MADRIGAL_SMOOTH_INTERPOLATION   1
#define MADRIGAL_ROLLBACK_NETCODE       1

// Lag compensation
#define MADRIGAL_LAG_COMPENSATION       1
#define MADRIGAL_MAX_ROLLBACK_FRAMES    10
#define MADRIGAL_PREDICTION_THRESHOLD   100  // ms

// ============================================================================
// PACKET DEFINITIONS
// ============================================================================

// Packet types (modernized)
typedef enum MadrigalPacketType
{
    // Authentication
    MADRIGAL_PKT_LOGIN_REQUEST      = 0x1001,
    MADRIGAL_PKT_LOGIN_RESPONSE     = 0x1002,
    MADRIGAL_PKT_LOGOUT_REQUEST     = 0x1003,
    
    // Character management
    MADRIGAL_PKT_CHAR_LIST          = 0x2001,
    MADRIGAL_PKT_CHAR_SELECT        = 0x2002,
    MADRIGAL_PKT_CHAR_CREATE        = 0x2003,
    
    // Movement (UDP optimized)
    MADRIGAL_PKT_MOVEMENT_UPDATE    = 0x3001,
    MADRIGAL_PKT_POSITION_SYNC      = 0x3002,
    MADRIGAL_PKT_MOVEMENT_PREDICT   = 0x3003,
    
    // Combat (time-critical)
    MADRIGAL_PKT_ATTACK             = 0x4001,
    MADRIGAL_PKT_SKILL_USE          = 0x4002,
    MADRIGAL_PKT_DAMAGE_DEALT       = 0x4003,
    
    // Chat and social
    MADRIGAL_PKT_CHAT_MESSAGE       = 0x5001,
    MADRIGAL_PKT_GUILD_MESSAGE      = 0x5002,
    MADRIGAL_PKT_PARTY_MESSAGE      = 0x5003,
    
    // World updates
    MADRIGAL_PKT_WORLD_UPDATE       = 0x6001,
    MADRIGAL_PKT_OBJECT_SPAWN       = 0x6002,
    MADRIGAL_PKT_OBJECT_DESPAWN     = 0x6003,
    
    // System messages
    MADRIGAL_PKT_SYSTEM_MESSAGE     = 0x9001,
    MADRIGAL_PKT_ERROR_MESSAGE      = 0x9002,
    MADRIGAL_PKT_HEARTBEAT          = 0x9003
    
} MadrigalPacketType;

// Packet header structure
typedef struct MadrigalPacketHeader
{
    uint16_t magic;         // MADRIGAL_PACKET_MAGIC
    uint16_t type;          // MadrigalPacketType
    uint32_t size;          // Packet size including header
    uint32_t sequence;      // Sequence number
    uint32_t timestamp;     // Timestamp
    uint16_t checksum;      // Header checksum
    uint8_t  flags;         // Packet flags
    uint8_t  reserved;      // Reserved for future use
    
} MadrigalPacketHeader;

// Packet flags
#define MADRIGAL_PKT_FLAG_COMPRESSED    0x01
#define MADRIGAL_PKT_FLAG_ENCRYPTED     0x02
#define MADRIGAL_PKT_FLAG_RELIABLE      0x04
#define MADRIGAL_PKT_FLAG_PRIORITY      0x08
#define MADRIGAL_PKT_FLAG_FRAGMENTED    0x10

// ============================================================================
// NETWORK OPTIMIZATION CLASSES
// ============================================================================

// Main network optimizer
class CMadrigalNetworkOptimizer
{
public:
    // System lifecycle
    static bool Initialize();
    static void Shutdown();
    static void Update();
    
    // Optimization features
    static bool EnableHybridProtocol();
    static bool EnablePacketCompression();
    static bool EnableQualityOfService();
    static bool EnableLagCompensation();
    
    // Performance monitoring
    static float GetAverageLatency();
    static uint32_t GetPacketsPerSecond();
    static uint32_t GetBandwidthUsage();
    static float GetCompressionRatio();
    
    // Configuration
    static void SetCompressionLevel(int level);  // 0-9
    static void SetQoSMode(int mode);            // 0=Off, 1=Basic, 2=Advanced
    static void EnablePrediction(bool enable);
    
private:
    static bool s_bInitialized;
    static CMadrigalNetworkOptimizer* s_pInstance;
};

// Packet compression system
class CMadrigalPacketCompressor
{
public:
    // Compression algorithms
    static bool CompressPacket(const void* input, uint32_t inputSize, 
                              void* output, uint32_t* outputSize);
    static bool DecompressPacket(const void* input, uint32_t inputSize,
                                void* output, uint32_t* outputSize);
    
    // Smart compression
    static bool ShouldCompress(const void* data, uint32_t size);
    static int GetOptimalCompressionLevel(const void* data, uint32_t size);
    
    // Statistics
    static float GetCompressionRatio();
    static uint64_t GetBytesSaved();
};

// Quality of Service manager
class CMadrigalQoSManager
{
public:
    // Packet prioritization
    static int GetPacketPriority(MadrigalPacketType type);
    static void SetPacketPriority(MadrigalPacketType type, int priority);
    
    // Bandwidth management
    static bool ManageBandwidth(uint32_t availableBandwidth);
    static void ThrottlePackets(bool enable);
    
    // Connection quality
    enum ConnectionQuality
    {
        CONNECTION_EXCELLENT = 0,
        CONNECTION_GOOD = 1,
        CONNECTION_FAIR = 2,
        CONNECTION_POOR = 3,
        CONNECTION_TERRIBLE = 4
    };
    
    static ConnectionQuality GetConnectionQuality();
    static void AdaptToConnectionQuality(ConnectionQuality quality);
};

// Lag compensation system
class CMadrigalLagCompensation
{
public:
    // Prediction
    static bool EnableClientPrediction(bool enable);
    static bool PredictMovement(uint32_t playerId, float deltaTime);
    
    // Reconciliation
    static bool ReconcilePosition(uint32_t playerId, 
                                 float serverX, float serverY, float serverZ,
                                 uint32_t timestamp);
    
    // Rollback
    static bool RollbackToTimestamp(uint32_t timestamp);
    static void SaveGameState();
    static void RestoreGameState(uint32_t timestamp);
    
    // Configuration
    static void SetPredictionThreshold(uint32_t milliseconds);
    static void SetMaxRollbackFrames(uint32_t frames);
};

// ============================================================================
// SECURITY ENHANCEMENTS
// ============================================================================

// Packet encryption
class CMadrigalPacketSecurity
{
public:
    // Encryption
    static bool EncryptPacket(void* packet, uint32_t size);
    static bool DecryptPacket(void* packet, uint32_t size);
    
    // Authentication
    static bool ValidatePacket(const MadrigalPacketHeader* header);
    static bool GenerateChecksum(const void* data, uint32_t size, uint16_t* checksum);
    
    // Anti-replay
    static bool IsValidSequence(uint32_t sequence);
    static void UpdateSequenceNumber(uint32_t sequence);
};

// ============================================================================
// PERFORMANCE METRICS
// ============================================================================

// Network statistics
struct MadrigalNetworkStats
{
    // Latency metrics
    float averageLatency;
    float minLatency;
    float maxLatency;
    float jitter;
    
    // Throughput metrics
    uint32_t packetsPerSecond;
    uint32_t bytesPerSecond;
    uint32_t compressionRatio;
    
    // Quality metrics
    float packetLoss;
    uint32_t duplicatePackets;
    uint32_t outOfOrderPackets;
    
    // Performance metrics
    uint32_t predictionsPerSecond;
    uint32_t reconciliationsPerSecond;
    float compressionTime;
};

// Global network statistics
extern MadrigalNetworkStats g_NetworkStats;

// ============================================================================
// LEGACY COMPATIBILITY
// ============================================================================

// Legacy protocol support (temporary)
#define FLYFF_PROTOCOL_SUPPORT          1
#define NEUZ_PACKET_COMPAT             1

// Legacy packet types mapping
#define PACKETTYPE_LOGIN               MADRIGAL_PKT_LOGIN_REQUEST
#define PACKETTYPE_LOGOUT              MADRIGAL_PKT_LOGOUT_REQUEST
#define PACKETTYPE_MOVE                MADRIGAL_PKT_MOVEMENT_UPDATE

// Legacy class aliases
typedef CMadrigalNetworkOptimizer CNetworkOptimizer;
#define g_pNetworkOptimizer CMadrigalNetworkOptimizer

#endif // MADRIGAL_NETWORK_OPTIMIZER_H