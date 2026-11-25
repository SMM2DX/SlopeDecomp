#pragma once

#include <BasicTypes.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_JOB_HPP
	#define		LP_UI_JOB_HPP
	struct Job {
		//	00000071028377F8
		virtual ~Job();

		int64 qword_00;
		int64 qword_08;
		void* qword_10;
		void* qword_18;
		int64 qword_20;
		void* qword_28;
		void* qword_30;
		int64 qword_38;
		void* qword_40;
		void* qword_48;
		int64 qword_50;
		void* qword_58;
		void* qword_60;
		int64 qword_68;
	};
	#endif	//	LP_UI_JOB_HPP
	static_assert(sizeof(Job) == 0x78);
}