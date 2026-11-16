#pragma once

#include <Lp/UI/PartsCtrl.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_BTNPARTSCTRL_HPP
	#define		LP_UI_BTNPARTSCTRL_HPP
	struct BtnPartsCtrl : public PartsCtrl {
		struct BtnEventArg{};
		struct DisplayCursorEvent{};
	};
	#endif	//	LP_UI_BTNPARTSCTRL_HPP
}