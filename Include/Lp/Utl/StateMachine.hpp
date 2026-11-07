#pragma once

#include <sead/seadBuffer.hpp>
#include <sead/seadSafeString.hpp>
#include <sead/seadHeap.hpp>

namespace Lp::Utl {
	
	namespace impl {
		struct Dummy { int mDummy; };
	}
	
	struct StateMachine {
		template<typename T>
		struct Delegate {
			using EnterFuncPtr = void (T::*)();
			using ExecFuncPtr = void (T::*)();
			using ExitFuncPtr = void (T::*)(int); 
			
			private:
			T* mOwner;
			EnterFuncPtr mEnter;
			ExecFuncPtr mExec;
			ExitFuncPtr mExit;
		
			public:
			virtual void enter () { mOwner.*mEnter(); }
			virtual void exec () { mOwner.*mExec(); }
			virtual void exit (int arg) { mOwner.*mExit(arg); }
		};

		using DelegateDummy = Delegate<impl::Dummy>;
		static_assert(sizeof(DelegateDummy) == 0x40, "");

		int mCurIndex;
		int mCurStateCounter;
		int mPrevIndex;
		int mPrevStateCounter;
		int mFirstIndex;
		int mMaxStateNum;
		bool field_20;
		bool field_21;

		sead::Buffer<DelegateDummy> mStateBuffer;
		sead::Buffer<sead::SafeString> mStateNameBuffer;

		virtual ~StateMachine();

		StateMachine();
		sead::SafeString const* getStateName(int) const;
		void initialize(int, int, sead::Heap*);
		void registStateName(int, sead::SafeString const&);
		void copyState(Lp::Utl::StateMachine const&);
		void changeFirstState();
		void changeState_(int);
		void enterState_();
		void changeState(int);
		void exitState_(int);
		bool changeStateIfDiff(int);
		void executeState();
		void execState_();

		template<typename T>
		Delegate<T>* getDelegate(int index) {
			return reinterpret_cast<sead::Buffer<Delegate<T>>*>(&mStateBuffer)->at(index);
		}
		template<typename T>
		void registstate(int index, T* ptr, Delegate<T>::EnterFuncPtr enter, Delegate<T>::ExecFuncPtr exec, Delegate<T>::ExitFuncPtr exit) {
			*getDelegate<T>(index) = { ptr, enter, exec, exit };
		}


		int field_50;
		char field_54;
	};
}