#pragma once

#include <cstddef>

#include "nn_Result.h"

namespace nn::nlibsdk {

template <typename TPtr, typename T>
class LockFreePlaceHolderPool {
    Result Init(size_t);
};

}  // namespace nn::nlibsdk
