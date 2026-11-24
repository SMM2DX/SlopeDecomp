#pragma once

#include <BasicTypes.hpp>

#include <sead/seadDisposer.hpp>

#include <Slope/CustomEnums.hpp>

struct level_info {
	virtual ~level_info();
	int32 dword_8;			//	0x08
	int32 isEdit;			//	0x0C
	int32 dword_10;			//	0x10
	int32 dword_14;			//	0x14
	int32 dword_18;			//	0x18
	Skin curSkin;			//	0x1C
	SceneSet curSceneSet;	//	0x20
	SceneHour curSceneHour;	//	0x24
	int32 dword_28;			//	0x28
	void* qword_30;			//	0x30	//	size 0x10
	void* qword_38;			//	0x38	//	size 0x04
	void* qword_40;			//	0x40	//	size 0x08
	void* qword_48;			//	0x48	//	size 0x24
	void* qword_50;			//	0x50	//	size 0x10
	int32 qword_58;			//	0x58
	int32 qword_5C;			//	0x5C
	int32 qword_60;			//	0x60
	void* qword_68;			//	0x68	//	size 0x0C
	int32 qword_70;			//	0x70
	int32 qword_74;			//	0x74
	void* qword_78;			//	0x78	//	size 0x10
	char byte_80;			//	0x80
	char byte_81;			//	0x80
	char byte_82;			//	0x80
	char byte_83;			//	0x80
	char byte_84;			//	0x84
};

struct StateHolder : public sead::IDisposer {
	int64 qword_20;
	int64 qword_28;
	level_info* levelInfo;
	int64 qword_38;
	int64 qword_40;
	int64 qword_48;
};