#pragma once

#include <BasicTypes.hpp>

#include <Slope/UIEditMainSeq.hpp>

#ifndef		UIEDITINFOHEAP_HPP
#define		UIEDITINFOHEAP_HPP
struct UIEditInfoHeap {
	virtual ~UIEditInfoHeap();
	Slope::UIEditMainSeq* pUIEditMainSeq;
	char _Z[0x1000];
};
#endif	//	UIEDITINFOHEAP_HPP
//static_assert(sizeof(UIEditInfoHeap) == 0x188);