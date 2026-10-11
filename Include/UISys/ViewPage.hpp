#pragma once

#include "../Lp/UI/Page.hpp"
#include "../Lp/UI/Control.hpp"
#include "../sead/hostio/seadHostIOEventListener.h"
#include "../sead/hostio/seadHostIOReflexible.h"
#include "../sead/math/seadVector.hpp"

namespace Lp::UI{
	struct PartsCtrl;
	struct PartsCtrlBuilder{
		struct PostCreatePartsArg;
		struct CtrlInitArg;
	};
	struct BtnPartsCtrl{
		struct BtnEventArg;
		struct DisplayCursorEvent;
	};
	struct KeyItem{
		struct Event;
		struct EventArg;
	};
	struct StickItem{
		struct EventArg;
	};
}

namespace UISys{
	struct ButtonActionCallbackArg;
	struct KeyActionCallbackArg;
	struct CursorActionCallbackArg;
	struct StickActionCallbackArg;

	class ViewPage : public Lp::UI::Page {
		SEAD_RTTI_OVERRIDE(ViewPage, Lp::UI::Page)
		~ViewPage() override;
		uintptr_t getClassInfo() override;
        void onPreCalc() override;
        void onPostCalc() override;
        void genMessage(sead::hostio::Context*) override;
        void listenPropertyEvent(sead::hostio::PropertyEvent const*) override;

		struct ViewPageInitArg;

	    virtual void sub_24();
	    virtual void sub_25();
	    virtual void sub_26();
	    virtual void sub_27();
	    virtual void sub_28();
	    virtual void sub_29();
	    virtual void sub_30();
	    virtual void sub_31();
	    virtual void sub_32();
	    virtual void sub_33();
	    virtual void sub_34();
	    virtual void sub_35();
	    virtual void sub_36();
	    virtual void sub_37();
	    virtual void sub_38();
	    virtual void sub_39();
	    virtual void sub_40();
	    virtual void sub_41();
	    virtual void sub_42();
	    virtual void sub_43();
	    virtual void sub_44();
	    virtual void sub_45();
	    virtual void sub_46();
	    virtual void sub_47();
	    virtual void sub_48();
	    virtual void sub_49();
	    virtual void sub_50();
	    virtual void sub_51();
	    virtual void ctrlInitCallback_(Lp::UI::PartsCtrlBuilder::CtrlInitArg const&);

	    virtual unsigned int getButtonIndex_(Lp::UI::BtnPartsCtrl const*);
	    virtual unsigned int getKeyItemIndex_(Lp::UI::KeyItem const*);

	    virtual void createButtonActionCallbackArg_(UISys::ButtonActionCallbackArg &,Lp::UI::BtnPartsCtrl::BtnEventArg const&);
	    virtual void preButtonActionInvoke_(UISys::ButtonActionCallbackArg const&);
	    virtual void checkButtonActionInvoke_(UISys::ButtonActionCallbackArg const&);
	    virtual void postButtonActionInvoke_(UISys::ButtonActionCallbackArg const&);
		
	    virtual void createKeyActionCallbackArg_(UISys::KeyActionCallbackArg &,Lp::UI::KeyItem::Event,Lp::UI::KeyItem::EventArg const&);
	    virtual void preKeyActionInvoke_(UISys::KeyActionCallbackArg const&);
	    virtual void checkKeyActionInvoke_(UISys::KeyActionCallbackArg const&);
	    virtual void postKeyActionInvoke_(UISys::KeyActionCallbackArg const&);
		
	    virtual void sub_63();
	    virtual void sub_64();

	    virtual void createCursorActionCallbackArg_(UISys::CursorActionCallbackArg &,Lp::UI::BtnPartsCtrl::DisplayCursorEvent,int);
	    virtual void preCursorActionInvoke_(UISys::CursorActionCallbackArg const&);
	    virtual void checkCursorActionInvoke_(UISys::CursorActionCallbackArg const&);
	    virtual void postCursorActionInvoke_(UISys::CursorActionCallbackArg const&);
		
	    virtual void createStickActionCallbackArg_(UISys::StickActionCallbackArg &,sead::Vector2<float> const&,Lp::UI::StickItem::EventArg const&);
	    virtual void preStickActionInvoke_(UISys::StickActionCallbackArg const&);
	    virtual void checkStickActionInvoke_(UISys::StickActionCallbackArg const&);
	    virtual void postStickActionInvoke_(UISys::StickActionCallbackArg const&);
		
	    virtual void sub_73();
	    virtual void sub_74();
	    virtual void sub_75();
	};
}