#pragma once

#include "EditUIClass.hpp"

class EditUIClassDerived : public EditUIClass {
	SEAD_RTTI_OVERRIDE(EditUIClassDerived, EditUIClass)
	~EditUIClassDerived() override;
};
