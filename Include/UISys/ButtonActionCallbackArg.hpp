#pragma once

#include "ViewPage.hpp"

namespace Lp::UI{
	struct BtnPartsCtrl;
}

namespace UISys{
	class ButtonActionCallbackArg {
		UISys::ViewPage *viewPage;
		Lp::UI::BtnPartsCtrl *btnPartsCtrl;
		unsigned int buttonIndex;
		unsigned int dword14;
		unsigned int dword18;
		unsigned int dword1C;
		unsigned int dword20;
		unsigned long long qword28;
	};
}