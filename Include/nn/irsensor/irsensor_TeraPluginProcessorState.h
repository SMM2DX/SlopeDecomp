#pragma once

#include <cstdint>

namespace nn::irsensor {
struct TeraPluginProcessorState {
    int64_t samplingNumber;
    int64_t timeStamp;
    int32_t ambientNoiseLevel;
    uint8_t pluginData[0x12c];
};
}  // namespace nn::irsensor
