#pragma once

#include <BasicTypes.hpp>

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadListImpl.hpp>
//#include <OLD/sead/thread/seadReadWriteLock.h>

#include <OLD/Lp/UI/Input/InputContext.hpp>
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

		int64 qword_8;						//	0x008
		int64 qword_10;						//	0x010
		int64 qword_18;						//	0x018
		int64 qword_20;						//	0x020
		Lp::UI::Impl::Name name;			//	0x028
		int64 nameBufferSize;				//	0x040
		int dword_48;						//	0x048
		int dword_4C;						//	0x04C
		int dword_50;						//	0x050
		int dword_54;						//	0x054
		int64	qword_58;					//	0x058
		sead::OffsetList list_60;			//	0x060
		Lp::UI::DelegateJob delegateJob1;	//	0x078
		char readWriteLock[0xB8];			//	0x110
	};
	#endif	//	LP_UI_PAGEBASE_HPP
	static_assert(sizeof(PageBase) == 0x1C8);
}
