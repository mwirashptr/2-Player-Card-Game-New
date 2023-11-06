#include "Board.h"

void Board::setCardStack(Card* input, int index)
{
	cardStack[index - 1] = input;
}

Card* Board::getCardStack(int index)
{
	return cardStack[index - 1];
}

int Board::getCardStackSize()
{
	int i = 1;
	while (i < cardStack.size())
	{
		if (getCardStack(i)->getNickname() == "")
			break;
		i++;
	}
	return i;
}

void Board::setChosenCard(Card* input, int index)
{
	chosenCard[index - 1] = input;
}

Card* Board::getChosenCard(int index)
{
	return chosenCard[index - 1];
}

void Board::initCardStack()
{
	int index = 1;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			Card* temp = new DebuffCard;
			setCardStack(temp, index);
			index++;
		}
		for (int j = 1; j <= 5; j++)
		{
			Card* temp = new ArmorCard;
			setCardStack(temp, index);
			index++;
		}
	}
}

Card* Board::takeFrontCard()
{
	std::cout << "CardStackSize " << getCardStackSize();
	std::cout << "BeforeGetCardStack";
	Card* temp = getCardStack(1);
	std::cout << "BeforeGetCardstackSize";
	for (int i = 0; i < getCardStackSize() - 1; i++)
	{
		cardStack[i] = cardStack[i + 1];
		std::cout << " moveCard " << i;
	}
	std::cout << "before empty";
	Card* empty = new DefaultCard;
	setCardStack(empty, getCardStackSize());
	return temp;
}

int Board::comparingCardDamage()
{
	if (getChosenCard(PLAYER1)->getNumber() > getChosenCard(PLAYER2)->getNumber())			return 1;		// damage kartu player 1 lebih besar
	else if (getChosenCard(PLAYER1)->getNumber() < getChosenCard(PLAYER2)->getNumber())		return 2;		// damage kartu player 2 lebih besar
	else																					return 0;		// damage kartu sama
}

int Board::comparingCardType()
{
	if (getChosenCard(PLAYER1)->getCardType() < getChosenCard(PLAYER2)->getCardType())		return 1;	// kartu player 1 attack
	else if (getChosenCard(PLAYER1)->getCardType() > getChosenCard(PLAYER2)->getCardType())	return 2;	// kartu player 2 attack
	else if (getChosenCard(PLAYER1)->getCardType() == 'A')									return 3;	// kedua kartu player attack
	else if (getChosenCard(PLAYER1)->getCardType() == 'D')									return 4;	// kedua kartu player defense
	else																					return 0;   // Error
}

void Board::destroyCard()
{
	Card* temp = 0;
	chosenCard = { temp, temp };
}