#pragma once

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadListImpl.hpp>

#include <LpOG/UI/Impl/LayoutSight.hpp>
#include <Lp/UI/Impl/Name.hpp>

namespace Lp::UI {
    struct Page;
    struct Control {
        SEAD_RTTI_BASE(Control);

        struct List {
            sead::OffsetList<Control> mList;
        };

        sead::ListNode mListNode;
        Impl::Name mName;
        Control* mParent;
        List mChildren;
        Page* mParentPage;
        Impl::LayoutSight* mLayoutSight;
        

        virtual ~Control();
        virtual uintptr_t getClassInfo() const;
        virtual void onBoundSight();
        virtual void onPreWake();
        virtual void onPostWake();
        virtual void onPreSleep();
        virtual void onPostSleep();
        virtual void onPreCalc();
        virtual void onPostCalc();
    };
}