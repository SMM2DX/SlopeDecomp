#pragma once

#include "sead/include/container/seadBuffer.h"
#include "sead/include/prim/seadSafeString.h"

namespace Lp::Utl {
	template <typename T> struct StateMachine {
		template<typename TT> struct Delegate {
			using EnterFuncPtr = void (TT::*)();
			using ExecFuncPtr = void (TT::*)();
			using ExitFuncPtr = void (TT::*)(int);

			private:
			TT* mOwner;
			EnterFuncPtr mEnter;
			ExecFuncPtr mExec;
			ExitFuncPtr mExit;

			public:
			virtual void enter () { mOwner.*mEnter(); }
			virtual void exec () { mOwner.*mExec(); }
			virtual void exit (int arg) { mOwner.*mExit(arg); }
		};

		using DelegateDummy = Delegate<T>;

		int mCurIndex;
		int mCurStateCounter;
		int mPrevIndex;
		int mPrevStateCounter;
		int mFirstStateIndex;
		int mMaxStateNum;
		bool field_20;
		bool field_21;

		sead::Buffer<DelegateDummy> mStateBuffer;
		sead::Buffer<sead::SafeString> mStateNameBuffer;
	};
}
