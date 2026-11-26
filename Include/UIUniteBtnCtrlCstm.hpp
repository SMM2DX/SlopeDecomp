#pragma once

#include <Lp/UI/UniteBtnCtrl.hpp>

#ifndef		UIUNITEBTNCTRLCSTM_HPP
#define		UIUNITEBTNCTRLCSTM_HPP
struct UIUniteBtnCtrlCstm : public Lp::UI::UniteBtnCtrl {
	//	00000071029D0C08
	virtual void sub_41();
	virtual void sub_42();
	virtual void sub_43();
	virtual void sub_44();
	virtual void sub_45();
	virtual void sub_46();
	virtual void sub_47();
	virtual void sub_48();
	virtual void sub_49();
	virtual void sub_50();

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
	char _Y[208];
};
#endif	//	UIUNITEBTNCTRLCSTM_HPP
static_assert(sizeof(UIUniteBtnCtrlCstm) == 0x4F0);