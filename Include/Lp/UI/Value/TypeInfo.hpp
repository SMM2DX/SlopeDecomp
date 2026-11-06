#pragma once

#include <seadOG/container/seadOffsetList.h>

#include "../Impl/Name.hpp"
#include "ValueConverter.hpp"

namespace Lp::UI {
    struct TypeInfo {
        sead::ListNode mListNode;
        Impl::Name mName;
        sead::OffsetList<ValueConverter> mConverters;
        ValueConverter* mSelfConverter;
    };
}