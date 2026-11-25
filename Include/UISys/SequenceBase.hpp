#pragma once

#include <BasicTypes.hpp>

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadListImpl.hpp>
#include <sead/seadCriticalSection.hpp>
#include <sead/seadBuffer.hpp>

#include <Lp/UI/Impl/Name.hpp>
#include <Lp/UI/PageHolder.hpp>

#include <UISys/SequenceHolder.hpp>
#include <UISys/SequenceJob.hpp>

#include <UISys/struct_temp_09.hpp>

namespace UISys {
	#ifndef		UISYS_SEQUENCEBASE_HPP
	#define		UISYS_SEQUENCEBASE_HPP
	class SequenceBase {
		//	00000071029F7C48
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

		sead::Buffer<void> buffer_8;				//	0x008
		int64 qword_18;								//	0x018
		int64 qword_20;								//	0x020
		int64 qword_28;								//	0x028
		int64 qword_30;								//	0x030
		int64 qword_38;								//	0x038
		int64 qword_40;								//	0x040
		temp_9_t* temp_09;							//	0x048
		sead::OffsetList list_50;					//	0x050
		sead::OffsetList list_68;					//	0x068
		Lp::UI::Impl::Name name;					//	0x080

		UISys::SequenceHolder* sequenceHolder;		//	0x098
		Lp::UI::PageHolder* pageHolder;				//	0x0A0
		int32 dword_A8;								//	0x0A8	MISSING IN LABO !
		UISys::SequenceJob sequenceJob1;			//	0x0B0
		UISys::SequenceJob sequenceJob2;			//	0x0E8
		int32 dword_120;							//	0x120
		UISys::SequenceJobList sequenceJobList1;	//	0x128
		UISys::SequenceJobList sequenceJobList2;	//	0x140
		int32 nextCreateID;							//	0x158
		int32 dword_15C;							//	0x15C
		void* qword_160;							//	0x160
		sead::CriticalSection criticalsection;		//	0x168
	};
	#endif	//	UISYS_SEQUENCEBASE_HPP
	static_assert(sizeof(SequenceBase) == 0x1A8);
}