#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/BtnPartsCtrl.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_SELECTORCTRL_HPP
	#define		LP_UI_SELECTORCTRL_HPP
	struct SelectorCtrl : public BtnPartsCtrl {
		//	0000007102839C98
		int64 qword_280;						//	0x280
		int64 qword_288;						//	0x288
		int64 qword_290;						//	0x290
		int64 qword_298;						//	0x298
		int64 qword_2A0;						//	0x2A0
		int64 qword_2A8;						//	0x2A8
		int64 qword_2B0;						//	0x2B0
		void* qword_2B8;						//	0x2B8
		int64 qword_2C0;						//	0x2C0
		int dword_2C8;							//	0x2C8
		int dword_2CC;							//	0x2CC
		int64 qword_2D0;						//	0x2D0
		int dword_2D8;							//	0x2D8
	};
	#endif	//	LP_UI_SELECTORCTRL_HPP
	static_assert(sizeof(SelectorCtrl) == 0x2E0);
}