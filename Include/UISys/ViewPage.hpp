#pragma once

//#include "ButtonActionCallbackArg.hpp" TEMP
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

	    virtual void onInitialize_(ViewPageInitArg const*);
	    virtual void onCloneParts_(Lp::UI::PartsCtrl *, Lp::UI::PartsCtrlBuilder *);
	    virtual void onPostCreatePartsCtrl_(Lp::UI::PartsCtrlBuilder::PostCreatePartsArg &);
	    virtual void appear(int);
	    virtual void disappear(int);
	    virtual void isAppeared(int);
	    virtual void isDisappeared(int);
	    virtual void isAbleAppear(int);
	    virtual void isAbleDisappear(int);
	    virtual void getLayoutNameByIndex(int);
	    virtual void getLayoutName();
	    virtual void getButton(int);
	    virtual void getButton_2(int);
	    virtual void getKeyItem(int);
	    virtual void getKeyItem_2(int);
	    virtual void ctrlInitCallback_(Lp::UI::PartsCtrlBuilder::CtrlInitArg const&);
	    virtual void getButtonIndex_(Lp::UI::BtnPartsCtrl const*);
	    virtual void getKeyItemIndex_(Lp::UI::KeyItem const*);
	    virtual void createButtonActionCallbackArg_(UISys::ButtonActionCallbackArg &, Lp::UI::BtnPartsCtrl::BtnEventArg const&);
	    virtual void preButtonActionInvoke_(UISys::ButtonActionCallbackArg const&);
	    virtual void checkButtonActionInvoke_(UISys::ButtonActionCallbackArg const&);
	    virtual void postButtonActionInvoke_(UISys::ButtonActionCallbackArg const&);
	    virtual void createKeyActionCallbackArg_(UISys::KeyActionCallbackArg &,Lp::UI::KeyItem::Event, Lp::UI::KeyItem::EventArg const&);
	    virtual void preKeyActionInvoke_(UISys::KeyActionCallbackArg const&);
	    virtual void checkKeyActionInvoke_(UISys::KeyActionCallbackArg const&);
	    virtual void postKeyActionInvoke_(UISys::KeyActionCallbackArg const&);
	    virtual void createCursorActionCallbackArg_(UISys::CursorActionCallbackArg &, Lp::UI::BtnPartsCtrl::DisplayCursorEvent, int);
	    virtual void preCursorActionCallbackArg_(UISys::CursorActionCallbackArg const&);
	    virtual void checkCursorActionCallbackArg_(UISys::CursorActionCallbackArg const&);
	    virtual void postCursorActionCallbackArg_(UISys::CursorActionCallbackArg const&);
	    virtual void createStickActionCallbackArg_(UISys::StickActionCallbackArg &, sead::Vector2<float> const&, Lp::UI::StickItem::EventArg const&);
	    virtual void preStickActionCallbackArg_(UISys::StickActionCallbackArg const&);
	    virtual void checkStickActionCallbackArg_(UISys::StickActionCallbackArg const&);
	    virtual void postStickActionCallbackArg_(UISys::StickActionCallbackArg const&);
	    virtual void checkDecidedButton_(Lp::UI::Control const*);
	};
}