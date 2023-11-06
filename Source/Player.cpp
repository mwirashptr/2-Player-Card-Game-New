#include "Player.h"

Player::Player()
{
	setHealth(0);
}

void Player::setDeck(Card* input, int index)
{
	std::cout << " before set deck ";
	deck[index - 1] = input;
	std::cout << " After set deck ";
}

Card* Player::getCard(int index)
{
	return deck[index - 1];
}

void Player::removeCard(int index)
{
	for (int i = index - 1; i < 4; i++)
	{
		deck[i] = deck[i + 1];
	}
	Card* temp = 0;
	deck[5 - 1] = temp;
	std::cout << "Remove Card ";
}

Card* Player::chooseCard()
{
	Card* temp; int index;
	std::cout << "\n\n\t\t\t\t\t\t\t";
	std::cin >> index;
	if (index < 1 || index > 5) chooseCard();
	temp = getCard(index);
	removeCard(index);
	return temp;
}