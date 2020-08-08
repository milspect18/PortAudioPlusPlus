/**
 *
 */

#include "AudioConfig.hpp"

namespace Pricetec {

    AudioConfig::AudioConfig(AudioRate rate,
                             AudioFormat format,
                             uint8_t inChns,
                             uint8_t outChns,
                             AudioMode mode,
                             uint32_t periodDurationMs) :
        rate(rate),
        format(format),
        inChns(inChns),
        outChns(outChns),
        mode(mode),
        periodDurationMs(periodDurationMs)
    {   }

    uint8_t AudioConfig::sampleDepth() {
        return static_cast<uint8_t>(this->format);
    }

    uint16_t AudioConfig::samplesPerPeriod() {
        double singleSampleLenInSecs = (1.0 / static_cast<double>(this->rate));
        double periodLenInSecs = (1.0 / static_cast<double>(this->periodDurationMs));

        return static_cast<uint16_t>(periodLenInSecs / singleSampleLenInSecs);
    }

    uint32_t AudioConfig::bytesPerPeriod() {
        return this->sampleDepth() * this->samplesPerPeriod();
    }

}