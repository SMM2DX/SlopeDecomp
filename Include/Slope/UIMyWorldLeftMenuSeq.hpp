#pragma once

#include <BasicTypes.hpp>

#include <Slope/UISequenceBase.hpp>

namespace Slope {
	#ifndef		SLOPE_UIMYWORLDLEFTMENUSEQ_HPP
	#define		SLOPE_UIMYWORLDLEFTMENUSEQ_HPP
	class UIMyWorldLeftMenuSeq : public UISequenceBase {
		SEAD_RTTI_OVERRIDE(UIMyWorldLeftMenuSeq, UISequenceBase)
		~UIMyWorldLeftMenuSeq() override;

		void sub_40() override;	// Set up Scene Buttons' textures
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

		// NOTE: Currently a direct copy of UIEditLeftMenuSeq.

		// NOTE: "child"(?) of UIMyWorldEditSeq, which is a "child"(?) of 

		void* parentViewPage;														//	0x288 May be misplaced now?
		int64 GAPFILL0;																//	0x290
		int32 GAPFILL1;																//	0x298
		uint32 GAPFILL2; 	// 0 = Skin, 1/2 = Scene, 3 = Timer, 4 = Scroll?		//	0x29C
		sead::PtrArray<Lp::UI::TextureInfo>		SceneButtons_TextureInfo;			//	0x2A0
		char _Y[0x40];
		sead::PtrArray<Lp::Utl::TextureHolder>	SceneButtons_TextureHolder;			//	0x2F0
		char _Z[0x4F0];
		sead::PtrArray<Lp::UI::TextureInfo>		texrureInfoArray2;					//	0x7F0
		char _Y2[0x40];
		sead::PtrArray<Lp::Utl::TextureHolder>	textureHolderArray2;				//	0x840
	};
	#endif	//	SLOPE_UIMYWORLDLEFTMENUSEQ_HPP
	//static_assert(sizeof(UIMyWorldLeftMenuSeq) == 0xC48);
}