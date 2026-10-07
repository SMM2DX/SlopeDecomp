/**
 * @brief Network inferface module.
 */

#pragma once

#include <cstdint>

#include "nn_Result.h"

namespace nn::nifm {

Result Initialize();
void SetLocalNetworkMode(bool);
void SubmitNetworkRequestAndWait();
void CancelNetworkRequest();
bool IsNetworkAvailable();
Result HandleNetworkRequestResult();
void SubmitNetworkRequest();
bool IsNetworkRequestOnHold();
Result GetCurrentPrimaryIpAddress(uint64_t* inAddr);

}  // namespace nn::nifm
