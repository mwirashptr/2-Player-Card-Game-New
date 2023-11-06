#pragma once

#include "BasePlayer.h"
namespace
{
	void Debuff_Ability(BasePlayer* user, BasePlayer* opponent)
	{
		opponent->modifHealth(-5);
	}

	void Armor_Ability(BasePlayer* user, BasePlayer* opponent)
	{
		user->modifHealth(5);
	}
}