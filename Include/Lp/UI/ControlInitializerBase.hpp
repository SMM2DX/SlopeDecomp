#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/Control.hpp>

namespace Lp::UI {
	#ifndef		LP_UI_CONTROLINITIALIZERBASE_HPP
	#define		LP_UI_CONTROLINITIALIZERBASE_HPP
	struct ControlInitializerBase {
		virtual ~ControlInitializerBase();
		int64 qword_8;					//	0x008
		int64 qword_10;					//	0x010
		Control* parentControl;				//	0x018
		int64 qword_20;					//	0x020
		int64 qword_28;					//	0x028
		int64 qword_30;					//	0x030
		int64 qword_38;					//	0x038
		int64 qword_40;					//	0x040
	};
	#endif	//	LP_UI_CONTROLINITIALIZERBASE_HPP
	static_assert(sizeof(ControlInitializerBase) == 0x48);
}
