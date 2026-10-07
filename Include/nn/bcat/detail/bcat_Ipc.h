#pragma once

#include "nn_ApplicationId.h"
#include "nn_Result.h"

namespace nn::bcat::detail::ipc {

class IBcatService;
class IDeliveryCacheStorageService;

Result Initialize();
void CreateBcatService(IBcatService**);
Result Finalize();
void CreateDeliveryCacheStorageService(IDeliveryCacheStorageService**);
void CreateDeliveryCacheStorageService(IDeliveryCacheStorageService**, ApplicationId);

}  // namespace nn::bcat::detail::ipc
