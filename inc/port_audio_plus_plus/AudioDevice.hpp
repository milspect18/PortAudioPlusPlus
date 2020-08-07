/**
 *  PortAudio C++ wrapper library
 *
 *  The AudioDevice struct hold device info
 */

#ifndef AUDIO_DEVICE_HPP
#define AUDIO_DEVICE_HPP

#include <string>
#include "portaudio.h"

namespace Pricetec {
    struct AudioDevice {
        std::string name;
        int defaultRate;
        int inputChannels;
        int outputChannels;

        AudioDevice(std::string name = "", int rate = -1, int inChns = -1, int outChns = -1);
    };
}

#endif