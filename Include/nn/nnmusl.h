#pragma once

#ifdef __cplusplus
#include "nn_Result.h"
using nn::Result;
extern "C" {
#else
#include <stdint.h>
typedef Result uint64_t;
#endif

// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnmusl_init_dso_0();
// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnmusl_init_dso();
// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnmusl_fini_dso_0();
// NOLINTNEXTLINE(bugprone-reserved-identifier)
void __nnmusl_fini_dso();

int _nnmusl_errno_from_result(Result);
// NOLINTNEXTLINE(bugprone-reserved-identifier)
int __nnmusl_BroadcastConditionVariable(void*);

#ifdef __cplusplus
}
#endif
