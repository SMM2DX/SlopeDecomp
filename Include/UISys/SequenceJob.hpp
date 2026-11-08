#pragma once

#include <sead/seadListImpl.hpp>
#include <oead/prim/seadDelegate.h>

namespace UISys{
	#ifndef		UISYS_SEQUENCEJOB_HPP
	#define		UISYS_SEQUENCEJOB_HPP
	class SequenceJob {
		sead::ListNode m_ListNode;
		//sead::AnyDelegate::UnbindDummy *m_UnbindDummy;
		//int m_Third;	// See UISys::SequenceJobList::insert()
		//int m_Fourth;	// See UISys::SequenceJobList::insert()
	};
	#endif	//	UISYS_SEQUENCEJOB_HPP

	#ifndef		UISYS_SEQUENCEJOBLIST_HPP
	#define		UISYS_SEQUENCEJOBLIST_HPP
	class SequenceJobList {
		sead::OffsetList<SequenceJob> m_OffsetList;
	};
	#endif	//	UISYS_SEQUENCEJOBLIST_HPP
}