#pragma once

#include "sf/detail/sf_PointerAndSize.h"

namespace nn::sf {

class OutBuffer {
public:
    constexpr OutBuffer() {}
    constexpr OutBuffer(const detail::PointerAndSize& buf) : buffer(buf) {}
    constexpr OutBuffer(void* ptr, size_t sz) : buffer(ptr, sz) {}

    detail::PointerAndSize buffer;
};

}  // namespace nn::sf
