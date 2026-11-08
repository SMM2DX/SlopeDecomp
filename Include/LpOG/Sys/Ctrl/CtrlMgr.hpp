#pragma once

#include "../Task/ProjTaskBase.hpp"
#include "Ctrl.hpp"
#include "CtrlType.hpp"

#include <oead/thread/seadCriticalSection.h>
#include <oead/thread/seadReadWriteLock.h>
#include <oead/container/seadPtrArray.h>
#include <oead/controller/seadController.h>
#include <oead/controller/seadControllerMgr.h>

namespace Lp::Sys {

    struct CtrlMgr : public ProjTaskBase {
        SEAD_RTTI_OVERRIDE(CtrlMgr, ProjTaskBase)
        
        public:
        uintptr_t thunk;
        /* TODO: prob a macro for this */
        uintptr_t field_230;
        sead::CriticalSection mCS;
        sead::ReadWriteLock mRWLock;
        char field_340;
        sead::SafeArray<sead::PtrArray<Ctrl>, CtrlType_End> mCtrls;
        uintptr_t mKbdMouseCtrl;
        sead::SafeArray<sead::Controller*, 8> mSeadCtrls;
        sead::Controller* mHandheldSeadCtrl;
        int field_3D8;

        void createCtrl(sead::ControllerMgr*);

        /* TODO: macro for this. */
        static CtrlMgr* sInstance;
    };
}