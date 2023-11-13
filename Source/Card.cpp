#include "Card.h"

Card::Card()
{
	number = 0;
	cardType = ' ';
	abilityDesc = "";
	nickname = "";
}
void Card::setNumber(int input)
{
	number = input;
}

void Card::setCardType(char input)
{
	cardType = input;
}

void Card::setAbilityDesc(std::string input)
{
	abilityDesc = input;
}

void Card::setNickname(std::string input)
{
	nickname = input;
}
int Card::getNumber()
{
	return number;
}
char Card::getCardType() // return 1 = attack, 2 = defense
{
	return cardType;
}std::string Card::getAbilityDesc()
{
	return abilityDesc;
}
std::string Card::getNickname()
{
	return nickname;
}