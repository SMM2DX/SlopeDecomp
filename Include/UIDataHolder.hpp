#pragma once

#include <BasicTypes.hpp>

#include <sead/seadDisposer.hpp>

#include <UIEditInfoHeap.hpp>

#ifndef		UIDATAHOLDER_HPP
#define		UIDATAHOLDER_HPP
struct UIDataHolder {
	virtual ~UIDataHolder();
	sead::IDisposer disposer;
	char _0[0x8];
	void* pUNK1;
	void* pUNK2;
	void* pUNK3;
	void* pUNK4;
	void* pUNK5;
	void* pUNK6;
	void* pUNK7;
	UIEditInfoHeap* pUIEditInfoHeap;
	void* pUICourseRobotInfoHeap;
	void* pUIQuestInfoHeap;
	void* pUILessonMenuInfoHeap;
	void* pUIMatchingInfoHeap;
	void* pCmn_TagWindowInfoHeap;
	void* pUINationalFlagInfo;
	void* pUICommentStampResInfo;
	void* pUIDummyTextureInfo;
	void* pUIMyWorldRobotInfoHeap;
	void* pUIMyWorldInfoHeap;
	char _1[0xB0];
	void* pTempJpegHeap;
	int32 dword_178;
	void* qword_180;
};
#endif	//	UIDATAHOLDER_HPP
static_assert(sizeof(UIDataHolder) == 0x188);