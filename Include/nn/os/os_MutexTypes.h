#pragma once

#include <cstdint>

// @nncbindgen skip
#include "detail/os_InternalCriticalSection.h"

namespace nn::os {

struct ThreadType;

// @nncbindgen
struct MutexType {
    uint8_t _state;
    bool _isRecursive;
    int _lockLevel;
    int _nestCount;
    ThreadType* _ownerThread;
    union {
        int32_t _mutexImage[1];
        detail::InternalCriticalSectionStorage _mutex;
    };
};

}  // namespace nn::os
