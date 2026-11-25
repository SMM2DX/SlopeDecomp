#pragma once

#include <sead/seadRuntimeTypeInfo.hpp>
#include <sead/seadHeap.hpp>

#ifndef		ACTORBASE_HPP
#define		ACTORBASE_HPP
class ActorBase {
	//	00000071028522E0
	SEAD_RTTI_BASE(ActorBase)
	virtual char* getClassName();
	virtual ~ActorBase();
	virtual bool sub_6();					//returns 1
	virtual int sub_7();					//
	virtual void sub_8();					//
	virtual bool sub_9();					//returns 1
	virtual bool sub_10();					//returns 0
	virtual void nullsub_11();				//
	virtual void sub_12();					//
	virtual void nullsub_13();				//
	virtual bool sub_14();					//returns 1
	virtual bool sub_15();					//returns 1
	virtual void nullsub_16();				//
	virtual bool sub_17();					//returns 1
	virtual int sub_18();					//
	virtual void nullsub_19();				//
	virtual int sub_20();					//returns 2
	virtual void sub_21();					//unknown return type
	virtual void sub_22();					//
	virtual bool sub_23();					//returns 0
	virtual sead::Heap sub_24();			//
	virtual void sub_25();					//returns UnknownClass
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
};
#endif	//	ACTORBASE_HPP