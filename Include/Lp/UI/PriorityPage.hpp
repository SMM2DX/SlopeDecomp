#pragma once

#include <Lp/UI/PageBase.hpp>

namespace Lp::UI {
	#ifndef		LP_UI_PRIORITYPAGE_HPP
	#define		LP_UI_PRIORITYPAGE_HPP
	struct PriorityPage : public PageBase {
		SEAD_RTTI_OVERRIDE(PriorityPage, PageBase)
		~PriorityPage() override;

		virtual void onPostAnimate();

		unsigned int ID;						//	0x3F0
	};
	#endif	//	LP_UI_PRIORITYPAGE_HPP
	static_assert(sizeof(PriorityPage) == 0x3F0);
}