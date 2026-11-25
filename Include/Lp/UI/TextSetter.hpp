#pragma once

#include <sead/seadRuntimeTypeInfo.hpp>

#include <Lp/UI/Impl/Name.hpp>
#include <Lp/UI/TempItemHandle.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_TEXTSETTER_HPP
	#define		LP_UI_TEXTSETTER_HPP
	struct TextSetter{
		//	00000071029F78D8
		SEAD_RTTI_BASE(TextSetter);
		virtual void sub_3();
		virtual void sub_4();
		virtual void sub_5();

		int64 qword_8;
		int64 qword_10;
		Lp::UI::Impl::Name textItemHandleName;
		Lp::UI::Impl::Name itemHandleName;
		TempItemHandle* itemHandle;
		int64 qword_50;
		int16 word_58;
	};
	#endif	//	LP_UI_TEXTSETTER_HPP
}