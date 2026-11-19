#pragma once

#include <BasicTypes.hpp>

#include <sead/seadBuffer.hpp>
#include <sead/seadPtrArray.hpp>
#include <sead/seadRuntimeTypeInfo.hpp>

#include <Lp/UI/TempItemHandle.hpp>
#include <Lp/UI/TextSetter.hpp>

#include <UISys/SequenceJob.hpp>

#include <Slope/UIPageBase.hpp>

namespace Slope {
	#ifndef		SLOPE_UIEDITMAINPAGE_HPP
	#define		SLOPE_UIEDITMAINPAGE_HPP
	class UIEditMainPage : public UIPageBase {
		SEAD_RTTI_OVERRIDE(UIEditMainPage, UIPageBase)
		~UIEditMainPage() override;

		int32 dword_568;													//	0x568
		char _0[0x200];		// Bro ICBA theyre all basically qwords
		sead::Buffer<Lp::UI::BtnPartsCtrl> buttonBuffer;					//	0x770	//	104	Elements	//	0x8 Span
		sead::Buffer<Lp::UI::TempItemHandle> UNKBuffer_780;					//	0x780	//	30	Elements	//	0x8 Span
		UISys::SequenceJob* sequenceJob_790;								//	0x790
		UISys::SequenceJob* sequenceJob_798;								//	0x798
		UISys::SequenceJob* sequenceJob_7A0;								//	0x7A0
		sead::Buffer<Lp::UI::TempItemHandle> smallButtonIconBuffer;			//	0x7A8	//	16	Elements	//	0x8 Span
		sead::Buffer<void> UNKBuffer_7BB;									//	0x7B8	//	6	Elements	//	0x8 Span
		sead::Buffer<void> UNKBuffer_7CB;									//	0x7C8	//	10	Elements	//	0x8 Span
		int64 qword_7D8;													//	0x7D8
		int64 qword_7E0;													//	0x7E0
		int64 qword_7E8;													//	0x7E8
		int64 qword_7F0;													//	0x7F0
		int64 qword_7F8;													//	0x7F8
		int64 qword_700;													//	0x800
		int64 qword_808;													//	0x808
		int64 qword_810;													//	0x810
		sead::PtrArrayImpl UNKPtrArray_818;									//	0x818	//	4	Ptrs
		int32 dword_828;													//	0x828
		int32 dword_82C;													//	0x82C
		int64 qword_830;													//	0x830
		int64 qword_838;													//	0x838
		int64 qword_840;													//	0x840
		int64 qword_848;													//	0x848
		int64 qword_850;													//	0x850
		int64 qword_858;													//	0x858
		int64 qword_860;													//	0x860
		int64 qword_868;													//	0x868
		sead::Buffer<void> UNKBuffer_870;									//	0x870	//	5	Elements	//	0x4 Span
		int64 qword_880;													//	0x880	//	Something is happening here
		int64 qword_888;													//	0x888
		int64 qword_890;													//	0x890
		int64 qword_898;													//	0x898
		int64 qword_8A0;													//	0x8A0
		int64 qword_8A8;													//	0x8A8
		int64 qword_8B0;													//	0x8B0
		int64 qword_8B8;													//	0x8B8
		int64 qword_8C0;													//	0x8C0
		int64 qword_8C8;													//	0x8C8
		int64 qword_8D0;													//	0x8D0
		int64 qword_8D8;													//	0x8D8
		int64 qword_8E0;													//	0x8E0
		int64 qword_8E8;													//	0x8E8
		int64 qword_8F0;													//	0x8F0
		int64 qword_8F8;													//	0x8F8
		int64 qword_900;													//	0x900
		int64 qword_908;													//	0x908
		int64 qword_910;													//	0x910
		int64 qword_918;													//	0x918
		int64 qword_920;													//	0x920
		int64 qword_928;													//	0x928
		int64 qword_930;													//	0x930
		int64 qword_938;													//	0x938
		int64 qword_940;													//	0x940
		void* qword_948;													//	0x948
		int64 qword_950;													//	0x950
		int64 qword_958;													//	0x958
		int64 qword_960;													//	0x960
		void* qword_968;													//	0x968
		int64 qword_970;													//	0x970
		int64 qword_978;													//	0x978
		int64 qword_980;													//	0x980
		sead::PtrArray<Lp::UI::TempItemHandle> skinButtonIconPtrArray;		//	0x988	//	6	Ptrs
		sead::PtrArray<Lp::UI::TempItemHandle> sceneButtonIconPtrArray;		//	0x998	//	10	Ptrs
		sead::PtrArray<Lp::UI::TextSetter> sceneButtonTextSetterPtrArray;	//	0x9A8	//	10	Ptrs
		sead::PtrArrayImpl UNKPtrArray_9B8;									//	0x9B8	//	11	Ptrs
		sead::PtrArrayImpl UNKPtrArray_9C8;									//	0x9C8	//	11	Ptrs
		sead::PtrArrayImpl UNKPtrArray_9D8;									//	0x9D8	//	11	Ptrs
		sead::PtrArrayImpl UNKPtrArray_9E8;									//	0x9E8	//	11	Ptrs
		char byte_9F8;														//	0x9F8
		void* qword_A00;													//	0xA00
		int64 qword_A08;													//	0xA08
		int64 qword_A10;													//	0xA10
		int64 qword_A18;													//	0xA18
		char byte_A20;														//	0xA20
	};
	#endif	//	SLOPE_UIEDITMAINPAGE_HPP
}
