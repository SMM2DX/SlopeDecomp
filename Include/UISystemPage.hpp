#pragma once

#include "sead/prim/seadSafeString.hpp"
#include "sead/prim/seadRuntimeTypeInfo.h"

class UISystemPage {
	SEAD_RTTI_BASE(UISystemPage)
	virtual ~UISystemPage();
	virtual sead::SafeString sub_5();
};