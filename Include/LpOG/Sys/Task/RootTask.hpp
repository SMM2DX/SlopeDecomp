#pragma once

#include <seadOG/framework/seadCalculateTask.h>
#include <seadOG/framework/seadTaskMgr.h>
#include "../Hio/IUseHioNode.hpp"

namespace Lp::Sys {
    struct RootTask : public sead::CalculateTask, public IUseHioNode {
        SEAD_TASK_SINGLETON(RootTask);

        static RootTask* spThis;
    };
}