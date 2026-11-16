#pragma once

#include <BasicTypes.hpp>

#include <Slope/CustomEnums.hpp>

struct struct_v20 {
  char _0[84];
  int16 byte54;
};

struct struct_v19 {
  char _0[528];
  struct_v20 *pstruct_v20;
};

struct temp_9_t {
	char _0[0x238];
	struct_v19 *qword_238;
	char _1[0xB0];
	int64 changeBitFlag;
	char _2[0x13CC];
	Skin		curSkin;
	Skin		nextSkin;
	SceneSet	curSceneSet;
	SceneHour	curSceneHour;
	SceneSet	nextSceneSet;
	SceneHour	nextSceneHour;
};