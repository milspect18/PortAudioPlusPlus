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
        S_INT_16,
        U_INT_16,
        FLOAT_32
    };

    struct AudioConfig {
        public:
            AudioConfig(uint16_t rate,
                        AudioFormat format,
                        uint8_t inChns,
                        uint8_t outChns,
                        AudioMode mode);

        private:
            uint16_t rate;
            uint8_t inChns;
            uint8_t outChns;
            AudioMode mode;
    };

}

#endif
