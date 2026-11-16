#pragma once

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadListImpl.hpp>
//#include <oead/thread/seadReadWriteLock.h>

#include <LpOG/UI/Input/InputContext.hpp>
#include <Lp/UI/Impl/Name.hpp>
#include <Lp/UI/DelegateJob.hpp>

namespace Lp::UI {
	#ifndef		LP_UI_PAGEBASE_HPP
	#define		LP_UI_PAGEBASE_HPP
	struct PageBase {
		SEAD_RTTI_BASE(PageBase);
		virtual ~PageBase();
		
		virtual void* getClassInfo();
		virtual void endInitializeImpl();
		virtual void finalizeImpl();
		virtual void wakeImpl();
		virtual void sleepImpl();
		virtual void priorManipulateImpl(InputContext*, bool);
		virtual void manipulateImpl(InputContext*, bool);
		virtual void preCalcImpl();
		virtual void postCalcImpl();
		virtual void updateBindingImpl();
		virtual void chainPostCalcImpl(Job*, bool);
		virtual void drawLayoutImpl();
		virtual void onPreWake();
		virtual void onPostWake();
		virtual void onPreSleep();
		virtual void onPostSleep();
		virtual void onPreCalc();
		virtual void onPostCalc();

		int64_t qword_0;					//	0x000
		int64_t qword_8;					//	0x008
		int64_t qword_10;					//	0x010
		int64_t qword_18;					//	0x018
		Lp::UI::Impl::Name name;			//	0x020
		int64_t nameBufferSize;				//	0x040
		int dword_48;						//	0x048
		int dword_4C;						//	0x04C
		int dword_50;						//	0x050
		int dword_54;						//	0x054
		int64_t	qword_58;					//	0x058
		sead::ListImpl list_60;				//	0x060
		Lp::UI::DelegateJob delegateJob1;	//	0x078
		char readWriteLock[0xB8];			//	0x110
		sead::ListImpl list_1C8;			//	0x1C8
		sead::ListImpl list_1E0;			//	0x1E0
		sead::ListImpl list_1F8;			//	0x1F8
		int64_t qword_210;					//	0x210
		int dword_218;						//	0x218
		short word_21C;						//	0x21C
		char byte_21E;						//	0x21E
		Lp::UI::DelegateJob delegateJob2;	//	0x220
		Lp::UI::DelegateJob delegateJob3;	//	0x2B8
		Lp::UI::DelegateJob delegateJob4;	//	0x350
	};
	#endif	//	LP_UI_PAGEBASE_HPP
	static_assert(sizeof(PageBase) == 0x3E8);
}
