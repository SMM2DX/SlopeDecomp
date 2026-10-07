#pragma once

#include <cstdint>

namespace nn::irsensor {
enum class ImageTransferProcessorFormat : uint32_t {
    _320x240,
    _160x120,
    _80x60,
    _40x30,  // [4.0.0+]
    _20x15,  // [4.0.0+]
};
}  // namespace nn::irsensor
