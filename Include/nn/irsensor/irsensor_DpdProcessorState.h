#pragma once

#include <cstdint>

namespace nn::irsensor {
struct DpdProcessorState {
    int64_t samplingNumber;
    int64_t timeStamp;
    int32_t pointingStatus;
    float positionX;
    float positionY;
};
}  // namespace nn::irsensor
