/**
 *  PortAudio C++ wrapper library
 *
 *  The Audio class is a top-level IO device class
 */

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <string>
#include <vector>
#include <functional>
#include "portaudio.h"
#include "AudioDevice.hpp"

namespace Pricetec {
    class Audio {
        public:
            Audio();
            ~Audio();
            bool ready();
            static std::vector<AudioDevice> availableDevices();
            static std::vector<AudioDevice> filterAvailableDevices(
                std::function<bool(AudioDevice)> where
            );

        private:
            bool isInitialized;
    };
} // namespace Pricetec

#endif