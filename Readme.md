# SecureWebFirewall

Secure Web Firewall is a basic firewall simulation written in C++ that demonstrates rule-based traffic filtering. 

This project allows users to define rules to block network traffic based on IP addresses and port numbers. The firewall inspects each packet and either allows or blocks it according to the configured rules. 

Configuration is stored in a JSON file, making it easy to modify and add rules without changing the source code.

## Features

* IP Address Blocking: Block network packets originating from specific IP addresses.

* Port Blocking: Block network packets destined for specific ports.

* JSON Configuration: Load firewall rules from a JSON file (config.json) for easy configuration.


        SecureWebFirewall/
        │
        ├── json.hpp         // JSON library for Modern C++
        ├── config.json      // JSON configuration file with firewall rules
        ├── firewall.h       // Header file defining the Firewall class
        ├── firewall.cpp     // Implementation file for firewall functionality
        └── main.cpp         // Main driver file to run the firewall simulation

## Prerequisites

To set up this project, you’ll need:

* A C++ compiler such as g++ (included in GCC), Clang, or Visual Studio.

* VS Code or another IDE/text editor (optional).

* JSON for Modern C++ Library (json.hpp file), which can be downloaded from nlohmann/json GitHub repository.


## Getting Started

### Step 1: Download or Clone the Repository
First, clone this repository to your local machine or download it as a ZIP file and extract it.

        git clone https://github.com/yourusername/SecureWebFirewall.git
        cd SecureWebFirewall

### Step 2: Add JSON Library
Download the json.hpp file from the JSON for Modern C++ GitHub repository and place it in the root folder of this project (SecureWebFirewall folder).

### Step 3: Set Up config.json Configuration File
The firewall rules are stored in a JSON file (config.json). Open this file and add the IP addresses and ports you want to block.

Example configuration:

        json
        {
            "blocked_ips": [
                "192.168.1.1",
                "10.0.0.2"
            ],
            "blocked_ports": [
                8080,
                443
            ]
        }

blocked_ips lists the IP addresses that the firewall will block.

blocked_ports lists the destination ports that the firewall will block.

### Step 4: Compile the Code
Use g++ or any other C++ compiler to compile the code.

For example, if you're in the project directory, run:

        bash

        g++ main.cpp firewall.cpp -o SecureWebFirewall

This command compiles main.cpp and firewall.cpp into an executable file named SecureWebFirewall.

### Step 5: Run the Program

After compiling, run the program:

        bash

        ./SecureWebFirewall   # On Linux or macOS
        SecureWebFirewall.exe # On Windows

### How the Code Works

1. Loading Configuration: The program loads firewall rules from config.json using the JSON for Modern C++ library.

2. Defining Traffic: The program simulates a list of incoming network packets, each represented by a source IP, destination IP, source port, destination port, and protocol.

3. Traffic Inspection: Each packet is checked against the firewall rules. If the packet’s source IP or destination port matches any rule, it is blocked; otherwise, it is allowed.

4. Output: The program outputs whether each packet is allowed or blocked based on the rules.

### Example Output
Given the following simulated traffic:

        std::vector<Packet> traffic = {
            {"192.168.1.1", "10.0.0.5", 80, 443, "TCP"},
            {"10.0.0.3", "10.0.0.5", 8080, 443, "TCP"},
            {"172.16.0.1", "10.0.0.5", 80, 443, "TCP"},
            {"10.0.0.10", "10.0.0.5", 80, 22, "TCP"},
        };

### And a config.json file with:

json

        {
            "blocked_ips": [
                "192.168.1.1",
                "10.0.0.2"
            ],
            "blocked_ports": [
                8080,
                443
            ]
        }

### The output will be:


        Configuration loaded successfully from config.json
        Blocked packet from IP: 192.168.1.1
        Blocked packet to port: 8080
        Allowed packet from IP: 172.16.0.1 to IP: 10.0.0.5
        Allowed packet from IP: 10.0.0.10 to IP: 10.0.0.5

## Code Explanation

### firewall.h
Defines the Firewall class and a Packet struct:

* Firewall class: Contains methods for adding rules, loading configurations, and inspecting packets.

* Packet struct: Represents network packets with fields like source IP, destination IP, source port, destination port, and protocol.

### firewall.cpp

Implements the Firewall methods:

* blockIP and blockPort: Add blocked IPs and ports to internal lists.

* loadConfig: Loads the configuration file (config.json) to add blocked IPs and ports.

* isPacketAllowed: Inspects each packet against blocked IPs and ports.

* simulateTraffic: Runs traffic through the firewall.

### main.cpp

main function: Initializes the firewall, loads configuration, defines simulated traffic, and processes it.

## Customizing the Firewall

To customize the firewall rules, simply modify config.json:

* Add or remove IPs under blocked_ips.

* Add or remove ports under blocked_ports.

No code changes are necessary for the firewall to recognize new rules.

## Possible Extensions

* Log blocked packets to a file.

* Add real-time rule updates to change firewall settings dynamically.

* Filter by protocol (e.g., only block TCP or UDP traffic).

* Command-line arguments to specify different configuration files.

## Contributing

Feel free to contribute by submitting issues or pull requests to improve the firewall’s functionality.

## License
This project is licensed under the MIT License.