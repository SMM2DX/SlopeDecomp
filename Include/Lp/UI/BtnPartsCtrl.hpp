#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/PartsCtrl.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_BTNPARTSCTRL_HPP
	#define		LP_UI_BTNPARTSCTRL_HPP
	struct BtnPartsCtrl : public PartsCtrl {
		struct BtnEventArg{};
		struct DisplayCursorEvent{};

		int dword_1FC;						//	0x1FC
		int dword_200;						//	0x200
		int64 qword_208;					//	0x208
		int64 qword_210;					//	0x210
		int64 qword_218;					//	0x218
		int dword_220;						//	0x220
		int64 qword_228;					//	0x228
		int dword_230;						//	0x230
		int64 qword_238;					//	0x238
		int64 qword_240;					//	0x240
		int64 qword_248;					//	0x248
		void* qword_250;					//	0x250
		void* qword_258;					//	0x258
		int64 qword_260;					//	0x260
		int64 qword_268;					//	0x268
		int64 qword_270;					//	0x270
		int64 qword_278;					//	0x278
	};
	#endif	//	LP_UI_BTNPARTSCTRL_HPP
	static_assert(sizeof(BtnPartsCtrl) == 0x280);
}