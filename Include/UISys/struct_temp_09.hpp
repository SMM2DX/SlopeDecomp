#pragma once

#include <Slope/CustomEnums.hpp>

struct struct_v20 {
  u8 _0[84];
  int8_t byte54;
};

struct struct_v19 {
  u8 _0[528];
  struct_v20 *pstruct_v20;
};

struct temp_9_t {
	u8 _0[0x238];
	struct_v19 *qword_238;
	u8 _1[0xB0];
	int64_t changeBitFlag;
	u8 _2[0x13CC];
	Skin		prevSkin;
	Skin		nextSkin;
	SceneSet	prevSceneSet;
	SceneHour	prevSceneHour;
	SceneSet	nextSceneSet;
	SceneHour	nextSceneHour;
};