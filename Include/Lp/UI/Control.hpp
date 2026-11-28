#pragma once

#include <BasicTypes.hpp>

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadListImpl.hpp>

#include <Lp/UI/Impl/Name.hpp>

namespace Lp::UI {
	#ifndef		LP_UI_CONTROL_HPP
	#define		LP_UI_CONTROL_HPP
	struct Control {
		//	0000007102823288
		SEAD_RTTI_BASE(Control);
		virtual ~Control();
		virtual void* getClassInfo() const;
		virtual void onBoundSight();
		virtual void onPreWake();
		virtual void onPostWake();
		virtual void onPreSleep();
		virtual void onPostSleep();
		virtual void onPreCalc();
		virtual void onPostCalc();

		int64 qword_8;						//	0x008
		int64 qword_10;						//	0x010
		Lp::UI::Impl::Name name;			//	0x018
		int64 qword_30;						//	0x030
		sead::OffsetList list_38;			//	0x038
		int64 qword_50;						//	0x050
		int64 qword_58;						//	0x058
		sead::OffsetList list_60;			//	0x060
		sead::OffsetList list_78;			//	0x078
		char contentSet[0x60];				//	0x090
		sead::OffsetList list_F0;			//	0x0F0
		sead::OffsetList list_108;			//	0x108
		sead::OffsetList list_120;			//	0x120
		sead::OffsetList list_138;			//	0x138
		sead::OffsetList list_150;			//	0x150
		int64 qword_168;					//	0x168
		int64 qword_170;					//	0x170
		sead::OffsetList list_178;			//	0x178
		sead::OffsetList list_190;			//	0x190
		char byte_1A8;						//	0x1A8
	};
	#endif	//	LP_UI_CONTROL_HPP
	static_assert(sizeof(Control) == 0x1B0);
}
