/**
 *  PortAudio C++ wrapper library
 *
 *  The AudioConfig struct is a simple structure for holding device config
 */

#ifndef AUDIO_CONFIG_HPP
#define AUDIO_CONFIG_HPP

#include <cstdint>

namespace Pricetec {
    enum class AudioMode: uint8_t {
        INPUT = 0,
        OUTPUT,
        DUPLEX
    };

    enum class AudioFormat: uint8_t {
        S_INT_16 = 2,
        U_INT_16 = 2,
        FLOAT_32 = 4
    };

    enum class AudioRate: uint32_t {
        SR_8khz = 8000,
        SR_16khz = 16000,
        SR_44_1khz = 44100,
        SR_48khz = 48000,
        SR_96khz = 96000
    };

    struct AudioConfig {
        public:
            AudioConfig(AudioRate rate = AudioRate::SR_48khz,
                        AudioFormat format = AudioFormat::S_INT_16,
                        uint8_t inChns = 0,
                        uint8_t outChns = 0,
                        AudioMode mode = AudioMode::DUPLEX,
                        uint32_t periodDurationMs = 20);

            uint8_t sampleDepth();
            uint16_t samplesPerPeriod();
            uint32_t bytesPerPeriod();

            AudioRate rate;
            uint8_t inChns;
            uint8_t outChns;
            AudioMode mode;
            AudioFormat format;
            uint32_t periodDurationMs;
    };

}

#endif
