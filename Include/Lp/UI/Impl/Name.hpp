#pragma once

#include <BasicTypes.hpp>

#include <sead/seadSafeString.hpp>

namespace Lp::UI::Impl {
	#ifndef		LP_UI_IMPL_NAME_HPP
	#define		LP_UI_IMPL_NAME_HPP
    struct Name  {
        sead::SafeString mSafeString;
        uint32 mHash;
        uint16 mStrLen;
        char field_16;
        char field_17;
    };
	#endif	//	LP_UI_IMPL_NAME_HPP
}