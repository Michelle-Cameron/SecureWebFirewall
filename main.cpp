#include "firewall.h"

int main() {
    Firewall firewall;

    // Define some blocking rules
    firewall.blockIP("192.168.1.1");
    firewall.blockPort(8080);

    // Simulate incoming network traffic
    std::vector<Packet> traffic = {
        {"192.168.1.1", "10.0.0.5", 80, 443, "TCP"},
        {"192.168.1.2", "10.0.0.5", 8080, 443, "TCP"},
        {"172.16.0.1", "10.0.0.5", 80, 443, "TCP"},
        {"10.0.0.10", "10.0.0.5", 80, 8080, "TCP"},
    };

    // Process traffic through the firewall
    firewall.simulateTraffic(traffic);

    return 0;
}
