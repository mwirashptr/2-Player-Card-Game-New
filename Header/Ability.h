#pragma once

#include "Player.h"
namespace
{
	void Debuff_Ability(Player& user, Player& opponent)
	{
		opponent.modifHealth(-5);
	}

	void Armor_Ability(Player& user, Player& opponent)
	{
		user.modifHealth(5);
	}
}