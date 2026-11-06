#pragma once

#include "../../sead/seadSafeString.hpp"

namespace Lp::Utl  {
    struct Meta {
        sead::FixedSafeString<256> mData;
    };
}