#pragma once

#include <sead/seadListImpl.hpp>
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