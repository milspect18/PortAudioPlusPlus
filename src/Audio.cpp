/**
 *  Audio class methods
 */

#include "Audio.hpp"
#include <iostream>
#include <memory>
#include <algorithm>

namespace Pricetec {
    Audio::Audio(AudioDevice dev, uint32_t bytesPerFrame, uint32_t framesPerBuf, AudioMode mode) :
        device(dev),
        inputBuffer(bytesPerFrame * framesPerBuf),
        mode(mode) {
        this->isInitialized = Pa_Initialize() == paNoError;

        if (this->isInitialized) {
           // Finish init stuff here
        } else {
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
                const PaDeviceInfo *paInfo = Pa_GetDeviceInfo(i);
                auto device = AudioDevice(
                    paInfo->name,
                    paInfo->defaultSampleRate,
                    paInfo->maxInputChannels,
                    paInfo->maxOutputChannels
                );

                devsFound.push_back(device);
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