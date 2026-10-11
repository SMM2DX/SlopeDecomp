#pragma once

#include "ViewPage.hpp"

namespace UISys{
	class KeyActionCallbackArg {
		UISys::ViewPage *viewPage;
		Lp::UI::KeyItem *keyItem;
		unsigned int keyItemIndex;
		unsigned int event;
		unsigned int dword18;
	};
}