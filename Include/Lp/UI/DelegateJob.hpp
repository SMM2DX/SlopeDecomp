#pragma once

#include <Lp/UI/Job.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_DELEGATEJOB_HPP
	#define		LP_UI_DELEGATEJOB_HPP
	struct DelegateJob : public Job {
		~DelegateJob() override;
		virtual void onProcess();

		void* vtbl;
		void* parent;
		void* function;
		int64_t number;
	};
	#endif	//	LP_UI_DELEGATEJOB_HPP
	static_assert(sizeof(DelegateJob) == 0x98);
}