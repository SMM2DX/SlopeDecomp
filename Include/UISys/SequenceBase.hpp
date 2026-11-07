#pragma once

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadListImpl.hpp>
#include <sead/seadCriticalSection.hpp>

#include <Lp/UI/Impl/Name.hpp>
//#include <Lp/UI/PageHolder.hpp>
#ifndef		LP_UI_PAGEHOLDER_HPP
namespace Lp::UI {
	class PageHolder {};
}
#endif	//	LP_UI_PAGEHOLDER_HPP

#include <UISys/SequenceHolder.hpp>
#include <UISys/SequenceJob.hpp>
#include <UISys/SequenceJobList.hpp>

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
		virtual void sub_11();	// nullsub Scenes?
		virtual void sub_12();	// nullsub Layouts?
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

		int temp_01;
		void* temp_02;
		long long temp_03;
		long long temp_04;
		long long temp_05;
		long long temp_06;
		long long temp_07;
		long long temp_08;
		long long temp_09;
		sead::ListImpl listImpl1;					// 0x50
		sead::ListImpl listImpl2;					// 0x68
		Lp::UI::Impl::Name name;					// 0x80
		UISys::SequenceHolder* sequenceHolder;		// 0x98
		Lp::UI::PageHolder* pageHolder;				// 0xA0
		long long temp_10;							// MISSING IN LABO !
		UISys::SequenceJob sequenceJob1;			// 0xB0
		UISys::SequenceJob sequenceJob2;			// 0xE8
		int temp_11;
		UISys::SequenceJobList sequenceJobList1;	// 0x128 Scenes?
		UISys::SequenceJobList sequenceJobList2;	// 0x140 Layouts?
		int temp_12;
		int temp_13;
		int temp_14;
		char temp_15;
		char createLayoutResourceAccessorHolder;
		char temp_16;
		char temp_17;
		sead::CriticalSection criticalsection;		// 0x168
	};
}