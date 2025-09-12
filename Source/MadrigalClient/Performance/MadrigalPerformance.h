/**
 * Madrigal Ascension - Performance Optimization System
 * 
 * Core performance enhancements eliminating traditional Flyff issues
 * Phase 2: Anti-lag movement, DirectX optimization, memory management
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_PERFORMANCE_H
#define MADRIGAL_PERFORMANCE_H

#include <stdint.h>

// ============================================================================
// ANTI-LAG MOVEMENT SYSTEM
// ============================================================================

// Movement validation and prediction
#define MADRIGAL_MAX_MOVEMENT_SPEED     200.0f
#define MADRIGAL_TELEPORT_THRESHOLD     500.0f
#define MADRIGAL_POSITION_VALIDATION    1
#define MADRIGAL_MOVEMENT_PREDICTION    1

// Anti-cheat movement detection
#define MADRIGAL_SPEED_HACK_DETECTION   1
#define MADRIGAL_TELEPORT_DETECTION     1
#define MADRIGAL_FLY_HACK_DETECTION     1

// Movement interpolation settings
#define MADRIGAL_SMOOTH_INTERPOLATION   1
#define MADRIGAL_INTERPOLATION_FACTOR   0.85f

// ============================================================================
// DIRECTX OPTIMIZATION
// ============================================================================

// Modern DirectX settings
#define MADRIGAL_USE_DIRECTX11          1
#define MADRIGAL_USE_HARDWARE_ACCEL     1
#define MADRIGAL_ENABLE_MULTITHREADING  1

// Rendering optimization
#define MADRIGAL_LOD_SYSTEM             1
#define MADRIGAL_TEXTURE_STREAMING      1
#define MADRIGAL_MESH_OPTIMIZATION      1

// Performance targets
#define MADRIGAL_TARGET_FPS             60
#define MADRIGAL_MAX_FPS                120
#define MADRIGAL_VSYNC_ENABLED          1

// ============================================================================
// MEMORY OPTIMIZATION
// ============================================================================

// Memory pooling
#define MADRIGAL_MEMORY_POOLING         1
#define MADRIGAL_TEXTURE_POOL_SIZE      (256 * 1024 * 1024)  // 256MB
#define MADRIGAL_MESH_POOL_SIZE         (128 * 1024 * 1024)  // 128MB
#define MADRIGAL_SOUND_POOL_SIZE        (64 * 1024 * 1024)   // 64MB

// Asset management
#define MADRIGAL_ASSET_PRELOADING       1
#define MADRIGAL_PROGRESSIVE_LOADING    1
#define MADRIGAL_SMART_CACHING          1

// ============================================================================
// NETWORK OPTIMIZATION
// ============================================================================

// Protocol improvements
#define MADRIGAL_PACKET_COMPRESSION     1
#define MADRIGAL_DELTA_COMPRESSION      1
#define MADRIGAL_HYBRID_PROTOCOL        1

// Anti-lag networking
#define MADRIGAL_NETWORK_PREDICTION     1
#define MADRIGAL_CLIENT_INTERPOLATION   1
#define MADRIGAL_SERVER_RECONCILIATION  1

// ============================================================================
// PERFORMANCE MONITORING
// ============================================================================

// Metrics and profiling
#define MADRIGAL_PERFORMANCE_METRICS    1
#define MADRIGAL_FPS_MONITORING         1
#define MADRIGAL_MEMORY_MONITORING      1
#define MADRIGAL_NETWORK_MONITORING     1

// ============================================================================
// CORE CLASSES (SIMPLIFIED)
// ============================================================================

// Forward declarations
class CMadrigalPerformanceManager;
class CAntiLagSystem;
class CRenderOptimizer;
class CMemoryManager;
class CNetworkOptimizer;

// Main performance management class
class CMadrigalPerformanceManager
{
public:
    // Lifecycle
    static bool Initialize();
    static void Shutdown();
    static void Update();
    
    // System enablement
    static bool EnableAntiLagMovement();
    static bool EnableDirectXOptimization();
    static bool EnableMemoryOptimization();
    static bool EnableNetworkOptimization();
    
    // Performance monitoring
    static float GetCurrentFPS();
    static uint32_t GetMemoryUsage();
    static float GetNetworkLatency();
    
    // Configuration
    static void SetTargetFPS(int fps);
    static void SetMemoryBudget(uint32_t bytes);
    static void EnablePerfectionMode(bool enable);
    
private:
    static bool s_bInitialized;
    static CMadrigalPerformanceManager* s_pInstance;
};

// Legacy compatibility
#define g_pPerformanceManager CMadrigalPerformanceManager
#define ENABLE_PERFORMANCE_MODE() CMadrigalPerformanceManager::EnablePerfectionMode(true)

#endif // MADRIGAL_PERFORMANCE_H