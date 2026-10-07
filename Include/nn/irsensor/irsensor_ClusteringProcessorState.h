#pragma once

#include "irsensor/irsensor_ClusteringData.h"

namespace nn::irsensor {
struct ClusteringProcessorState {
    int64_t samplingNumber;
    int64_t timeStamp;
    uint8_t objectCount;
    int32_t ambientNoiseLevel;
    ClusteringData data[16];
};
}  // namespace nn::irsensor
