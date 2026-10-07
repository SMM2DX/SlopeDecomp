#pragma once

#include <cstdint>

namespace nn::irsensor {
struct TeraPluginProcessorConfig {
    int8_t mode;
    int8_t _1;  // [6.0.0+]
    int8_t _2;  // [6.0.0+]
    int8_t _3;  // [6.0.0+]
};
}  // namespace nn::irsensor
