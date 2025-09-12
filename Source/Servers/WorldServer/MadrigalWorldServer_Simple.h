/**
 * Madrigal Ascension - World Server (Simplified)
 * 
 * Basic world server header for rebranding purposes
 * Modernized from legacy WORLDSERVER
 * 
 * @version 1.0.0
 */

#ifndef MADRIGAL_WORLD_SERVER_SIMPLE_H
#define MADRIGAL_WORLD_SERVER_SIMPLE_H

// Basic includes
#include <stdint.h>

// Version and branding
#define MADRIGAL_WORLD_SERVER_VERSION   "1.0.0"
#define MADRIGAL_WORLD_SERVER_NAME      "Madrigal Ascension World Server"

// Legacy compatibility defines
#define WORLD_SERVER_VER                MADRIGAL_WORLD_SERVER_VERSION
#define WORLD_SERVER_NAME               MADRIGAL_WORLD_SERVER_NAME

// Basic server configuration
#define MADRIGAL_WORLD_PORT             15500
#define MADRIGAL_MAX_PLAYERS            1000
#define MADRIGAL_MAX_LEVEL              120

// Legacy compatibility for port
#define DEFAULT_WORLD_PORT              MADRIGAL_WORLD_PORT
#define MAX_PLAYER                      MADRIGAL_MAX_PLAYERS

// Basic class forward declaration
class CMadrigalWorldServer
{
public:
    // Basic lifecycle methods
    bool Initialize();
    void Shutdown();
    bool Start();
    void Stop();
    
    // Static instance for legacy compatibility  
    static CMadrigalWorldServer* GetInstance();
    
private:
    static CMadrigalWorldServer* s_pInstance;
    bool m_bRunning;
    bool m_bInitialized;
};

// Legacy compatibility
typedef CMadrigalWorldServer CWorldServer;
#define g_pWorldServer CMadrigalWorldServer::GetInstance()

// Basic utility functions
namespace MadrigalWorld 
{
    const char* GetServerName();
    const char* GetVersion();
    bool IsRunning();
}

#endif // MADRIGAL_WORLD_SERVER_SIMPLE_H