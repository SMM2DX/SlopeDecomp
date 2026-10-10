#pragma once

#include "../Lp/Sys/Task/ProjTaskBase.hpp"
#include "../sead/framework/seadMethodTree.h"

namespace UISys{
	class SequenceMgr : public Lp::Sys::ProjTaskBase {
		~SequenceMgr() override;
		SEAD_RTTI_OVERRIDE(SequenceMgr, Lp::Sys::ProjTaskBase)

		char gapA[0xC0];
		long long temp1;
		char gapB[0x38];
		long long temp2;
		char gapC[0xB0];
		char temp3;

		sead::MethodTreeNode methodTreeNode1;
		sead::MethodTreeNode methodTreeNode2;
		sead::MethodTreeNode methodTreeNode3;
		long long temp4;
		long long temp5;
		long long temp6;
		long long temp7;
		long long temp8;
		long long temp9;
		char gap[0x40];
		long long tempA;

		void prepare() override;
	};
	static_assert(sizeof(SequenceMgr) == 0x568);
}