/**
 * @brief Dynamic module (Runtime object) API.
 */

#pragma once

#include "nn_Result.h"
#include "ro/ro_Types.h"

namespace nn::ro {

Result Initialize();
Result InitializeWithPortName(const char* portname);  // "ldr:ro" or "ro:1"
Result Finalize();

Result GetBufferSize(uint64_t* size, const void* nro);  // Gets Bss size from nro+0x38

Result RegisterModuleInfo(nn::ro::RegistrationInfo* regInfo, const void* nrr);
Result RegisterModuleInfo(nn::ro::RegistrationInfo* regInfo, const void* nrr, uint32_t);
Result UnregisterModuleInfo(nn::ro::RegistrationInfo* regInfo);

Result LoadModule(Module* outModule, const void* nro, void* nroBss, uint64_t nroBssSize,
                  int32_t flags);
Result LoadModule(Module* outModule, const void* nro, void* nroBss, uint64_t nroBssSize,
                  int32_t flags, bool);
Result UnloadModule(Module* module);

Result LookupSymbol(uint64_t* funcAddress, const char* symbolName);
Result LookupModuleSymbol(uint64_t* funcAddress, const Module* module, const char* symbolName);

}  // namespace nn::ro
