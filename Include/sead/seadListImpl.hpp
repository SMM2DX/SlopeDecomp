#pragma once

namespace sead {
	#ifndef		SEAD_LISTNODE_HPP
	#define		SEAD_LISTNODE_HPP
	struct ListNode {
		sead::ListNode *mPrev;
		sead::ListNode *mNext;
	};
	#endif	//	SEAD_LISTNODE_HPP

	#ifndef		SEAD_LISTIMPL_HPP
	#define		SEAD_LISTIMPL_HPP
	struct ListImpl {
		sead::ListNode mStartEnd;
		int mCount;
	};
	#endif	//	SEAD_LISTIMPL_HPP

	#ifndef		SEAD_OFFSETLIST_HPP
	#define		SEAD_OFFSETLIST_HPP
	template <typename T> struct OffsetList : public ListImpl {
		int mOffset;
	};
	#endif	//	SEAD_OFFSETLIST_HPP
}