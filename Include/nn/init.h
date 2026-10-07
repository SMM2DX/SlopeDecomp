#pragma once

#include "mem.h"

namespace nn::init {
void InitializeAllocator(void* addr, uint64_t size);
nn::mem::StandardAllocator* GetAllocator();

namespace detail {
void* DefaultAllocatorForThreadLocal(uint64_t, uint64_t);
void* DefaultDeallocatorForThreadLocal(void*, uint64_t);
}  // namespace detail
}  // namespace nn::init
