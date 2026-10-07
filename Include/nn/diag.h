/**
 * @brief Module, logging, and symbol operations.
 */

#pragma once

#include <cstddef>
#include <cstdint>

#include "nn_Result.h"

namespace nn::diag {
struct LogMetaData;

struct ModuleInfo {
    char* mPath;
    uint64_t mBaseAddr;
    uint64_t mSize;
};

enum AssertionType {};

namespace detail {
// LOG
void LogImpl(nn::diag::LogMetaData const&, char const*, ...);
void AbortImpl(char const*, char const*, char const*, int32_t);
void AbortImpl(char const*, char const*, char const*, int, Result);

void OnAssertionFailure(nn::diag::AssertionType, char const*, char const*, char const*, int);
}  // namespace detail

// MODULE / SYMBOL
size_t GetSymbolName(char* name, size_t nameSize, uintptr_t addr);
uint64_t GetRequiredBufferSizeForGetAllModuleInfo();
int32_t GetAllModuleInfo(nn::diag::ModuleInfo** out, void* buffer, uint64_t bufferSize);
uint64_t GetSymbolSize(uint64_t addr);
}  // namespace nn::diag
