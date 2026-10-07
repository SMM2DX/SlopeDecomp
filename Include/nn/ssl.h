/**
 * @brief SSL implementation.
 */
#pragma once

#include "nn_Result.h"
#include "ssl/ssl_Connection.h"
#include "ssl/ssl_Context.h"
// @nncbindgen skip-start
#include "ssl/ssl_BuiltInManager.h"
#include "ssl/ssl_Debug.h"
#include "ssl/ssl_ISslConnection.h"
#include "ssl/ssl_ISslContext.h"
#include "ssl/ssl_ISslService.h"
#include "ssl/ssl_Types.h"
// @nncbindgen skip-end

namespace nn::ssl {

// @nncbindgen
nn::Result Initialize();
// @nncbindgen(rename=InitializeWithConcurrencyLimit)
nn::Result Initialize(uint32_t concurrencyLimit);
// @nncbindgen
nn::Result Finalize();
nn::Result GetSslResultFromValue(nn::Result*, const char*, uint32_t);

}  // namespace nn::ssl
