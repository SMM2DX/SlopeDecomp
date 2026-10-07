#pragma once

#include "bcat/bcat_Util.h"
#include "nn_Result.h"

namespace nn::bcat::detail {

class ShimLibraryGlobal {
public:
    ShimLibraryGlobal();
    ~ShimLibraryGlobal();
    Result Initialize();
    Result GetSession();
    Result MountDeliveryCacheStorage();
    Result IsDeliveryCacheStorageMounted();
    Result UnmountDeliveryCacheStorage();
    // void CreateFileService(nn::bcat::detail::ipc::IDeliveryCacheFileService**);
    // void CreateDirectoryService(nn::bcat::detail::ipc::IDeliveryCacheDirectoryService**)
    Result IncrementDeliveryCacheFileCount();
    Result DecrementDeliveryCacheFileCount();
    Result IncrementDeliveryCacheDirectoryCount();
    Result EnumerateDeliveryCacheDirectory(int*, DirectoryName*, int);
};
}  // namespace nn::bcat::detail
