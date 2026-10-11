#pragma once

#include "ViewPage.hpp"
#include "../sead/math/seadVector.h"

namespace UISys{
	class StickActionCallbackArg {
		UISys::ViewPage *viewPage;
		Lp::UI::StickItem::EventArg *eventArg;
		unsigned int dword10;
		sead::Vector2f vector;
	};
}