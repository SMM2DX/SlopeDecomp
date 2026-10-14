#pragma once

#include "SequenceBase.hpp"

namespace UISys {
	class ISelectCursorSubSequence : public UISys::SequenceBase {
		SEAD_RTTI_OVERRIDE(ISelectCursorSubSequence, UISys::SequenceBase)
		~ISelectCursorSubSequence() override;

		void sub_19() override;
		void sub_22() override;
		void sub_23() override;
		void sub_24() override;
		void sub_29() override;
		void sub_30() override;
		void sub_33() override;
		void sub_34() override;

		virtual void updateCursor_();
		virtual void stateEnterInit();
		virtual void stateInit();
		virtual void stateExitInit(int);
		virtual void stateEnterIdle();
		virtual void stateIdle();
		virtual void stateExitIdle(int);
		virtual void stateEnterAppear();
		virtual void stateAppear();
		virtual void stateExitAppear(int);
		virtual void stateEnterPlay();
		virtual void statePlay();
		virtual void stateExitPlay(int);
		virtual void stateEnterDisappear();
		virtual void stateDisappear();
		virtual void stateExitDisappear(int);
		virtual void stateEnterDecideOut();
		virtual void stateDecideOut();
		virtual void stateExitDecideOut(int);
	};
}
