#pragma once

#include "nn_Result.h"

namespace nn::bcat {

class DeliveryCacheProgress {
public:
    DeliveryCacheProgress();
    ~DeliveryCacheProgress();
    Result Detach();
    Result Update();
    Result GetStatus();
    Result GetCurrentDirectoryName();
    Result GetCurrentFileName();
    Result GetCurrentDownloaded();
    Result GetCurrentTotale();
    Result GetWholeDownloaded();
    Result GetWholeTotal();
    Result GetResult();
    // void Attach(nn::bcat::detail::ipc::IDeliveryCacheProgressService*);
};

}  // namespace nn::bcat
