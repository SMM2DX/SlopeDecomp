#pragma once

#include "Actor.hxx"
#include "Lp/Utl/StateMachine.hpp"

class ActorCollision : public Actor {
	SEAD_RTTI_OVERRIDE(ActorCollision, Actor)
	char* getClassName() override;
	~ActorCollision() override;

	using StateMachine = Lp::Utl::StateMachine<ActorCollision>;
	enum State : int {
		cState_Sleep = 0,
		cState_HitStar = 1,
		cState_HitShell = 2,
		cState_HitMetMario = 3,
		cState_HitTogezoMario = 4,
		cState_HitTail = 5,
		cState_HitKoopa = 6,
		cState_HitStamp = 7,
		cState_HitBg = 8,
		cState_StampKoopacar = 9,
		cState_DieCastleWait = 10,
		cState_DieCastleFall = 11,
		cState_HitShield = 12,
		cState_HitBoomerang = 13,
		cState_HitSword = 14,
		cState_COUNT = 15,
	};

	char gap_0[6072];
	StateMachine stateMachine;
	char gap_2[4000];
	State bullshit;
};
