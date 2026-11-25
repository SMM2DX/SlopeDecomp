#pragma once

#include <Actor.hpp>

#ifndef		PLAYEROBJECT_HPP
#define		PLAYEROBJECT_HPP
class PlayerObject : public Actor {
	//	0000007102954498
	SEAD_RTTI_OVERRIDE(PlayerObject, Actor)
	~PlayerObject() override;

	char _Z[0x8000];
};
#endif	//	PLAYEROBJECT_HPP