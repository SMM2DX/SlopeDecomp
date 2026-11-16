#pragma once

#include <sead/seadSafeString.hpp>

namespace Lp::UI::Impl {
	#ifndef		LP_UI_IMPL_NAME_HPP
	#define		LP_UI_IMPL_NAME_HPP
    struct Name : public sead::SafeString {
        unsigned int mHash;
        unsigned short mStrLen;
        char field_16;
        char field_17;
    };
	#endif	//	LP_UI_IMPL_NAME_HPP
}