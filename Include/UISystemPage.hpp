#pragma once

#include <sead/seadSafeString.hpp>
#include <sead/seadRuntimeTypeInfo.hpp>

class UISystemPage {
	SEAD_RTTI_BASE(UISystemPage)
	virtual ~UISystemPage();
	virtual sead::SafeString sub_5();
};