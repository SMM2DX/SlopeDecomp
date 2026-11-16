#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/PageBase.hpp>

namespace Lp::UI {
	#ifndef		LP_UI_PAGE_HPP
	#define		LP_UI_PAGE_HPP
	struct Page : public PageBase {
		SEAD_RTTI_OVERRIDE(Page, PageBase)
		~Page() override;

		virtual void onPostAnimate();

		sead::OffsetList list_1C8;			//	0x1C8
		sead::OffsetList list_1E0;			//	0x1E0
		sead::OffsetList list_1F8;			//	0x1F8
		void* manipulator_210;				//	0x210	//	Lp::UI::Manipulator (0xA8)
		int dword_218;						//	0x218
		short word_21C;						//	0x21C
		char byte_21E;						//	0x21E
		Lp::UI::DelegateJob delegateJob2;	//	0x220
		Lp::UI::DelegateJob delegateJob3;	//	0x2B8
		Lp::UI::DelegateJob delegateJob4;	//	0x350
	};
	#endif	//	LP_UI_PAGE_HPP
	static_assert(sizeof(Page) == 0x3E8);
}