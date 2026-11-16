#pragma once

#include <Lp/UI/Control.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_PARTSCTRL_HPP
	#define		LP_UI_PARTSCTRL_HPP
	struct PartsCtrl : public Control {
		int64_t qword_1B0;					//	0x1B0
		int64_t qword_1B8;					//	0x1B8
		int64_t qword_1C0;					//	0x1C0
		int64_t qword_1C8;					//	0x1C8
		int64_t qword_1D0;					//	0x1D0
		sead::ListImpl *list_1D8;			//	0x1D8
		int64_t qword_1E0;					//	0x1E0
		int64_t qword_1E8;					//	0x1E8
		int64_t qword_1F0;					//	0x1F0
		char byte_1F8;						//	0x1F8
	};
	#endif	//	LP_UI_PARTSCTRL_HPP

	#ifndef		LP_UI_PARTSCTRLBUILDER_HPP
	#define		LP_UI_PARTSCTRLBUILDER_HPP
	struct PartsCtrlBuilder {
		struct PostCreatePartsArg{};
		struct CtrlInitArg{};
	};
	#endif	//	LP_UI_PARTSCTRLBUILDER_HPP
}