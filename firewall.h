#ifndef FIREWALL_H
#define FIREWALL_H

#include <iostream>
#include <vector>
#include <string>

struct Packet {
    std::string sourceIP;
    std::string destinationIP;
    int sourcePort;
    int destinationPort;
    std::string protocol;
};

class Firewall {
private:
    std::vector<std::string> blockedIPs;
    std::vector<int> blockedPorts;

public:
    // Add methods to add rules for blocking IPs or ports
    void blockIP(const std::string& ip);
    void blockPort(int port);

    // Method to inspect a packet and determine if it's allowed
    bool isPacketAllowed(const Packet& packet);

    // Method to simulate network packet
    void simulateTraffic(const std::vector<Packet>& traffic);
};

#endif
