#pragma once

#include <BasicTypes.hpp>

#include <Slope/UISequenceBase.hpp>

namespace Slope {
	#ifndef		SLOPE_UIEDITMAINSEQ_HPP
	#define		SLOPE_UIEDITMAINSEQ_HPP
	class UIEditMainSeq : public UISequenceBase {
		//	000000710298A7C8
		SEAD_RTTI_OVERRIDE(UIEditMainSeq, UISequenceBase)
		~UIEditMainSeq() override;

		char _0[0x10];
		Lp::Utl::StateMachine stateMachine_1;		//	0x298
		char _1[0x30];
		Lp::UI::TextureInfo textureInfo_1;			//	0x318
		Lp::Utl::TextureHolder textureHolder_1;		//	0x338
		char _2[0xD0];
		Lp::UI::TextureInfo textureInfo_2;			//	0x898
		Lp::Utl::TextureHolder textureHolder_2;		//	0x8B8
		Lp::UI::TextureInfo textureInfo_3;			//	0xD48
		Lp::Utl::TextureHolder textureHolder_3;		//	0xD68
		Lp::UI::TextureInfo textureInfo_4;			//	0x11F8
		Lp::Utl::TextureHolder textureHolder_4;		//	0x1218
		char _4[0x8000];
	};
	#endif	//	SLOPE_UIEDITMAINSEQ_HPP
}
