#pragma once

#include <cstdint>

namespace nn::irsensor {

struct Rect {
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t width = 320;
    uint16_t height = 240;
};

Rect MakeRect(int32_t x, int32_t y, int32_t width, int32_t height);

}  // namespace nn::irsensor
