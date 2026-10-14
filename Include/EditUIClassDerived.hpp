#pragma once

#include "UISys/SequenceBase.hpp"

class EditUIClassDerived : public UISys::SequenceBase {
	SEAD_RTTI_OVERRIDE(EditUIClassDerived, UISys::SequenceBase)
	~EditUIClassDerived() override;
};
