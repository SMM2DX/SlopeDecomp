#pragma once

#include "../sead/prim/seadRuntimeTypeInfo.h"
#include "../sead/container/seadBuffer.h"
#include "../sead/container/seadPtrArray.h"
#include "../sead/thread/seadCriticalSection.h"
#include "../Lp/Utl/StateMachine.hpp"
#include "ButtonActionCallbackArg.hpp"
#include "SequenceJobList.hpp"
#include "SequenceJob.hpp"

namespace Lp::UI{
	struct BtnPartsCtrl;
}

namespace UISys {
	class SequenceBase {
		SEAD_RTTI_BASE(SequenceBase)
		virtual ~SequenceBase();
		virtual void sub_5();	// if ???????? and sub_31() then sub_22()
		virtual void sub_6();	// sub_25()
		virtual void sub_7();	// nullsub
		virtual void sub_8();	// sub_26()
		virtual void sub_9();	// sub_27()
		virtual void sub_10();	// nullsub
		virtual void sub_11();	// nullsub
		virtual void sub_12();	// nullsub
		virtual void sub_13();	// nullsub
		virtual void sub_14();	// nullsub
		virtual void sub_15();	// nullsub
		virtual void sub_16();	// nullsub
		virtual void sub_17();	// nullsub
		virtual void sub_18();	// nullsub
		virtual void sub_19();	// nullsub
		virtual void sub_20();	// nullsub
		virtual void sub_21();	// nullsub
		virtual void sub_22();	// nullsub
		virtual void sub_23();	// nullsub
		virtual void sub_24();	// nullsub
		virtual void sub_25();	// nullsub
		virtual void sub_26();	// nullsub
		virtual void sub_27();	// nullsub
		virtual void sub_28();	// returns 1 //SequenceBase::isCreatePage_
		virtual void sub_29();	// returns 0
		virtual void sub_30();	// returns 0
		virtual bool sub_31();	// returns 0
		virtual void sub_32();	// returns 0
		virtual void sub_33();	// returns 0
		virtual void sub_34();	// returns 0
		virtual void sub_35();	// nullsub

		int temp_1;
		void* temp_2;
		long long temp_3;
		long long temp_4;
		long long temp_5;
		long long temp_6;
		long long temp_7;
		long long temp_8;
		long long temp_9;
		void* temp_10;
		void* temp_11;
		int temp_12a;
		int temp_12b;
		void* temp_13;
		void* temp_14;
		int temp_15a;
		int temp_15b;
		Lp::UI::Impl::Name name;					// 0x80
		long long temp_16;							// MISSING IN LABO !
		Lp::UI::PageHolder* pageHolder;				// 0xA0
		long long gapTemp1;
		UISys::SequenceJob sequenceJob1;			// 0xB0
		UISys::SequenceJob sequenceJob2;			// 0xE8
		int gapTemp2;
		UISys::SequenceJobList sequenceJobList1;	// 0x128
		UISys::SequenceJobList sequenceJobList2;	// 0x140
		int gapTemp3;
		int gapTemp4;
		int gapTemp5;
		short gapTemp6;
		char gapTemp7;
		sead::CriticalSection criticalsection;		// 0x168
	};
}