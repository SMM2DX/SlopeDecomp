#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/BtnPartsCtrl.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_UNITEBTNCTRL_HPP
	#define		LP_UI_UNITEBTNCTRL_HPP
	struct UniteBtnCtrl : public BtnPartsCtrl {
		virtual void sub_41();
		virtual void sub_42();
		
		int64 qword_280;						//	0x280
		int64 qword_288;						//	0x288
		int64 qword_290;						//	0x290
		int64 qword_298;						//	0x298
		int64 qword_2A0;						//	0x2A0
		int64 qword_2A8;						//	0x2A8
		int dword_2B0;							//	0x2B0
		int dword_2B4;							//	0x2B4
		int dword_2B8;							//	0x2B8
		char byte_2BC;							//	0x2BC
		char byte_2BD;							//	0x2BD
		char byte_2BE;							//	0x2BE
		char byte_2BF;							//	0x2BF
		char byte_2C0;							//	0x2C0
		char byte_2C1;							//	0x2C1
		char byte_2C2;							//	0x2C2
		char byte_2C3;							//	0x2C3
		char byte_2C4;							//	0x2C4
	};
	#endif	//	LP_UI_UNITEBTNCTRL_HPP
	static_assert(sizeof(UniteBtnCtrl) == 0x2C8);
}