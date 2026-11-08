#pragma once

#include "../../../oead/thread/seadCriticalSection.h"
#include <sead/seadListImpl.hpp>
namespace Lp::UI::Impl {
    struct LayoutResourceAccessor;
    struct LayoutResourceAccessorHolder {
        bool field_0;
        /* TODO: what are the purposes for each? */
        sead::OffsetList<LayoutResourceAccessor> mList1;
        sead::OffsetList<LayoutResourceAccessor> mList2;
        LayoutResourceAccessor* mTemporaryAccessor;
        sead::CriticalSection mCS;
    };
}