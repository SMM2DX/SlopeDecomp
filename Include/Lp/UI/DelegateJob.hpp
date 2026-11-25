#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/Job.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_DELEGATEJOB_HPP
	#define		LP_UI_DELEGATEJOB_HPP
	struct DelegateJob : public Job {
		//	0000007102837820 (?)
		~DelegateJob() override;
		virtual void onProcess();

		void* vtbl;
		void* parent;
		void* function;
		int64 number;
	};
	#endif	//	LP_UI_DELEGATEJOB_HPP
	static_assert(sizeof(DelegateJob) == 0x98);
}