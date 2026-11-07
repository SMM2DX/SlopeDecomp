#pragma once

#include <sead/seadHeap.hpp>
#include <sead/seadListImpl.hpp>
#include <IDAClangDestructorFix.hpp>

namespace sead {
	#ifndef		SEAD_IDISPOSER_HPP
	#define		SEAD_IDISPOSER_HPP
	struct IDisposer {
		enum class HeapNullOption
		{
			AlwaysUseSpecifiedHeap = 0,
			UseSpecifiedOrContainHeap = 1,
			DoNotAppendDisposerIfNoHeapSpecified = 2,
			UseSpecifiedOrCurrentHeap = 3,
		};

		virtual ~IDisposer();
		#ifndef		IDACLANG_DESTRUCTOR_FIX
		virtual void destructor_2();
		#endif	//	IDACLANG_DESTRUCTOR_FIX

		sead::Heap* mDisposerHeap;
		sead::ListNode mListNode;
	};
	#endif	//	SEAD_IDISPOSER_HPP
}

