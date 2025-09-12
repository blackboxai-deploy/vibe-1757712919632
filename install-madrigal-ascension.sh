#!/bin/bash
# Madrigal Ascension - Complete Installation Script
# One-click setup for the Next Generation MMORPG
# 
# Version: 1.0.0

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Installation configuration
INSTALL_DIR="/opt/madrigal-ascension"
DATA_DIR="/var/lib/madrigal-ascension"
LOG_DIR="/var/log/madrigal-ascension"
USER="madrigal"
GROUP="madrigal"

# Function to print colored output
print_header() {
    echo -e "${CYAN}========================================${NC}"
    echo -e "${CYAN}$1${NC}"
    echo -e "${CYAN}========================================${NC}"
    echo
}

print_success() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_error() {
    echo -e "${RED}❌ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️ $1${NC}"
}

print_info() {
    echo -e "${BLUE}ℹ️ $1${NC}"
}

print_step() {
    echo -e "${PURPLE}🚀 $1${NC}"
}

# Function to check if running as root
check_root() {
    if [ "$EUID" -ne 0 ]; then
        print_error "This script must be run as root"
        print_info "Please run: sudo $0"
        exit 1
    fi
}

# Function to detect OS
detect_os() {
    if [ -f /etc/os-release ]; then
        . /etc/os-release
        OS=$ID
        VERSION=$VERSION_ID
    else
        print_error "Cannot detect operating system"
        exit 1
    fi
    
    print_info "Detected OS: $OS $VERSION"
}

# Function to install dependencies
install_dependencies() {
    print_step "Installing system dependencies..."
    
    case $OS in
        ubuntu|debian)
            apt update
            apt install -y \
                cmake \
                build-essential \
                gcc-9 \
                g++-9 \
                git \
                mysql-server \
                mysql-client \
                libmysqlclient-dev \
                openssl \
                libssl-dev \
                zlib1g-dev \
                libbz2-dev \
                wget \
                curl \
                unzip
            ;;
        centos|rhel|rocky|almalinux)
            yum update -y
            yum install -y \
                cmake \
                gcc \
                gcc-c++ \
                git \
                mysql-server \
                mysql-devel \
                openssl \
                openssl-devel \
                zlib-devel \
                bzip2-devel \
                wget \
                curl \
                unzip
            ;;
        *)
            print_warning "Unsupported OS: $OS"
            print_info "Please install dependencies manually:"
            print_info "- CMake 3.20+"
            print_info "- GCC 7+ or Clang 6+"
            print_info "- MySQL/MariaDB"
            print_info "- OpenSSL development libraries"
            ;;
    esac
    
    print_success "System dependencies installed"
}

# Function to create system user
create_system_user() {
    print_step "Creating system user and directories..."
    
    # Create user and group
    if ! getent group $GROUP > /dev/null 2>&1; then
        groupadd $GROUP
        print_success "Created group: $GROUP"
    fi
    
    if ! getent passwd $USER > /dev/null 2>&1; then
        useradd -r -g $GROUP -d $INSTALL_DIR -s /bin/bash $USER
        print_success "Created user: $USER"
    fi
    
    # Create directories
    mkdir -p $INSTALL_DIR
    mkdir -p $DATA_DIR
    mkdir -p $LOG_DIR
    mkdir -p $DATA_DIR/database
    mkdir -p $DATA_DIR/backups
    mkdir -p $DATA_DIR/logs
    
    # Set permissions
    chown -R $USER:$GROUP $INSTALL_DIR
    chown -R $USER:$GROUP $DATA_DIR
    chown -R $USER:$GROUP $LOG_DIR
    
    print_success "System user and directories created"
}

# Function to setup database
setup_database() {
    print_step "Setting up Madrigal Ascension database..."
    
    # Start MySQL service
    case $OS in
        ubuntu|debian)
            systemctl start mysql
            systemctl enable mysql
            ;;
        centos|rhel|rocky|almalinux)
            systemctl start mysqld
            systemctl enable mysqld
            ;;
    esac
    
    # Generate random database password
    DB_PASSWORD=$(openssl rand -base64 32)
    
    # Create database and user
    mysql -e "CREATE DATABASE IF NOT EXISTS madrigal_ascension;"
    mysql -e "CREATE USER IF NOT EXISTS 'madrigal'@'localhost' IDENTIFIED BY '$DB_PASSWORD';"
    mysql -e "GRANT ALL PRIVILEGES ON madrigal_ascension.* TO 'madrigal'@'localhost';"
    mysql -e "FLUSH PRIVILEGES;"
    
    # Save database credentials
    cat > $INSTALL_DIR/database.conf << EOF
DB_HOST=localhost
DB_NAME=madrigal_ascension
DB_USER=madrigal
DB_PASSWORD=$DB_PASSWORD
EOF
    
    chown $USER:$GROUP $INSTALL_DIR/database.conf
    chmod 600 $INSTALL_DIR/database.conf
    
    print_success "Database setup completed"
    print_info "Database credentials saved to: $INSTALL_DIR/database.conf"
}

# Function to build Madrigal Ascension
build_madrigal() {
    print_step "Building Madrigal Ascension..."
    
    # Change to installation directory
    cd $INSTALL_DIR
    
    # Build the project
    mkdir -p build
    cd build
    
    cmake .. \
        -DCMAKE_BUILD_TYPE=Release \
        -DMADRIGAL_BUILD_CLIENT=ON \
        -DMADRIGAL_BUILD_WORLD_SERVER=ON \
        -DMADRIGAL_BUILD_LOGIN_SERVER=ON \
        -DMADRIGAL_BUILD_DATABASE_SERVER=ON \
        -DMADRIGAL_ENABLE_MULTITHREADING=ON \
        -DMADRIGAL_ENABLE_MODERN_GRAPHICS=ON \
        -DMADRIGAL_ENABLE_ANTI_CHEAT=ON \
        -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR
    
    make -j$(nproc)
    make install
    
    # Set permissions
    chown -R $USER:$GROUP $INSTALL_DIR
    chmod +x $INSTALL_DIR/bin/*
    
    print_success "Build completed successfully"
}

# Function to create systemd services
create_services() {
    print_step "Creating systemd services..."
    
    # Database Server Service
    cat > /etc/systemd/system/madrigal-database.service << EOF
[Unit]
Description=Madrigal Ascension Database Server
After=mysql.service
Requires=mysql.service

[Service]
Type=simple
User=$USER
Group=$GROUP
WorkingDirectory=$INSTALL_DIR
ExecStart=$INSTALL_DIR/bin/MadrigalDatabaseServer
Restart=always
RestartSec=10
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
EOF

    # Login Server Service
    cat > /etc/systemd/system/madrigal-login.service << EOF
[Unit]
Description=Madrigal Ascension Login Server
After=madrigal-database.service
Requires=madrigal-database.service

[Service]
Type=simple
User=$USER
Group=$GROUP
WorkingDirectory=$INSTALL_DIR
ExecStart=$INSTALL_DIR/bin/MadrigalLoginServer
Restart=always
RestartSec=10
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
EOF

    # World Server Service
    cat > /etc/systemd/system/madrigal-world.service << EOF
[Unit]
Description=Madrigal Ascension World Server
After=madrigal-login.service
Requires=madrigal-login.service

[Service]
Type=simple
User=$USER
Group=$GROUP
WorkingDirectory=$INSTALL_DIR
ExecStart=$INSTALL_DIR/bin/MadrigalWorldServer
Restart=always
RestartSec=10
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
EOF

    # Reload systemd
    systemctl daemon-reload
    
    print_success "Systemd services created"
}

# Function to create configuration files
create_config() {
    print_step "Creating configuration files..."
    
    # Main server configuration
    cat > $INSTALL_DIR/server.conf << EOF
# Madrigal Ascension Server Configuration
# The Next Generation MMORPG Server

[ServerInfo]
ServerName=Madrigal Ascension Server
ServerDescription=The Next Generation MMORPG Server
Version=1.0.0

[Network]
WorldServerPort=15500
LoginServerPort=15400
DatabaseServerPort=15300
MaxConnections=1000
EnableCompression=1
EnableEncryption=1

[Performance]
EnableMultiThreading=1
MaxWorkerThreads=8
EnableMemoryPooling=1
EnableAntiLag=1

[Security]
EnableAntiCheat=1
SecurityLevel=2
EnableBehavioralAnalysis=1

[Features]
EnableModernUI=1
EnableAIAssistant=0
EnableAutoPickup=1
EnableSmartInventory=1

[Database]
DatabaseType=MySQL
DatabaseServer=localhost
DatabaseName=madrigal_ascension
DatabaseUser=madrigal
DatabasePort=3306
EOF
    
    # AI Configuration (for future use)
    cat > $INSTALL_DIR/ai-config.json << EOF
{
  "enabled": false,
  "apiKey": "your-openai-api-key-here",
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
EOF

    chown -R $USER:$GROUP $INSTALL_DIR/*.conf $INSTALL_DIR/*.json
    
    print_success "Configuration files created"
}

# Function to create management scripts
create_scripts() {
    print_step "Creating management scripts..."
    
    # Start script
    cat > $INSTALL_DIR/start-servers.sh << 'EOF'
#!/bin/bash
echo "Starting Madrigal Ascension servers..."
sudo systemctl start madrigal-database
sleep 5
sudo systemctl start madrigal-login  
sleep 3
sudo systemctl start madrigal-world
echo "✅ All servers started"
echo "Check status with: sudo systemctl status madrigal-*"
EOF

    # Stop script
    cat > $INSTALL_DIR/stop-servers.sh << 'EOF'
#!/bin/bash
echo "Stopping Madrigal Ascension servers..."
sudo systemctl stop madrigal-world
sudo systemctl stop madrigal-login
sudo systemctl stop madrigal-database
echo "✅ All servers stopped"
EOF

    # Status script
    cat > $INSTALL_DIR/server-status.sh << 'EOF'
#!/bin/bash
echo "=== Madrigal Ascension Server Status ==="
echo
echo "Database Server:"
sudo systemctl status madrigal-database --no-pager
echo
echo "Login Server:"
sudo systemctl status madrigal-login --no-pager
echo
echo "World Server:"
sudo systemctl status madrigal-world --no-pager
EOF

    # Restart script  
    cat > $INSTALL_DIR/restart-servers.sh << 'EOF'
#!/bin/bash
echo "Restarting Madrigal Ascension servers..."
./stop-servers.sh
sleep 3
./start-servers.sh
EOF

    # Make scripts executable
    chmod +x $INSTALL_DIR/*.sh
    chown $USER:$GROUP $INSTALL_DIR/*.sh
    
    print_success "Management scripts created"
}

# Function to setup firewall
setup_firewall() {
    print_step "Configuring firewall..."
    
    if command -v ufw >/dev/null 2>&1; then
        # Ubuntu/Debian firewall
        ufw allow 15400/tcp  # Login Server
        ufw allow 15500/tcp  # World Server
        ufw allow 22/tcp     # SSH
        print_info "UFW firewall rules added"
    elif command -v firewall-cmd >/dev/null 2>&1; then
        # CentOS/RHEL firewall
        firewall-cmd --permanent --add-port=15400/tcp
        firewall-cmd --permanent --add-port=15500/tcp
        firewall-cmd --reload
        print_info "Firewalld rules added"
    else
        print_warning "No firewall detected - please configure manually:"
        print_info "- Allow port 15400 (Login Server)"
        print_info "- Allow port 15500 (World Server)"
    fi
}

# Function to display completion message
display_completion() {
    print_header "🎉 MADRIGAL ASCENSION INSTALLATION COMPLETE! 🎉"
    
    echo -e "${GREEN}The Next Generation MMORPG server is now installed!${NC}"
    echo
    echo -e "${CYAN}Installation Details:${NC}"
    echo -e "📁 Installation Directory: ${YELLOW}$INSTALL_DIR${NC}"
    echo -e "📊 Data Directory: ${YELLOW}$DATA_DIR${NC}"
    echo -e "📜 Log Directory: ${YELLOW}$LOG_DIR${NC}"
    echo -e "👤 System User: ${YELLOW}$USER${NC}"
    echo
    echo -e "${CYAN}Server Management:${NC}"
    echo -e "🚀 Start servers: ${YELLOW}$INSTALL_DIR/start-servers.sh${NC}"
    echo -e "🛑 Stop servers: ${YELLOW}$INSTALL_DIR/stop-servers.sh${NC}"
    echo -e "📊 Check status: ${YELLOW}$INSTALL_DIR/server-status.sh${NC}"
    echo -e "🔄 Restart servers: ${YELLOW}$INSTALL_DIR/restart-servers.sh${NC}"
    echo
    echo -e "${CYAN}Configuration Files:${NC}"
    echo -e "⚙️ Server config: ${YELLOW}$INSTALL_DIR/server.conf${NC}"
    echo -e "🗄️ Database config: ${YELLOW}$INSTALL_DIR/database.conf${NC}"
    echo -e "🤖 AI config: ${YELLOW}$INSTALL_DIR/ai-config.json${NC}"
    echo
    echo -e "${CYAN}Network Ports:${NC}"
    echo -e "🌐 Login Server: ${YELLOW}15400${NC}"
    echo -e "🌍 World Server: ${YELLOW}15500${NC}"
    echo -e "🗄️ Database Server: ${YELLOW}15300 (internal)${NC}"
    echo
    echo -e "${CYAN}Next Steps:${NC}"
    echo -e "1. ${GREEN}Configure your server settings in $INSTALL_DIR/server.conf${NC}"
    echo -e "2. ${GREEN}Start the servers: $INSTALL_DIR/start-servers.sh${NC}"
    echo -e "3. ${GREEN}Check server status: $INSTALL_DIR/server-status.sh${NC}"
    echo -e "4. ${GREEN}Connect your client to: localhost:15400${NC}"
    echo
    echo -e "${PURPLE}🎮 Welcome to Madrigal Ascension - The Future of MMORPG Gaming! 🚀${NC}"
    echo
}

# Main installation function
main() {
    print_header "MADRIGAL ASCENSION - INSTALLATION WIZARD"
    print_info "The Next Generation MMORPG Server Setup"
    echo
    
    # Pre-flight checks
    check_root
    detect_os
    
    # Installation steps
    print_step "Starting installation process..."
    
    install_dependencies
    create_system_user
    setup_database
    build_madrigal
    create_services
    create_config
    create_scripts
    setup_firewall
    
    # Complete installation
    display_completion
    
    print_success "Installation completed successfully!"
    print_info "Run '$INSTALL_DIR/start-servers.sh' to start your Madrigal Ascension server"
}

# Run main installation
main "$@"