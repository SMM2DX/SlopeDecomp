#pragma once

#include <sead/seadDisposer.hpp>

namespace sead {
	#ifndef		SEAD_HEAP_HPP
	#define		SEAD_HEAP_HPP
	struct Heap : public IDisposer {
		enum HeapDirection
		{
			cHeapDirection_Forward = 1,
			cHeapDirection_Reverse = -1
		};
		// WIP
	};
	#endif	//	SEAD_HEAP_HPP
}

