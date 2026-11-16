#pragma once

#include <BasicTypes.hpp>

#include <UISys/ViewPage.hpp>

namespace UISys{
	class ButtonActionCallbackArg {
		UISys::ViewPage *viewPage;
		Lp::UI::BtnPartsCtrl *btnPartsCtrl;
		uint32 buttonIndex;
		uint32 dword14;
		uint32 dword18;
		uint32 dword1C;
		uint32 dword20;
		uint64 qword28;
	};
}