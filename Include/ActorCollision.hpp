#pragma once

#include <Actor.hpp>

#ifndef		ACTORCOLLISION_HPP
#define		ACTORCOLLISION_HPP
class ActorCollision : public Actor {
	SEAD_RTTI_OVERRIDE(ActorCollision, Actor)
	~ActorCollision() override;

	char _Z[0x8000];
};
#endif	//	ACTORCOLLISION_HPP