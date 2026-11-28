#pragma once

#include <BasicTypes.hpp>

#include <Slope/CustomEnums.hpp>

namespace Slope {
	#ifndef		SLOPE_BGMHANDLER_HPP
	#define		SLOPE_BGMHANDLER_HPP
	class BgmHandler {
		virtual void sub_1();
		int64 qword_08;
		int32 dword_10;
		ptr_t qword_18;

		char _0[0x90];
	};
	#endif	//	SLOPE_BGMHANDLER_HPP
	static_assert(sizeof(BgmHandler) == 0xB0);
}
