#pragma once

#include <iostream>
#include "Player.h"
#include "Board.h"

using std::cout;

class Game : public Board
{
private:
	Player Player_1;
	Player Player_2;
public:
	void randomCardStack();
	void give5Card();
	void giveAnotherCard();
	void initPlayer();

	void abilityTurn(int input);
	void damageTurn(int input);

	Card* playerTurn(Player& input, int index);
	void boardTurn();
	int checkWinner();

	void theGame();
	void mainMenu();

	void Play();
};