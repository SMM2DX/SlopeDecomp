#pragma once

#include <Lp/UI/TempItemHandle.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_TEXTSETTER_HPP
	#define		LP_UI_TEXTSETTER_HPP
	struct TextSetter{
		virtual void sub_1();

		char _0[0x40];
		TempItemHandle* tempItemHandle;
		char _Z[0x1000];
	};
	#endif	//	LP_UI_TEXTSETTER_HPP
}