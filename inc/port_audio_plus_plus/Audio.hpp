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

namespace Pricetec {
    enum class AudioMode: uint8_t {
        INPUT = 0,
        OUTPUT,
        DUPLEX
    };

    class Audio {
        public:
            Audio(AudioDevice dev,
                  uint32_t bytesPerFrame,
                  uint32_t framesPerBuf = 100,
                  AudioMode mode = AudioMode::INPUT);
            ~Audio();
            bool ready();
            static std::vector<AudioDevice> availableDevices();
            static std::vector<AudioDevice> filterAvailableDevices(
                std::function<bool(AudioDevice)> where
            );

        private:
            bool isInitialized;
            AudioDevice device;
            AudioMode mode;
            boost::circular_buffer<uint8_t> inputBuffer;
            boost::circular_buffer<uint8_t> outputBuffer;

            static AudioDevice deviceFromPaInfo(const PaDeviceInfo *devInfo);
    };
} // namespace Pricetec

#endif