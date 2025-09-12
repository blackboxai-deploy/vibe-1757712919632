# 🚀 Madrigal Ascension - Installation & Server Management Guide

**The Complete Guide to installing, managing, and running your Next Generation MMORPG server**

---

## 🎯 **Installation Options**

You have **3 ways** to install and run Madrigal Ascension:

### **Option 1: Fresh Installation (Recommended)** 🆕
Complete new installation of Madrigal Ascension

### **Option 2: Legacy Integration** 🔄  
Integrate with existing Flyff repository

### **Option 3: Development Build** 🛠️
Build from source for development

---

## 🆕 **Option 1: Fresh Installation**

### **Linux/macOS (Automated)**
```bash
# Download and run the installer
curl -O https://raw.githubusercontent.com/GitMischaHub/MSFlyff/master/install-madrigal-ascension.sh
chmod +x install-madrigal-ascension.sh
sudo ./install-madrigal-ascension.sh
```

### **Windows (Automated)**
```batch
REM Download and run the installer
curl -O https://raw.githubusercontent.com/GitMischaHub/MSFlyff/master/install-madrigal-ascension.bat
install-madrigal-ascension.bat
```

### **What the installer does:**
- ✅ **Installs all dependencies** (CMake, compilers, MySQL)
- ✅ **Creates system user** and directories
- ✅ **Builds Madrigal Ascension** from source
- ✅ **Configures database** with secure credentials
- ✅ **Sets up systemd services** (Linux) or Windows services
- ✅ **Creates management scripts** for easy server control
- ✅ **Configures firewall** for security

---

## 🔄 **Option 2: Legacy Integration**

If you have an existing Flyff repository:

```bash
# Navigate to your Flyff repository
cd /path/to/your/flyff/repo

# Download and run the integration script
curl -O https://raw.githubusercontent.com/GitMischaHub/MSFlyff/master/integrate-with-legacy-flyff.sh
chmod +x integrate-with-legacy-flyff.sh
./integrate-with-legacy-flyff.sh
```

### **Integration Benefits:**
- ✅ **Keeps your existing Flyff** setup unchanged
- ✅ **Adds Madrigal Ascension** alongside legacy system
- ✅ **Gradual migration** tools included
- ✅ **Switch between modes** easily
- ✅ **Backup safety** - your original files are preserved

---

## 🛠️ **Option 3: Development Build**

For developers who want to build manually:

### **Prerequisites:**
- **CMake 3.20+**
- **Visual Studio 2019+** (Windows) or **GCC 7+/Clang 6+** (Linux/macOS)
- **MySQL/MariaDB**
- **OpenSSL development libraries**

### **Build Steps:**
```bash
# Clone the repository
git clone https://github.com/GitMischaHub/MSFlyff.git
cd MSFlyff

# Switch to Madrigal branch
git checkout blackboxai-madrigal-ascension

# Build with CMake
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel

# Or use the provided scripts
./build.sh          # Linux/macOS
# or
Build.bat          # Windows
```

---

## 🎮 **Server Management**

After installation, you have several management options:

### **Quick Start (Linux/macOS):**
```bash
# Start all servers
sudo systemctl start madrigal-database
sudo systemctl start madrigal-login  
sudo systemctl start madrigal-world

# Or use the management script
./manage-madrigal-server.sh
```

### **Quick Start (Windows):**
```batch
REM Start all servers  
C:\MadrigalAscension\start-servers.bat

REM Check server status
C:\MadrigalAscension\server-status.bat
```

### **Management Interface:**
```bash
# Launch the interactive management console
./manage-madrigal-server.sh
```

**Features of the management interface:**
- 🚀 **Start/Stop servers** with one click
- 📊 **Real-time server status** monitoring
- 📈 **Performance metrics** and optimization
- 🔧 **Configuration management** 
- 📜 **Log viewing** and analysis
- 🤖 **AI Assistant control** panel
- 🛡️ **Security dashboard**
- 💾 **Database management**

---

## ⚙️ **Configuration**

### **Server Configuration:**
```bash
# Edit main server settings
nano /opt/madrigal-ascension/server.conf   # Linux
# or
notepad C:\MadrigalAscension\Config\server.conf   # Windows
```

### **Key Settings:**
```ini
[Network]
WorldServerPort=15500      # Main game world port
LoginServerPort=15400      # Player login port
MaxConnections=1000        # Maximum concurrent players

[Performance]  
EnableMultiThreading=1     # Enable multi-core optimization
EnableAntiLag=1           # Enable anti-lag movement system
EnableMemoryPooling=1     # Enable memory optimization

[Security]
EnableAntiCheat=1         # Enable AI-powered anti-cheat
SecurityLevel=2           # Security level (0-3)
EnableBehavioralAnalysis=1 # Enable AI behavioral analysis

[Features]
EnableAIAssistant=0       # AI Assistant (requires OpenAI API key)
EnableAutoPickup=1        # Quality of life features
EnableModernUI=1          # Modern interface
```

### **AI Assistant Configuration:**
```json
{
  "enabled": false,
  "apiKey": "your-openai-api-key-here",
  "model": "gpt-4o",
  "features": {
    "questHelp": true,
    "buildAdvice": true,
    "navigation": true
  }
}
```

---

## 🌐 **Network & Ports**

### **Default Ports:**
- **15400** - Login Server (players connect here)
- **15500** - World Server (game world)
- **15300** - Database Server (internal only)

### **Firewall Configuration:**
```bash
# Linux (UFW)
sudo ufw allow 15400/tcp
sudo ufw allow 15500/tcp

# Linux (Firewalld)  
sudo firewall-cmd --permanent --add-port=15400/tcp
sudo firewall-cmd --permanent --add-port=15500/tcp
sudo firewall-cmd --reload

# Windows (automatically configured by installer)
```

### **Port Testing:**
```bash
# Test if servers are listening
netstat -ln | grep :15400    # Login server
netstat -ln | grep :15500    # World server

# Test external connectivity
telnet your-server-ip 15400
```

---

## 🎮 **Client Connection**

### **Local Development:**
- **Server Address:** `localhost` or `127.0.0.1`
- **Port:** `15400` (Login Server)

### **Remote Server:**
- **Server Address:** Your server's IP address
- **Port:** `15400`

### **Client Configuration:**
Update your client's server list to point to:
```
ServerName=Madrigal Ascension
ServerIP=your-server-ip
ServerPort=15400
```

---

## 🔧 **Troubleshooting**

### **Common Issues:**

#### **Servers won't start:**
```bash
# Check logs
tail -f /opt/madrigal-ascension/logs/*.log

# Check port conflicts
netstat -ln | grep :15400
netstat -ln | grep :15500

# Check permissions
ls -la /opt/madrigal-ascension/bin/
```

#### **Build failures:**
```bash
# Check dependencies
cmake --version
gcc --version  # or clang --version

# Clean build
rm -rf build/
cmake -B build
cmake --build build
```

#### **Database connection issues:**
```bash
# Check MySQL service
sudo systemctl status mysql    # Linux
net start mysql               # Windows

# Test database connection
mysql -u madrigal -p madrigal_ascension
```

#### **Performance issues:**
```bash
# Check system resources
htop                          # Linux
Task Manager                  # Windows

# Enable performance mode
./manage-madrigal-server.sh
# Select option 11 (Performance Optimization)
```

---

## 📊 **Monitoring & Maintenance**

### **Log Locations:**
- **Linux:** `/var/log/madrigal-ascension/`
- **Windows:** `C:\MadrigalAscension\Logs\`

### **Key Log Files:**
- `database.log` - Database server events
- `login.log` - Login server and authentication
- `world.log` - Game world and player events
- `security.log` - Anti-cheat and security events
- `performance.log` - Performance metrics
- `ai.log` - AI Assistant activities (if enabled)

### **Automated Monitoring:**
```bash
# Set up log rotation (Linux)
sudo logrotate /etc/logrotate.d/madrigal-ascension

# Monitor server health
watch -n 5 './server-status.sh'

# Real-time performance monitoring
./manage-madrigal-server.sh
# Select option 5 (Performance Monitor)
```

---

## 🚀 **Performance Optimization**

### **Hardware Recommendations:**

#### **Minimum Requirements:**
- **CPU:** 4 cores, 2.5GHz
- **RAM:** 4GB 
- **Storage:** 50GB SSD
- **Network:** 100 Mbps

#### **Recommended (1000 players):**
- **CPU:** 8 cores, 3.5GHz  
- **RAM:** 16GB
- **Storage:** 200GB NVMe SSD
- **Network:** 1 Gbps

#### **Enterprise (5000+ players):**
- **CPU:** 16+ cores, 4.0GHz
- **RAM:** 64GB+
- **Storage:** 1TB NVMe SSD + backup storage
- **Network:** 10 Gbps

### **Optimization Tips:**
1. **Enable Performance Mode** in server config
2. **Use SSD storage** for database and logs
3. **Optimize MySQL** configuration for your hardware
4. **Enable memory pooling** and asset streaming
5. **Use dedicated network interface** for game traffic

---

## 🛡️ **Security Configuration**

### **Basic Security:**
```ini
[Security]
EnableAntiCheat=1
SecurityLevel=1
EnableBehavioralAnalysis=0
```

### **High Security (Recommended):**
```ini
[Security]  
EnableAntiCheat=1
SecurityLevel=2
EnableBehavioralAnalysis=1
EnableMemoryProtection=1
```

### **Maximum Security (Tournaments):**
```ini
[Security]
EnableAntiCheat=1
SecurityLevel=3
EnableBehavioralAnalysis=1
EnableMemoryProtection=1
EnableAdvancedDetection=1
```

---

## 🤖 **AI Assistant Setup**

### **1. Get OpenAI API Key:**
1. Visit [OpenAI Platform](https://platform.openai.com/)
2. Create account and get API key
3. Add billing information (pay-per-use)

### **2. Configure AI:**
```json
{
  "enabled": true,
  "apiKey": "sk-your-actual-api-key-here",
  "model": "gpt-4o",
  "maxTokens": 150,
  "timeout": 5000,
  "features": {
    "questHelp": true,
    "buildAdvice": true,
    "navigation": true,
    "socialAssistance": true
  }
}
```

### **3. Test AI:**
```bash
# Test AI connection
curl -X POST http://localhost:15500/api/ai/test
```

---

## 📞 **Support & Community**

### **Get Help:**
- 📖 **Documentation:** [GitHub Wiki](https://github.com/GitMischaHub/MSFlyff/wiki)
- 💬 **Discord:** [discord.gg/madrigal](https://discord.gg/madrigal) 
- 🐛 **Issues:** [GitHub Issues](https://github.com/GitMischaHub/MSFlyff/issues)
- 📧 **Email:** support@madrigalascension.com

### **Community:**
- 🎮 **Players:** [r/MadrigalAscension](https://reddit.com/r/madrigalascension)
- 👨‍💻 **Developers:** [GitHub Discussions](https://github.com/GitMischaHub/MSFlyff/discussions)
- 🎥 **YouTube:** [Madrigal Ascension Channel](https://youtube.com/@madrigalascension)

---

## 🎉 **Quick Start Summary**

### **For Impatient Gamers:** 😄
```bash
# 1. One-line installation
curl -sL https://install.madrigalascension.com | bash

# 2. Start servers
sudo systemctl start madrigal-*

# 3. Connect and play!
# Server: localhost:15400
```

### **For Existing Flyff Servers:**
```bash
# 1. Integrate with existing setup  
./integrate-with-legacy-flyff.sh

# 2. Choose your migration path
./migrate-to-madrigal.sh

# 3. Switch modes as needed
./switch-mode.sh
```

### **For Server Administrators:**
```bash
# 1. Use the management interface
./manage-madrigal-server.sh

# 2. Monitor performance
# Select option 5 in management menu

# 3. Configure as needed
# Edit config files in Config/ directory
```

---

## 🏆 **Success Indicators**

### **✅ Installation Successful When:**
- All servers start without errors
- Ports 15400 and 15500 are listening
- Client can connect to localhost:15400
- Management scripts work correctly
- Performance metrics show improvements

### **✅ Ready for Players When:**
- Database is populated with game data
- World server is stable and responsive  
- Anti-cheat system is operational
- Player accounts can be created
- Character creation works properly

### **🚀 Revolution Mode Active When:**
- Loading times under 20 seconds
- Network latency under 80ms
- FPS stable at 60-120
- Memory usage under 1GB
- Zero position bugs detected
- AI Assistant responding (if enabled)

---

## 🎊 **Welcome to Madrigal Ascension!**

### **🎮 Ready to Play?**

1. **🚀 Start your servers** using the management scripts
2. **🔧 Configure** your server settings  
3. **🎯 Connect** your client to the server
4. **🤖 Enable AI** for the ultimate experience
5. **🎉 Enjoy** the Next Generation MMORPG!

### **🌟 You Now Have:**
- ✅ **Professional MMORPG server** with enterprise features
- ✅ **Complete management tools** for easy administration
- ✅ **Revolutionary performance** eliminating Flyff problems
- ✅ **AI-powered assistance** for enhanced gameplay
- ✅ **Modern security** protecting against cheats
- ✅ **Cross-platform support** for all devices

**Welcome to the future of MMORPG gaming!** 🚀

*Need help? Join our community or check the troubleshooting section above.*

---

## 📋 **Quick Reference**

### **Essential Commands:**
```bash
# Server Management
./manage-madrigal-server.sh          # Interactive management
./start-servers.sh                   # Start all servers
./stop-servers.sh                    # Stop all servers
./server-status.sh                   # Check status

# Build & Development
./build.sh                           # Build from source
./integrate-with-legacy-flyff.sh     # Legacy integration
./migrate-to-madrigal.sh             # Migration tool

# Troubleshooting
tail -f logs/*.log                   # View logs
netstat -ln | grep :15400           # Check ports
systemctl status madrigal-*         # Service status
```

### **Important Paths:**
- **Installation:** `/opt/madrigal-ascension/` (Linux) or `C:\MadrigalAscension\` (Windows)
- **Configuration:** `Config/server.conf` and `Config/ai-config.json`
- **Logs:** `logs/` directory
- **Database:** MySQL `madrigal_ascension` database

### **Network Access:**
- **Local Development:** `localhost:15400`
- **Remote Server:** `your-server-ip:15400`
- **Management Interface:** SSH to server + `./manage-madrigal-server.sh`

**🎉 That's it! You're ready to run the Next Generation MMORPG server! 🎉**