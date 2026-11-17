#pragma once

#include <Actor.hpp>

#ifndef		PLAYEROBJECT_HPP
#define		PLAYEROBJECT_HPP
class PlayerObject : public Actor {
	SEAD_RTTI_OVERRIDE(PlayerObject, Actor)
	~PlayerObject() override;

	char _Z[0x8000];
};
#endif	//	PLAYEROBJECT_HPP