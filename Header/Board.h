#pragma once

#include <array>
#include "AllCard.h"

#define PLAYER1 1
#define PLAYER2 2

class Board
{
private:
	std::array<Card*, 50> cardStack;
	std::array<Card*, 2> chosenCard;
protected:
	void setCardStack(Card* input, int index);
	Card* getCardStack(int index);
	int getCardStackSize();

	void initCardStack();
	Card* takeFrontCard();

	void setChosenCard(Card* input, int index);
	Card* getChosenCard(int index);

	int comparingCardDamage();
	int comparingCardType();

	void destroyCard();
};