#!/bin/bash
# Madrigal Ascension - Stop Servers Script
# Safely stops all Madrigal Ascension server components
# 
# Version: 1.0.0

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'

# Configuration
INSTALL_DIR="/opt/madrigal-ascension"
if [ ! -d "$INSTALL_DIR" ]; then
    INSTALL_DIR="."
fi

LOG_DIR="$INSTALL_DIR/logs"
PID_DIR="$INSTALL_DIR/pids"

print_header() {
    echo -e "${CYAN}╔════════════════════════════════════════╗${NC}"
    echo -e "${CYAN}║        MADRIGAL ASCENSION SERVER       ║${NC}"
    echo -e "${CYAN}║          SHUTDOWN SEQUENCE             ║${NC}"
    echo -e "${CYAN}║   Safely stopping all components      ║${NC}"
    echo -e "${CYAN}╚════════════════════════════════════════╝${NC}"
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
    echo -e "${PURPLE}🛑 $1${NC}"
}

# Function to stop a server component
stop_server_component() {
    local server_name=$1
    local pid_file="$PID_DIR/$server_name.pid"
    
    print_step "Stopping $server_name..."
    
    if [ -f "$pid_file" ]; then
        local pid=$(cat "$pid_file")
        
        if kill -0 "$pid" 2>/dev/null; then
            # Send SIGTERM first (graceful shutdown)
            kill "$pid" 2>/dev/null
            
            # Wait up to 10 seconds for graceful shutdown
            local count=0
            while [ $count -lt 10 ] && kill -0 "$pid" 2>/dev/null; do
                sleep 1
                count=$((count + 1))
                echo -n "."
            done
            echo
            
            # If still running, force kill
            if kill -0 "$pid" 2>/dev/null; then
                print_warning "$server_name didn't stop gracefully, forcing shutdown..."
                kill -9 "$pid" 2>/dev/null
                sleep 1
            fi
            
            # Verify it's stopped
            if ! kill -0 "$pid" 2>/dev/null; then
                print_success "$server_name stopped successfully"
                rm -f "$pid_file"
            else
                print_error "Failed to stop $server_name (PID: $pid)"
                return 1
            fi
        else
            print_warning "$server_name was not running (cleaning up PID file)"
            rm -f "$pid_file"
        fi
    else
        print_info "$server_name was not running"
    fi
    
    # Also try to kill by process name (backup method)
    pkill -f "$server_name" 2>/dev/null
    
    return 0
}

# Function to stop all servers in reverse order
stop_all_servers() {
    print_info "Madrigal Ascension Server Shutdown"
    print_info "Stopping servers in safe order..."
    echo
    
    # Stop in reverse order of startup (World -> Login -> Database)
    stop_server_component "world"
    echo
    
    stop_server_component "login"
    echo
    
    stop_server_component "database"
    echo
    
    # Additional cleanup - kill any remaining processes
    print_step "Performing final cleanup..."
    
    # Kill any remaining Madrigal processes
    pkill -f "Madrigal" 2>/dev/null
    pkill -f "madrigal" 2>/dev/null
    
    # Clean up simulation processes
    if [ -d "$PID_DIR" ]; then
        for sim_script in "$PID_DIR"/*-sim.sh; do
            if [ -f "$sim_script" ]; then
                pkill -f "$(basename "$sim_script")" 2>/dev/null
                rm -f "$sim_script"
            fi
        done
    fi
    
    # Clean up any stale PID files
    rm -f "$PID_DIR"/*.pid 2>/dev/null
    
    print_success "Final cleanup completed"
}

# Function to verify shutdown
verify_shutdown() {
    echo
    print_step "Verifying complete shutdown..."
    
    local running_processes=0
    
    # Check for any remaining Madrigal processes
    if pgrep -f "Madrigal" >/dev/null 2>&1; then
        print_warning "Some Madrigal processes may still be running:"
        pgrep -f "Madrigal" | while read pid; do
            echo -e "   ${YELLOW}PID $pid:${NC} $(ps -p $pid -o comm= 2>/dev/null || echo 'Unknown')"
        done
        running_processes=1
    fi
    
    # Check ports
    if command -v netstat >/dev/null 2>&1; then
        local ports_in_use=""
        
        if netstat -ln 2>/dev/null | grep ":15300" >/dev/null; then
            ports_in_use="$ports_in_use 15300"
        fi
        if netstat -ln 2>/dev/null | grep ":15400" >/dev/null; then
            ports_in_use="$ports_in_use 15400"
        fi
        if netstat -ln 2>/dev/null | grep ":15500" >/dev/null; then
            ports_in_use="$ports_in_use 15500"
        fi
        
        if [ -n "$ports_in_use" ]; then
            print_warning "Some Madrigal ports still in use:$ports_in_use"
            running_processes=1
        fi
    fi
    
    if [ $running_processes -eq 0 ]; then
        print_success "All Madrigal Ascension servers stopped successfully"
        print_success "System is clean and ready for restart"
    else
        print_warning "Some components may still be running"
        print_info "Use 'ps aux | grep -i madrigal' to check manually"
    fi
}

# Main function
main() {
    print_header
    
    # Perform shutdown sequence
    stop_all_servers
    
    # Verify shutdown
    verify_shutdown
    
    # Final message
    echo
    print_header
    echo -e "${GREEN}🛑 MADRIGAL ASCENSION SERVERS STOPPED SUCCESSFULLY 🛑${NC}"
    echo
    echo -e "${CYAN}All server components have been safely shut down.${NC}"
    echo
    echo -e "${YELLOW}📊 Shutdown Summary:${NC}"
    echo -e "   Database Server: ${GREEN}STOPPED${NC}"
    echo -e "   Login Server: ${GREEN}STOPPED${NC}"
    echo -e "   World Server: ${GREEN}STOPPED${NC}"
    echo
    echo -e "${CYAN}To restart servers:${NC} ${YELLOW}./start-servers.sh${NC}"
    echo -e "${CYAN}To check status:${NC} ${YELLOW}./server-status.sh${NC}"
    echo -e "${CYAN}Server management:${NC} ${YELLOW}./manage-madrigal-server.sh${NC}"
    echo
    echo -e "${PURPLE}Thank you for using Madrigal Ascension! 🚀${NC}"
    echo
}

# Handle command line arguments
case "${1:-}" in
    --help|-h)
        echo "Madrigal Ascension - Stop Servers Script"
        echo
        echo "Usage: $0 [options]"
        echo
        echo "Options:"
        echo "  --help, -h      Show this help message"
        echo "  --force, -f     Force kill all processes"
        echo "  --verify, -v    Verify shutdown completion"
        echo "  --quiet, -q     Quiet mode (minimal output)"
        echo
        exit 0
        ;;
    --force|-f)
        echo "Force stopping all Madrigal processes..."
        pkill -9 -f "Madrigal" 2>/dev/null
        pkill -9 -f "madrigal" 2>/dev/null
        rm -f "$PID_DIR"/*.pid 2>/dev/null
        echo "✅ Force shutdown completed"
        ;;
    --verify|-v)
        main
        verify_shutdown
        ;;
    --quiet|-q)
        # Quiet mode - minimal output
        stop_all_servers >/dev/null 2>&1
        echo "Madrigal Ascension servers stopped"
        ;;
    *)
        # Default shutdown
        main
        ;;
esac