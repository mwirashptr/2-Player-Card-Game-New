#pragma once

#include "Card.h"
#include "Ability.h"

class DefaultCard : public Card
{
public:
	DefaultCard()
	{
		setNumber(0);
		setCardType(' ');
		setAbilityDesc("");
		setNickname("");
	}
	void ability(Player& user, Player& opponent) override
	{
	}
};

class DebuffCard : public Card
{
public:
	DebuffCard(int _number)
	{
		setNumber(_number);
		setCardType('A');
		setAbilityDesc("It is a Debuff Card");
		setNickname("" + std::to_string(_number) + getCardType());
	}
	void ability(Player& user, Player& opponent) override
	{
		Debuff_Ability(user, opponent);
	}
};

class ArmorCard : public Card
{
public:
	ArmorCard(int _number)
	{
		setNumber(_number);
		setCardType('D');
		setAbilityDesc("It is an Armor Card");
		setNickname("" + std::to_string(_number) + getCardType());
	}
	void ability(Player& user, Player& opponent) override
	{
		Armor_Ability(user, opponent);
	}
};
