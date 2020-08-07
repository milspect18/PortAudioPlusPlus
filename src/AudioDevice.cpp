/**
 *
 */

#include "AudioDevice.hpp"

namespace Pricetec {
    /**
     *  AudioDevice struct methods
     */
    AudioDevice::AudioDevice(std::string name, int rate, int inChns, int outChns) :
        name(name),
        defaultRate(rate),
        inputChannels(inChns),
        outputChannels(outChns)
    {   }
}