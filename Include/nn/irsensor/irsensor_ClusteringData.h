#pragma once

#include <cstdint>

#include "irsensor/irsensor_MomentStatistic.h"
#include "irsensor/irsensor_Rect.h"

namespace nn::irsensor {
struct ClusteringData {
    MomentStatistic momentStatistic;
    int32_t pixelCount;
    Rect bounds;
};
}  // namespace nn::irsensor
