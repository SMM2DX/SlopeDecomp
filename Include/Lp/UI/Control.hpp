#pragma once

using int64_t = long long int;

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadListImpl.hpp>

#include <Lp/UI/Impl/Name.hpp>

namespace Lp::UI {
	#ifndef		LP_UI_CONTROL_HPP
	#define		LP_UI_CONTROL_HPP
	struct Control {
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

		int64_t qword_0;					//	0x000
		int64_t qword_8;					//	0x008
		Lp::UI::Impl::Name name;			//	0x010
		int64_t qword_30;					//	0x030
		sead::ListImpl list_38;				//	0x038
		int64_t qword_50;					//	0x050
		int64_t qword_58;					//	0x058
		sead::ListImpl list_60;				//	0x060
		sead::ListImpl list_78;				//	0x078
		char contentSet[0x60];				//	0x090
		sead::ListImpl list_F0;				//	0x0F0
		sead::ListImpl list_108;			//	0x108
		sead::ListImpl list_120;			//	0x120
		sead::ListImpl list_138;			//	0x138
		sead::ListImpl list_150;			//	0x150
		int64_t qword_168;					//	0x168
		int64_t qword_170;					//	0x170
		sead::ListImpl list_178;			//	0x178
		sead::ListImpl list_190;			//	0x190
		char byte_1A8;						//	0x1A8
	};
	#endif	//	LP_UI_CONTROL_HPP
	static_assert(sizeof(Control) == 0x1B0);
}
