#pragma once

#include <BasicTypes.hpp>

#include <sead/seadListImpl.hpp>

namespace UISys{
	#ifndef		UISYS_SEQUENCEJOB_HPP
	#define		UISYS_SEQUENCEJOB_HPP
	class SequenceJob {
		virtual void invoke();
		virtual void clone();
		virtual void isNoDummy();

		int64 temp_08;
		int64 temp_10;
		void* parent;
		void* function;
		int64 temp_28;
		int64 temp_30;
	};
	#endif	//	UISYS_SEQUENCEJOB_HPP

	#ifndef		UISYS_SEQUENCEJOBLIST_HPP
	#define		UISYS_SEQUENCEJOBLIST_HPP
	class SequenceJobList {
		sead::OffsetList m_OffsetList;
	};
	#endif	//	UISYS_SEQUENCEJOBLIST_HPP
}