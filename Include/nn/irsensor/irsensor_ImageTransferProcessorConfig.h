#pragma once

#include <cstdint>

#include "irsensor/irsensor_ImageTransferProcessorFormat.h"

namespace nn::irsensor {
struct __attribute__((packed)) ImageTransferProcessorConfig {
    int64_t exposureTime = 300000;
    int32_t lightTarget = 0;
    int32_t gain = 8;
    bool isNegativeImageUsed = false;
    uint8_t reserved[7];
    ImageTransferProcessorFormat format = ImageTransferProcessorFormat::_320x240;
};
}  // namespace nn::irsensor
