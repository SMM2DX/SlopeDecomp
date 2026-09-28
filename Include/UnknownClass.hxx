#pragma once

#include "ActorBase.hxx"

#include "sead/include/prim/seadRuntimeTypeInfo.h"

class UnknownClass {
	SEAD_RTTI_BASE(ActorBase)
	virtual void sub_3();
	virtual void sub_4();
	virtual void sub_5();
	virtual void sub_6();
	virtual void sub_7();
	virtual void sub_8();
	virtual void sub_9();

	ActorBase actorBase;
	char gap0[216];
};

#define UnknownClass 1
