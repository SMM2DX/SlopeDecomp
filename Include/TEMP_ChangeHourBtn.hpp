#pragma once

#include <Lp/UI/BtnPartsCtrl.hpp>

struct TEMP_ChangeHourBtn : public Lp::UI::BtnPartsCtrl {
	virtual void sub_41();

	char _E[0x43];
	char temp_67;
	char temp_68;
	char temp_69;
	char temp_6A;
	char temp_6B;
	char temp_6C;
	char temp_6D;
	char temp_6E;
	char temp_6F;
	int64 usedForHour;
	int64 setsUsedForHour;
	int32 IDEK;
	char _F[0xE8];
	int64 um;
};