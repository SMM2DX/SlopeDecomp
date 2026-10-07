#pragma once

#include "account.h"
#include "fs/fs_Types.h"
#include "nn_ApplicationId.h"

namespace nn::fs {

Result EnsureSaveData(const nn::account::Uid&);
Result MountSaveData(const char*, UserId);
Result MountSaveData(const char*, const nn::account::Uid&);
Result MountSaveData(const char*, ApplicationId, const nn::account::Uid&);
Result MountSaveDataForDebug(const char*);
Result CommitSaveData(const char* path);

}  // namespace nn::fs
