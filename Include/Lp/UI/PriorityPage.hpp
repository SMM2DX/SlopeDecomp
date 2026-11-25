#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/Page.hpp>

namespace Lp::UI {
	#ifndef		LP_UI_PRIORITYPAGE_HPP
	#define		LP_UI_PRIORITYPAGE_HPP
	struct PriorityPage : public Page {
		//	0000007102837910
		SEAD_RTTI_OVERRIDE(PriorityPage, Page)
		~PriorityPage() override;

		uint64 nextCreateID;					//	0x3E8
	};
	#endif	//	LP_UI_PRIORITYPAGE_HPP
	static_assert(sizeof(PriorityPage) == 0x3F0);
}