#pragma once

#include <cstdint>

#include "irsensor/irsensor_Rect.h"

namespace nn::irsensor {
struct ClusteringProcessorConfig {
    int64_t exposureTime = 200000;
    int32_t lightTarget = 0;
    int32_t gain = 2;
    bool isNegativeImageUsed = false;
    uint8_t reserved[7];
    Rect windowOfInterest;
    int32_t objectPixelCountMin = 3;
    int32_t objectPixelCountMax = 76800;  // windowOfInterest.width * windowOfInterest.height;
    int32_t objectIntensityMin = 150;
    bool isExternalLightFilterEnabled = true;
};
}  // namespace nn::irsensor
