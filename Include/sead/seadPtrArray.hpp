

namespace sead{
	#ifndef		SEAD_PTRARRAYIMPL_HPP
	#define		SEAD_PTRARRAYIMPL_HPP
	struct PtrArrayImpl{
		int mPtrNum;
		int mPtrNumMax;
		void **mPtrs;
	};
	#endif	//	SEAD_PTRARRAYIMPL_HPP
}