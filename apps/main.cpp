/**
 *  Sandbox for testing PortAudio lib dev with C++
 */
#include "PortAudioPlusPlus.hpp"
#include <iostream>
#include <algorithm>

// Local function prototypes
void printDeviceInfo(std::vector<Pricetec::AudioDevice> devices);


/**
 *  MAIN
 */
int main(int argc, const char *argv[]) {
    // Use the lambda as a filtering predicate to only get devices
    // with '(hw:' included in the name.
    auto hwDevs = Pricetec::Audio::filterAvailableDevices(
        [](Pricetec::AudioDevice dev) { return dev.name.find("(hw:") != std::string::npos; }
    );

    printDeviceInfo(hwDevs);

    return 0;
}


/**
 *  Pretty print device info about all device provided
 */
void printDeviceInfo(std::vector<Pricetec::AudioDevice> devices) {
    for (auto device : devices) {
        std::cout << device.name << ":\n";
        std::cout << "\tINPUTS: " << device.inputChannels << "\n";
        std::cout << "\tOUTPUTS: " << device.outputChannels << "\n";
        std::cout << "\tDEFAULT RATE: " << device.defaultRate << "\n";
    }
}
