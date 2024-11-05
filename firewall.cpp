#include "firewall.h"
#include <fstream>

// Method to add a blocked IP
void Firewall::blockIP(const std::string& ip) {
    blockedIPs.push_back(ip);
}

// Method to add a blocked port
void Firewall::blockPort(int port) {
    blockedPorts.push_back(port);
}

// Method to load firewall rules from a JSON configuration file
void Firewall::loadConfig(const std::string& filename) {
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        std::cerr << "Failed to open config file: " << filename << "\n";
        return;
    }

    json config;
    configFile >> config;

    // Load blocked IPs
    if (config.contains("blocked_ips")) {
        for (const auto& ip : config["blocked_ips"]) {
            blockedIPs.push_back(ip);
        }
    }

    // Load blocked ports
    if (config.contains("blocked_ports")) {
        for (const auto& port : config["blocked_ports"]) {
            blockedPorts.push_back(port);
        }
    }

    std::cout << "Configuration loaded successfully from " << filename << "\n";
}

// Method to check if a packet is allowed
bool Firewall::isPacketAllowed(const Packet& packet) {
    for (const auto& blockedIP : blockedIPs) {
        if (packet.sourceIP == blockedIP) {
            std::cout << "Blocked packet from IP: " << packet.sourceIP << "\n";
            return false;
        }
    }

    for (const auto& blockedPort : blockedPorts) {
        if (packet.destinationPort == blockedPort) {
            std::cout << "Blocked packet to port: " << packet.destinationPort << "\n";
            return false;
        }
    }

    std::cout << "Allowed packet from IP: " << packet.sourceIP << " to IP: " << packet.destinationIP << "\n";
    return true;
}

void Firewall::simulateTraffic(const std::vector<Packet>& traffic) {
    for (const auto& packet : traffic) {
        isPacketAllowed(packet);
    }
}
