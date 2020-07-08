/**
 *  Audio class methods
 */

#include "Audio.hpp"
#include <iostream>
#include <memory>
#include <algorithm>

namespace Pricetec {
    Audio::Audio() {
        this->isInitialized = Pa_Initialize() == paNoError;

        if (!this->isInitialized) {
            std::cout << "Failed to initialize!!!\n";
        }
    }

    Audio::~Audio() {
        if (this->isInitialized) {
            Pa_Terminate();
        }
    }

    bool Audio::ready() {
        return this->isInitialized;
    }

    std::vector<AudioDevice> Audio::availableDevices() {
        std::vector<AudioDevice> devsFound;

        if (Pa_Initialize() == paNoError) {
            int numDevs = Pa_GetDeviceCount();

            for(int i = 0; i < numDevs; i++) {
                devsFound.push_back(AudioDevice(Pa_GetDeviceInfo(i)));
            }

            Pa_Terminate();
        } else {
            std::cout << "Unable to init PortAudio!  Cannot search for devices!\n";
        }

        return devsFound;
    }

    std::vector<AudioDevice> Audio::filterAvailableDevices(std::function<bool(AudioDevice)> where) {
        std::vector<AudioDevice> filtered;
        auto allDevs = Audio::availableDevices();

        std::copy_if(allDevs.begin(), allDevs.end(), std::back_inserter(filtered), where);

        return filtered;
    }
}