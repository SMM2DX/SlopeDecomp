#pragma once

#include <BasicTypes.hpp>

#include <Slope/UISequenceBase.hpp>
#include <Slope/UIEditMainPage.hpp>

namespace Slope {
	#ifndef		SLOPE_UIEDITLEFTMENUSEQ_HPP
	#define		SLOPE_UIEDITLEFTMENUSEQ_HPP
	class UIEditLeftMenuSeq : public UISequenceBase {
		//	00000071029897E0
		SEAD_RTTI_OVERRIDE(UIEditLeftMenuSeq, UISequenceBase)
		~UIEditLeftMenuSeq() override;

		void sub_40() override;	// Set up Scene & Skin Buttons' textures
		void sub_56() override;
		void sub_59() override;	// stateMachine2.field_50 |= 1
		void sub_60() override;	// nullsub
		void sub_65() override;	// stateMachine2.field_50 |= 8
		void sub_67() override;	// SIX SEVEEEN! I'm such a fat fucking chud.
		void sub_68() override;
		void sub_73() override;	// nullsub
		void sub_74(UISys::ButtonActionCallbackArg *) override; // button_index_handler_thing
		void sub_77() override;	// nullsub
		void sub_101() override;

		UIEditMainPage* parentViewPage;												//	0x288 May be misplaced now?
		int64 qword_290;															//	0x290
		int32 dword_298;															//	0x298
		uint32 subMenuIndex; 	// 0 = Skin, 1/2 = Scene, 3 = Timer, 4 = Scroll?	//	0x29C
		sead::PtrArray<Lp::UI::TextureInfo>		SkinButtons_TextureInfo;			//	0x2A0
		sead::PtrArray<Lp::Utl::TextureHolder>	SkinButtons_TextureHolder;			//	0x2B0
		sead::PtrArray<Lp::UI::TextureInfo>		SceneButtons_TextureInfo;			//	0x2C0
		sead::PtrArray<Lp::Utl::TextureHolder>	SceneButtons_TextureHolder;			//	0x2D0
		Lp::UI::TextureInfo						SceneSmallButton_TextureInfo;		//	0x2E0
		Lp::Utl::TextureHolder					SceneSmallButton_TextureHolder;		//	0x300
		Lp::UI::TextureInfo						UNK_TextureInfo;					//	0x790
		Lp::Utl::TextureHolder					UNK_TextureHolder;					//	0x7B0
		int32 dword_C40;															//	0xC40
		char byte_C44;																//	0xC44
	};
	#endif	//	SLOPE_UIEDITLEFTMENUSEQ_HPP
	static_assert(sizeof(UIEditLeftMenuSeq) == 0xC48);
}