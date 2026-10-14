#pragma once

#include "EditUIClass_intermediate.hpp"

class UIEditLeftMenuSeq : public EditUIClass_intermediate {
	SEAD_RTTI_OVERRIDE(UIEditLeftMenuSeq, EditUIClass_intermediate)
	~UIEditLeftMenuSeq() override;

	void sub_40() override;	// Lyt_E_Scene_[scene]_00
	void sub_56() override;
	void sub_59() override;	// stateMachine2.field_50 |= 1
	void sub_60() override;	// nullsub
	void sub_65() override;	// stateMachine2.field_50 |= 8
	void sub_67() override;	// SIX SEVEEEN! I'm such a fat fucking chud.
	void sub_68() override;
	void sub_73() override;	// nullsub
	void sub_74(UISys::ButtonActionCallbackArg *) override; // button_index_handler_thing
	void sub_77() override;	// nullsub
	void sub_101() override;
};
