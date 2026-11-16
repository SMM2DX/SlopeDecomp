#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/BtnPartsCtrl.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_SCROLLBARCTRL_HPP
	#define		LP_UI_SCROLLBARCTRL_HPP
	struct ScrollBarCtrl : public BtnPartsCtrl {
		int64 qword_280;						//	0x280
		int64 qword_288;						//	0x288
		int64 qword_290;						//	0x290
		int64 qword_298;						//	0x298
		int64 qword_2A0;						//	0x2A0
		int64 qword_2A8;						//	0x2A8
		int dword_2B0;							//	0x2B0
		int dword_2B4;							//	0x2B4
		int dword_2B8;							//	0x2B8
		int dword_2BC;							//	0x2BC
		int dword_2C0;							//	0x2C0
		int dword_2C4;							//	0x2C4
		int dword_2C8;							//	0x2C8
		int dword_2CC;							//	0x2CC
		int dword_2D0;							//	0x2D0
		int dword_2D4;							//	0x2D4
		int dword_2D8;							//	0x2D8
		int dword_2DC;							//	0x2DC
		int dword_2E0;							//	0x2E0
		int dword_2E4;							//	0x2E4
		int dword_2E8;							//	0x2E8
		int dword_2EC;							//	0x2EC
		int dword_2F0;							//	0x2F0
		int dword_2F4;							//	0x2F4
		int dword_2F8;							//	0x2F8
		int dword_2FC;							//	0x2FC
		int64 qword_300;						//	0x300
		int64 qword_308;						//	0x308
		int64 qword_310;						//	0x310
		char byte_318;							//	0x318
	};
	#endif	//	LP_UI_SCROLLBARCTRL_HPP
	static_assert(sizeof(ScrollBarCtrl) == 0x320);
}