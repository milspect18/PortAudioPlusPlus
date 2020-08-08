/**
 *  PortAudio C++ wrapper library
 *
 *  The Audio class is a top-level IO device class
 */

#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <functional>
#include <boost/circular_buffer.hpp>
#include "portaudio.h"
#include "AudioDevice.hpp"
#include "AudioConfig.hpp"

namespace Pricetec {
    class Audio {
        public:
            Audio(AudioDevice dev, AudioConfig cfg);
            ~Audio();
            bool ready();
            static std::vector<AudioDevice> availableDevices();
            static std::vector<AudioDevice> filterAvailableDevices(
                std::function<bool(AudioDevice)> where
            );

        private:
            bool isInitialized;
            AudioDevice device;
            AudioConfig config;
            boost::circular_buffer<uint8_t> inputBuffer;
            boost::circular_buffer<uint8_t> outputBuffer;

            static AudioDevice deviceFromPaInfo(const PaDeviceInfo *devInfo);
    };
} // namespace Pricetec

#endif