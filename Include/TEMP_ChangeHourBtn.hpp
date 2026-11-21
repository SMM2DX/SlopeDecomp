#pragma once

#include <Lp/UI/BtnPartsCtrl.hpp>

struct TEMP_ChangeHourBtn : public Lp::UI::BtnPartsCtrl {
	char _E[0x50];
	int64 usedForHour;
	int64 setsUsedForHour;
	int32 IDEK;
	char _F[0x1000];
};