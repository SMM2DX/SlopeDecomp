#pragma once

#include "os_InternalCriticalSection.h"
#include "../os_ConditionVariableCommon.h"

namespace nn::os::detail {

class TimeoutHelper;

class InternalConditionVariableImplByHorizon {
public:
    InternalConditionVariableImplByHorizon();
    void Initialize();
    void Signal();
    void Broadcast();
    void Wait(InternalCriticalSection*);
    ConditionVariableStatus TimedWait(InternalCriticalSection*, const TimeoutHelper&);

private:
    uint32_t m_Value;
};

typedef InternalConditionVariableImplByHorizon InternalConditionVariableImpl;

}  // namespace nn::os::detail
