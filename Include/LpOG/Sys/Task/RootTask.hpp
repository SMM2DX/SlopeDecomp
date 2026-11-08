#pragma once

#include <oead/framework/seadCalculateTask.h>
#include <oead/framework/seadTaskMgr.h>
#include "../Hio/IUseHioNode.hpp"

namespace Lp::Sys {
    struct RootTask : public sead::CalculateTask, public IUseHioNode {
        SEAD_TASK_SINGLETON(RootTask);

        static RootTask* spThis;
    };
}