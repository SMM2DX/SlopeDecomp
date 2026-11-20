#pragma once

#include <BasicTypes.hpp>

#include <sead/seadBuffer.hpp>

#include <Lp/UI/PriorityPage.hpp>
#include <Lp/UI/Control.hpp>
#include <Lp/UI/PartsCtrl.hpp>
#include <Lp/UI/BtnPartsCtrl.hpp>
#include <Lp/UI/KeyItem.hpp>
#include <Lp/UI/StickItem.hpp>

namespace UISys{
	struct ButtonActionCallbackArg;
	struct KeyActionCallbackArg;
	struct CursorActionCallbackArg;
	struct StickActionCallbackArg;

	#ifndef		UISYS_VIEWPAGE_HPP
	#define		UISYS_VIEWPAGE_HPP
	class ViewPage : public Lp::UI::PriorityPage {
		SEAD_RTTI_OVERRIDE(ViewPage, Lp::UI::PriorityPage)
		~ViewPage() override;
		void* getClassInfo() override;
        void onPreCalc() override;
        void onPostCalc() override;

		struct ViewPageInitArg;

	    virtual void sub_24();	// onInitiailize_()
	    virtual void sub_25();	// onCloneParts_()
	    virtual void sub_26();	// onPostCreatePartsCtrl_
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
	    virtual void getLayoutNameByIndex(int);
	    virtual void getLayoutName();
	    virtual Lp::UI::BtnPartsCtrl* getButton(int);
	    virtual Lp::UI::BtnPartsCtrl* getButton(int) const;
	    virtual Lp::UI::KeyItem* getKeyItem(int);
	    virtual Lp::UI::KeyItem* getKeyItem(int) const;
	    virtual int sub_52();
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
		
	    virtual void sub_64();
	    virtual void sub_65();

	    virtual void createCursorActionCallbackArg_(UISys::CursorActionCallbackArg &,Lp::UI::BtnPartsCtrl::DisplayCursorEvent,int);
	    virtual void preCursorActionInvoke_(UISys::CursorActionCallbackArg const&);
	    virtual void checkCursorActionInvoke_(UISys::CursorActionCallbackArg const&);
	    virtual void postCursorActionInvoke_(UISys::CursorActionCallbackArg const&);
		
	    virtual void createStickActionCallbackArg_();//UISys::StickActionCallbackArg &,sead::Vector2<float> const&,Lp::UI::StickItem::EventArg const&);
	    virtual void preStickActionInvoke_(UISys::StickActionCallbackArg const&);
	    virtual void checkStickActionInvoke_(UISys::StickActionCallbackArg const&);
	    virtual void postStickActionInvoke_(UISys::StickActionCallbackArg const&);
		
	    virtual void checkDecidedButton_(Lp::UI::Control const*);

		sead::Buffer<Lp::UI::Control*> controlBuffer;			//	0x3F0
		int dword_400;
		int64 qword_408;
		int64 qword_410;
		int64 qword_418;
		int64 qword_420;
		int64 qword_428;
		int64 qword_430;
		int64 qword_438;
		int64 qword_440;
		int dword_448;
		int64 qword_450;
		int64 qword_458;
		int64 qword_460;
		int64 qword_468;
		int64 qword_470;
		int64 qword_478;
		int64 qword_480;
		void* qword_488;
		int64 qword_490;
		int64 qword_498;
		int64 qword_4A0;
		void* qword_4A8;
		int64 qword_4B0;
		int64 qword_4B8;
		int64 qword_4C0;
		void* qword_4C8;
		int64 qword_4D0;
		int64 qword_4D8;
		int64 qword_4E0;
		void* qword_4E8;
		int64 qword_4F0;
		int64 qword_4F8;
		int64 qword_500;
		int64 qword_508;
		int dword_510;
		int64 dword_518;
		int qword_520;
		int64 dword_528;
		int qword_530;
		sead::OffsetList list_538;			//	0x538
		sead::OffsetList list_550;			//	0x550
	};
	#endif	//	UISYS_VIEWPAGE_HPP
	static_assert(sizeof(ViewPage) == 0x568);
}