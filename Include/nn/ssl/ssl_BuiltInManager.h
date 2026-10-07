#pragma once

#include "nn_Result.h"
#include "ssl/ssl_Types.h"

namespace nn::ssl::BuiltInManager {
struct BuiltInCertificateInfo;  // TODO

Result GetBuiltInCertificates(BuiltInCertificateInfo**, uint8_t*, uint32_t, CaCertificateId*,
                              uint32_t);
Result GetBuiltInCertificateBufSize(uint32_t*, CaCertificateId*, uint32_t);
}  // namespace nn::ssl::BuiltInManager
