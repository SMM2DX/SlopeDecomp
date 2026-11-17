#pragma once

#include "../Task/ProjTaskBase.hpp"
#include "Ctrl.hpp"
#include "CtrlType.hpp"

#include <OLD/sead/thread/seadCriticalSection.h>
#include <OLD/sead/thread/seadReadWriteLock.h>
#include <OLD/sead/container/seadPtrArray.h>
#include <OLD/sead/controller/seadController.h>
#include <OLD/sead/controller/seadControllerMgr.h>

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