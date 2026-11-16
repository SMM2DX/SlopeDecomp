#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/BtnPartsCtrl.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_KEYDECIDEICONCTRL_HPP
	#define		LP_UI_KEYDECIDEICONCTRL_HPP
	struct KeyDecideIconCtrl : public BtnPartsCtrl {
		int64 qword_280;							//	0x280
		int dword_288;								//	0x288
		int64 qword_290;							//	0x290
		int64 qword_298;							//	0x298
		short word_2A0;								//	0x2A0
		char byte_2A2;								//	0x2A2
	};
	#endif	//	LP_UI_KEYDECIDEICONCTRL_HPP
	static_assert(sizeof(KeyDecideIconCtrl) == 0x2A8);
}