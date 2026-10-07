#pragma once

#include <cstddef>

namespace nn::sf::detail {

class PointerAndSize {
public:
    constexpr PointerAndSize() : pointer(nullptr), size(0) {}
    constexpr PointerAndSize(void* ptr, size_t sz) : pointer(ptr), size(sz) {}

    void* pointer;
    size_t size;
};

}  // namespace nn::sf::detail
