#pragma once

#include <sead/seadBuffer.hpp>
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
	virtual void sub_97();
	virtual void sub_98();
	virtual void sub_99();
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

	char _0[0x218];
	sead::Buffer<Lp::UI::Control> controlBuffer;			// 0x3F0
	char _1[0x370];
	sead::Buffer<Lp::UI::BtnPartsCtrl> buttonBuffer;		// 0x770
	sead::Buffer<Lp::UI::TempItemHandle> smallIconBuffer;	// 0x7A8
	char _2[0x208];
	sead::Buffer<Lp::UI::TempItemHandle> iconBuffer;		// 0x998
	sead::Buffer<Lp::UI::TextSetter> textSetterBuffer;		// 0x9A8
};