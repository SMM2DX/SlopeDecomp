#pragma once

#include "../../../seadOG/prim/seadDelegate.h"

#include "Job.hpp"

namespace Lp::UI {
    struct PageBase;

    struct DelegateJob : public Job {
        /* TODO: ? */
        sead::Delegate<PageBase> mDelegate;
    };
    static_assert(sizeof(DelegateJob) == 0x98);
}