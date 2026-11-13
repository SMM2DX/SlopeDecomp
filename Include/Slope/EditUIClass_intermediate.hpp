#pragma once

#include <agl/TextureData.hpp>

#include <sead/seadBuffer.hpp>
#include <sead/seadPtrArray.hpp>

#include <Lp/Utl/StateMachine.hpp>
#include <Lp/Utl/TextureHolder.hpp>
#include <Lp/UI/BtnPartsCtrl.hpp>
#include <Lp/UI/TextureInfo.hpp>

#include <UISys/ButtonActionCallbackArg.hpp>
#include <UISys/SequenceBase.hpp>

#include <Slope/UIEditMainPage.hpp>

class EditUIClass_intermediate : public UISys::SequenceBase {
	SEAD_RTTI_OVERRIDE(EditUIClass_intermediate, UISys::SequenceBase)
	~EditUIClass_intermediate() override;

	void sub_6() override;	// sub_25(), sub_41()
	void sub_7() override;	// sub_42()
	void sub_8() override;	// sub_26(), sub_44()
	void sub_9() override;	// sub_27(), sub_46()
	void sub_10() override;	// sub_47()
	void sub_11() override;	// sub_48()
	void sub_12() override;	// sub_49()
	void sub_13() override;	// sub_50()
	void sub_14() override;	// sub_51()
	void sub_15() override;	// sub_52()
	void sub_16() override;	// sub_53()
	void sub_17() override;	// sub_54()
	void sub_18() override;	// sub_55()
	void sub_19() override;	// ????????, sub_56()
	void sub_20() override;	// sub_57()
	void sub_21() override;	// sub_58()
	void sub_22() override;	// sub_59()
	void sub_23() override;	// sub_60()
	void sub_24() override;	// sub_61()
	void sub_25() override;	// sub_40()
	void sub_26() override;	// sub_43()
	void sub_27() override;	// sub_45()

	virtual void sub_36();	// sub_38()
	virtual void sub_37();	// sub_39()
	virtual void sub_38();	// nullsub
	virtual void sub_39();	// nullsub
	virtual void sub_40();	// nullsub
	virtual void sub_41();	// nullsub
	virtual void sub_42();	// nullsub
	virtual void sub_43();	// nullsub
	virtual void sub_44();	// nullsub
	virtual void sub_45();	// nullsub
	virtual void sub_46();	// nullsub
	virtual void sub_47();	// nullsub
	virtual void sub_48();	// nullsub
	virtual void sub_49();	// nullsub
	virtual void sub_50();	// nullsub
	virtual void sub_51();	// nullsub
	virtual void sub_52();	// nullsub
	virtual void sub_53();	// nullsub
	virtual void sub_54();	// nullsub
	virtual void sub_55();	// nullsub
	virtual void sub_56();	// nullsub
	virtual void sub_57();	// nullsub
	virtual void sub_58();	// nullsub
	virtual void sub_59();	// nullsub
	virtual void sub_60();	// nullsub
	virtual void sub_61();	// nullsub
	virtual void sub_62();	// nullsub
	virtual void sub_63();	// nullsub
	virtual void sub_64();	// nullsub
	virtual void sub_65();	// nullsub
	virtual void sub_66();	// nullsub
	virtual void sub_67();	// nullsub
	virtual void sub_68();	// nullsub
	virtual void sub_69();	// nullsub
	virtual void sub_70();	// nullsub
	virtual void sub_71();	// nullsub
	virtual void sub_72();	// nullsub
	virtual void sub_73();	// nullsub
	virtual void sub_74(UISys::ButtonActionCallbackArg *);	// nullsub
	virtual void sub_75();	// nullsub
	virtual void sub_76();	// nullsub
	virtual void sub_77();	// nullsub
	virtual void sub_78();	// nullsub
	virtual void sub_79();	// nullsub
	virtual void sub_80();	// nullsub
	virtual void sub_81();	// nullsub
	virtual void sub_82();	// nullsub
	virtual void sub_83();	// nullsub
	virtual void sub_84();	// nullsub
	virtual void sub_85();	// nullsub
	virtual void sub_86();	// nullsub
	virtual void sub_87();	// nullsub
	virtual void sub_88();	// nullsub
	virtual void sub_89();	// nullsub
	virtual void sub_90();	// nullsub
	virtual void sub_91();	// nullsub
	virtual void sub_92();	// returns 1
	virtual void sub_93();	// returns 1
	virtual void sub_94();	// returns 1
	virtual void sub_95();	// returns 1
	virtual void sub_96();	// returns 1
	virtual void sub_97();	// nullsub
	virtual void sub_98();	// nullsub
	virtual void sub_99();	// nullsub
	virtual void sub_100();	// nullsub
	virtual void sub_101();	// nullsub
	virtual void sub_102();	// nullsub
	virtual void sub_103();	// returns 2
	virtual void sub_104();	// returns 0
	virtual void sub_105();	// nullsub
	virtual void sub_106();	// nullsub

	Lp::Utl::StateMachine* pStateMachine1;
	long long unk_num1;
	bool unk_bool;
	long long unk_num2;
	Lp::Utl::StateMachine stateMachine1;
	char gapFill1[0x58];
	Lp::Utl::StateMachine stateMachine2;
	uint32_t gapFill2;
	uint32_t gapFill3;
	UISys::ViewPage* parentViewPage;
	int64_t gapFill4;
	int64_t gapFill5;
	
	sead::PtrArray<Lp::UI::TextureInfo>		SkinButtons_TextureInfo;		//	0x2A0
	sead::PtrArray<Lp::Utl::TextureHolder>	SkinButtons_TextureHolder;		//	0x2B0
	sead::PtrArray<Lp::UI::TextureInfo>		SceneButtons_TextureInfo;		//	0x2C0
	sead::PtrArray<Lp::Utl::TextureHolder>	SceneButtons_TextureHolder;		//	0x2D0
	Lp::UI::TextureInfo*					SceneSmallButton_TextureInfo;	//	0x2E0
	long long temp_6; // what are you?
	long long temp_7; // what are you?
	long long temp_8; // what are you?
	Lp::Utl::TextureHolder*					SceneSmallButton_TextureHolder;	//	0x300
	long long temp_10; // what are you?

	// 0x790 is a TextureInfo
	// 0x7B0 is a TextureData

	char gap_2f[0x48];
	long long temp1;
	unsigned long long temp2;
	char gap_1[304];
	unsigned int dword530;
	char gap534[52];
	unsigned int dword568;
	int dword56C;
	unsigned int dword570;
	int dword574;
	unsigned long long qword578;
	unsigned int dword580;
	int dword584;
	unsigned long long qword588;
	unsigned long long qword590;
	unsigned long long qword598;
	unsigned long long qword5A0;
	unsigned int dword5A8;
	unsigned long long qword5AC;
	int dword5B4;
	unsigned int dword5B8;
	int dword5BC;
	unsigned long long qword5C0;
	unsigned int dword5C8;
	int dword5CC;
	unsigned long long qword5D0;
	unsigned long long qword5D8;
	unsigned int dword5E0;
	int dword5E4;
	unsigned long long qword5E8;
	unsigned int dword5F0;
	int dword5F4;
	unsigned long long qword5F8;
	unsigned int dword600;
	int dword604;
	unsigned long long qword608;
	unsigned int dword610;
	int dword614;
	unsigned long long qword618;
	unsigned long long qword620;
	unsigned long long qword628;
	unsigned long long qword630;
	unsigned long long qword638;
	unsigned long long qword640;
	unsigned long long qword648;
	unsigned long long qword650;
	unsigned long long qword658;
	unsigned int dword660;
	int dword664;
	unsigned int dword668;
	int dword66C;
	unsigned long long qword670;
	unsigned long long qword678;
	unsigned long long qword680;
	unsigned long long qword688;
	unsigned long long qword690;
	unsigned long long qword698; // Used in Small Icon function?
	unsigned long long qword6A0;
	unsigned long long qword6A8;
	unsigned long long qword6B0;
	unsigned long long qword6B8;
	unsigned long long qword6C0;
	unsigned long long qword6C8;
	unsigned long long qword6D0;
	unsigned long long qword6D8;
	unsigned long long qword6E0;
	unsigned long long qword6E8;
	unsigned long long qword6F0;
	unsigned long long qword6F8;
	unsigned int dword700;
	int dword704;
	unsigned long long qword708;
	unsigned int dword710;
	int dword714;
	unsigned long long qword718;
	unsigned int dword720;
	int dword724;
	unsigned long long qword728;
	unsigned long long qword730;
	unsigned long long qword738;
	unsigned long long qword740;
	unsigned long long qword748;
	unsigned long long qword750;
	unsigned long long qword758;
	unsigned long long qword760;
	unsigned long long qword768;
	sead::Buffer<Lp::UI::BtnPartsCtrl> mBtnPartsCtrlBuffer;
	unsigned int unsigned_int780;
	int dword784;
	unsigned long long qword788;
	unsigned long long qword790;
	unsigned long long qword798;
	unsigned long long qword7A0;
	unsigned int unsigned_int7A8;
	int dword7AC;
	unsigned long long qword7B0;
	unsigned int unsigned_int7B8;
	int dword7BC;
	unsigned long long qword7C0;
	unsigned int unsigned_int7C8;
	int dword7CC;
	unsigned long long qword7D0;
	unsigned long long qword7D8;
	unsigned long long qword7E0;
	unsigned long long qword7E8;
	unsigned long long qword7F0;
	unsigned long long qword7F8;
	unsigned long long qword800;
	unsigned long long qword808;
	unsigned long long qword810;
	unsigned long long qword818;
	unsigned long long qword820;
	unsigned int dword828;
	unsigned int dword82C;
	unsigned long long qword830;
	unsigned long long qword838;
	unsigned long long qword840;
	unsigned long long qword848;
	unsigned long long qword850;
	unsigned long long qword858;
	unsigned long long qword860;
	unsigned long long qword868;
	unsigned int unsigned_int870;
	int dword874;
	unsigned long long qword878;
	unsigned int dword880;
	int dword884;
	unsigned long long qword888;
	unsigned long long qword890;
	unsigned long long qword898;
	unsigned long long qword8A0;
	unsigned long long qword8A8;
	unsigned long long qword8B0;
	unsigned long long qword8B8;
	char gap8C0[40];
	unsigned long long qword8E8;
	unsigned long long qword8F0;
	unsigned long long qword8F8;
	unsigned long long qword900;
	unsigned long long qword908;
	unsigned long long qword910;
	unsigned long long qword918;
	unsigned long long qword920;
	unsigned long long qword928;
	unsigned long long qword930;
	unsigned long long qword938;
	unsigned long long qword940;
	unsigned long long qword948;
	unsigned long long qword950;
	unsigned long long qword958;
	unsigned long long qword960;
	unsigned long long qword968;
	unsigned long long qword970;
	unsigned long long qword978;
	unsigned long long qword980;
	unsigned long long qword988;
	unsigned long long qword990;
	unsigned long long qword998;
	unsigned long long qword9A0;
	unsigned long long qword9A8;
	unsigned long long qword9B0;
	unsigned long long qword9B8;
	unsigned long long qword9C0;
	unsigned long long qword9C8;
	unsigned long long qword9D0;
	unsigned long long qword9D8;
	unsigned long long qword9E0;
	unsigned long long qword9E8;
	unsigned long long qword9F0;
	long long qword9F8;
	unsigned long long qwordA00;
	char gapA08[24];
	char byteA20;
};
