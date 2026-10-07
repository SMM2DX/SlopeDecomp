#pragma once

#include "sf/detail/sf_PointerAndSize.h"

namespace nn::sf {

class InBuffer {
public:
    constexpr InBuffer() {}
    constexpr InBuffer(const detail::PointerAndSize& buf) : buffer(buf) {}
    constexpr InBuffer(void* ptr, size_t sz) : buffer(ptr, sz) {}

    detail::PointerAndSize buffer;
};

}  // namespace nn::sf
