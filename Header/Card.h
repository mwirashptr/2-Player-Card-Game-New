#pragma once

#include <string>
#include "BasePlayer.h"

class Card
{
protected:
	int number;
	char cardType;
	std::string abilityDesc;
	std::string nickname = "";
public:
	Card();
	void setNumber(int input);
	void setCardType(char input);
	void setAbilityDesc(std::string input);
	void setNickname(std::string input);

	int getNumber();
	char getCardType(); // return 1 = attack, 2 = defense
	std::string getAbilityDesc();
	std::string getNickname();

	virtual void ability(BasePlayer* user, BasePlayer* opponent) = 0;
};