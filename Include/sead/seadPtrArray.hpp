#pragma once

namespace sead{
	#ifndef		SEAD_PTRARRAYIMPL_HPP
	#define		SEAD_PTRARRAYIMPL_HPP
	struct PtrArrayImpl{
		int mPtrNum;
		int mPtrNumMax;
		void **mPtrs;
	};
	#endif	//	SEAD_PTRARRAYIMPL_HPP

	// IDK if this is accurate to sead but it makes the code look nicer imo
	#ifndef		SEAD_PTRARRAY_HPP
	#define		SEAD_PTRARRAY_HPP
	template <typename T> struct PtrArray{
		int mPtrNum;
		int mPtrNumMax;
		T **mPtrs;
	};
	#endif	//	SEAD_PTRARRAY_HPP
}
