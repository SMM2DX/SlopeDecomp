#pragma once

#include <sead/seadBuffer.hpp>
#include <sead/seadPtrArray.hpp>
#include <sead/seadRuntimeTypeInfo.hpp>

#include <Lp/UI/TempItemHandle.hpp>
#include <Lp/UI/TextSetter.hpp>

#include <UISys/ViewPage.hpp>

class UIEditMainPage : public UISys::ViewPage {
	SEAD_RTTI_OVERRIDE(UIEditMainPage, ViewPage)
	~UIEditMainPage() override;

	virtual void sub_75();
	virtual void sub_76();
	virtual void sub_77();
	virtual void sub_78();
	virtual void sub_79();
	virtual void sub_80();
	virtual void sub_81();
	virtual void sub_82();
	virtual void sub_83();
	virtual void sub_84();
	virtual void sub_85();
	virtual void sub_86();
	virtual void sub_87();
	virtual void sub_88();
	virtual void sub_89();
	virtual void sub_90();
	virtual void sub_91();
	virtual void sub_92();
	virtual void sub_93();
	virtual void sub_94(); // doInitialize_() ?
	virtual void sub_95();
	virtual void sub_96();
	virtual void sub_97(); // smallIconBuffer
	virtual void sub_98();
	virtual void sub_99(); // sets up textSetterPtrArray 
	virtual void sub_100();
	virtual void sub_101();
	virtual void sub_102();
	virtual void sub_103();
	virtual void sub_104();
	virtual void sub_105();
	virtual void sub_106();
	virtual void sub_107();
	virtual void sub_108();
	virtual void sub_109();
	virtual void sub_110();
	virtual void sub_111();
	virtual void sub_112();
	virtual void sub_113();
	virtual void sub_114();
	virtual void sub_115();
	virtual void sub_116();
	virtual void sub_117();
	virtual void sub_118();
	virtual void sub_119();
	virtual void sub_120();
	virtual void sub_121();
	virtual void sub_122();
	virtual void sub_123();
	virtual void sub_124();
	virtual void sub_125();
	virtual void sub_126();
	virtual void sub_127();
	virtual void sub_128();
	virtual void sub_129();
	virtual void sub_130();
	virtual void sub_131();
	virtual void sub_132();

	char _2[0x200];
	sead::Buffer<Lp::UI::BtnPartsCtrl> buttonBuffer;		//	0x770	//	104	Elements
	sead::Buffer<Lp::UI::TempItemHandle> smallIconBuffer;	//	0x780	//	30	Elements
	char _3[0x18];
	sead::Buffer<void> UNKBuffer_7A8;						//	0x7A8	//	16	Elements
	sead::Buffer<void> UNKBuffer_7BB;						//	0x7B8	//	6	Elements
	sead::Buffer<void> UNKBuffer_7CB;						//	0x7C8	//	10	Elements
	char _4[0x40];
	sead::PtrArrayImpl UNKPtrArray_818;						//	0x818	//	4	Ptrs
	char _5[0x48];
	sead::Buffer<void> UNKBuffer_870;						//	0x870	//	5	Elements
	char _6[0x108];
	sead::PtrArrayImpl UNKPtrArray_988;						//	0x988	//	6	Ptrs
	sead::PtrArray<Lp::UI::TempItemHandle> iconPtrArray;	//	0x998	//	10	Ptrs
	sead::PtrArray<Lp::UI::TextSetter> textSetterPtrArray;	//	0x9A8	//	10	Ptrs
	sead::PtrArrayImpl UNKPtrArray_9B8;						//	0x9B8	//	11	Ptrs
	sead::PtrArrayImpl UNKPtrArray_9C8;						//	0x9C8	//	11	Ptrs
	sead::PtrArrayImpl UNKPtrArray_9D8;						//	0x9D8	//	11	Ptrs
	sead::PtrArrayImpl UNKPtrArray_9E8;						//	0x9E8	//	11	Ptrs
};
