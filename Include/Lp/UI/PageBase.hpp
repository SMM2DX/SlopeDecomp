#pragma once

#include <sead/seadRuntimeTypeInfo.hpp>
#include <oead/thread/seadReadWriteLock.h>

#include <sead/seadListImpl.hpp>
#include <Lp/UI/Impl/Name.hpp>
#include <LpOG/UI/Impl/DrawSightArg.hpp>
#include <LpOG/UI/Input/InputContext.hpp>
#include <LpOG/UI/Job/Job.hpp>
#include <LpOG/UI/Job/DelegateJob.hpp>

namespace Lp::UI {
    struct PageHolder;

    struct PageBase {
        SEAD_RTTI_BASE(PageBase);
        virtual ~PageBase();
        
        virtual uintptr_t getClassInfo();
        virtual void endInitializeImpl();
        virtual void finalizeImpl();
        virtual void wakeImpl();
        virtual void sleepImpl();
        virtual void priorManipulateImpl(InputContext*, bool);
        virtual void manipulateImpl(InputContext*, bool);
        virtual void preCalcImpl();
        virtual void postCalcImpl();
        virtual void updateBindingImpl();
        virtual void chainPostCalcImpl(Job*, bool);
        virtual void drawLayoutImpl(Impl::DrawSightArg*);
        virtual void onPreWake();
        virtual void onPostWake();
        virtual void onPreSleep();
        virtual void onPostSleep();
        virtual void onPreCalc();
        virtual void onPostCalc();

        uintptr_t field_8;
        uintptr_t field_10;
        uintptr_t field_18;
        uintptr_t field_20;
        sead::ListNode mListNode;
        Impl::Name field_30;
        PageHolder* mHolder;
        int mState; /* TODO: */
        unsigned int mPauseFlags;
        char field_60;
        int field_64;
        PageBase* mParentPage;
        sead::OffsetList<PageBase> mChildPages;
        DelegateJob mPostCalcJob;
        sead::ReadWriteLock mChildPagesRwLock;
    };
    //static_assert(sizeof(PageBase) == 0x1E8); TEMP
}