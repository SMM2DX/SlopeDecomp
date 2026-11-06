#pragma once

#include "sead/seadSafeString.hpp"
#include "seadOG/prim/seadRuntimeTypeInfo.h"

class UISystemPage {
	SEAD_RTTI_BASE(UISystemPage)
	virtual ~UISystemPage();
	virtual sead::SafeString sub_5();
};