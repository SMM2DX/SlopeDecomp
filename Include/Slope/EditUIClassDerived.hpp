#pragma once

#include <BasicTypes.hpp>

#include <Slope/EditUIClass_intermediate.hpp>

class EditUIClassDerived : public EditUIClass_intermediate {
	SEAD_RTTI_OVERRIDE(EditUIClassDerived, UISys::SequenceBase)
	~EditUIClassDerived() override;
};
