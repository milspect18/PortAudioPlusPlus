/**
 *
 */

#include "AudioDevice.hpp"

namespace Pricetec {
    /**
     *  AudioDevice struct methods
     */
    AudioDevice::AudioDevice(const PaDeviceInfo *info) :
        name(info->name),
        defaultRate(info->defaultSampleRate),
        inputChannels(info->maxInputChannels),
        outputChannels(info->maxOutputChannels)
    {   }

    AudioDevice::AudioDevice(std::string name, int rate, int inChns, int outChns) :
        name(name),
        defaultRate(rate),
        inputChannels(inChns),
        outputChannels(outChns)
    {   }
}