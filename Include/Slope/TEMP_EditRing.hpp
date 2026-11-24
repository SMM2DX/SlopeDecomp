#pragma once

#include <BasicTypes.hpp>

#include <sead/seadBuffer.hpp>

#include <Lp/Utl/StateMachine.hpp>
#include <Lp/Utl/TextureHolder.hpp>
#include <Lp/UI/TextureInfo.hpp>
#include <Lp/UI/TempItemHandle.hpp>

#include <UISys/struct_temp_09.hpp>

#include <Slope/CustomEnums.hpp>


namespace Slope {
	#ifndef		SLOPE_EDITRING_HPP
	#define		SLOPE_EDITRING_HPP
	class EditRing {
		char _0[0x238];
		sead::Buffer<Lp::UI::TempItemHandle>* tempItemHandleBuffer;
		char _1[0x58];
		Lp::Utl::StateMachine stateMachine;
		char _1a[0x30];
		Lp::UI::TextureInfo textureInfo;
		Lp::Utl::TextureHolder textureHolder;
		char _aa[0xEE0];
		uint32 curRingIndex;
		uint32 newRingIndex;
		uint32 maxRingIndex;
		int32* ringItemCountArray;
		int32 unk_2;
		Skin curSkin;
		char _2a[0x4];
		SceneSet curSceneSet;
		SceneHour curSceneHour;
		char _2[0x18];
		int32 isSoundEffects;
		char _3[0x50];
		temp_9_t* resFile;
		char _Z[0x1000];
	};
	#endif	//	SLOPE_EDITRING_HPP
}
