#include "firewall.h"

void Firewall::blockIP(const std::string& ip) {
    blockedIPs.push_back(ip);
}

void Firewall::blockPort(int port) {
    blockedPorts.push_back(port);
}

bool Firewall::isPacketAllowed(const Packet& packet) {
    // Check if the packet's source IP is blocked
    for (const auto& blockedIP : blockedIPs) {
        if (packet.sourceIP == blockedIP) {
            std::cout << "Blocked packet from IP: " << packet.sourceIP << "\n";
            return false;
        }
    }

    // Check if the packet's destination port is blocked
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
