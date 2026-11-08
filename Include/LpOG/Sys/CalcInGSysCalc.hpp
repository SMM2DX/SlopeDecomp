#pragma once

#include <sead/seadDisposer.hpp>
#include <sead/seadSafeString.hpp>
#include <oead/mc/seadJobQueue.h>
#include <oead/mc/seadJob.h>

#include <gsys/ISystemTaskCallback.hpp>

namespace Lp::Sys {
    struct CalcInGSysCalc : sead::IDisposer {
        struct CalcInGSysCalc_DefaultJob : public sead::Job {
            CalcInGSysCalc* mParent;

            virtual void invoke();
        };
        static_assert(sizeof(CalcInGSysCalc_DefaultJob) == 0x20);

        sead::FixedSafeString<32> field_20;
        uintptr_t field_58;
        uintptr_t field_60;
        gsys::ISystemTaskCallback::Timing field_68;
        gsys::ISystemTaskCallback::Timing field_6C;
        sead::FixedSizeJQ field_70;
        CalcInGSysCalc_DefaultJob mDefaultJob;
    };
    static_assert(sizeof(CalcInGSysCalc) == 0x158);
}