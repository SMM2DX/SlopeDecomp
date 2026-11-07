#pragma once

#include <nn/os/os_MutexTypes.h>
#include <sead/seadDisposer.hpp>
#include <IDAClangDestructorFix.hpp>

namespace sead {
	#ifndef		SEAD_CRITICALSECTION_HPP
	#define		SEAD_CRITICALSECTION_HPP
	struct CriticalSection : sead::IDisposer {
		~CriticalSection() override;
		#ifndef		IDACLANG_DESTRUCTOR_FIX
		void destructor_2() override;
		#endif	//	IDACLANG_DESTRUCTOR_FIX
		
		nn::os::MutexType mCriticalSectionInner;
	};
	#endif	//	SEAD_CRITICALSECTION_HPP
}