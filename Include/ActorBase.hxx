#pragma once

#include "ActorCreateParam.hxx"

#include "sead/container/seadOffsetList.h"
#include "sead/heap/seadHeap.h"
#include "sead/prim/seadBitFlag.h"
#include "sead/prim/seadRuntimeTypeInfo.h"

class ActorMgr;
#ifndef UnknownClass
class UnknownClass;
#endif

class ActorBase {
	public:
		enum MainState
		{
			cState_None = 0,
			cState_Failed,
			cState_Success,
			cState_Wait
		};

		enum Result
		{
			cResult_Wait = 0,
			cResult_Success,
			cResult_Failed
		};

	SEAD_RTTI_BASE(ActorBase)
	virtual char* getClassName();
	virtual ~ActorBase();
	virtual bool sub_6();					//returns 1
	virtual Result sub_7();					//
	virtual void sub_8(MainState state);	//
	virtual bool sub_9();					//returns 1
	virtual bool sub_10();					//returns 0
	virtual void nullsub_11();
	virtual void sub_12(MainState state);	//
	virtual void nullsub_13();
	virtual bool sub_14();					//returns 1
	virtual bool sub_15();					//returns 1
	virtual void nullsub_16();
	virtual bool sub_17();					//returns 1
	virtual Result sub_18();				//
	virtual void nullsub_19();
	virtual int sub_20();					//returns 2
	virtual void sub_21();					//unknown return type
	virtual Profile sub_22();				//
	virtual bool sub_23();					//returns 0
	virtual sead::Heap sub_24();			//
	virtual UnknownClass sub_25();			//returns UnknownClass
	virtual void nullsub_26();
	virtual void nullsub_27();
	virtual void nullsub_28();
	virtual void nullsub_29();
	virtual void nullsub_30();
	virtual void nullsub_31();
	virtual void nullsub_32();
	virtual void nullsub_33();
	virtual void nullsub_34();
	virtual void nullsub_35();
	virtual bool sub_36();					//returns 0

	public:
		typedef sead::OffsetList<ActorBase> List;
	public:
		bool isActive() const
		{
			return mIsActive;
		}

		void deleteRequest()
		{
			mDeleteRequestFlag = true;
		}

		bool isRequestedDelete() const
		{
			return mDeleteRequestFlag;
		}

		ActorUniqueID getActorUniqueID() const
		{
			return mActorUniqueID;
		}

		// Address: 0x02002C80
		s32 getProfileID() const;

		sead::Heap* getActorHeap() const
		{
			return mpActorHeap;
		}

		ActorBase* getParent() const
		{
			return mpParent;
		}

		template <typename T>
		T* getParent() const
		{
			return sead::DynamicCast<T>(mpParent);
		}

		void removeChild(ActorBase* p_child);

	protected:
		ActorBase(const ActorCreateParam& param);

	protected:
		void setActive_(bool active)
		{
			mIsActive = active;
		}

	protected:
		sead::Heap*     mpActorHeap;
		ActorUniqueID   mActorUniqueID;
		Profile*        mpActorProfile;
		bool            mCreateImmediately;
		bool            _d;
		bool            mIsActive;
		bool            mDeleteRequestFlag;
		u32             mParam0;
		u32             mParam1;
		ActorParamEx1   mParamEx;
		List            mChildList;
		sead::ListNode  mChildNode;
		ActorBase*      mpParent;
		sead::ListNode  mExecuteNode;
		sead::ListNode  mDrawNode;
		sead::BitFlag32 mFlag;

		friend class ActorMgr;
	};

	template <typename T>
	ActorBase* TActorFactory(const ActorCreateParam& param)
	{
		return new T(param);
	}
