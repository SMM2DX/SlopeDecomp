#pragma once

#include <BasicTypes.hpp>

#include <sead/seadSafeString.hpp>

struct TEMP_EditorObjectID : public sead::SafeString {
	int32 bitflag;
};