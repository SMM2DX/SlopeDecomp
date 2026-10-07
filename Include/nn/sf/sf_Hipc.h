#pragma once

#include "nn_Result.h"
#include "svc.h"

namespace nn::sf::hipc {

void* GetMessageBufferOnTls();

Result InitializeHipcServiceResolution();
Result ConnectToHipcService(svc::Handle*, const char*);
Result FinalizeHipcServiceResolution();

Result SendSyncRequest(svc::Handle, void*, uint64_t);
Result CloseClientSessionHandle(svc::Handle);

}  // namespace nn::sf::hipc
