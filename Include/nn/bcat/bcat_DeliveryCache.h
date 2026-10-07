#pragma once

#include "bcat/bcat_DeliveryCacheProgress.h"
#include "bcat/bcat_Util.h"
#include "nn_Result.h"

namespace nn::bcat {

Result MountDeliveryCacheStorage();
Result UnmountDeliveryCacheStorage();
Result EnumerateDeliveryCacheDirectory(int*, DirectoryName*, int);
Result RequestSyncDeliveryCache(DeliveryCacheProgress*);

}  // namespace nn::bcat
