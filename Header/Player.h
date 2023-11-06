#pragma once

#include <array>
#include "BasePlayer.h"
#include "Card.h"

class Player : public BasePlayer
{
	std::array<Card*, 5> deck;
public:
	Player();
	void setDeck(Card* input, int index);
	Card* getCard(int index);
	void removeCard(int index);

	Card* chooseCard();
};