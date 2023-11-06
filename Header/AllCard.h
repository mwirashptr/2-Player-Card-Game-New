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
	void ability(BasePlayer* user, BasePlayer* opponent) override
	{
	}
};

class DebuffCard : public Card
{
public:
	DebuffCard()
	{
		setNumber(5);
		setCardType('A');
		setAbilityDesc("It is a Debuff Card");
		setNickname("5A");
	}
	void ability(BasePlayer* user, BasePlayer* opponent) override
	{
		//Debuff_Ability(user, opponent);
	}
	/*int getNumber() { return number; };
	char getCardType() { return cardType; };
	std::string getAbilityDesc() { return abilityDesc; };
	std::string getNickname() { return nickname; };*/
};
/*DebuffCard::DebuffCard()
{
	setNumber(5);
	setCardType('A');
	setAbilityDesc("It is a Debuff Card");
	std::string temp = "";
	setNickname(temp + char(getNumber() + '0') + getCardType());
}*/

class ArmorCard : public Card
{
public:
	ArmorCard()
	{
		setNumber(5);
		setCardType('D');
		setAbilityDesc("It is an Armor Card");
		setNickname("5D");
	}
	void ability(BasePlayer* user, BasePlayer* opponent) override
	{
		Armor_Ability(user, opponent);
	}
	/*int getNumber() { return number; };
	char getCardType() { return cardType; };
	std::string getAbilityDesc() { return abilityDesc; };
	std::string getNickname() { return nickname; };*/
};
/*ArmorCard::ArmorCard()
{
	setNumber(5);
	setCardType('D');
	setAbilityDesc("It is an Armor Card");
	std::string temp = "";
	setNickname(temp + char(getNumber() + '0') + getCardType());
}*/