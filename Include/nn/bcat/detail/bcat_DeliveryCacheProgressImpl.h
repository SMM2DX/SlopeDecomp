#pragma once

#include <cstdint>
#include "bcat/bcat_Util.h"
#include "nn_Result.h"

namespace nn::bcat::detail::DeliveryCacheProgressImpl {

Result Clear();
Result NotifyStartConnect();
Result NotifyStartProcessList();
Result SetWholeDownloadSize(int64_t);
Result SetDownloadProgress(int64_t, DirectoryName const&, FileName const&, int64_t);
Result NotifyStartDownloadFile(DirectoryName const&, FileName const&, int64_t);
Result UpdateDownloadFileProgress(int64_t);
Result NotifyStartCommitDirectory(DirectoryName const&);
Result NotifyDone(Result);

}  // namespace nn::bcat::detail::DeliveryCacheProgressImpl
