#pragma once

#include <sead/seadDisposer.hpp>
#include <sead/seadListImpl.hpp>
#include <sead/seadHeap.hpp>
#include <seadOG/heap/seadExpHeap.h>

#include <Lp/UI/PageBase.hpp>

#include <LpOG/UI/Impl/DualHeapAdapter.hpp>
#include <LpOG/UI/Impl/LayoutResourceMgr.hpp>
#include <Lp/UI/Impl/Name.hpp>
#include <LpOG/UI/Impl/LayoutResourceAccessorHolder.hpp>

namespace Lp::UI {
    struct PageHolder : public sead::IDisposer {
        struct HeapSet {
            sead::ListNode mListNode;
            sead::ExpHeap* mHeap;
            Impl::DualHeapAdapter* mDualHeapAdapter;
            Impl::LayoutResourceMgr mLytResMgr;
        };
        
        uintptr_t field_20;
        uintptr_t field_28;
        Impl::Name name;
        sead::Heap* pHeap;
        sead::OffsetList<HeapSet> mHeapSetList;
        HeapSet* mRootHeapSet;
        bool field_70;
        sead::OffsetList<PageBase> mChildPages;
        Impl::LayoutResourceAccessorHolder* pLayoutResourceAccessorHolder;
    };
}