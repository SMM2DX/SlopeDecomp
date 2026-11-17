#pragma once

#include <sead/seadRuntimeTypeInfo.hpp>

#include <Slope/UIPageBase.hpp>

namespace Slope {
	#ifndef		SLOPE_UISYSTEMPAGE_HPP
	#define		SLOPE_UISYSTEMPAGE_HPP
	class UISystemPage : public Slope::UIPageBase {
		SEAD_RTTI_OVERRIDE(UISystemPage, Slope::UIPageBase)
		~UISystemPage() override;
	};
	#endif	//	SLOPE_UISYSTEMPAGE_HPP
}
