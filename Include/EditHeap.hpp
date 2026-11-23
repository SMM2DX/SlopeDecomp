#pragma once

#include <BasicTypes.hpp>

#include <sead/seadDisposer.hpp>
#include <sead/seadListImpl.hpp>

#ifndef		EDITHEAP_HPP
#define		EDITHEAP_HPP
struct EditHeap {
	virtual ~EditHeap();
	sead::IDisposer disposer;			//	0x008
	int32 array[421];					//	0x028	//	even indexes map to actual objects, odd indexes... ???
	char _Z[4];							//	0x6BC	//	why is this not just lumped in with the above ???
	sead::OffsetList offsetList_6C0;	//	0x6C0
	sead::OffsetList offsetList_6D8;	//	0x6D8
	int64 qword_6F0;					//	0x6F0
	int64 qword_6F8;					//	0x6F8
};
#endif	//	EDITHEAP_HPP
static_assert(sizeof(EditHeap) == 0x700);
