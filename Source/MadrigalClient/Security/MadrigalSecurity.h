/**
 * Madrigal Ascension - Advanced Security System
 * 
 * Enterprise-grade security eliminating cheating and exploits
 * Phase 5: Modern encryption, behavioral analysis, memory protection
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_SECURITY_H
#define MADRIGAL_SECURITY_H

#include "../../Config/MadrigalConfig.h"
#include <stdint.h>

// ============================================================================
// SECURITY CONFIGURATION
// ============================================================================

// Security levels
typedef enum MadrigalSecurityLevel
{
    SECURITY_DISABLED = 0,      // No security (development only)
    SECURITY_BASIC = 1,         // Basic protection
    SECURITY_STANDARD = 2,      // Standard protection (default)
    SECURITY_HIGH = 3,          // High security
    SECURITY_MAXIMUM = 4        // Maximum security (tournament mode)
} MadrigalSecurityLevel;

// Default security settings
#define MADRIGAL_DEFAULT_SECURITY       SECURITY_STANDARD
#define MADRIGAL_ENABLE_ENCRYPTION      1
#define MADRIGAL_ENABLE_MEMORY_PROTECTION 1
#define MADRIGAL_ENABLE_BEHAVIORAL_ANALYSIS 1

// ============================================================================
// MODERN ENCRYPTION SYSTEM
// ============================================================================

// Encryption algorithms
#define MADRIGAL_USE_AES256             1
#define MADRIGAL_USE_RSA2048            1       // For key exchange
#define MADRIGAL_USE_ECDH               1       // Elliptic curve key exchange
#define MADRIGAL_ROTATION_INTERVAL      300000  // 5 minutes

// Encryption modes
typedef enum MadrigalEncryptionMode
{
    ENCRYPT_NONE = 0,
    ENCRYPT_BASIC = 1,          // Simple XOR (legacy compatibility)
    ENCRYPT_AES128 = 2,         // AES-128
    ENCRYPT_AES256 = 3,         // AES-256 (default)
    ENCRYPT_CHACHA20 = 4        // ChaCha20-Poly1305
} MadrigalEncryptionMode;

// Key management
#define MADRIGAL_KEY_SIZE_256           32      // 256-bit keys
#define MADRIGAL_KEY_SIZE_128           16      // 128-bit keys
#define MADRIGAL_IV_SIZE                16      // Initialization vector
#define MADRIGAL_MAX_KEYS               16      // Key rotation buffer

// ============================================================================
// ANTI-CHEAT SYSTEM
// ============================================================================

// Cheat detection methods
#define MADRIGAL_SPEED_HACK_DETECTION   1
#define MADRIGAL_TELEPORT_DETECTION     1
#define MADRIGAL_FLY_HACK_DETECTION     1
#define MADRIGAL_MEMORY_SCAN_DETECTION  1
#define MADRIGAL_PACKET_INJECTION_DETECTION 1
#define MADRIGAL_AUTOMATION_DETECTION   1

// Behavioral analysis
#define MADRIGAL_BEHAVIORAL_AI          1
#define MADRIGAL_PATTERN_RECOGNITION    1
#define MADRIGAL_STATISTICAL_ANALYSIS   1
#define MADRIGAL_MACHINE_LEARNING       1

// Detection thresholds
#define MADRIGAL_SPEED_THRESHOLD        1.5f    // 150% of normal speed
#define MADRIGAL_TELEPORT_DISTANCE      500.0f  // Max teleport distance
#define MADRIGAL_SUSPICIOUS_ACTIONS     5       // Actions before flagging
#define MADRIGAL_CONFIDENCE_THRESHOLD   0.85f   // ML confidence level

// ============================================================================
// MEMORY PROTECTION
// ============================================================================

// Memory protection techniques
#define MADRIGAL_MEMORY_ENCRYPTION      1       // Encrypt sensitive memory
#define MADRIGAL_STACK_PROTECTION       1       // Stack canaries
#define MADRIGAL_HEAP_PROTECTION        1       // Heap corruption detection
#define MADRIGAL_DEP_PROTECTION         1       // Data Execution Prevention

// Code integrity
#define MADRIGAL_CODE_SIGNING           1       // Verify executable integrity
#define MADRIGAL_RUNTIME_CHECKS         1       // Runtime integrity checks
#define MADRIGAL_ANTI_DEBUGGING         1       // Anti-debugging protection
#define MADRIGAL_OBFUSCATION            1       // Code obfuscation

// Process protection
#define MADRIGAL_PROCESS_HOLLOWING_DETECT 1     // Detect process hollowing
#define MADRIGAL_DLL_INJECTION_DETECT   1       // Detect DLL injection
#define MADRIGAL_HOOK_DETECTION         1       // Detect API hooks
#define MADRIGAL_VIRTUAL_MACHINE_DETECT 1       // Detect VM/sandbox

// ============================================================================
// SECURITY CLASSES
// ============================================================================

// Main security manager
class CMadrigalSecurityManager
{
public:
    // System lifecycle
    static bool Initialize(MadrigalSecurityLevel level);
    static void Shutdown();
    static void Update();
    
    // Security level management
    static bool SetSecurityLevel(MadrigalSecurityLevel level);
    static MadrigalSecurityLevel GetSecurityLevel();
    
    // Encryption management
    static bool EnableEncryption(MadrigalEncryptionMode mode);
    static bool GenerateSessionKeys();
    static bool RotateKeys();
    
    // Anti-cheat control
    static bool EnableAntiCheat(bool enable);
    static bool EnableBehavioralAnalysis(bool enable);
    static bool EnableMemoryProtection(bool enable);
    
    // Security monitoring
    static uint32_t GetSecurityViolations();
    static float GetThreatLevel();
    static bool IsPlayerSuspicious(uint32_t playerId);
    
private:
    static bool s_bInitialized;
    static MadrigalSecurityLevel s_SecurityLevel;
    static CMadrigalSecurityManager* s_pInstance;
};

// Advanced encryption system
class CMadrigalEncryption
{
public:
    // Initialization
    static bool Initialize(MadrigalEncryptionMode mode);
    static bool GenerateKeyPair();
    static bool ExchangeKeys(const uint8_t* publicKey, uint32_t keySize);
    
    // Encryption/Decryption
    static bool EncryptData(const void* input, uint32_t inputSize,
                           void* output, uint32_t* outputSize);
    static bool DecryptData(const void* input, uint32_t inputSize,
                           void* output, uint32_t* outputSize);
    
    // Packet encryption
    static bool EncryptPacket(void* packet, uint32_t packetSize);
    static bool DecryptPacket(void* packet, uint32_t packetSize);
    
    // Key management
    static bool RotateKeys();
    static bool ValidateKeyIntegrity();
    static void ClearSensitiveData();
    
private:
    static MadrigalEncryptionMode s_EncryptionMode;
    static uint8_t s_EncryptionKey[MADRIGAL_KEY_SIZE_256];
    static uint8_t s_InitializationVector[MADRIGAL_IV_SIZE];
};

// Behavioral analysis engine
class CMadrigalBehavioralAnalysis
{
public:
    // Player behavior tracking
    static bool TrackPlayerAction(uint32_t playerId, uint32_t actionType, 
                                 float x, float y, float z, uint32_t timestamp);
    static bool AnalyzeMovementPattern(uint32_t playerId);
    static bool DetectAutomation(uint32_t playerId);
    
    // Statistical analysis
    static float CalculateSuspicionScore(uint32_t playerId);
    static bool IsActionPatternSuspicious(uint32_t playerId, uint32_t actionType);
    static bool DetectBotBehavior(uint32_t playerId);
    
    // Machine learning integration
    static bool LoadMLModel(const char* modelPath);
    static float PredictCheatProbability(uint32_t playerId);
    static bool UpdateModelWithData(uint32_t playerId, bool isCheat);
    
    // Pattern recognition
    struct BehaviorPattern
    {
        uint32_t playerId;
        uint32_t actionType;
        float frequency;
        float regularity;
        float suspicionScore;
        uint64_t lastActionTime;
    };
    
    static bool RegisterBehaviorPattern(const BehaviorPattern* pattern);
    static bool GetPlayerBehaviorProfile(uint32_t playerId, BehaviorPattern* profile);
    
private:
    static bool s_bMLModelLoaded;
    static float s_SuspicionThreshold;
};

// Memory protection system
class CMadrigalMemoryProtection
{
public:
    // Memory encryption
    static bool EncryptSensitiveMemory(void* memory, uint32_t size);
    static bool DecryptSensitiveMemory(void* memory, uint32_t size);
    
    // Integrity checking
    static bool CalculateMemoryChecksum(const void* memory, uint32_t size, uint32_t* checksum);
    static bool VerifyMemoryIntegrity(const void* memory, uint32_t size, uint32_t expectedChecksum);
    
    // Protection mechanisms
    static bool EnableStackProtection(bool enable);
    static bool EnableHeapProtection(bool enable);
    static bool EnableDEP(bool enable);
    
    // Runtime checks
    static bool PerformRuntimeCheck();
    static bool ValidateCodeIntegrity();
    static bool DetectCodeModification();
    
    // Anti-debugging
    static bool EnableAntiDebugging(bool enable);
    static bool DetectDebugger();
    static bool ObfuscateCode(void* code, uint32_t size);
    
private:
    static bool s_bMemoryEncrypted;
    static uint32_t s_MemoryKey;
};

// Cheat detection engine
class CMadrigalCheatDetection
{
public:
    // Movement cheat detection
    static bool DetectSpeedHack(uint32_t playerId, float speed, float maxSpeed);
    static bool DetectTeleportHack(uint32_t playerId, float oldX, float oldY, 
                                  float newX, float newY, float deltaTime);
    static bool DetectFlyHack(uint32_t playerId, float z, float groundZ);
    
    // Combat cheat detection
    static bool DetectDamageHack(uint32_t playerId, uint32_t damage, uint32_t maxDamage);
    static bool DetectCooldownHack(uint32_t playerId, uint32_t skillId, float cooldown);
    static bool DetectInfiniteResourceHack(uint32_t playerId, uint32_t resourceType);
    
    // Packet analysis
    static bool AnalyzePacketFrequency(uint32_t playerId, uint32_t packetType);
    static bool DetectPacketInjection(const void* packet, uint32_t size);
    static bool ValidatePacketSequence(uint32_t sequence, uint32_t expected);
    
    // Advanced detection
    static bool DetectMemoryScanner();
    static bool DetectProcessInjection();
    static bool DetectVirtualMachine();
    
    // Violation handling
    struct SecurityViolation
    {
        uint32_t playerId;
        uint32_t violationType;
        float confidence;
        uint64_t timestamp;
        char description[256];
    };
    
    static bool ReportViolation(const SecurityViolation* violation);
    static bool GetViolationHistory(uint32_t playerId, SecurityViolation* violations, int maxViolations);
    
private:
    static uint32_t s_ViolationCount;
    static float s_GlobalThreatLevel;
};

// ============================================================================
// AUDIT AND LOGGING
// ============================================================================

// Security audit system
class CMadrigalSecurityAudit
{
public:
    // Audit logging
    static bool LogSecurityEvent(uint32_t eventType, uint32_t playerId, const char* description);
    static bool LogLoginAttempt(const char* username, const char* ipAddress, bool success);
    static bool LogCheatDetection(uint32_t playerId, uint32_t cheatType, float confidence);
    
    // Audit analysis
    static bool AnalyzeSecurityLogs();
    static bool GenerateSecurityReport(char* report, uint32_t maxLength);
    static bool GetSecurityMetrics(void* metrics);
    
private:
    static bool s_bAuditEnabled;
};

// ============================================================================
// SECURITY METRICS AND MONITORING
// ============================================================================

// Security statistics
struct MadrigalSecurityStats
{
    // Detection statistics
    uint32_t totalViolations;
    uint32_t speedHackDetections;
    uint32_t teleportHackDetections;
    uint32_t memoryViolations;
    uint32_t packetInjections;
    
    // Performance metrics
    float averageAnalysisTime;
    float falsePositiveRate;
    float detectionAccuracy;
    
    // System health
    float encryptionOverhead;
    float memoryProtectionOverhead;
    float overallPerformanceImpact;
};

extern MadrigalSecurityStats g_SecurityStats;

// ============================================================================
// LEGACY COMPATIBILITY
// ============================================================================

// Legacy anti-cheat compatibility
#define NEUZ_ANTICHEAT_ENABLED          MADRIGAL_ENABLE_BEHAVIORAL_ANALYSIS
#define FLYFF_SECURITY_LEVEL            MADRIGAL_DEFAULT_SECURITY

// Legacy class aliases
typedef CMadrigalSecurityManager CSecurityManager;
#define g_pSecurityManager CMadrigalSecurityManager

#endif // MADRIGAL_SECURITY_H