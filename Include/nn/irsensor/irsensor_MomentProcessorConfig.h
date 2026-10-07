#pragma once

#include <cstdint>

#include "irsensor/irsensor_Rect.h"

namespace nn::irsensor {
struct MomentProcessorConfig {
    int64_t exposureTime = 300000;
    int32_t lightTarget = 0;
    int32_t gain = 8;
    bool isNegativeImageUsed = false;
    uint8_t reserved[7];
    Rect windowOfInterest;
    int32_t preprocess = 1;
    int32_t preprocessIntensityThreshold = 80;
};
}  // namespace nn::irsensor
