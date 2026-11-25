#pragma once

#include <BasicTypes.hpp>

#include <Lp/UI/Control.hpp>

namespace Lp::UI{
	#ifndef		LP_UI_PARTSCTRL_HPP
	#define		LP_UI_PARTSCTRL_HPP
	struct PartsCtrl : public Control {
		//	00000071028381A0
		SEAD_RTTI_OVERRIDE(PartsCtrl, Control);
		~PartsCtrl() override;
		virtual void isFadeIn();
		virtual void isFadeOut();
		virtual void sub_15();
		virtual void playLoopAnim();
		virtual void playCurrentLoopAnim();
		virtual void stopLoopAnim();
		virtual void stopCurrentLoopAnim();
		virtual void playLoopRandomAnim();
		virtual void stopLoopRandomAnim();
		virtual void playLoopAnimForIn();
		virtual void playWaitAnim();
		virtual void playCurrentWaitAnim();
		virtual void stopWaitAnim();
		virtual void stopCurrentWaitAnim();
		virtual void onCreateClonePartsCtrlInner();
		virtual void onInitializeXLinkInner();
		virtual void onInitializeXLinkInnerOld();
		virtual void onInitializedChild();

		int64 qword_1B0;					//	0x1B0
		int64 qword_1B8;					//	0x1B8
		int64 qword_1C0;					//	0x1C0
		int64 qword_1C8;					//	0x1C8
		int64 qword_1D0;					//	0x1D0
		sead::OffsetList *list_1D8;			//	0x1D8
		int64 qword_1E0;					//	0x1E0
		int64 qword_1E8;					//	0x1E8
		int64 qword_1F0;					//	0x1F0
		char byte_1F8;						//	0x1F8
	};
	#endif	//	LP_UI_PARTSCTRL_HPP
	static_assert(sizeof(PartsCtrl) == 0x200);

	#ifndef		LP_UI_PARTSCTRLBUILDER_HPP
	#define		LP_UI_PARTSCTRLBUILDER_HPP
	struct PartsCtrlBuilder {
		struct PostCreatePartsArg{};
		struct CtrlInitArg{};
	};
	#endif	//	LP_UI_PARTSCTRLBUILDER_HPP
}